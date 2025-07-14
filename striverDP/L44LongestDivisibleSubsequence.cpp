// leetcode 368. Largest DIvisible subset

#include<bits/stdc++.h>
using namespace std;

// using memoization 
int f(int ind , int prevInd, vector<int> &nums, vector<vector<int>> &DP){
    if(ind == nums.size()) return 0;

    if(DP[ind][prevInd+1] != -1) return DP[ind][prevInd+1];

    int notPick = f(ind+1 , prevInd , nums , DP);
    int pick = 0;
    if(prevInd == -1 || nums[ind] % nums[prevInd] == 0){
        pick = 1 + f(ind+1 , ind , nums, DP);
    }

    return DP[ind][prevInd+1] = max(pick , notPick);
}

int largestDivisibleSubsetM(vector<int> &nums){
    int n = nums.size();
    if(n == 0) return {};
    sort(nums.begin() , nums.end());

    vector<vector<int>> DP(n , vector<int>(n+1 , -1));
    
    int maxSize = f(0 , -1 , nums ,DP);

    cout << "maximum Size : " << maxSize;
    return maxSize;
}

// using tabulation
vector<int> largestDivisibleSubsetT(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin() , nums.end());

    vector<int> DP(n , 1);
    vector<int> temp(n);

    int maxSize = 1;
    int maxInd = -1;

    for(int ind=0 ; ind<n ; ind++){
        temp[ind] = ind;
        for(int prevInd = ind-1 ; prevInd >=0 ; prevInd--){
            if(nums[ind] % nums[prevInd] == 0 && DP[ind] < 1 + DP[prevInd]){
                temp[ind] = prevInd;
                DP[ind] = 1 + DP[prevInd];
            }
        }
        if(maxSize < DP[ind]){
            maxSize = DP[ind];
            maxInd = ind;
        }
    }


    vector<int> result;
    result.push_back(nums[maxInd]);
    while(temp[maxInd] != maxInd){
        maxInd = temp[maxInd];
        result.push_back(nums[maxInd]);
    }

    reverse(result.begin() , result.end());
    return result;
}

int main(){
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of array : ";
    for(int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    int maxSize = largestDivisibleSubsetM(nums);

    vector<int> ans = largestDivisibleSubsetT(nums);

    cout << "Largest Divisible Subset : ";
    for(int i=0 ; i<ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}