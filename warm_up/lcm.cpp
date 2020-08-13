#include <iostream>

/*
uint64_t lcm_naive(int a, int b) {
  for (long l = 1; l <= (uint64_t) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (uint64_t) a * b;
}
*/
uint64_t gcd_fast(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else if (a == 0)
    {
        return b;
    }

    int a_prime = a % b;
    return gcd_fast(b, a_prime);
}

uint64_t lcm_gcd(uint64_t a, uint64_t b)
{
    uint64_t gcd = gcd_fast(a, b);
    return (a * b) / gcd;
}

int main() {
  uint64_t a, b;
  std::cin >> a >> b;
  std::cout << lcm_gcd(a, b) << std::endl;
  return 0;
}
