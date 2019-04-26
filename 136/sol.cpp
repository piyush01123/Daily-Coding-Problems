
#include <iostream>
#include <stack>
#define R 4
#define C 4


int maxAreaHistogram(int arr[], int n){
  std::stack<int> S;
  int i = 0, top, max_area = 0, area_with_top;
  while (i<n){
    if (S.empty() || arr[i]>=arr[S.top()]){
      S.push(i);
      i++;
    } else {
      top = S.top();
      S.pop();
      area_with_top=arr[top]*(S.empty()?i:i-S.top()-1);
      max_area = max_area<area_with_top?area_with_top:max_area;
    }
  }
  while(!S.empty()){
    top = S.top();
    S.pop();
    area_with_top=arr[top]*(S.empty()?i:i-S.top()-1);
    max_area = max_area<area_with_top?area_with_top:max_area;
  }
  return max_area;
}


void test_maxAreaHistogram(){
  int arr[] = {2, 1, 2, 3, 1};
  int n = sizeof(arr)/sizeof(arr[0]);
  std::cout << "Test 1:\n";
  std::cout << "Array:\n";
  for (int i=0; i<n; i++) std::cout<<arr[i]<<" "; std::cout<<std::endl;
  std::cout << "Max Histogram Area = " << maxAreaHistogram(arr, n) <<"\n\n\n";
  int arr2[] = {6, 2, 5, 4, 5, 1, 6};
  n = sizeof(arr2)/sizeof(arr2[0]);
  std::cout << "Test 2:\n";
  std::cout << "Array:\n";
  for (int i=0; i<n; i++) std::cout<<arr2[i]<<" "; std::cout<<std::endl;
  std::cout << "Max Histogram Area = " << maxAreaHistogram(arr2, n) <<"\n\n\n";
}


int largestReactangeArea(int A[][C]){
  int res = maxAreaHistogram(A[0], C);
  for (int i=1; i<R; i++){
    for (int j=0; j<C; j++){
      if (A[i][j]==1) A[i][j] += A[i-1][j];
    }
    int res_row = maxAreaHistogram(A[i], C);
    res = res_row>res?res_row:res;
  }
  return res;
}


void test(){
  std::cout<<"Test Case 1"<<std::endl;
  int A[][C] = {{1, 0, 0, 0},
                {1, 0, 1, 1},
                {1, 0, 1, 1},
                {0, 1, 0, 0}};
  std::cout << "largest rectangle area = " << largestReactangeArea(A) << std::endl;

  std::cout<<"Test Case 2"<<std::endl;
  int B[][C] = {{0, 1, 1, 0},
                {1, 1, 1, 1},
                {1, 1, 1, 1},
                {1, 1, 0, 0}};
  std::cout << "largest rectangle area = " << largestReactangeArea(B) << std::endl;
}

int main(){
  test_maxAreaHistogram();
  test();
  return 0;
}
