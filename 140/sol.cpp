
#include <iostream>
#include <unordered_map>

// int *occurOnce(int *arr){
//   // linear time linear space
//   int *A = new int[2];
//   std::unordered_map<int, int> H;
//   for (int i=0; i<sizeof(arr); i++){
//     H[arr[i]]++;
//   }
//   int k = 0;
//   for (int i=0; i<sizeof(arr); i++){
//     if (H[arr[i]]==1){
//       A[k] = arr[i];
//       k++;
//     }
//   }
//   return A;


int *occurOnce(int *arr){
  // linear time constant space using bit ops
  int xored = 0;
  for (int i=0; i<sizeof(arr); i++){
    xored = xored^arr[i];
  }
  // now the question boils down to this - xored is the xor of which 2 items
  // in the array
  int right_most_set_bit = xored&(~(xored-1));
  // this is the first bit from right with different values (one has 0 other has 1)
  // then we can form two groups based on whether or not their right_most_set_bit is 1 or 0. each group's xor are the answer
  int x = 0;
  int y = 0;
  for (int i=0; i<sizeof(arr); i++){
    if ((right_most_set_bit&arr[i])==0){
      x^=arr[i];
    }else{
      y^=arr[i];
    }
  }
  int *A = new int[2];
  A[0] = x;
  A[1] = y;
  return A;
}

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
