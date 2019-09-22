#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int N = 1000000;
    int count = 1;
    std::vector<int> primes;
    primes.push_back(2);
    std::cout << "2 is prime\n";
    for (int i = 3; i <= N; i++)
    {
      for (int p: primes)
      {
        if (p*p>i)
        {
          // std::cout << i << " is prime" << '\n';
          primes.push_back(i);
          count++;
          break;
        }
        if (i%p==0)
        {
          // std::cout << i << " has prime factor" << p << '\n';
          break;
        }
      }
    }
    std::cout << "Number of primes less than or equal to " << N << " is " << count << '\n';
    return 0;
}
