
#include <iostream>
#include <vector>

int minRangeRequired(std::vector<int> listeners, std::vector<int> towers){
  int i=0, j=0, d1, d2;
  while (i<listeners.size()){
    d1 = towers[j]-listeners[i];
    d2 = towers[j+1]-listeners[i];
    if (d2>d1) j++;
    i++;
  }
}

int main(){
  std::vector<int> listeners {1, 5, 11, 20};
  std::vector<int> towers {4, 8, 15};
  int range_min = minRangeRequired(listeners, towers);
  std::cout << "Min Required Range = " << range_min << '\n';
  return 0;
}
