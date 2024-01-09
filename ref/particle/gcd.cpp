#include <iostream>
using namespace std;

#define LL long long

// Greatest Common Divisor using the Euclidean Algorithm
// 1. Checks base Cases
// 2. Uses Recurrance if there is a difference between the numbers, and neither one of the numbers is 0
// It works on the principle that the GCD of two numbers remains the same if the greater number is replaced by the difference between the two numbers.
LL gcd(LL a, LL b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    if (a == b)
        return a;
    
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

// Other similar solution
// Depends on how do you want to format your code
LL gcd(LL a, LL b) {
  return (b == 0) ? a : gcd(b, a%b);
}
