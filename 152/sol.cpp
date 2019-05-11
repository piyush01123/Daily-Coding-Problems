
#include <ctime>
#include <cstdlib>
#include <iostream>

class randomGenerator{
private:
  // we cant have two flexible size array for a class because compiler needs to know how much space to create for the class so we'll have to use pointers
  int *nums;
  double *cumProbs;
  int size;
public:
  randomGenerator(int numbers[], double probabilities[], int sz){
    nums = numbers;
    size = sz;
    cumProbs = new double[size];
    double p = 0;
    for (int i=0; i<sz; i++){
      p += probabilities[i];
      cumProbs[i] = p;
    }
  }

  int *generate(int n){
    std::srand(std::time(nullptr)); //seed by curr. time

    int *rand_nums = new  int[n];
    for (int i=0; i<n; i++){
      double rand_dbl = double(rand())/double(RAND_MAX);
      int j=0;
      while (rand_dbl>cumProbs[j]) j++;
      rand_nums[i] = nums[j];
    }
    return rand_nums;
  }
};

void test(){
  int N[] = {1, 2, 3, 4};
  double P[] = {0.1, 0.5, 0.2, 0.2};
  int size = sizeof(N)/sizeof(N[0]);
  randomGenerator rg = randomGenerator(N, P, size);
  int T = 100000;
  int *rand_nums = rg.generate(T);
  // for (int i=0; i<10000; i++) std::cout<<rand_nums[i]<<'\n';

  int freq[size];
  for (int i=0; i<size; i++) freq[i] = 0;
  for (int i=0; i<T; i++) freq[rand_nums[i]-1]++; //by looking at N
  std::cout<<"Frequency Table"<<'\n';
  for (int i=0; i<size; i++) std::cout<<N[i]<<' '<<double(freq[i])/double(T)<<'\n';

}

int main(){
  test();

  // int x = 0;
  // for (int i=0;  i<1000; i++){
  //   std::srand(std::time(nullptr));
  //   if (rand()==x) std::srand(std::time(nullptr)+1000);
  //   int x = rand();
  //   std::cout<<x<<'\n';
  // }
  // for(int i = 0; i<1000; i++)
  //       std::cout<<rand()<<'\n';
    return 0;
}
