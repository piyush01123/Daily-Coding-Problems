
#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>     /* atoi */


template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> v){
  if (v.size()==0){
    out<<"[]\n";
    return out;
  }

  out<<'[';
  for (int i=0; i<v.size()-1; i++) out<<v[i]<<", ";
  out<<v[v.size()-1]<<']'<<'\n';
  return out;
}


bool isValid(std::string ip){
  char *ip_ = new char[ip.size()+1]; //1 for the backslash 0
  strcpy(ip_, ip.c_str());
  // std::cout<<ip_<<'\n';
  char *token = strtok(ip_, ".");
  std::vector<char *> ipParts;
  while (token!=NULL){
    // std::cout<<token<<'\n';
    ipParts.push_back(token);
    token = strtok(NULL, ".");
  }
  // std::cout<<ipParts;
  for (std::string part: ipParts){
    // std::cout<<part.length()<<'\n';
    char *part_ = new char[part.size()+1];
    strcpy(part_, part.c_str());
    int n = atoi(part_);
    if (part.length()>3 || n>255) return false;
    if (part.length()>1 && part[0]=='0') return false;
  }
  return true;
}


std::vector<std::string> convertToIPs(std::string digitString){
  int len = digitString.length();
  if (len<4 || len>12) return {};
  std::vector<std::string> ips, validIPs;
  for (int i=1; i<len-2; i++){
    for (int j=i+1; j<len-1; j++){
      for (int k=j+1; k<len; k++){
        std::string snew = digitString;
        snew = snew.substr(0, k) + "." + snew.substr(k, len-k);
        snew = snew.substr(0, j) + "." + snew.substr(j, len-j+1);
        snew = snew.substr(0, i) + "." + snew.substr(i, len-i+2);
        if (isValid(snew)){
          // std::cout<<snew<<'\n';
          validIPs.push_back(snew);
        }
      }
    }
  }
  return validIPs;
}


void test(){
  std::string S = "2542540123";
  std::vector<std::string> vIPs = convertToIPs(S);
  std::cout<<"Valid IPs are "<<vIPs;
}


int main(){
  test();
  return 0;
}
