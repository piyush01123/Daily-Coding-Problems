#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


bool isPalindromable(std::string S, int l, int r){
    if (r==l){
      // std::cout << "palindrome " << l << " " << r << std::endl;
      return true;
    }
    std::unordered_map<char, int> H;
    std::string S_sub = S.substr(l-1, r-l+1);
    // std::cout << S_sub << std::endl;
    for (char c: S_sub) H[c]++;
    int ctr = 0;
    for (auto item: H){
      if (item.second%2==1){
        ctr++;
        if (ctr>=2){
          // std::cout << "not palindrome " << S_sub << std::endl;
          return false;
        }
      }
    }
    // std::cout << "palindrome " << S_sub << std::endl;
    return true;
}


std::unordered_map<char, std::vector<int>> prefixFrequencies(std::string S){
  std::unordered_map<char, std::vector<int>> H;
  for (char c: S){
    H[c];
  }
  int pos = 0;
  for (char c: S){
    for (auto item: H){
      char f = item.first;
      if (pos==0){
        H[f].push_back(f==c?1:0);
      } else {
        int last = item.second.back();
        H[f].push_back(f==c?last+1:last);
      }
    }
    pos++;
  }
  // for (auto item: H){
  //   std::cout<<item.first<<"-->";
  //   for (int i: item.second) std::cout<<i<<" ";
  //   std::cout<<std::endl;
  // }
  return H;
}


bool isPalindromableFaster(const std::unordered_map<char, std::vector<int>> &H, int l, int r){
  if (l==r) return true;
  int ctr = 0;
  for (auto item: H){
    // char c = item.first;
    int diff;
    if (l==1) diff = item.second[r-1];
    else diff = item.second[r-1]-item.second[l-2];
    if (diff%2==1){
      ctr++;
      if (ctr>=2) return false;
    }
  }
  return true;
}


int main(){
    std::unordered_map<char, std::vector<int>> H = prefixFrequencies("dekhodekhodekhoaayasher");
    int T, N, Q, l, r;
    std::string S;
    std::cin >> T;
    for (int t=1; t<=T; t++){
        std::cin >> N;
        std::cin >> Q;
        std::cin >> S;
        std::unordered_map<char, std::vector<int>> H = prefixFrequencies(S);
        int ctr = 0;
        for (int q=0; q<Q; q++){
            std::cin >> l;
            std::cin >> r;
            if (N==1 || l==r || isPalindromableFaster(H, l, r)) ctr++;
        }
      std::cout << "Case #" << t << ": " << ctr << std::endl;
    }
    std::string S = "Dekhodekhodekhoaayasher";
    std::cout << S[0]-'A'<<std::endl;
    return 0;
}


// #include<bits/stdc++.h>
// #define N 100005
// using namespace std;
// int n,q;
// string s;
// int c[N];
// int main(){
//   //  freopen("test.inp","r",stdin);
//     ios::sync_with_stdio(false);
//     int t;
//     cin>>t;
//     int tc = 1;
//     while(tc <= t){
//         int ans = 0;
//         cin>>n>>q;
//         cin>>s;
//         for(int i = 1 ; i <= n ; i++) c[i] = (c[i - 1]^(1<<(s[i - 1] - 'A')));
//         for(int i = 1 ; i <= q ; i++){
//             int l,r;
//             cin>>l>>r;
//             ans += (__builtin_popcount(c[r]^c[l - 1]) <= 1);
//         }
//         cout<<"Case #"<<tc<<": "<<ans<<'\n';
//         tc++;
//     }
// }
