#include <iostream>

void printarray(int *arr, int n){
	for (int i=0; i<n; i++) std::cout << arr[i] << ' ';
	std::cout << '\n';
}

void swap(int *a, int *b){
int p = *a;
*a = *b;
*b = p;
}

int partition(int *arr, int left, int right){
	int pivot = arr[right];
	int i = left;
	for (int j=left; j<=right-1; j++){
		if (arr[j]<=pivot){
			swap(&arr[j], &arr[i]);
			i++;
		}
	}
	swap(&arr[right], &arr[i]);
	printarray(arr, 6);
	return i;
}

void quickSort(int *arr, int left, int right){
	// base case
	if (right-left<=0) return;
	// put last element in its right place
	int pos = partition(arr, left, right);
	// recurse for left and right sub arrays
	quickSort(arr, left, pos-1);
	quickSort(arr, pos+1, right);
}

int main(int argc, char **argv){
	int arr[] = {5, 6, 4, 1, 3, 2};
	printarray(arr, 6);
	quickSort(arr, 0, 5);
	printarray(arr, 6);
}
