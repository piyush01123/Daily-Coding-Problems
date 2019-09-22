#include <cstddef>

class Summer{
private:
  size_t sz = 0;
  int *arr = nullptr;
public:
  Summer(){}
  Summer(const size_t _sz, int *_arr): sz(_sz), arr(_arr){}
  int sum(){
    int total = 0;
    for (int i=0; i<sz; i++) total+=*(arr+i);
    return total;
  }
};

extern "C" {
  int sum(const size_t _sz, int *_arr){
    Summer S(_sz, _arr);
    return S.sum();
  }
}
