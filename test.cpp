//Name: SOURASHIS MONDAL

#include <bits/stdc++.h>

using namespace std;

int toInt(char c)
{
    return c - '0';
}

char toChar(int n)
{
    return '0' + n;
}

class bigInt
{
    enum sign_type
    {
        plus,
        minus
    };

    sign_type sign;
    string digits;
    long long numOfDigit;

private:
    bool areDigitsValid() const;
    void removeZerosFromFront();
    sign_type oppositeSign();

    //adds 2 positive integers
    friend bigInt addPositiveNums(bigInt a, bigInt b);

    //subtratcs two positive integers and gives the absolute difference
    friend bigInt absoluteDiffOfPositiveNums(bigInt a, bigInt b);

    friend bigInt subtract(bigInt a, bigInt b);

    //multiplies 2 positive integers
    bigInt multipyPositiveNums();

    //multiplies 2 integers(may be positive or negative or zero)
    bigInt multiply();

    //adds 2 integers(may be positive or negative or zero)
    friend bigInt add(bigInt a, bigInt b);

public:
    void makePositive();

    //*_______________________CONSTRUCTORS_________________________________________
    bigInt();
    bigInt(int n);
    bigInt(long n);
    bigInt(long long n);
    bigInt(const string &s);
    bigInt(const char *s);
    bigInt(const bigInt &);
    //*_______________________CONSTRUCTORS_________________________________________

    bool isNegative() const;
    bool isZero() const;

    friend ostream &operator<<(ostream &output, const bigInt &n);

    friend bigInt abs(const bigInt &a);

    //*_________RELATIONAL OPERATORS_____________________________________________________
    friend bool operator<(const bigInt &a, const bigInt &b);
    friend bool operator>(const bigInt &a, const bigInt &b);
    friend bool operator==(const bigInt &a, const bigInt &b);

    friend bool operator>=(const bigInt &a, const bigInt &b);
    friend bool operator<=(const bigInt &a, const bigInt &b);
    friend bool operator!=(const bigInt &a, const bigInt &b);
    //*_________________________________________________________________________________

    //*_____________UNARY OPERATORS____________________________________
    bigInt operator-() const;
    //*____________________________________________________________

    //*______________________ARITHMETIC OPERATOR___________________________________________
    friend bigInt operator-(bigInt a, bigInt b);
    friend bigInt operator+(bigInt a, bigInt b);
};

bool bigInt::areDigitsValid() const
{
    for (auto c : digits)
    {
        if (!(c >= '0' && c <= '9'))
            return false;
    }

    return true;
}

void bigInt::removeZerosFromFront()
{
    if (digits.empty())
    {
        digits = "0";
        return;
    }

    //remove zeros from front
    int k = 0;
    while (k < digits.size() && digits[k] == '0')
        k++;

    digits.erase(0, k);

    if (digits.empty())
        digits = "0";
}

bool bigInt::isNegative() const
{
    return (this->sign == minus);
}
bigInt::bigInt()
{
    sign = plus;
    digits = "0";
    numOfDigit = 0;
}

bigInt::bigInt(int n)
{
    if (n >= 0)
        sign = plus;
    else
        sign = minus;

    digits = to_string(n);
    if (digits[0] == '-')
        digits.erase(0, 1);

    numOfDigit = digits.size();
}
bigInt::bigInt(long n)
{
    if (n >= 0)
        sign = plus;
    else
        sign = minus;

    digits = to_string(n);
    if (digits[0] == '-')
        digits.erase(0, 1);

    numOfDigit = digits.size();
}
bigInt::bigInt(long long n)
{
    if (n >= 0)
        sign = plus;
    else
        sign = minus;

    digits = to_string(n);
    if (digits[0] == '-')
        digits.erase(0, 1);

    numOfDigit = digits.size();
}

bigInt::bigInt(const string &s)
{
    sign = plus;

    if (s.empty())
        this->digits = "0";
    else
    {
        //if s contains minus signs at begining
        //count minus signs and evaluate the resultant sign
        int i = 0;
        while (i < s.size() && s[i] == '-')
            i++;

        int minusCount = i;
        if (minusCount % 2 == 1)
            sign = minus;
        else
            sign = plus;

        digits = s.substr(i, s.size() - i);

        //check if digits are valid or not
        if (!areDigitsValid())
        {
            //*EXCEPTION
        }

        removeZerosFromFront();
        this->numOfDigit = digits.size();
    }
}

bigInt::bigInt(const char *s)
{
    sign = plus;

    *this = bigInt(string(s));
}

bigInt::bigInt(const bigInt &a)
{
    *this = a;
}

ostream &operator<<(ostream &output, const bigInt &n)
{
    if (n.isNegative())
        output << "-";

    output << n.digits;
    return output;
}

bool bigInt::isZero() const
{
    return digits == "0";
}

bool operator<(const bigInt &a, const bigInt &b)
{
    if (a.isZero() && b.isZero())
        return false;

    // if both are positive
    if (!a.isNegative() && !b.isNegative())
    {
        if (a.numOfDigit < b.numOfDigit)
            return true;
        else if (a.numOfDigit > b.numOfDigit)
            return false;
        else // if(a.numOfDigit == b.numOfDigit)
            return (a.digits < b.digits);
    }

    //if both are negative
    else if (a.isNegative() && b.isNegative())
    {
        if (a.numOfDigit > b.numOfDigit)
            return true;
        else if (a.numOfDigit < b.numOfDigit)
            return false;
        else // if(a.numOfDigit == b.numOfDigit)
            return (a.digits > b.digits);
    }

    else if (a.isNegative() && !b.isNegative())
        return true;
    else // if(!a.isNegative() && b.isNegative())
        return false;
}

