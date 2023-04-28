#include <iostream>
#include <iomanip>  // For setprecision

using namespace std;

// Note that the Simpson's rule is an approximation
// We can find the area using Simpson's formula which is
// Area ≈ △x/3 [f(x₀) + 4f(x₁) + 2f(x₂) + 4f(x₃) + ... + 2f(xₙ₋₂) + 4f(xₙ₋₁) + f (xₙ)]
// Where n is even and △x = b-a / n
// a and b are the lower limit and the upper limit respectively

void findPoints();
void findArea();

const int n = 8;  // n is the amount of subspaces you have in your data
double x[n + 1] = {0.0, 11.4, 13.2, 10.8, 15.1, 19.8, 20.1, 12.9, 0.0};
double points[n + 1];

double a = 0;      // Lower limit
double b = 80;     // Upper limit
double deltax = (b - a) / n;

int main() {
    findPoints();
    findArea();
}

void findPoints() {
    for (int i = 1; i < n; ++i) {
        points[i] = x[i] * 4;
        points[i + 1] = x[i + 1] * 2;
        i++;
    }
}

void findArea() {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += points[i];
    }
    total *= deltax / 3;
    cout << "The area is: " << setprecision(10) << total << " units squared.\n";
}
