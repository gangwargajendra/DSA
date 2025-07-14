#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// time = O(N * M) space = O(N * M)

void printMatrix(vector<vector<char>> &matrix){
    cout << "matrix : " << endl;
    for(int i=0 ; i<matrix.size() ; i++){
        for(int j=0 ; j<matrix[i].size() ; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
} 

// void printMatrix1(vector<vector<int>> &matrix){
//     cout << "matrix : " << endl;
//     for(int i=0 ; i<matrix.size() ; i++){
//         for(int j=0 ; j<matrix[i].size() ; j++){
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
// } 

void DFS(vector<vector<char>> &grid , vector<vector<int>> &vis , pair<int, int> src , int delRow[] , int delCol[]){
    vis[src.first][src.second] = 1;

    for(int i=0 ; i<4 ; i++){
        int row = src.first + delRow[i];
        int col = src.second + delCol[i];

        if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 'O' && !vis[row][col]){
            DFS(grid , vis , {row , col} ,delRow , delCol);
        }
    }
}

vector<vector<char>> fill(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<char>> ans(n , vector<char>(m));
    vector<vector<int>> vis(n , vector<int>(m , 0));
    
    int delRow[] = {-1 , 0 , 1 , 0};
    int delCol[] = {0 , 1 , 0 , -1};
    /// for traversing boundary O's
    // neeche dono ka total time = O(N * M * 4)
    // for first and last row
    for(int i= 0 ; i<m ; i++){
        if(grid[0][i] == 'O' && !vis[0][i]){
            DFS(grid , vis , {0 ,i}, delRow , delCol);
        }
        if(grid[n-1][i] == 'O' && !vis[n-1][i]){
            DFS(grid , vis , {n-1 ,i}, delRow , delCol);
        }
    }
    // for last first and last column
    for(int i=1 ; i<n-1 ; i++){
        if(grid[i][0] == 'O' && !vis[i][0]){
            DFS(grid , vis ,{i ,0},delRow ,delCol);
        }
        if(grid[i][m-1] == 'O' && !vis[i][m-1]){
            DFS(grid , vis , {i , m-1} ,delRow , delCol);
        }
    }

    // for making new ans matrix 
    // time = O(N * M)
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            // if there is O and visited means it's boundary O
            if(grid[i][j] == 'O' && vis[i][j]){
                ans[i][j] = 'O';
            // if there is O and not visited means it's not a boundary O 
            }else if(grid[i][j] == 'O' && !vis[i][j]){
                ans[i][j] = 'X';
            // if there is X put it in ans at it is
            }else if(grid[i][j] == 'X'){
                ans[i][j] = 'X';
            }
        }
    }

    // cout <<"visited ";
    // printMatrix1(vis);

    // cout << "src vector : ";
    // for(auto it : src){
    //     cout << "(" << it.first << "," << it.second << "),";
    // }
    // cout << endl;

    return ans;
}

int main(){
    int n, m;
    cout << "Enter rows and columns : ";
    cin >> n >> m;

    vector<vector<char>> grid(n , vector<char>(m));

    for(int i=0 ; i<n ; i++){
        cout << "Enter " << i+1 << " rows elements : ";
        for(int j=0 ; j<m ; j++){
            cin >> grid[i][j];
        }
    }
    cout << "before ";
    printMatrix(grid);

    vector<vector<char>> ans = fill(grid);

    cout << "after ";
    printMatrix(ans);

    return 0;
}