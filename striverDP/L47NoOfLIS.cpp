// Leetcode 673 Number os lingest increasing Subsequence

#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &nums){
    int n = nums.size();
    if(n == 0) return 0;

    int maxSize = 1;

    vector<int> DP(n , 1);
    vector<int> count(n , 1);

    for(int ind=0 ; ind<n ; ind++){
        for(int prevInd=ind-1 ; prevInd>=0 ; prevInd--){
            if(nums[ind] > nums[prevInd] && DP[ind] < 1 + DP[prevInd]){
                DP[ind] = 1 + DP[prevInd];
                count[ind] = count[prevInd];
            }else if(nums[ind] > nums[prevInd] && DP[ind] == DP[prevInd] + 1){
                count[ind] = count[ind] + count[prevInd];
            }
        }
        maxSize = max(maxSize , DP[ind]);
    }

    int noOfLIS = 0;
    for(int i=0 ; i<n ; i++){
        if(DP[i] == maxSize){
            noOfLIS += count[i];
        }
    }

    return noOfLIS;
}

int main(){
    int n;
    cout<< "Enter the size of array : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of array : ";
    for(int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    int ans = findNumberOfLIS(nums);

    cout << "Number of lis : " << ans;

    return 0;
}