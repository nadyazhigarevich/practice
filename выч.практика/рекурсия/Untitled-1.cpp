#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int recursiveOperationCount = 0;

int arithmeticProgressionRecursive(int a, int d, int n) {
    recursiveOperationCount++;
    if (n == 1) {
        return a;
    }
    return arithmeticProgressionRecursive(a, d, n-1) + d;
}

int nonRecursiveOperationCount = 2;

int main() {
    int a = 1, d = 2, n = 10;
    
    auto start = high_resolution_clock::now();
    int recursiveResult = arithmeticProgressionRecursive(a, d, n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    
    cout << "Recursive solution: " << recursiveResult << " (took " << duration.count() << " nanoseconds, " << recursiveOperationCount << " operations)" << endl;
    
    start = high_resolution_clock::now();
    int nonRecursiveResult = a + (n-1)*d;
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    
    cout << "Non-recursive solution: " << nonRecursiveResult << " (took " << duration.count() << " nanoseconds, " << nonRecursiveOperationCount << " operations)" << endl;
    
    return 0;
}