bool operator>(const bigInt &a, const bigInt &b)
{
    if (a.isZero() && b.isZero())
        return false;

    // if both are positive
    if (!a.isNegative() && !b.isNegative())
    {
        if (a.numOfDigit > b.numOfDigit)
            return true;
        else if (a.numOfDigit < b.numOfDigit)
            return false;
        else // if(a.numOfDigit == b.numOfDigit)
            return (a.digits > b.digits);
    }

    //if both are negative
    else if (a.isNegative() && b.isNegative())
    {
        if (a.numOfDigit < b.numOfDigit)
            return true;
        else if (a.numOfDigit > b.numOfDigit)
            return false;
        else // if(a.numOfDigit == b.numOfDigit)
            return (a.digits < b.digits);
    }

    else if (a.isNegative() && !b.isNegative())
        return false;
    else // if(!a.isNegative() && b.isNegative())
        return true;
}

bool operator==(const bigInt &a, const bigInt &b)
{
    return (a.sign == b.sign) && (a.numOfDigit == b.numOfDigit) && (a.digits == b.digits);
}

bool operator>=(const bigInt &a, const bigInt &b)
{
    return (a == b) || (a > b);
}

bool operator<=(const bigInt &a, const bigInt &b)
{
    return (a == b) || (a < b);
}

bool operator!=(const bigInt &a, const bigInt &b)
{
    return !(a == b);
}

bigInt bigInt::operator-() const
{
    bigInt b = *this;
    if (b == 0)
        return b;

    if (b.sign == plus)
        b.sign = minus;
    else
        b.sign = plus;

    return b;
}

bigInt addPositiveNums(bigInt a, bigInt b)
{

    //make a point to the larger string
    if (a < b)
        swap(a, b);

    int n1 = a.digits.size(), n2 = b.digits.size();

    string res(n1 + 1, '0');

    int i = n1 - 1, j = n2 - 1, k = res.size() - 1;

    int sum = 0, digit = 0;
    int carry = 0;
    while (i >= 0)
    {
        sum = 0;
        if (j >= 0)
            sum = toInt(a.digits[i]) + toInt(b.digits[j]) + carry;
        else
            sum = toInt(a.digits[i]) + carry;

        digit = sum % 10;
        carry = floor(sum / 10);

        res[k] = toChar(digit);

        i--;
        j--;
        k--;
    }

    if (carry > 0)
        res[k] = toChar(carry);

    bigInt resBigInt(res);

    return resBigInt;
}

bigInt absoluteDiffOfPositiveNums(bigInt a, bigInt b)
{

    //make a point to the larger string
    if (a < b)
        swap(a, b);

    int n1 = a.digits.size(), n2 = b.digits.size();

    string res(n1, '0');

    int i = n1 - 1, j = n2 - 1, k = res.size() - 1;

    int diff = 0, digit = 0;
    int carry = 0;
    while (i >= 0)
    {
        diff = 0;
        if (j >= 0)
            diff = toInt(a.digits[i]) - toInt(b.digits[j]) - carry;
        else
            diff = toInt(a.digits[i]) - carry;

        if (diff < 0)
        {
            diff = diff + 10;
            carry = 1;
        }
        else
            carry = 0;

        digit = diff;

        res[k] = toChar(digit);

        i--;
        j--;
        k--;
    }

    bigInt resBigInt(res);

    return resBigInt;
}

void bigInt::makePositive()
{
    this->sign = plus;
}
bigInt abs(const bigInt &a)
{
    bigInt b = a;
    b.makePositive();

    return b;
}

bigInt subtract(bigInt a, bigInt b)
{
    bigInt abs_a = abs(a);
    bigInt abs_b = abs(b);

    if (b == 0)
        return a;
    if (a == 0)
        return -b;

    bigInt res = 0;
    if (a < 0)
    {
        if (b > 0)
            return -addPositiveNums(abs_a, abs_b);

        else // if (b < 0)
        {
            if (a >= b)
                return absoluteDiffOfPositiveNums(abs_b, abs_a);
            else
                return -absoluteDiffOfPositiveNums(abs_b, abs_a);
        }
    }
    else //if (a > 0)
    {
        if (b < 0)
            return addPositiveNums(abs_a, abs_b);
        else //if (b > 0)
        {
            if (a >= b)
                return absoluteDiffOfPositiveNums(abs_a, abs_b);
            else // if(a < b)
                return -absoluteDiffOfPositiveNums(abs_b, abs_a);
        }
    }
}

bigInt operator-(bigInt a, bigInt b)
{
    return subtract(a, b);
}

bigInt add(bigInt a, bigInt b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    if (a > 0)
    {
        if (b > 0)
            return addPositiveNums(a, b);
        else //if(b<0)
            return subtract(a, -b);
    }
    else // if (a < 0 )
    {
        if (b < 0)
            return -addPositiveNums(-a, -b);
        else //if(b > 0)
            return subtract(b, -a);
    }
}

bigInt operator+(bigInt a, bigInt b)
{
    return add(a, b);
}
int main()
{
    cout << "\n\nHello earth\n\n\n";

    bigInt a = "-69";
    bigInt b = 123;
    bigInt c("-000123456");

    cout << "\na = " << a;
    cout << "\nb = " << b;
    cout << "\nc = " << c;

    cout << endl
         << (a == 0) << endl;

    if (a >= b)
        cout << "\na>=b";

    bigInt res = addPositiveNums(a, b);

    cout << "\n-a = " << -a;
    cout << "\n|a| + |b| = " << addPositiveNums(a, b);

    // cout << "\nabs(a-b) = " << absoluteDiffOfPositiveNums(a, b);

    cout << "\na + b = " << (a + b);
    return 0;
}