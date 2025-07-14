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

// space com = O(N*M)
// time com = O(N*M)

vector<vector<int>> NearestDistanceByBFS(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n , vector<int>(m ,0)); // space O(N * M)
    vector<vector<int>> vis(n , vector<int>(m ,0));  // space O(N * M)
    queue<pair<pair<int , int> , int>> q;
    //time complexity = O(N * M)
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == 1){
                q.push({{i , j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    int delRow[] = {-1 , 0 , 1 , 0};
    int delCol[] = {0 , 1 , 0 , -1}; 
    // time complexity = O(N * M * 4)
    // space complexity = O(N * M) // if all are 1 then it will take this
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dis = q.front().second;
        q.pop();
        dist[row][col] = dis;
    
        for(int i=0 ; i<4 ; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i]; 
    
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol]){
                vis[nRow][nCol] = 1;
                q.push({{nRow , nCol}, dis+1});
            } 
        }
    }
    return dist;
}

int main(){
    int n,m;
    cout << "Enter row and column : ";
    cin >> n >> m;
    vector<vector<int>> grid(n , vector<int>(m));
    
    for(int i=0 ; i<n ; i++){
        cout << "Enter "<< i+1 << " rows element : ";
        for(int j=0 ; j<m ; j++){
            cin >> grid[i][j];
        }
    }

    cout << "original matrix : ";
    printMatrix(grid);

    vector<vector<int>> ans = NearestDistanceByBFS(grid);

    cout << "Answer grid : ";
    printMatrix(ans);
}