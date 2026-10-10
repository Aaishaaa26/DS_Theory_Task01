#include <iostream>
using namespace std;

const int N = 5;
int maze[N][N] = {
	{1,0,1,0,1},
	{1,1,1,1,1},
	{0,1,0,1,1},
	{1,0,0,1,1},
	{1,1,1,0,1}
};

int sol[N][N] = {0};

bool isSafe(int row, int col){
	if(row>=0 && row< N && col>=0 && col< N && maze[row][col]==1) return true;
	else return false;
}

bool solveMaze(int row, int col){
	if(row == N-1 && col == N-1){
		sol[row][col] = 1;
		return true;
	}
	if(isSafe(row, col)){
		sol[row][col] = 1;
	
		if (solveMaze(row +1, col)) return true;
		if(solveMaze(row, col+1)) return true;	//agar ye condition ab oper wali line se pehle likhe, tou ouput last col prefernce per chalay ga. abhi last row prefernce per chal rha
		sol[row][col] = 0;
	}
	return false;
}

void display(){
	for (int i = 0; i <N; i++){
		for(int j = 0; j < N; j++) cout<< sol[i][j]<< " ";
		cout << endl;
	}
}

int main(){
	if(solveMaze(0,0)) display();
	else cout<<"No path";
}
