// Leetcode : Partition Array Into Two Arrays to Minimize Sum Difference

// if some element of nums is giving sum equal to tha half of total sum 
// then rest will also give half of total sum. that's means partition is 
// possible.

#include<iostream>
#include<vector>
using namespace std;

// using tabulation
int minimumDifferenceT(vector<int> &nums){
    int n = nums.size();
    int sum = 0;
    int minNumber = 0;
    for(auto it : nums){
        sum += it;
        minNumber = min(minNumber , it);
    }

    for(int i=0 ; i<n ; i++){
        nums[i] = nums[i] + (-1) * minNumber;
        cout << nums[i] << " ";
    }
    cout << endl ;
    cout << "SUm : " << sum << endl;

    sum = sum + n * (-1) * minNumber; 
    cout << "SUm : " << sum << endl;

    int isEven = 1;
    if(sum % 2 == 1){
        isEven = 0;
    }
    int k = sum / 2;
    cout << "k : " << k << endl;

    vector<vector<bool>> DP(n , vector<bool>(k+1 , false)); 

    for(int index=0 ; index<n ; index++){
        DP[index][0] = true;
    }
    if(nums[0] <= k && nums[0] >= 0)DP[0][nums[0]] = true;

    for(int index=1 ; index<n ; index++){
        for(int target=1 ; target<=k ; target++){
            bool notTaken = DP[index-1][target];
            bool taken = false;
            if(target >= nums[index]) taken = DP[index-1][target-nums[index]];
        
            DP[index][target] = (taken || notTaken);
        }
    }

    // find the closest minimum k(target) that is possible to achieve
    for(int i=k ; i>=0 ; i--){
        if(DP[n-1][i]){
            cout << "Target that is done : " << i << endl;
            if(isEven) return 2*(k - i);
            else return (2*(k-i)) + 1;
        }
    }

    return 0;
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

    int ans = minimumDifferenceT(arr);
    cout << "minimum absolute differnece using tabulation..." << ans << endl;
    
    return 0;
}