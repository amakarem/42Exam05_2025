#include "bigint.hpp"

int main(void)
{
std::cout << std::boolalpha;
   const bigint a(42);
    bigint b(21), c, d(1337), e(d);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "(c += a) = " << (c += a) << std::endl;

    std::cout << "b = " << b << std::endl;
    std::cout << "++b = " << ++b << std::endl;
    std::cout << "b++ = " << b++ << std::endl;

    std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
    std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
    std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;

    std::cout << "a =" << a << std::endl;
    std::cout << "d =" << d << std::endl;

    std::cout << "(d < a) = " << (d < a) << std::endl;
    std::cout << "(d <= a) = " << (d <= a) << std::endl;
    std::cout << "(d > a) = " << (d > a) << std::endl;
    std::cout << "(d >= a) = " << (d >= a) << std::endl;
    std::cout << "(d == a) = " << (d == a) << std::endl;
    std::cout << "(d != a) = " << (d != a) << std::endl;

    std::cout << "======== EQUALITY TESTS ========\n";

	bigint a1(5);
bigint b1(7);
bigint c1(5);

// a < b
std::cout << "5 <= 7 | expected: true  | got: " << (a1 <= b1) << std::endl;
std::cout << "5 >= 7 | expected: false | got: " << (a1 >= b1) << std::endl;

// a == c
std::cout << "5 <= 5 | expected: true  | got: " << (a1 <= c1) << std::endl;
std::cout << "5 >= 5 | expected: true  | got: " << (a1 >= c1) << std::endl;

// b > a
std::cout << "7 <= 5 | expected: false | got: " << (b1 <= a1) << std::endl;
std::cout << "7 >= 5 | expected: true  | got: " << (b1 >= a1) << std::endl;

bigint z(0);
bigint n(123);

std::cout << "0 <= 0 | expected: true  | got: " << (z <= z) << std::endl;
std::cout << "0 >= 0 | expected: true  | got: " << (z >= z) << std::endl;

std::cout << "0 <= 123 | expected: true  | got: " << (z <= n) << std::endl;
std::cout << "0 >= 123 | expected: false | got: " << (z >= n) << std::endl;

std::cout << "123 <= 0 | expected: false | got: " << (n <= z) << std::endl;
std::cout << "123 >= 0 | expected: true  | got: " << (n >= z) << std::endl;


bigint l1(99999999);
bigint l2(100000000);

std::cout << "999... <= 1000... | expected: true  | got: " << (l1 <= l2) << std::endl;
std::cout << "999... >= 1000... | expected: false | got: " << (l1 >= l2) << std::endl;


bigint d1(1234);
bigint d2(1235);

std::cout << "1234 <= 1235 | expected: true  | got: " << (d1 <= d2) << std::endl;
std::cout << "1234 >= 1235 | expected: false | got: " << (d1 >= d2) << std::endl;
std::cout << "1235 <= 1234 | expected: false | got: " << (d2 <= d1) << std::endl;
std::cout << "1235 >= 1234 | expected: true  | got: " << (d2 >= d1) << std::endl;

bigint s(7777);

std::cout << "7777 <= 7777 | expected: true  | got: " << (s <= s) << std::endl;
std::cout << "7777 >= 7777 | expected: true  | got: " << (s >= s) << std::endl;

    a1 = bigint(12345);
    b1 = bigint(12345);
    std::cout << "12345 == 12345 | expected: true  | got: " << (a1 == b1) << std::endl;

    bigint a2(12345);
    bigint b2(12344);
    std::cout << "12345 == 12344 | expected: false | got: " << (a2 == b2) << std::endl;

    bigint a3(0);
    bigint b3(0);
    std::cout << "0 == 0         | expected: true  | got: " << (a3 == b3) << std::endl;

    std::cout << "\n======== COMPARISON TESTS ========\n";

    c1 = bigint(1000);
    bigint c2(999);
    std::cout << "1000 > 999     | expected: true  | got: " << (c1 > c2) << std::endl;

    bigint c3(9234);
    bigint c4(8234);
    std::cout << "9234 > 8234    | expected: true  | got: " << (c3 > c4) << std::endl;

    bigint c5(12345);
    bigint c6(12335);
    std::cout << "12345 > 12335  | expected: true  | got: " << (c5 > c6) << std::endl;

    bigint c7(5);
    bigint c8(10000);
    std::cout << "5 < 10000      | expected: true  | got: " << (c7 < c8) << std::endl;
	std::cout << "10000 > 5      | expected: true  | got: " << (c8 > c7) << std::endl;

    bigint c9(7777);
    bigint c10(7777);
    std::cout << "7777 < 7777    | expected: false | got: " << (c9 < c10) << std::endl;
	std::cout << "7777 > 7777    | expected: false | got: " << (c9 > c10) << std::endl;

    std::cout << "\n======== LEFT SHIFT TESTS ========\n";

    d1 = bigint(1377);
    d2 = d1 << 4;
    std::cout << "1377 << 4      | expected: 13770000 | got: " << d2 << std::endl;

    bigint d3(1377);
    bigint d4 = d3 << bigint(4);
    std::cout << "1377 << 4(big) | expected: 13770000 | got: " << d4 << std::endl;

    bigint d5(1234);
    bigint d6 = d5 << 0;
    std::cout << "1234 << 0      | expected: 1234     | got: " << d6 << std::endl;

    bigint d7(0);
    bigint d8 = d7 << 5;
    std::cout << "0 << 5         | expected: 0        | got: " << d8 << std::endl;

    std::cout << "\n======== RIGHT SHIFT TESTS ========\n";

    bigint e1(13770000);
    bigint e2 = e1 >> 4;
    std::cout << "13770000 >> 4  | expected: 1377 | got: " << e2 << std::endl;

    bigint e3(1234);
    bigint e4 = e3 >> 10;
    std::cout << "1234 >> 10     | expected: 0    | got: " << e4 << std::endl;

    bigint e5(1234);
    bigint e6 = e5 >> 4;
    std::cout << "1234 >> 4      | expected: 0    | got: " << e6 << std::endl;

    std::cout << "\n======== CHAIN SHIFT TEST ========\n";

    bigint f1(1377);
    f1 <<= 4;
    f1 >>= 2;
    std::cout << "1377 <<=4 >>=2 | expected: 137700 | got: " << f1 << std::endl;

    std::cout << "\n======== LARGE NUMBER TEST ========\n";

    bigint g1(99999999);
    bigint g2(100000000);
    std::cout << "999... < 1000... | expected: true  | got: " << (g1 < g2) << std::endl;

    std::cout << "\n======== SELF COMPARISON ========\n";

    bigint h1(55555);
    std::cout << "a == a | expected: true  | got: " << (h1 == h1) << std::endl;
    std::cout << "a < a  | expected: false | got: " << (h1 < h1) << std::endl;
    std::cout << "a > a  | expected: false | got: " << (h1 > h1) << std::endl;

    std::cout << "\n======== ALL TESTS FINISHED ========\n";

// bigint a(42);
// bigint b(21);
// bigint c(0);
// bigint d(1337);
// bigint e(1337);

// // Addition
// std::cout << "a + b = " << (a + b) << "\n";    
// // Output: a + b = 63

// std::cout << "a + c = " << (a + c) << "\n";    
// // Output: a + c = 42

// c += a;
// std::cout << "(c += a) = " << c << "\n";       
// // Output: (c += a) = 42

// // Increment
// std::cout << "b = " << b << "\n";              
// // Output: b = 21

// std::cout << "++b = " << ++b << "\n";          
// // Output: ++b = 22

// std::cout << "b++ = " << b++ << "\n";          
// // Output: b++ = 22

// std::cout << "b after b++ = " << b << "\n";    
// // Output: b after b++ = 23

// // Decimal digitshift (<< and >>)
// std::cout << "(b << 10) + 42 = " << (b << bigint(10)) + 42 << "\n"; 
// // b = 23 after b++, shift 10 digits → 23 * 10^10 + 42
// // Output: (b << 10) + 42 = 230000000042

// d <<= bigint(4);
// std::cout << "(d <<= 4) = " << d << ", d: " << d << "\n"; 
// // d = 1337 * 10^4 = 13370000
// // Output: (d <<= 4) = 13370000, d: 13370000

// d >>= bigint(2);
// std::cout << "(d >>= 2) = " << d << ", d: " << d << "\n"; 
// // d = 13370000 / 10^2 = 133700
// // Output: (d >>= 2) = 133700, d: 133700

// // Comparisons
// std::cout << "a = " << a << "\n";             
// // Output: a = 42

// std::cout << "d = " << d << "\n";             
// // Output: d = 133700

// std::cout << "(d < a) = " << (d < a) << "\n"; 
// // 133700 < 42 → false
// // Output: (d < a) = 0

// std::cout << "(d > a) = " << (d > a) << "\n"; 
// // 133700 > 42 → true
// // Output: (d > a) = 1

// std::cout << "(d == d) = " << (d == d) << "\n"; 
// // true
// // Output: (d == d) = 1

// std::cout << "(d != a) = " << (d != a) << "\n"; 
// // true
// // Output: (d != a) = 1

// std::cout << "(d <= a) = " << (d <= a) << "\n"; 
// // false
// // Output: (d <= a) = 0

// std::cout << "(d >= a) = " << (d >= a) << "\n"; 
// // true
// // Output: (d >= a) = 1

// // Another example
// bigint x1(12345678);
// bigint y(5);

// std::cout << "(x1 << y) = " << (x1 << y) << ", x1: " << x1 << ", y: " << y << "\n"; 
// // Decimal shift: 12345678 * 10^5 = 1234567800000
// // Output: (x1 << y) = 1234567800000, x1: 12345678, y: 5

// x1 >>= y;
// std::cout << "(x1 >>= y) = " << x1 << ", x1: " << x1 << ", y: " << y << "\n";        
// // x1 / 10^5 = 123
// // Output: (x1 >>= y) = 123, x1: 123, y: 5

// bigint f(12300000);
// bigint g(500000000); // within unsigned int
// std::cout << "(f >= g) = " << (f >= g) << ", f: " << f << ", g: " << g << "\n";      
// // 12300000 >= 500000000 → false
// // Output: (f >= g) = 0, f: 12300000, g: 500000000


	return (0);
}