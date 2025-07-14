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

int BFS(vector<vector<int>> &grid , vector<vector<int>> &vis){
    queue<pair <pair<int , int> , int>> q;
    int cntFresh = 0;
    // fpr entering all rotten Oranges (2) in the queue and mark them visited
    for(int i= 0 ; i<grid.size() ; i++){
        for(int j = 0 ; j < grid[0].size() ; j++){
            if(grid[i][j] == 2){
                q.push({{i,j} , 0});
                vis[i][j] = 1;
            }
            if(grid[i][j] == 1){
                cntFresh++;
            }
        }
    }
    int t = 0 , cnt = 0;
    int delRow[4] = {-1 ,0 , 1 , 0};
    int delCol[4] = {0 ,1 , 0 , -1};

    while(!q.empty()){
        int crntRow = q.front().first.first;
        int crntCol = q.front().first.second;
        int crntT = q.front().second;
        t = max(crntT , t);
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nRow = crntRow + delRow[i];
            int nCol = crntCol + delCol[i];

            if(nRow >= 0 && nRow < grid.size() && nCol >= 0 && 
            nCol < grid[0].size() && vis[nRow][nCol] != 1 && grid[nRow][nCol] == 1){
                vis[nRow][nCol] = 1;
                q.push({{nRow , nCol} , crntT+1});
                cnt++;
            }
        } 
    }
    // for checking that all the fresh oranges are rotten or not
    // for(int i=0 ; i<grid.size() ; i++){
    //     for(int j=0 ; j<grid[0].size() ; j++){
    //         if(vis[i][j] == 1){
    //             cout << "It's not possible to do all oranges rotten"<< endl;
    //             return -1;
    //         }
    //     }
    // }
    // OR

    if(cnt != cntFresh) return -1;

    return t;
}

int minTimeToRottenAllOranges(vector<vector<int>> &grid){
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> vis(row , vector<int>(col , 0));

    return BFS(grid , vis);
}

int main(){
    int n, m;
    cout << "Enter rows and column : ";
    cin >> n >> m ;

    vector<vector<int>> grid(n , vector<int>(m));

    for(int i=0 ; i<n ; i++){
        cout << "Enter " << i+1 << " rows elements : ";
        for(int j=0 ; j<m ; j++){
            cin >> grid[i][j];
        }
    }

    cout << "before : " << endl;    
    printMatrix(grid);  

    int t = minTimeToRottenAllOranges(grid);

    cout << "total time to taken to rotten all ornages : " << t << endl;
    return 0;
}