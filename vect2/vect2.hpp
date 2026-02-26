#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
class vect2
{
    private:
        int v[2];
    public:
        vect2();
        vect2(int x, int y);
        vect2(const vect2 &other);
        vect2& operator=(const vect2 &other);
        ~vect2();
        vect2& operator++();
        vect2 operator++(int);
        vect2& operator--();
        vect2 operator--(int);
        vect2& operator+=(const vect2 &other);
        vect2& operator-=(const vect2 &other);
        vect2& operator*=(const vect2 &other);
        vect2& operator*=(const int n);
        vect2 operator+(const vect2 &other) const;
        vect2 operator-(const vect2 &other) const;
        vect2 operator-() const;
        vect2 operator+() const;
        vect2 operator*(const vect2 &other) const;
        vect2 operator*(const int n) const;
        int operator[](int index) const;
        int& operator[](int index);
        bool operator==(const vect2 &other) const;
        bool operator!=(const vect2 &other) const;
        void print(std::ostream &os) const;
};
std::ostream& operator<<(std::ostream &os, const vect2 &v);
vect2 operator*(int n, const vect2 &other);
#endif