// leetcode 300. Longest increasing subsequence

#include<bits/stdc++.h>
using namespace std;

// using memoization
//***************************************************** */
//   if we will go from n--> 0  i.e f(n-1 , n);
// *****************************************************?
// int f(int ind ,int next_ind , vector<int> &nums , vector<vector<int>> &DP){
//     if(ind == -1) return 0;

//     if(DP[ind][next_ind] != -1) return DP[ind] [next_ind];

//     int notPick = f(ind-1 , next_ind , nums ,DP);
//     int pick = 0;
//     if(next_ind == nums.size() || nums[ind] < nums[next_ind]){
//         pick = 1 + f(ind-1 , ind , nums,DP);
//     }

//     return DP[ind][next_ind] = max(pick , notPick);
// }

//***************************************************** */
//   if we will go from 0--> n-1  i.e f(0 , -1);
// ******************************************************/

int f(int ind , int prev_ind , vector<int> &nums,vector<vector<int>> &DP){
    if(ind == nums.size()) return 0;

    if(DP[ind][prev_ind+1] != -1) return DP[ind][prev_ind+1];

    int not_pick = f(ind+1 , prev_ind ,nums,DP);

    int pick = 0;
    if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
        pick = 1 + f(ind+1 , ind , nums,DP);
    }

    return DP[ind][prev_ind+1] = max(pick , not_pick);
}

int lengthOfLISM(vector<int> &nums){
    int n = nums.size();

    vector<vector<int>> DP(n , vector<int>(n+1 , -1));

    return f(0 , -1 , nums,DP);  // from f(n-1 , n) i.e. calculate n-1 ---> 0
}

// using tabulation, by using commented function
int lengthOfLIST(vector<int> &nums) {
    int n = nums.size(); 
    if (n == 0) return 0; 
    vector<vector<int>> DP(n+1, vector<int>(n+1, 0)); 

    // base case will also initialise as ZERO bcz whole array is initializa as ZERO

    for (int ind = n-1; ind >= 0; ind--) { 
        // prevIndex is always lower then index
        for (int prev_ind = ind-1 ; prev_ind >= -1; prev_ind--) { 
            int notPick = DP[ind+1][prev_ind+1];
            int pick = 0; 
            if (prev_ind == -1 || nums[ind] > nums[prev_ind]) { 
                pick = 1 + DP[ind+1][ind+1]; 
            }
            DP[ind][prev_ind+1] = max(pick, notPick);  
        }
    } 
    return DP[0][-1+1];
}

// space optimization
int lengthOfLISS(vector<int> &nums){
    int n = nums.size(); 
    if (n == 0) return 0; 
    vector<int> nextRow(n+1, 0), crntRow(n+1 , 0); 

    // base case will also initialise as ZERO bcz whole array is initializa as ZERO

    for (int ind = n-1; ind >= 0; ind--) { 
        // prevIndex is always lower then index
        for (int prev_ind = ind-1 ; prev_ind >= -1; prev_ind--) { 
            int notPick = nextRow[prev_ind+1];
            int pick = 0; 
            if (prev_ind == -1 || nums[ind] > nums[prev_ind]) { 
                pick = 1 + nextRow[ind+1]; 
            }
            crntRow[prev_ind+1] = max(pick, notPick);  
        }
        nextRow = crntRow;
    } 
    return crntRow[-1+1];
}

int main(){
    int n;
    cout << "Enter the size of array : ";
    cin  >> n;

    vector<int> nums(n);
    cout << "Enter the elements of array : ";
    for(int i=0 ; i<n ; i++){
        cin >> nums[i];
    }  

    cout << "Longest increasing subsequence using memo : " << lengthOfLISM(nums); 
    cout << "\nLongest increasing subsequence using tabu : " << lengthOfLIST(nums);
    cout << "\nLongest increasing subsequence using space : " << lengthOfLISS(nums);
    return 0;
}