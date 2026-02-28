// 🧩 Problem: Factor and Digit Transformation

// You are given a positive integer N.

// Perform the following operations:

// 🔹 Step 1: Find Second Smallest Factor

// Find the second smallest factor of N.

// Note:

// 1 is always the smallest factor.

// So second smallest factor = smallest divisor greater than 1.

// Example:

// N = 120
// Factors = 1, 2, 3, 4, 5, ...
// Second smallest factor = 2

// ⚠️ But in your example output factor = 3
// That means the problem likely considers:

// Second smallest distinct prime factor

// For 120:

// Prime factors: 2, 3, 5
// Second smallest prime factor = 3

// We’ll follow this logic since example matches 3.

// 🔹 Step 2: Add Factor to Even Digits

// For every even digit in N,

// Add the factor to that digit.

// Odd digits remain unchanged.

// Example:

// N = 120
// Factor = 3
// Digits: 1 2 0

// 2 is even → 2 + 3 = 5
// 0 is even → 0 + 3 = 3

// New number = 1 5 3 → 153
// 🔹 Step 3: Find Largest Digit (From Right)

// From the transformed number,

// Find the largest digit.

// Print its position counting from the unit place (1-based index).

// Example:

// 153

// From right:
// 3 → position 1
// 5 → position 2
// 1 → position 3

// Largest digit = 5
// Position = 2
// 📥 Input Format

// Single integer N

// 📤 Output Format

// Print:

// factor transformed_number position
// 📝 Sample Input
// 120
// 📝 Sample Output
// 3 153 2

#include <iostream>
#include <string>
using namespace std;

// Function to find second smallest factor (normal factor)
long long secondSmallestFactor(long long n) {
    for(long long i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return i;   // smallest divisor greater than 1
        }
    }
    return n;  // if n is prime
}

int main() {
    long long N;
    cin >> N;

    // Step 1: Get second smallest factor
    long long factor = secondSmallestFactor(N);

    // Step 2: Add factor to even digits
    string s = to_string(N);

    for(int i = 0; i < s.length(); i++) {
        int digit = s[i] - '0';

        if(digit % 2 == 0) {
            digit += factor;
        }

        s[i] = digit + '0';
    }

    // Step 3: Find largest digit from right
    int maxDigit = -1;
    int position = 0;
    int len = s.length();

    for(int i = len - 1; i >= 0; i--) {
        int digit = s[i] - '0';

        if(digit > maxDigit) {
            maxDigit = digit;
            position = len - i;  // 1-based from right
        }
    }

    cout << factor << " " << s << " " << position;

    return 0;
}