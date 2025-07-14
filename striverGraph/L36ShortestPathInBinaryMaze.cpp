//gfg : shortest path in a binary maze

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

// using dijkastra algorithm
int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
    if(source == destination) return 0;
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> distance(n ,vector<int>(m , INT_MAX));
    queue<pair<int,pair<int,int>>> q;
    q.push({0,source});
    distance[source.first][source.second] = 0;
    int delRow[] = {-1, 0 , 1 ,0};
    int delCol[] = {0 , 1,0 ,-1};
    
    while(!q.empty()){
        int nodeDis = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nX = x + delRow[i];
            int nY = y + delCol[i];

            if(nX>=0 && nX<n && nY>=0 && nY<m && grid[nX][nY]){
                if(nX == destination.first && nY == destination.second){
                    return nodeDis + 1; 
                }
                if(distance[nX][nY] > nodeDis + 1){
                    distance[nX][nY] = nodeDis + 1;
                    q.push({distance[nX][nY] , {nX,nY}});
                    // q.push({1 + nodeDis , {nX,nY}});
                }
            }
        }
    }
    return -1;
}


// simple bfs traversal
int shortestPath1(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
    if(source == destination) return 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n ,vector<int>(m , 0));
    queue<pair<int,int>> q;
    q.push(source);
    vis[source.first][source.second] = 1;
    int delRow[] = {-1, 0 , 1 ,0};
    int delCol[] = {0 , 1,0 ,-1};
    int level =0;
    
    while(!q.empty()){
        int levelSize = q.size();
        for(int i=0 ; i<levelSize ; i++){
            int x = (q.front()).first;
            int y = (q.front()).second;
            q.pop();
            
            for(int j=0 ; j<4 ; j++){
                int nX = x + delRow[j];
                int nY = y + delCol[j];
                
                if(nX>=0 && nX<n && nY>=0 && nY<m && grid[nX][nY] && !vis[nX][nY]){
                    if(nX == destination.first && nY == destination.second){
                        return level+1;
                    }
                    vis[nX][nY] = 1;
                    q.push({nX,nY});
                }
            }   
        }
        level += 1;
    }
    return -1;
}

int main(){
    int n,m;
    cout << "Enter rows and column of grid : ";
    cin >> n >> m;

    vector<vector<int>> grid(n , vector<int>(m , 0));
    cout << "Enter grid data : ";
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            int x;
            cin >> x;
            grid[i][j] = x;
        }
    }

    pair<int  , int> source , destination;
    cout << "Enter source and destination : ";
    cin >> source.first >> source.second >> destination.first >> destination.second;

    int shortestDistance = shortestPath(grid, source , destination);
    cout << "shortest distance : " << shortestDistance<<endl;

    int shortestDistance1 = shortestPath1(grid, source , destination);
    cout << "shortest distance : " << shortestDistance1;
    return 0;
}