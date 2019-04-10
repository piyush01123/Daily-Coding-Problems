
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include  <unordered_set>
#include <algorithm>
#include <iterator>

using namespace std;

int firstPrimeFactor(int num, int N){
  vector<int> primes {2};
  for (int i=3; i<=N; i++){
    for (int p: primes){
      if (p*p>i){
        if (num%i==0) return i;
        primes.push_back(i);
        break;
      }
      if (i%p==0) break;
    }
  }
}

void printVector(vector<int> A){
  ostream_iterator<int> outit (cout, " ");
  copy(A.begin(), A.end(), outit);
  cout << endl;
}

string solve(vector<int> A, int N, int L){
  int a = firstPrimeFactor(A[0], N);
  int b = A[0]/a;
  int f;
  if (A[1]%a==0) f = a;
  else f = b;
  vector<int> nums {A[0]/f, f};
  for (int i=1; i<L; i++){
    f = A[i]/f;
    nums.push_back(f);
  }
  unordered_set<int> s(nums.begin(), nums.end());
  vector<int> v(s.begin(), s.end());
  sort(v.begin(), v.end());
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  vector<char> letters(alphabet.begin(), alphabet.end());
  unordered_map<int, char> dic;
  for (int i=0; i<v.size(); i++){
    dic[v[i]] = letters[i];
  }
  vector<char> real_letters;
  for (int num: nums) real_letters.push_back(dic[num]);
  string ans(real_letters.begin(), real_letters.end());
  return ans;
}

int main(){
  int T, N, L;
  cin >> T;
  for (int t=1; t<=T; t++){
    vector<int> A;
    cin >> N;
    cin >> L;
    int a;
    for (int i=0; i<L; i++){
      cin >> a;
      A.push_back(a);
    }
    string sol = solve(A, N, L);
    cout << "Case #" << t << ": " << sol << endl;
  }
}
