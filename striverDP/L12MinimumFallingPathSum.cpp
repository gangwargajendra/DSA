// Leetcode 931. Minimum Falling Path Sum

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// using memoization
// f(i , j) -> i,j idex se 0th row tak ka path with max Sum
int f(vector<vector<int>> &matrix, vector<vector<int>> &DP, int i , int j){
    int n = matrix.size();
    if(j < 0 || j >= n || i < 0) return INT_MAX;
    if(i == 0) return matrix[i][j];

    if(DP[i][j] != -1) return DP[i][j];

    int s = f(matrix , DP , i-1 , j);
    int ld = f(matrix ,DP ,i-1 , j-1); 
    int rd = f(matrix , DP ,i-1 , j+1);
    // this matrix[i][j] can be add upper but due int overflow, we add below
    return DP[i][j] = matrix[i][j] +  min(s , min(ld , rd));
}

int minFallingPathSumM(vector<vector<int>> &matrix){
    int n = matrix.size();

    vector<vector<int>> DP(n , vector<int>(n, -1));

    int minPath = INT_MAX;
    for(int j=0 ; j<n ; j++){
        int ans = f(matrix ,DP ,n-1 , j);
        minPath = min(minPath , ans);
    }
    return minPath;
}

//using tabulation
int minFallingPathSumT(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector<vector<int>> DP(n , vector<int>(n , 0));

    // base case
    for(int j=0 ; j<n ; j++){
        DP[0][j] = matrix[0][j];
    }

    for(int i=1 ; i<n ; i++){    // first Row is like base case
        for(int j=0 ; j<n ; j++){
            int s = matrix[i][j] + DP[i-1][j];
            int ld = 999999 , rd = 999999;
            if(j-1 >= 0) ld = matrix[i][j] + DP[i-1][j-1];
            if(j+1 < n) rd = matrix[i][j] + DP[i-1][j+1];

            DP[i][j] = min({s , ld , rd});
        }
    }
    
    int ans = DP[n-1][0];
    for(int i=1 ; i<n ; i++){
        ans = min(ans , DP[n-1][i]);
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter size of the matrix : ";
    cin >> n;

    vector<vector<int>> matrix(n , vector<int>(n));
    cout << "Enter elements of matrix : ";
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            int x;
            cin >>x;
            matrix[i][j] = x;
        }
    }

    cout << matrix[0][0] << matrix[0][1];

    cout << "minimum Falling path using memoization : "<< minFallingPathSumM(matrix);
    cout << "\nminimum Falling path using tabulation : "<< minFallingPathSumT(matrix);
}