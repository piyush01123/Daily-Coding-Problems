
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> convert(int);

int main(void)
{
  int num;
  cout << "Enter a number\n";
  cin >> num;
  cout << "Binary for " << num << " is ";
  vector <int> bin = convert(num);
  reverse(bin.begin(), bin.end());
  for (int b: bin)
  {
    cout<<b;
  }
  cout << endl;
  return 0;
}

vector <int> convert(int num)
{
  vector <int> res;
  while (num)
  {
    if (num&1)
      res.push_back(1);
    else
      res.push_back(0);
    num >>= 1;

  }
  return res;
}
