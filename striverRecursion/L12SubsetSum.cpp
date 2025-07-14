#include<bits/stdc++.h>
using namespace std;


void printVector(vector<int> &arr){
    sort(arr.begin(), arr.end());
    for(auto element : arr){
        cout << element << " ";
    }
    cout << endl;
}

void printAllSubsetSum(int i, vector<int> &arr, int sum, vector<int> &ans){
    int n = arr.size();
    if(i == n){
        ans.push_back(sum);
        return ;
    }

    //not take
    printAllSubsetSum(i+1, arr, sum, ans);

    // take
    printAllSubsetSum(i+1, arr, sum+arr[i], ans);

}

int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter all numbers: ";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    vector<int> ans;
    printAllSubsetSum(0, arr, 0, ans);

    printVector(ans);

    return 0;
}