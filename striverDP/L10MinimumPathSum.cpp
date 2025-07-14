// Leetcode - 63.Unique Paths II
// from here we left space optimisation

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// left means= up  right=down
// using mameization TC=(M*N) SC=O((N-1)+(M-1))+O(N*M) // recursion stack and DP array
int compute(int m,int n, vector<vector<int>> &DP,vector<vector<int>> &grid){
    if(m == 0 && n == 0) return grid[m][n];

    if(DP[m][n] != -1) return DP[m][n];

    int left = INT_MAX;
    if(m-1 >= 0) left = compute(m-1 , n, DP,grid); 
    int right = INT_MAX;
    if(n-1 >= 0) right = compute(m ,n-1, DP,grid);

    return DP[m][n] = grid[m][n] + min(left , right);      
}

int minPathSumM(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    if(m == 0 || n == 0) return 0;
    vector<vector<int>> DP(m ,vector<int>(n,-1));

    return compute(m-1 ,n-1 ,DP,grid);  // Zero base indexing
}

// using tabulation
int minPathSumT(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    if(m == 0 || n == 0) return 0;

    vector<vector<int>> DP(m , vector<int>(n,0));
    // base conditoin
    DP[0][0] = grid[0][0];

    for(int i=0 ; i<m ; i++){
        for(int j=0; j<n ; j++){
            if(i == 0 && j == 0) continue;
             
            // otherwise do recurance work
            int left = INT_MAX;
            if(i-1 >= 0) left = DP[i-1][j];
            int right = INT_MAX;
            if(j-1 >= 0) right = DP[i][j-1];

            DP[i][j] = grid[i][j] + min(left , right);
        }
    }
    return DP[m-1][n-1];
}

int main(){
    int m,n;
    cout << "Enter length and width : ";
    cin >> m >> n;

    vector<vector<int>> grid(m ,vector<int>(n));
    cout << "Enter space and obstacle : ";
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> grid[i][j];
        }
    }

    cout << "Unique paths : " << minPathSumM(grid);

    cout << "\nUnique paths : " << minPathSumT(grid);

    
}
