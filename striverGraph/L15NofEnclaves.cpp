#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// time = O(N * M) space = O(N * M)

void printMatrix(vector<vector<int>> &matrix){
    cout << "matrix : " << endl;
    for(int i=0 ; i<matrix.size() ; i++){
        for(int j=0 ; j<matrix[i].size() ; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
} 
 
//from  DFS
void DFS(vector<vector<int>> &grid , vector<vector<int>> &vis , pair<int, int> src , int delRow[] , int delCol[]){
    vis[src.first][src.second] = 1;

    for(int i=0 ; i<4 ; i++){
        int row = src.first + delRow[i];
        int col = src.second + delCol[i];

        if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1 && !vis[row][col]){
            DFS(grid , vis , {row , col} ,delRow , delCol);
        }
    }
}

int noOfEnclaves(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n , vector<int>(m , 0));
    
    int delRow[] = {-1 , 0 , 1 , 0};
    int delCol[] = {0 , 1 , 0 , -1};
    /// for traversing boundary 1's
    // neeche dono ka total time = O(N * M * 4)
    // for first and last row
    for(int i= 0 ; i<m ; i++){
        if(grid[0][i] == 1 && !vis[0][i]){
            DFS(grid , vis , {0 ,i}, delRow , delCol);
        }
        if(grid[n-1][i] == 1 && !vis[n-1][i]){
            DFS(grid , vis , {n-1 ,i}, delRow , delCol);
        }
    }
    // for last first and last column
    for(int i=1 ; i<n-1 ; i++){
        if(grid[i][0] == 1 && !vis[i][0]){
            DFS(grid , vis ,{i ,0},delRow ,delCol);
        }
        if(grid[i][m-1] == 1 && !vis[i][m-1]){
            DFS(grid , vis , {i , m-1} ,delRow , delCol);
        }
    }
    int cntr = 0;
    // for counting cell which can go boundary of grid
    // time = O(N * M)
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == 1 && !vis[i][j]){
                cntr++;
            }
        }
    }

    return cntr;
}

// from BFS (2nd approach)  time = O(N*M) space = O(N*M)
int numberOdEnclaves(vector<vector<int>> &grid){
    queue<pair<int, int>> q;
    int n = grid.size();
    int m =grid[0].size();
    int vis[n][m] = {0};
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            // first row ,first col ,last row ,last col
            if(i==0 || j==0 || i == n-1 || j==m-1){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
    }
    int delRow[] = {-1 ,0 , 1 , 0};
    int delCol[] = {0 , 1 , 0 ,-1};
    // time complexity = O(N*M*4)
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol] == 1 && !vis[nRow][nCol]){
                vis[nRow][nCol] = 1;
                q.push({nRow,nCol});
            }
        }
    }
    int cntr = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == 1 && !vis[i][j]){
                cntr++;
            }
        }
    }
    return cntr;
}

int main(){
    int n, m;
    cout << "Enter rows and columns : ";
    cin >> n >> m;

    vector<vector<int>> grid(n , vector<int>(m));

    for(int i=0 ; i<n ; i++){
        cout << "Enter " << i+1 << " rows elements : ";
        for(int j=0 ; j<m ; j++){
            cin >> grid[i][j];
        }
    }
    cout << "before ";
    printMatrix(grid);

    int totalCell = noOfEnclaves(grid);

    cout << "total no of Enclaves : " << totalCell;

    return 0;
}