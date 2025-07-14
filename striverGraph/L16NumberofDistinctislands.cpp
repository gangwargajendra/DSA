#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<utility> //  for using pairs in set
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

// void printSet(set<vector<pair<int, int>>> &mySet){
//     cout << "Set elements : " << endl;

//     for(auto island : mySet){
//         cout << "{ ";   
//         for(auto cell : island){
//             cout << "(" << cell.first << "," << cell.second << ")," ;
//         }
//         cout << "}" << endl;
//     }
//     cout << endl;
// }

void printSet(set<vector<pair<int, int>>> &mySet) {
    int index = 0; // Initialize an index variable
    for (auto it = mySet.begin(); it != mySet.end(); ++it) { // Use an iterator to go through the set
        cout << "Island " << index++ << ": { "; // Print the index of the island
        for (auto cell : *it) { // Dereference the iterator to access the vector
            cout << "(" << cell.first << ", " << cell.second << ") "; // Print each cell
        }
        cout << "} ";
    }
    cout << endl;
}

void BFS(vector<vector<int>> &grid ,vector<vector<int>> &vis, pair<int , int> src , set<vector<pair<int , int>>> &mySet){
    vis[src.first][src.second] = 1;
    queue<pair<int, int>> q;
    q.push({src.first , src.second});

    int delRow[] = {-1 , 0 , 1 , 0};
    int delCol[] = {0 , 1 , 0 , -1};

    vector<pair<int , int>> islandCell;

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        islandCell.push_back({row - src.first , col - src.second});
        for(int i=0 ; i<4 ; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow >=0 && nRow < grid.size() && nCol >=0 && nCol < grid[0].size() && grid[nRow][nCol] == 1 && !vis[nRow][nCol]){
                q.push({nRow , nCol});
                vis[nRow][nCol] = 1;
            }
        }
    }

    printSet(mySet);

    mySet.insert(islandCell);
}
 
int countDistinctIslands(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    set<vector<pair<int , int>>> mySet;

    vector<vector<int>> vis(n , vector<int>(m , 0));
    // time = N * M (for loop) + log(n*M) for(making inserting in set) + N * M * 4 (for making dfs)
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == 1 && !vis[i][j]){
                BFS(grid ,vis , {i , j} , mySet);
            }
        }
    }

    return mySet.size();
}

int main(){
    int n,m;
    cout << "Enter row and column : ";
    cin >> n >> m;

    vector<vector<int>> grid(n , vector<int>(m));

    for(int i=0 ; i<n ; i++){
        cout << "Enter "<< i+1 << " rows elements : ";
        for(int j=0 ; j<m ;j++){
            cin >> grid[i][j];
        }
    }

    cout << "Before ";
    printMatrix(grid);

    int t = countDistinctIslands(grid);

    cout << "Total distinct Islands : " << t << endl;
    return 0;
}