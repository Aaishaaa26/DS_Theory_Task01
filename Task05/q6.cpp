#include <iostream>
using namespace std;

const int N = 6;

char grid[N][N] = {
    {'D','S','S','F','D','F'},
    {'S','S','S','F','S','D'},
    {'S','D','S','S','S','F'},
    {'F','S','F','S','S','F'},
    {'S','S','S','D','S','F'},
    {'S','F','S','F','S','H'}
};

int sol[N][N] = {0}; 
int best[N][N] = {0};   
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int minWind = N*N + 1;
int bestLen = N*N + 1;

bool isSafe(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < N && grid[r][c] != 'F' && sol[r][c] == 0;
}

void path(int r, int c, int wind, int len){
    if(!isSafe(r, c)) return;

    if(grid[r][c] == 'D' && (r != 0 || c != 0)) wind++;
    if(wind > minWind) return;                
    sol[r][c] = 1;                          
    len++;

    if(grid[r][c] == 'H'){
        if(wind < minWind || (wind == minWind && len < bestLen)){
            minWind = wind;
            bestLen = len;
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    best[i][j] = sol[i][j];   
        }
    } else {
        for(int k = 0; k < 4; k++)
            path(r + dr[k], c + dc[k], wind, len);
    }
    sol[r][c] = 0;                           
}

int main(){
    path(0, 0, 0, 0);

    if(bestLen > N*N){
        cout << "No path found" << endl;
        return 0;
    }
    cout<<"best path:\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << best[i][j] << " ";
        cout << endl;
    }
    cout << "\nNo fly Zone: " << endl;
	for(int i = 0; i < N; i++){
	    for(int j = 0; j < N; j++)
	        cout << (grid[i][j] == 'F') << " ";
	    cout << endl;
	}
    cout << "\nHigh wind zones : " << minWind << endl;
      cout << "\nPath length: " << bestLen;
}
