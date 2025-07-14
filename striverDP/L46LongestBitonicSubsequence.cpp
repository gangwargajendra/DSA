// gfg Longest Bitonic subsequence

#include<bits/stdc++.h>
using namespace std;

int LongestBitonicSequence(int n, vector<int> &nums){
    if(n == 0) return 0;
    vector<int> revNums = nums;
    reverse(revNums.begin() , revNums.end());
    // by reversing the array , if we calculate LIS then that will
    // be the LDS(longest decreasing subsequence).


    vector<int> DPI(n, 1);
    vector<int> DPD(n ,1);

    for(int ind=0 ; ind<n ; ind++){
        for(int prevInd=ind-1 ; prevInd>=0 ; prevInd--){
            if(nums[ind] > nums[prevInd] && DPI[ind] < (1 + DPI[prevInd])){
                DPI[ind] = 1 + DPI[prevInd];
            }
            if(revNums[ind] > revNums[prevInd] && DPD[ind] < (1 + DPD[prevInd])){
                DPD[ind] = 1 + DPD[prevInd];
            }
        }
    }

    reverse(DPD.begin() , DPD.end());

    cout << "DPI : " ;
    for(int i=0 ; i<n ; i++){
        cout << DPI[i] << " ";
    }

    cout << "\nDPD : " ;
    for(int i=0 ; i<n ; i++){
        cout << DPD[i] << " ";
    }
    cout << endl;

    int ans = 0;
    for(int i=0 ; i<n ; i++){
        if(DPI[i] > 1 && DPD[i] > 1){
            if(ans < DPI[i] + DPD[i] - 1){
                ans = DPI[i] + DPD[i] - 1;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the element of array : ";
    for(int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    int ans = LongestBitonicSequence(n , nums);

    cout << "Longest Bitonic sequence : " << ans;

    return 0;
}