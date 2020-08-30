
// C++ program to print all primes smaller than or equal to n using Sieve of Eratosthenes 

#include <iostream>

void sieveOfEratosthenes(int n){
	bool *primes = new bool[n+1];
	for (int i=0;i<=n;i++){ 
		primes[i]=true; 
	}
	
	for (int p=2; p*p <= n; p++){
		if (primes[p]){
			for (int i=p*p; i<=n; i+=p){
				primes[i]=false;
			}
		}
	}
	std::cout << "List of primes less than " << n << ":\n";
	for (int i=2; i<=n; i++){
		if (primes[i]) std::cout << i <<  " ";
	}
	std::cout << '\n';
	return;
	
}

int main(){
	sieveOfEratosthenes(50);
	return 0;
}
