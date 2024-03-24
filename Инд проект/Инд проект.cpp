#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void caesarCipher(char text[], int key) {
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] >= 'а' && text[i] <= 'я') {
            text[i] = tolower('а' + (text[i] - 'а' + key) % 32);
        }
        else if (text[i] >= 'А' && text[i] <= 'Я') {
            text[i] = toupper('А' + (text[i] - 'А' + key) % 32);
        }
        i++;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);

    int ecrypt_mode, key, mode;
    char text[MAX_LENGTH];

    printf("Выберите режим:\n1. Шифрование\n2. Дешифрование\n");
    scanf_s("%d", &ecrypt_mode);

    printf("Введите ключ шифрования: ");
    scanf_s("%d", &key);
    if (ecrypt_mode == 2)
        key = -key;
    printf("Выберите режим ввода текста:\n1. Через консоль\n2. Из файла\n");
    scanf_s("%d", &mode);

    if (mode == 1) {
        printf("Введите текст: ");
        getchar();
        fgets(text, MAX_LENGTH, stdin);
    }
    else if (mode == 2) {
        FILE* file;
        fopen_s(&file, "input.txt", "r");
        if (file == NULL) {
            printf("Ошибка открытия файла\n");
            return 1;
        }
        fgets(text, MAX_LENGTH, file);
        fclose(file);
    }
    else {
        printf("Неверный режим ввода\n");
        return 1;
    }

    printf("Выберите режим вывода текста:\n1. В консоль\n2. В файл\n");
    scanf_s("%d", &mode);

    if (mode == 1) {
        caesarCipher(text, key);
        printf("Результат: %s\n", text);
    }
    else if (mode == 2) {
        caesarCipher(text, key);
        FILE* file;
        fopen_s(&file, "output.txt", "w");
        if (file == NULL) {
            printf("Ошибка открытия файла для записи\n");
            return 1;
        }
        fprintf(file, "%s", text);
        fclose(file);
        printf("Текст успешно записан в файл 'output.txt'\n");
    }
    else {
        printf("Неверный режим вывода\n");
        return 1;
    }

    return 0;
}
