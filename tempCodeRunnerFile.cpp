bigInt bigInt::operator=(const bigInt &a)
{
    this->sign = a.sign;
    this->digits = a.digits;
    this->numOfDigit = a.numOfDigit;

    return *this;
}

bigInt bigInt::operator=(const string &s)
{
    *this = bigInt(s);
    return *this;
}
