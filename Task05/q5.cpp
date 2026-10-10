#include <iostream>
using namespace std;

const int N = 16;

int grid[N][N] = {0};

bool isSafe(int row, int col){
	for(int i = 0; i < row; i++){
		if (grid[i][col] == 1) return false; //checking col
	}
	for(int i = row -1, j = col -1; i>= 0 && j>=0; i--, j--){
		if(grid[i][j] == 1) return false; //negative sloped diagnol
	}
	for(int i = row-1, j = col+1; i>=0 && j<N; i--, j++){
		if(grid[i][j] == 1) return false;  //positive sloped diagnol
	}
	return true;
}

bool solveFlags(int row){
	if(row == N) return true;
	for(int col = 0; col<N; col++){
		if(isSafe(row, col)){
			grid[row][col] = 1;
			
			if(solveFlags(row+1)) return true;
			
			grid[row][col] = 0;
		}
	}
	return false;
}

void display(){
	int max = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j< N; j++){
				if(grid[i][j] == 1){
					cout <<" F ";
					max++;
				}
				else cout<<" . ";
		}
		cout<< endl;
	}
	cout<<"\n\nMax Flags = "<< max;
}

int main(){
	if(solveFlags(0)) display();
	else cout <<"no sol";
}
