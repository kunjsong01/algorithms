#include <iostream>

uint64_t fibonacci_fast(int n) {
    // write your code here
    if (n <= 1)
        return n;

    uint64_t F, F1, F2;
    F1 = 0; // (i-1)th number
    F2 = 1; // (i-2)th number
    
    for (int i = 2; i <=n; ++i)
    {
        F = (F1 + F2) % 10;
        F1 = F2 % 10;
        F2 = F % 10;
    }

    return F;
}

int main() {
    int n;
    std::cin >> n;
    uint64_t c = fibonacci_fast(n);
    std::cout << c << '\n';
}
