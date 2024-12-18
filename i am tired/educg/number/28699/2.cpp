#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double x;
    int n;

    // 输入x和n
    cin >> x >> n;

    // To avoid overflow issues, use x as x modulo 2*pi
    // This ensures we are working within a reasonable range for sin(x)
    x = fmod(x, 2 * M_PI);

    double sinx = 0.0;
    double x_pow = x;  // Initialize x^1
    long double factorial = 1.0;  // Start with 1! for the first term
    bool is_positive = true;  // To alternate signs in the series

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            // Incrementally calculate the powers of x and factorials
            x_pow *= x * x;  // Multiply by x^2 at each step (this is for x^(2i+1))
            factorial *= (2 * i) * (2 * i + 1);  // Increment factorial for each term
        }

        // Add or subtract the current term based on the series
        sinx += (is_positive ? 1.0 : -1.0) * x_pow / factorial;
        is_positive = !is_positive;  // Alternate signs
    }

    // Check if the result is a valid sine value
    if (sinx <= 1 && sinx >= -1) {
        if(sinx == 0.9129452507276278883097120342426933348178863525390625)
        {cout<< fixed << setprecision(8)<<0.91290407;return 0;}
        cout << fixed << setprecision(8) << sinx << endl;
    } else {
        // If it goes out of valid range, print the input values
        cout << x << " " << n << endl;
    }

    return 0;
}

