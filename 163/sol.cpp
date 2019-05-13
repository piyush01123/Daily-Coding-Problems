
#include <stdio.h>
#include <list>


int eval_RPN_seq(std::list<int> v){
  int num = v.front();
  char sign = v.back();
  v.pop_front();
  v.pop_back();
  if (v.size()==1){
    int num2 = v.front();
    switch (sign) {
      case  '+': return num+num2;
      case  '-': return num-num2;
      case  '*': return num*num2;
      case  '/': return num/num2;
    }
  }
  switch (sign) {
    case '+': return num+eval_RPN_seq(v);
    case '-': return num-eval_RPN_seq(v);
    case '*': return num*eval_RPN_seq(v);
    case '/': return num/eval_RPN_seq(v);
  }
  return -1;
}

int evaluateRPN(int arr[], int n){
  /*
  Evaluates arr by RPN. Any member of an array cant be 42, 43, 45, 47 because these are reserved for the signs +,-,*,/
  */
  int i = 0;
  std::list<int> v;
  while(arr[i]!=42 && arr[i]!=43 && arr[i]!=45 && arr[i]!=47){
    v.push_back(arr[i]);
    i++;
  }
  while(arr[i]==42 || arr[i]==43 || arr[i]==45 || arr[i]==47){
    v.push_back(arr[i]);
    i++;
  }
  int res = eval_RPN_seq(v);
  v.clear();

  while (i<n){
    v.push_back(res);
    while(i<n && arr[i]!=42 && arr[i]!=43 && arr[i]!=45 && arr[i]!=47){
      v.push_back(arr[i]);
      i++;
    }
    while(i<n && (arr[i]==42 || arr[i]==43 || arr[i]==45 || arr[i]==4)){
      v.push_back(arr[i]);
      i++;
    }
    res = eval_RPN_seq(v);
    v.clear();
  }
  return res;
}


void test(){
  //this is possible because essentially ints and chars are stored the same way
  int arr1[] = {5, 3, '+'};
  int arr2[] = {15, 7, 2, '-', '/'};
  // these 2 were essentially tests of eval_RPN_seq fn
  int arr3[] = {15, 3, '/', 3, '+'};
  int arr4[] = {15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-'};
  // printf("%c\n", arr1[2]);

  int n1 = sizeof(arr1)/sizeof(int);
  int n2 = sizeof(arr2)/sizeof(int);
  int n3 = sizeof(arr3)/sizeof(int);
  int n4 = sizeof(arr4)/sizeof(int);
  printf("%d\n", evaluateRPN(arr1, n1));
  printf("%d\n", evaluateRPN(arr2, n2));
  printf("%d\n", evaluateRPN(arr3, n3));
  printf("%d\n", evaluateRPN(arr4, n4));
}


int main(){
  // printf("+ %d\t- %d\t* %d\t/ %d\n", '+', '-', '*', '/');
  test();
  return 0;
}
