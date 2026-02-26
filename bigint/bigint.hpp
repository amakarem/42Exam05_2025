#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <vector>
class bigint
{
    private:
        std::vector<unsigned int> digits;
    public:
        bigint();
        ~bigint();
        bigint(unsigned int n);
        bigint(const bigint &other);
        bigint& operator=(const bigint &other);
        bigint operator+(const bigint &other) const;
        bigint& operator+=(const bigint &other);
        bigint& operator++();
        bigint operator++(int);
        unsigned int toUnsignedInt() const;
        bigint operator<<(const unsigned int shift) const;
        bigint operator<<(const bigint &shift) const;
        bigint operator>>(const unsigned int shift) const;
        bigint operator>>(const bigint &shift) const;
        bigint& operator<<=(const unsigned int shift);
        bigint& operator<<=(const bigint &shift);
        bigint& operator>>=(const unsigned int shift);
        bigint& operator>>=(const bigint &shift);
        bool operator!=(const bigint &other) const;
        bool operator==(const bigint &other) const;
        bool operator>(const bigint &other) const;
        bool operator<(const bigint &other) const;
        bool operator>=(const bigint &other) const;
        bool operator<=(const bigint &other) const;
        void print(std::ostream &os) const;
};
std::ostream& operator<<(std::ostream &os, const bigint &n);
#endif
