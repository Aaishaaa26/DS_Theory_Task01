#include <iostream>
using namespace std;

struct emp{
	string designation;
	int priority;
};
int main(){
	
	emp employees[8] = {{"EMP", 1}, {"CFO", 4},{"MGR", 2},{"EMP", 1},{"VP", 3},{"CTO", 5},{"MGR", 2},{"CEO", 6}};
	for(int i = 0; i < 8; i++){
		emp key = employees[i];
		int j = i -1;
		while(j >=0 && employees[j].priority < key.priority){
			employees[j+1] = employees[j];
			j--;
		}
		employees[j+1] = key;
	}
	
	for(int i = 0; i < 8; i++){
		cout << employees[i].designation << endl;
	}
	
}
