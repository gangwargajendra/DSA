// gfg : subset Sum problem
// it's working if we don't partition into n and n subarray

#include<iostream>
#include<vector>
using namespace std;

// using memoizatoin
bool f(int index , int target,vector<int> &arr, vector<vector<int>> &DP){
    if(target == 0) return true;
    if(index == 0) return (arr[0] == target);

    if(DP[index][target] != -1) return DP[index][target];

    bool notTaken = f(index-1 ,target ,arr , DP);
    bool taken = false;
    if(target >= arr[index]) taken = f(index-1 ,target-arr[index] , arr , DP);

    return DP[index][target] = (int)(notTaken || taken);
}

bool isSubsetSumM(vector<int> &arr, int k){
    int n = arr.size();
    
    vector<vector<int>> DP(n , vector<int>(k+1 , -1));
    return f(n-1 , k ,arr , DP);
}

// using tabulation
bool isSubsetSumT(vector<int> &arr, int k){
    int n = arr.size();

    vector<vector<bool>> DP(n , vector<bool>(k+1 , false)); 

    for(int index=0 ; index<n ; index++){
        DP[index][0] = true;
    }
    if(arr[0] <= k) DP[0][arr[0]] = true;

    for(int index=1 ; index<n ; index++){
        for(int target=1 ; target<=k ; target++){
            bool notTaken = DP[index-1][target];
            bool taken = false;
            if(target >= arr[index]) taken = DP[index-1][target-arr[index]];
        
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

    int sum ;
    cout << "Enter target : ";
    cin >> sum;

    bool ans = isSubsetSumM(arr ,sum);
    if(ans){
        cout << "Target is there in Array using memoization..." << endl;
    }else{
        cout << "Target is not there in array using nemoization..."<< endl;
    }
    ans = isSubsetSumT(arr ,sum);
    if(ans){
        cout << "Target is there in Array using tabulation..." << endl;
    }else{
        cout << "Target is not there in array using tabulation..." << endl;
    }
    return 0;
}