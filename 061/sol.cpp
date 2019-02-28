
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long exponentiation(long long, int);

int main(void)
{
  cout << "Enter base\n";
  long long x;
  int y;
  cin >> x;
  cout << "Enter power\n";
  cin >> y;
  long long z = exponentiation(x, y);
  cout << x << " raised to the " << y << "th power is "<< z << endl;
  cout << x << " raised to the " << y << "th power using pow is "<< pow(x, y) << endl;
  return 0;
}

long long exponentiation(long long x, int y)
{
  long long res = 1;
  while (y)
  {
    if (y&1)
    {
      res*=x;
    }
    x*=x;
    y>>=1;
  }
  return res;
}
