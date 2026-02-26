#include "vect2.hpp"

vect2::vect2()
{
    v[0] = 0;
    v[1] = 0;
}

vect2::~vect2() {};
vect2::vect2(int x, int y)
{
    v[0] = x;
    v[1] = y;
}

vect2::vect2(const vect2 &other)
{
    v[0] = other.v[0];
    v[1] = other.v[1];
}

vect2& vect2::operator=(const vect2 &other)
{
    if (this != &other)
    {
        v[0] = other.v[0];
        v[1] = other.v[1];
    }
    return *this;
}

vect2& vect2::operator++()
{
    ++v[0];
    ++v[1];
    return *this;
}
vect2 vect2::operator++(int)
{
    vect2 result(*this);
    ++(*this);
    return result;
}

vect2& vect2::operator--()
{
    --v[0];
    --v[1];
    return *this;
}
vect2 vect2::operator--(int)
{
    vect2 result(*this);
    --(*this);
    return result;
}

vect2& vect2::operator+=(const vect2 &other)
{
    v[0] += other.v[0];
    v[1] += other.v[1];
    return *this;
}

vect2& vect2::operator-=(const vect2 &other)
{
    v[0] -= other.v[0];
    v[1] -= other.v[1];
    return *this;
}

vect2& vect2::operator*=(const vect2 &other)
{
    v[0] *= other.v[0];
    v[1] *= other.v[1];
    return *this;
}

vect2& vect2::operator*=(const int n)
{
    v[0] *= n;
    v[1] *= n;
    return *this;
}

vect2 vect2::operator+(const vect2 &other) const
{
    return (vect2(this->v[0] + other.v[0], this->v[1] + other.v[1]));
}

vect2 vect2::operator-(const vect2 &other) const
{
    return (vect2(this->v[0] - other.v[0], this->v[1] - other.v[1]));
}

vect2 vect2::operator-() const
{
    return (vect2(-v[0], -v[1]));
}

vect2 vect2::operator+() const
{
    return (vect2(+v[0], +v[1]));
}

vect2 vect2::operator*(const vect2 &other) const
{
    return (vect2(this->v[0] * other.v[0], this->v[1] * other.v[1]));
}

vect2 vect2::operator*(const int n) const
{
    return (vect2(this->v[0] * n, this->v[1] * n));
}

vect2 operator*(int n, const vect2 &other)
{
    return (other * n);
}


int vect2::operator[](int index) const
{
    return v[index];
}
int& vect2::operator[](int index)
{
    return v[index];
}

bool vect2::operator==(const vect2 &other) const
{
    return (v[0] == other.v[0] && v[1] == other.v[1]);
}

bool vect2::operator!=(const vect2 &other) const
{
    return (v[0] != other.v[0] || v[1] != other.v[1]);
}

void vect2::print(std::ostream &os) const
{
    os << "{" << v[0] << ", " << v[1] << "}";
}
std::ostream& operator<<(std::ostream &os, const vect2 &v)
{
    v.print(os);
    return os;
}