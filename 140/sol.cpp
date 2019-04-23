
#include <iostream>
#include <unordered_map>

int *occurOnce(int *arr){
  // linear time linear space
  int *A = new int[2];
  std::unordered_map<int, int> H;
  for (int i=0; i<sizeof(arr); i++){
    H[arr[i]]++;
  }
  int k = 0;
  for (int i=0; i<sizeof(arr); i++){
    if (H[arr[i]]==1){
      A[k] = arr[i];
      k++;
    }
  }
  return A;


void test(){
  int arr[] = {2, 4, 6, 8, 10, 2, 6, 10};
  int *ans = occurOnce(arr);
  std::cout << ans[0] << " " << ans[1] << std::endl;
  int arr2[] =  {2, 7, 8, 3, 5, 3, 7, 8};
  int *ans2 = occurOnce(arr2);
  std::cout << ans2[0] << " " << ans2[1] << std::endl;
}

int main(){
  test();
  return 0;
}
