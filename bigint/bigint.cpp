#include "bigint.hpp"

bigint::bigint()
{
    digits.push_back(0);
}

bigint::bigint(const bigint &other)
{
    this->digits = other.digits;
}

bigint& bigint::operator=(const bigint &other)
{
    if (this != &other)
        this->digits = other.digits;
    return *this;
}

bigint::bigint(unsigned int n)
{
    if (n == 0)
        this->digits.push_back(0);
    else
    {
        while (n > 0)
        {
            this->digits.push_back(n % 10);
            n = n / 10;
        }
    }
}

bigint::~bigint() {}

bigint bigint::operator+(const bigint &other) const
{
    bigint result;
    result.digits.clear();
    size_t max_size = std::max(digits.size(), other.digits.size());
    unsigned int carry = 0;
    for (size_t i = 0; i < max_size || carry; ++i)
    {
        unsigned int sum = carry;
        if (i < digits.size())
            sum += digits[i];
        if (i < other.digits.size())
            sum += other.digits[i];
        result.digits.push_back(sum % 10);
        carry = sum / 10;
    }
    return result;
}

bigint& bigint::operator+=(const bigint &other)
{
    *this = *this + other;
    return *this;
}

bigint& bigint::operator++()
{
    *this = *this + 1;
    return *this;
}
bigint bigint::operator++(int)
{
    bigint result(*this);
    *this = *this + 1;
    return result;
}

bigint bigint::operator<<(const unsigned int shift) const
{
    bigint result(*this);
    if (*this != 0)
        result.digits.insert(result.digits.begin(), shift, 0);
    return result;
}

bigint bigint::operator<<(const bigint &shift) const
{
    return (*this) << shift.toUnsignedInt();
}

bigint bigint::operator>>(const unsigned int shift) const
{
    bigint result(*this);
    if (shift >= result.digits.size())
    {
        result.digits.clear();
        result.digits.push_back(0);
    }
    else
        result.digits.erase(result.digits.begin(), result.digits.begin() + shift);
    return result;
}

bigint bigint::operator>>(const bigint &shift) const
{
    return (*this) >> shift.toUnsignedInt();
}

unsigned int bigint::toUnsignedInt() const
{
    unsigned int s = 0;
    unsigned int multiplyer = 1;
    for (size_t i = 0; i < digits.size(); ++i)
    {
        s += digits[i] * multiplyer;
        multiplyer *= 10;
    }
    return s;
}

bigint& bigint::operator<<=(const unsigned int shift)
{
    if (*this != 0)
        this->digits.insert(this->digits.begin(), shift, 0);
    return *this;
}

bigint& bigint::operator<<=(const bigint &shift)
{
    return (*this) <<= shift.toUnsignedInt();
}

bigint& bigint::operator>>=(const unsigned int shift)
{
    if (shift >= digits.size())
    {
        digits.clear();
        digits.push_back(0);
    }
    else
        digits.erase(digits.begin(), digits.begin() + shift);
    return *this;
}

bigint& bigint::operator>>=(const bigint &shift)
{
    return (*this) >>= shift.toUnsignedInt();
}

bool bigint::operator!=(const bigint &other) const
{
    return (this->digits != other.digits);
}

bool bigint::operator==(const bigint &other) const
{
    return (this->digits == other.digits);
}

bool bigint::operator>(const bigint &other) const
{
    if (digits.size() != other.digits.size())
        return (digits.size() > other.digits.size());
    for (size_t i = digits.size(); i-- > 0;)
    {
        if (digits[i] != other.digits[i])
            return (digits[i] > other.digits[i]);
    }
    return false;
}

bool bigint::operator<(const bigint &other) const
{
    return (other > *this);
}

bool bigint::operator<=(const bigint &other) const
{
    return (*this < other || *this == other);
}

bool bigint::operator>=(const bigint &other) const
{
    return (*this > other || *this == other);
}

void bigint::print(std::ostream &os) const
{
    for (size_t i = digits.size(); i-- > 0;)
        os << digits[i];
}


std::ostream& operator<<(std::ostream &os, const bigint &n)
{
    n.print(os);
    return os;
}