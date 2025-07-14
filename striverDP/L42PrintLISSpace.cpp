// Leetcode 368. Largest Divisible Subset 

#include<bits/stdc++.h>
using namespace std;


// space = O(N)
vector<int> printLIS(vector<int> &nums){
    int n = nums.size();
    if(n == 0) return {};

    vector<int> DP(n, 1);
    vector<int> prnt(n);
    int lastInd = 0;
    int maxi = 1;

    for(int ind=0 ; ind<n ; ind++){
        prnt[ind] = ind;
        for(int prev_ind=ind-1 ; prev_ind>=0 ; prev_ind--){
            if(nums[ind] > nums[prev_ind] && DP[ind] < 1+DP[prev_ind]){
                DP[ind] = 1 + DP[prev_ind];
                prnt[ind] = prev_ind;
            }
        }
        if(DP[ind] > maxi){
            maxi = DP[ind];
            lastInd = ind;
        }
    }
    
    cout << "LIS length : " << maxi;

    vector<int> ans;
    ans.push_back(nums[lastInd]);
    
    while(prnt[lastInd] != lastInd){
        lastInd = prnt[lastInd];
        ans.push_back(nums[lastInd]);
    }

    reverse(ans.begin() , ans.end());
    return ans;
}

int main(){
    int n;
    cout << "Enter size of an array : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter all the elements of array : ";
    for(int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    vector<int> ans = printLIS(nums);

    cout << "\nLIS elements : ";
    for(int i=0 ; i<ans.size() ; i++){
        cout << ans[i] << " ";
    }

    return 0;
}