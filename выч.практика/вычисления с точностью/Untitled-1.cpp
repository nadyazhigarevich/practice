#include <iostream>
#include <cmath>

using namespace std;

double corr_coef(int n, int x[], int y[]) {
    int sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0, sum_y2 = 0;
    
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
        sum_y2 += y[i] * y[i];
    }
    
    double mean_x = static_cast<double>(sum_x) / n;
    double mean_y = static_cast<double>(sum_y) / n;
    
    double numerator = n * sum_xy - sum_x * sum_y;
    double denominator = sqrt((n * sum_x2 - sum_x * sum_x) * (n * sum_y2 - sum_y * sum_y));
    
    return numerator / denominator;
}

int main() {
    int n;
    cout << "Enter the size of the arrays: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Error: Array size must be positive." << endl;
        return 1;
    }
    
    int* x = new int[n];
    int* y = new int[n];
    
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> x[i])) {
            cout << "Error: Array elements must be integers." << endl;
            delete[] x;
            delete[] y;
            return 1;
        }
    }
    
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> y[i])) {
            cout << "Error: Array elements must be integers." << endl;
            delete[] x;
            delete[] y;
            return 1;
        }
    }
    
    double r = corr_coef(n, x, y);
    cout << "Correlation coefficient: " << r << endl;
    
    delete[] x;
    delete[] y;
    
    return 0;
}