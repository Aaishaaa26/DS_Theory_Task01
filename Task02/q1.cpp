#include <iostream>
using namespace std;
struct date{
	int day;
	int month;
	int year;
};

int main(){
	date dates[5];
	
	cout <<"Input 5 dates: "<< endl;
	for(int i = 0; i < 5; i++){
		cout<<"Enter day: ";
		cin >> dates[i].day;
		cout<< "Enter month: ";
		cin >> dates[i].month;
		cout<< "Enter Year: ";
		cin>> dates[i].year;
	}
	for(int i = 0; i <4 ; i++){
		int minIndex = i;
		for(int j = i+1; j < 5; j++){
			if(dates[j].year < dates[minIndex].year){
				minIndex = j;
			}

		}
		date temp = dates[i];
		dates[i] = dates[minIndex];
		dates[minIndex] =temp;
	}
	
	for(int i = 0; i < 5; i++){
		cout<< dates[i].day << "/"<< dates[i].month <<"/" <<dates[i].year << endl;
	}
}
