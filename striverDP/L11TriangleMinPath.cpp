// Leetcode : 120 Triangle

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// using memoization TC=O(N*N)// no of stats :  SC=O(N)+O(N*N) // recursion stack  + DP array
int compute(vector<vector<int>> &triangle ,int i,int j,vector<vector<int>> &DP){
    int row = triangle.size();
    if(i == row-1) return triangle[i][j];   // i -> rows

    if(DP[i][j] != -1) return DP[i][j];

    int down = triangle[i][j] + compute(triangle ,i+1 ,j ,DP);
    int downRight = triangle[i][j] + compute(triangle,i+1,j+1,DP);

    return DP[i][j] = min(down , downRight); 
}

int minimumTotalM(vector<vector<int>> &triangle){
    int rows = triangle.size();

    vector<vector<int>> DP(rows);
    for(int i=0 ; i<rows ; i++){
        vector<int> temp(i+1 , -1);
        DP[i] = temp;
    }

    return compute(triangle, 0 , 0 ,DP);
}

// using tabulation TC=O(N*N) no of stats : SC=O(N*N) //for DP array
int minimumTotalT(vector<vector<int>> &triangle){
    int row = triangle.size();

    vector<vector<int>> DP(row);
    for(int i=0 ; i<row ; i++){
        vector<int> temp(i+1 , -1);
        DP[i] = temp;
    }

    // base case
    for(int i=0 ; i<row ; i++){
        DP[row-1][i] = triangle[row-1][i];
    } 

    for(int i=row-2 ; i>=0 ; i--){
        for(int j=0 ; j<i+1 ; j++){
            int down = triangle[i][j] + DP[i+1][j];
            int downRight = triangle[i][j] + DP[i+1][j+1];

            DP[i][j] = min(down , downRight);
        }
    }
    return DP[0][0];
}

int main(){
    int n;
    cout << "Enter number of rows : ";
    cin >> n;

    vector<vector<int>> triangle(n);
    cout << "Enter all triangle elements : ";
    for(int i=0 ; i<n ; i++){
        vector<int> temp(i+1);
        for(int j=0 ; j<i+1 ; j++){
            cin >> temp[j];
        }
        triangle[i] = temp;
    }

    cout << "minimum Path using memoization : " << minimumTotalM(triangle);
    cout << "\nminimum Path using tabulation : " << minimumTotalT(triangle);
}