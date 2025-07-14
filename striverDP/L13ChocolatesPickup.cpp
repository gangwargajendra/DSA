// gfg : chocolates Pickup

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// using memoization
// dono ki row lene se accha h, kisi ek ke row ko store kare, kyuki 
// dono at the same time ek hi row par honge
int f(int i,int j1, int j2,vector<vector<int>> &grid,vector<vector<vector<int>>> &DP){
    int n = grid.size();
    int m = grid[0].size();
    
    if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -99999;
    if(i == n-1){
        if(j1 == j2) return grid[i][j1];   // if both edded at the same position
        return grid[i][j1] + grid[i][j2];
    }

    if(DP[i][j1][j2] != -1) return DP[i][j1][j2];

    int maxi = -999999;
    for(int colF=-1 ; colF<=1 ; colF++){
        for(int colS=-1 ; colS<=1 ; colS++){
            int x;
            if(j1 == j2) x = grid[i][j1] + f(i+1,j1+colF,j2+colS,grid,DP);
            else x = grid[i][j1] + grid[i][j2] + f(i+1,j1+colF,j2+colS ,grid,DP);
            maxi = max(maxi , x);
        }
    }
    return DP[i][j1][j2] = maxi;
}

int solveM(int n , int m , vector<vector<int>> &grid){
    if(n == 0 || m == 0) return 0;

    vector<vector<vector<int>>> DP(n , vector<vector<int>>(m , vector<int>(m , -1)));

    return f(0 , 0 , m-1 , grid ,DP); // row ,Start1 ,Start2 ,grid,DP
}


// using tabulation
int solveT(int n, int m, vector<vector<int>> &grid){
    if(n == 0 || m == 0) return 0;

    vector<vector<vector<int>>> DP(n , vector<vector<int>>(m , vector<int>(m , 0)));

    for(int j1=0 ; j1<m ; j1++){
        for(int j2=0 ; j2<m ; j2++){
            if(j1 == j2) DP[n-1][j1][j2] = grid[n-1][j1]; // if both at the same position
            else DP[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i=n-2 ; i>=0 ; i--){
        for(int j1=0 ; j1<m ; j1++){
            for(int j2=0 ; j2<m ; j2++){
                // for checking it below , digonal right, digonal left
                int maxi = -999999;
                for(int colF=-1 ; colF<=1 ; colF++){
                    for(int colS=-1 ; colS<=1 ; colS++){
                        // check out of bound condition
                        if(j1+colF >=0 && j1+colF<m && j2+colS>=0 && j2+colS<m){
                            int x;
                            if(j1 == j2) x = grid[i][j1] + DP[i+1][j1+colF][j2+colS];
                            else x = grid[i][j1] + grid[i][j2] + DP[i+1][j1+colF][j2+colS];
                            maxi = max(maxi , x);
                        }
                    }
                }
                DP[i][j1][j2] = maxi;
            }
        }
    }

    return DP[0][0][m-1]; // (i,j1,j2)  // because one is started at (0,0) and other at (0,m-1);
}

int main(){
    int n , m;
    cout << "Enter grid's size : ";
    cin >> n >> m;

    vector<vector<int>> grid(n ,vector<int>(m));
    cout << "Enetr grid's elements : ";
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> grid[i][j];
        }
    }

    cout << "maximum chocolate using memoization : " << solveM(n , m , grid ) << endl;
    cout << "maximum chocolate using tabulation : " << solveT(n , m , grid);
}