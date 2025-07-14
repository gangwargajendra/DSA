#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// using Memoization TC=O(N) SC=O(N)+O(N)
int compute(vector<int> &nums, vector<int> &DP, int indx){
    if(indx == 0) return nums[indx];
    if(indx < 0) return 0;

    if(DP[indx] != -1) return DP[indx];

    int pickIndx = nums[indx] + compute(nums, DP, indx-2);
    int NotPickIndx = 0 + compute(nums, DP, indx-1);

    return DP[indx] = max(pickIndx , NotPickIndx);
}

int robM(vector<int> &nums){
    int n = nums.size();
    vector<int> DP(n , -1);
    return compute(nums , DP ,n-1);
}

// using tabulation TC=O(N) SC=O(N)
int robT(vector<int> &nums){
    int n = nums.size();
    vector<int> DP(n , -1);
    DP[0] = nums[0];
    for(int indx=1 ; indx<n ; indx++){
        int pickIndx = nums[indx];
        if(indx-2 >= 0) pickIndx = nums[indx] + DP[indx-2];
        int notPickIndx = 0;
        if(indx-1 >= 0) notPickIndx = 0 + DP[indx-1];

        DP[indx] = max(pickIndx , notPickIndx);
    }
    return DP[n-1];
}

// space optimization TC=O(N) SC=O(1)
int robS(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0];
    int scndPrev = 0;
    for(int indx=1 ; indx<n ; indx++){
        int pickIndx = nums[indx];
        if(indx-2 >=0) pickIndx = nums[indx] + scndPrev;
        int notPickIndx = 0;
        if(indx-1 >= 0) notPickIndx = 0 + prev;

        int crntIndx = max(pickIndx , notPickIndx);
        scndPrev = prev;
        prev = crntIndx;
    }
    return prev; // can be crntIndx if it is declear outside the loop
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













// this cumpute function will also work if we handle a case in which
// there is only two element in array

// int compute(vector<int> &nums , vector<int> &DP ,int indx){
//     if(indx <= 1) return nums[indx];

//     if(DP[indx] != -1) return DP[indx];

//     // if indx is a part of solution
//     int x = 0;
//     int y = 0;
//     if(indx-2 >= 0) x = compute(nums, DP ,indx-2);
//     if(indx-3 >= 0) y = compute(nums, DP ,indx-3);

//     int left = nums[indx] + max(x , y);

//     // if indx is not a part of solution
//     int a = 0;
//     int b = 0;
//     if(indx-3 >= 0) a = compute(nums, DP, indx-3);
//     if(indx-4 >= 0) b = compute(nums, DP, indx-4);

//     int right = nums[indx-1] + max(a, b); 

//     return DP[indx] = max(left , right);
// }