// Leetcode 322.Coin Change

#include<bits/stdc++.h>
using namespace std;

// using memoization
int f(int ind , int amount,vector<int> &coins ,vector<vector<int>> &DP){
    if(ind == 0) {
        if(amount % coins[ind] == 0){
            return amount / coins[ind];
        }else{
            return 1e9;
        }
    }

    if(DP[ind][amount] != -1) return DP[ind][amount];

    int notTake = 0 + f(ind-1 , amount , coins ,DP);
    int take = 1e9;
    if(amount >= coins[ind]){
        take = 1 + f(ind , amount - coins[ind] , coins , DP);
    }

    return DP[ind][amount] = min(take , notTake);
}

int coinChangeM(vector<int> &coins , int amount){
    int n = coins.size();

    vector<vector<int>> DP(n , vector<int>(amount+1 , -1));

    int ans = f(n-1 , amount , coins , DP);
    if(ans == 1e9) return -1;
    else return ans;
}

// using tabulation
int coinChangeT(vector<int>& arr, int T) {
    int n = arr.size();
    
    vector<vector<int>> dp(n, vector<int>(T + 1, 0));
    
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            dp[0][i] = i / arr[0];
        else
            dp[0][i] = 1e9;
    }
    
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            int notTake = dp[ind - 1][target];
            
            int take = 1e9;
            if (arr[ind] <= target)
                take = 1 + dp[ind][target - arr[ind]];
                
            dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n - 1][T];
    
    if (ans >= 1e9)
        return -1;
    
    return ans;
}

int main(){
    int n;
    cout << "Enter number of coins : ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coins : ";
    for(int i=0 ; i<n ; i++){
        cin >> coins[i];
    }

    int amount;
    cout << "Enter amount : ";
    cin >> amount;

    cout << "Minimum coins to make amount using memoization : " << coinChangeM(coins ,amount) << endl; 
    cout << "Minimum coins to make amount using tabulation : " << coinChangeT(coins ,amount) << endl; 
}