#include <iostream>
using namespace std;

const int N = 5;

char forest[N][N] = {
    {'S','A','A','T','A'},
    {'A','T','A','A','G'},
    {'T','A','T','A','F'},
    {'A','A','A','T','G'},
    {'A','T','G','T','G'}
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool explore(int vis[N][N], int r, int c, char item, int target, int &found){
    if(r < 0 || r >= N || c < 0 || c >= N) return false;  
    if(forest[r][c] == 'T' || vis[r][c]) return false;  
    vis[r][c] = 1;
    
    if(forest[r][c] == item) found++;
    if(found == target) return true;

    for(int k = 0; k < 4; k++)
        if(explore(vis, r + dr[k], c + dc[k], item, target, found)) return true;

    return false;   
}

void printMatrix(int m[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << m[i][j] << " ";
        cout << endl;
    }
}

int main(){
    int squirrel[N][N] = {0}, fox[N][N] = {0};
    int acorns = 0, gems = 0;

    bool sCollect = explore(squirrel, 0, 0, 'A', 7, acorns);
    bool fCollect = explore(fox, 2, 4, 'G', 4, gems);

    cout << "Squirrel path (acorns: " << acorns << "/7):" << endl;
    printMatrix(squirrel);
    if(!sCollect ) cout << "Squirrel could not collect all acorns" << endl;

    cout << "\nFox path (gems: " << gems << "/4):" << endl;
    printMatrix(fox);
    if(!fCollect ) cout << "Fox could not collect all gems" << endl;
}
