// Leetcode 494. Target sum

#include<bits/stdc++.h>
using namespace std;

// using memoization
int f(vector<int>& nums, int target, int index, int ans, vector<vector<int>> &dp) {
        if (index == nums.size()) {
            return ans == target ? 1 : 0;
        }

        if (dp[index][ans + 1000] != -1) {
            return dp[index][ans + 1000];
        }

        int include = f(nums, target, index + 1, ans + nums[index], dp);
        int exclude = f(nums, target, index + 1, ans - nums[index], dp);

        return dp[index][ans+1000] = include + exclude;
    }

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(2001, -1));
    return f(nums, target, 0, 0, dp);
}

int main(){
    int n;
    cout << "Enter nums's size : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter all nums : ";
    for(int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    int target;
    cout << "Enter target : ";
    cin >> target;

    cout << "different ways : " << findTargetSumWays(nums , target) << endl;
}