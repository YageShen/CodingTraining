#include <iostream>
#include <math.h>

using namespace std;

double fun(double x, double a, double b, double c) {
    return - x * x * x / 6 / a + x * x / 2 / b - x * c / b;
}

int main() {
    int k;
    cin >> k;
    while(k-- > 0) {
        double a,b,c;
        // x^2 = 2a*y; x = b*y + c;
        cin >> a >> b >> c;
        // y^2 - 2a/b*y + 2ac/b = 0
        double A = 1 / (2 * a), B = -1 / b, C = c / b;
        double delta = B * B - 4 * A * C;
        if(delta <= 0) {
            cout << 0 << endl;
        }
        else {
            double x1 = (- B + sqrt(delta)) / (2 * A);
            double x2 = (- B - sqrt(delta)) / (2 * A);
            // double y1 = (x1 - c) / 2 / b;
            // double y2 = (x2 - c) / 2 / b;
            // 积分: -1/6a * x^3 + 1/2b * x^2 - c/b * x | (x2, x1)
            cout << fun(x1, a, b, c) - fun(x2, a, b, c) << endl;

        }
    }
    return 0;
}
