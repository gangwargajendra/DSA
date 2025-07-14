#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void printMatrix(vector<vector<int>> &matrix){
    cout << "matrix : " << endl;
    for(int i=0 ; i<matrix.size() ; i++){
        for(int j=0 ; j<matrix[i].size() ; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS(vector<vector<int>> &grid , vector<vector<int>> &vis , int row , int col){
    queue<pair<int,int>> q;
    q.push({row,col});
    vis[row][col] = 1;

    while(!q.empty()){
        pair<int,int> crnt = q.front();
        q.pop();
        // for traversing its neighbour
        for(int delrow = -1 ; delrow <= 1 ; delrow++){
            for(int delcol = -1 ; delcol <= 1 ; delcol++){
                int nRow = crnt.first + delrow;
                int nCol = crnt.second + delcol;
                // for checking neiRow and neiCol are existing or  not
                if(nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size()){
                    // checking neighbour are visited or not
                    if(!vis[nRow][nCol] && grid[nRow][nCol] == 1){
                        vis[nRow][nCol] = 1;
                        q.push({nRow , nCol});
                    }
                }
            }
        }
    }
}

int Island(vector<vector<int>> &grid){
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> vis(row , vector<int>(col , 0));

    int cntr = 0;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                cntr++;
                BFS(grid , vis , i , j);
            }
        }
    }
    return cntr;
}

int main(){
    int n , m;
    cout << "Enter rows and columns of the matrix : ";
    cin >> n >> m ;

    vector<vector<int>> grid(n);

    for(int i=0 ; i<n ; i++){
        int t;
        cout << "Enter " << i+1 << " rows elements : ";
        for(int j=0 ; j<m ; j++){
            cin >> t;
            grid[i].push_back(t);
        }
    }

    int NoIsland = Island(grid);
    cout << "total no of island : " << NoIsland;
    return 0;
}