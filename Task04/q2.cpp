#include <iostream>
using namespace std;

int max(int arr[], int n){
	if(n == 1) return arr[0];
	int maximum = max(arr, n-1);
	
	if(arr[n-1] > maximum) return arr[n-1];
	else return maximum;//returns max call function mei takay compare krke accordinly return karay
}
int main(){
	int arr[5] = {1,2,3,4,5};
	int n = sizeof(arr) /sizeof(arr[0]);
	cout<<"Max: "<< max(arr,n);
}
