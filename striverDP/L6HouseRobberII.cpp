// Leetcode 213. House Robber II

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// two temporary array lekar ek mai 0 to n-1 and second mai 1 to n 
// elements ko rakh le and dono mai L5 ki tarah maximum robbed money
// find kar le to dono array ke maximum answer hoga

// using Memoization TC=O(N) SC=O(N)+O(N)
int compute(vector<int> &nums, vector<int> &DP, int st, int indx){
    if(indx == st) return nums[indx];
    if(indx < st) return 0;

    if(DP[indx] != -1) return DP[indx];

    int pickIndx = nums[indx] + compute(nums, DP,st, indx-2);
    int NotPickIndx = 0 + compute(nums, DP,st, indx-1);

    return DP[indx] = max(pickIndx , NotPickIndx);
}

int robM(vector<int> &nums){
    int n = nums.size();
    if(n == 1) return nums[0];

    vector<int> DP(n , -1);
    int withFirst = compute(nums,DP,0,n-2);
    fill(DP.begin(),DP.end(),-1);

    int withOutFirst = compute(nums,DP,1,n-1);
    return max(withFirst , withOutFirst);
}

// using tabulation TC=O(N) SC=O(N)
int robT(vector<int> &nums){
    int n = nums.size();
    if(n == 1) return nums[0];
    vector<int> DP(n , -1);
    
    // first calculate with First
    DP[0] = nums[0];
    for(int indx=1 ; indx<n-1 ; indx++){
        int pickIndx = nums[indx];
        if(indx-2 >= 0) pickIndx = nums[indx] + DP[indx-2];
        int notPickIndx = 0;
        if(indx-1 >= 0) notPickIndx = 0 + DP[indx-1];

        DP[indx] = max(pickIndx , notPickIndx);
    }
    int withFirst = DP[n-2];

    fill(DP.begin() , DP.end() , -1);
    // secondly calculate without First
    DP[1] = nums[1];
    for(int indx = 2 ; indx<n ; indx++){
        int pickIndx = nums[indx];
        if(indx-2 >= 1) pickIndx = nums[indx] + DP[indx-2];
        int notPickIndx = 0;
        if(indx-1 >= 1) notPickIndx = 0 + DP[indx-1];

        DP[indx] = max(pickIndx , notPickIndx);
    }
    int withOutFirst = DP[n-1];

    return max(withFirst , withOutFirst);
}

// space optimization TC=O(N) SC=O(1)
int robS(vector<int> &nums){
    int n = nums.size();    
    if(n == 1) return nums[0];

    // firstly find with First
    int prev = nums[0];
    int scndPrev = 0;
    for(int indx=1 ; indx<n-1 ; indx++){
        int pickIndx = nums[indx];
        if(indx-2 >= 0) pickIndx = nums[indx] + scndPrev;
        int notPickIndx = 0;
        if(indx-1 >= 0) notPickIndx = 0 + prev;

        int crntIndx = max(pickIndx , notPickIndx);
        scndPrev = prev;
        prev = crntIndx;
    }
    int withFirst = prev;

    // secondly find without First
    prev = nums[1];
    scndPrev = 0;
    for(int indx=2 ; indx<n ; indx++){
        int pickIndx = nums[indx];
        if(indx-2 >= 1) pickIndx = nums[indx] + scndPrev;
        int notPickIndx = 0;
        if(indx-1 >= 1) notPickIndx = 0 + prev;

        int crntIndx = max(pickIndx , notPickIndx);
        scndPrev = prev;
        prev = crntIndx;
    }
    int withOutFirst = prev;

    return max(withFirst , withOutFirst);
}

int main(){
    int n;
    cout << "Enter number of houses : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter amount in each house :" ;
    for(int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    cout << "maximum amount using memoizatoin : " << robM(nums) << endl ;
    cout << "maximum amount using tabulation : " << robT(nums) << endl ;
    cout << "maximum amount with space optimization : " << robS(nums) << endl ;
}