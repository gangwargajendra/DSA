// gfg : Partition Equal Subset Sum

#include<iostream>
#include<vector>
using namespace std;

// using memoizatoin
bool f(int index , int target,vector<int> &nums, vector<vector<int>> &DP){
    if(target == 0) return true;
    if(index == 0) return (nums[0] == target);

    if(DP[index][target] != -1) return DP[index][target];

    bool notTaken = f(index-1 ,target ,nums , DP);
    bool taken = false;
    if(target >= nums[index]) taken = f(index-1 ,target-nums[index] , nums , DP);

    return DP[index][target] = (int)(notTaken || taken);
}

bool canPartitionM(vector<int> &nums){
    int n = nums.size();
    
    int sum = 0;
    for(int i=0 ; i<n ; i++){
        sum += nums[i];
    }

    if(sum % 2 != 0) return false;
    int k = sum / 2;

    vector<vector<int>> DP(n , vector<int>(k+1 , -1));
    return f(n-1 , k ,nums , DP);
}

// using tabulation
bool canPartitionT(vector<int> &nums){
    int n = nums.size();

    int sum = 0;
    for(int i=0 ; i<n ; i++){
        sum += nums[i];
    }
    if(sum %2 != 0) return false;
    int k = sum / 2;  // half sum

    vector<vector<bool>> DP(n , vector<bool>(k+1 , false)); 

    for(int index=0 ; index<n ; index++){
        DP[index][0] = true;
    }
    if(nums[0] <= k) DP[0][nums[0]] = true;

    for(int index=1 ; index<n ; index++){
        for(int target=1 ; target<=k ; target++){
            bool notTaken = DP[index-1][target];
            bool taken = false;
            if(target >= nums[index]) taken = DP[index-1][target-nums[index]];
        
            DP[index][target] = (taken || notTaken);
        }
    }

    return DP[n-1][k];
}

int main(){
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array element : ";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    bool ans = canPartitionM(arr);
    if(ans){
        cout << "Partition can be possible using memoization..." << endl;
    }else{
        cout << "Partition can't be possible using nemoization..."<< endl;
    }
    ans = canPartitionT(arr);
    if(ans){
        cout << "Partition can be possible using tabulation..." << endl;
    }else{
        cout << "Partition can't be possible using tabulation..." << endl;
    }
    return 0;
}