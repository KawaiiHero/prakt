/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, b, c, d;
    int x1, x2;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;
    cout << "c="; cin >> c;

    d = b * b - 4 * a * c;

    x1 = -b - sqrt(d) / 2 * a;
    x2 = (-b + sqrt(d)) / 2 * a;
    cout << x1 << " " << x2;

    return 0;
}