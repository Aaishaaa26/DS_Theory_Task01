#include <iostream>
using namespace std;
//using 1.7 shrink factotr cz it'll take less passes

int main(){
	int prices[7] = {20, 16, 8, 79, 3, 6, 12};
	float shrink = 1.7;
	int gap = 7;
	bool swap = true;
	
	while(gap > 1 || swap){
		gap /= shrink;
		if(gap<1) gap = 1;
		swap = false;
		
		for(int i = 0; i + gap < 7; i++){
			if(prices[i] > prices[i+gap]){
				int temp = prices[i];
				prices[i] = prices[i+gap];
				prices[i+gap] = temp;
				
				swap = true;
			}
		}
	}
	
	for(int i = 0; i < 7; i++){
		cout << prices[i] << endl;
	}
	
}
