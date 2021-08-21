//Name: SOURASHIS MONDAL
#include <bits/stdc++.h>
#include "bigInt.h"

using namespace std;
// int main()
// {
//     cout << "\n\nHello earth :)\n\n\n";

//     bigInt a = "-69";
//     bigInt b = 123;
//     bigInt c("-000123456");

//     cout << "\na = " << a;
//     cout << "\nb = " << b;
//     cout << "\nc = " << c;

//     cout << endl
//          << (a == 0) << endl;

//     if (a >= b)
//         cout << "\na>=b";

//     bigInt res = addPositiveNums(a, b);

//     cout << "\n-a = " << -a;
//     cout << "\n|a| + |b| = " << addPositiveNums(a, b);

//     // cout << "\nabs(a-b) = " << absoluteDiffOfPositiveNums(a, b);

//     cout << "\na + b = " << (a + b);

//     cout << "\na * b = " << (a * b);

//     a *= b;
//     cout << "\nafter doing  a*=b ,  a = " << a;

//     cout << "\na++ = " << a++;
//     cout << "\na = " << a;
//     cout << "\n++a = " << ++a;
//     cout << "\na = " << a;

//     string s = string(a);
//     cout << "\ns = " << s;

//     cout << "\n"
//          << to_string(b);
//     cout << "\n\n\n___________________________END__________________________________________\n";
//     return 0;
// }

int main()
{
     cout << "\n\nHello earth :)\n\n\n";

     string num1 = "2";
     string num2 = "3";

     bigInt a = num1;
     bigInt b = num2;

     cout << "\na = " << a;
     cout << "\nb = " << b;

     cout << "\na * b = " << a * b;

     bigInt x = -100, y = 12;

     // x %= y;
     cout << "\n"
          << x << " / " << y << " = " << (x / y);
     cout << "\n"
          << x << " % " << y << " = " << (x % y);

     cout << "\n"
          << pow(bigInt(123), 123);
     cout << "\n"
          << pow(bigInt(123), 124);

     cout << "\n\nfactorial(100) = " << factorial(1000);
     cout << "\n\n\n___________________________END__________________________________________\n";

     return 0;
}