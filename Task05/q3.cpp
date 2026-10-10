#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim){
	if(dim < 0) return 0;
	
	int sum = 0;
	for(int i = 0; i< sizes[dim]; i++){
		sum += arr[dim][i];
	}
	return sum + recursiveArraySum(arr, sizes, dim-1);
}

int main(){
	int arr1[] = {1,2,3}, arr2 []= {4,5,6,7}, arr3 []={8,9}; 
	
	int* arr[] = {arr1,arr2,arr3};
	int dim = 2;
	int sizes[] = {3,4,2};
	cout<< "Sum: "<< recursiveArraySum(arr,sizes,dim);
	
}
