#include<bits/stdc++.h>
using namespace std;

void print2Dvector(vector<vector<int>> &ans){
    for(int i=0 ; i<ans.size(); i++){
        for(auto number : ans[i]){
            cout << number << " ";
        }
        cout << endl;
    }
}


void f(int i, int target, vector<int> &arr, vector<int> &seq, int sum, vector<vector<int>> &ans){
    int n = arr.size();
    if(sum > target)    return;

    if(i == n){
        if(sum == target)  
            ans.push_back(seq);
        return;
    }

    // take and repeat
    seq.push_back(arr[i]);
    f(i, target, arr, seq, sum+arr[i], ans);
    seq.pop_back();

    // did not take
    f(i+1, target, arr, seq, sum, ans);
}

void f1(int ind, vector<int> &arr, int target, vector<int> &seq, vector<vector<int>> &ans){
    int n = arr.size();
    if(ind == n){
        if(target == 0){
            ans.push_back(seq);
        }
        return;
    }

    // take and repeat
    if(arr[ind] <= target){
        seq.push_back(arr[ind]);
        f1(ind, arr, target - arr[ind], seq, ans);
        seq.pop_back();
    }   

    // not take
    f1(ind+1, arr, target, seq, ans);
}


int main(){
    int n, target;
    cout << "Enter n and target : ";
    cin >> n >> target;

    vector<int> arr(n);
    cout << "Enter all distinct numbers : ";
    for(int i=0 ; i<n ;i++){
        cin >> arr[i];
    }

    
    cout << "first : "<< endl;
    vector<int> seq;
    vector<vector<int>> ans;
    f(0, target, arr, seq, 0, ans);
    print2Dvector(ans);
    cout << "Second : "<< endl;

    vector<int> seq1;
    vector<vector<int>> ans1;
    f1(0, arr, target, seq1, ans1);
    print2Dvector(ans1);

    return 0;
}