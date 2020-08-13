#include <iostream>
#include <cassert>
#include <vector>

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    // write your code here
    if (n <= 1)
        return n;

    int F, F1, F2;
    F1 = 0; // (i-1)th number
    F2 = 1; // (i-2)th number
    
    for (int i = 2; i <=n; ++i)
    {
        F = F1 + F2;
        F1 = F2;
        F2 = F;
    }
    //std::cout << "This is F: " << F << std::endl;

    return F;
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;

    //std::cout << fibonacci_naive(n) << '\n';
    //test_solution();
    /*
    for (int i = 0; i <=20; ++i)
    {
        std::cout << "i=" << i << std::endl;
        std::cout << fibonacci_fast(i) << '\n';
    }
    */
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
