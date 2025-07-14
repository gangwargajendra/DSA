#include<bits/stdc++.h>
using namespace std;

void print2DSet(set<vector<int>> &ans){
    for(auto seq : ans){
        for(auto number : seq){
            cout << number << " ";
        }
        cout << endl;
    }
}

void print2DVector(vector<vector<int>> &ans){
    for(auto seq : ans){
        for(auto number : seq){
            cout << number << " ";
        }
        cout << endl;
    }
}


// this will return all unique subsequnce
void findUniqueSubsequence(int ind, vector<int> &arr, int target, vector<int> &seq, vector<vector<int>> &ans){
    if(target == 0){
        ans.push_back(seq);
        return;
    }

    for(int i=ind ; i<arr.size(); i++){
        if(i > ind && arr[i] == arr[i-1]) continue;
        if(arr[i] > target) break;

        seq.push_back(arr[i]);
        findUniqueSubsequence(i+1, arr, target-arr[i], seq, ans);
        seq.pop_back();
    }
}


// both f and f1 will give duplicate subsequence as well
void f(int i, int target, vector<int> &arr, vector<int> &seq, int sum, set<vector<int>> &ans){
    int n = arr.size();
    if(sum > target)    return;

    if(i == n){
        if(sum == target)  
            ans.insert(seq);
        return;
    }

    // take and repeat
    seq.push_back(arr[i]);
    f(i+1, target, arr, seq, sum+arr[i], ans);
    seq.pop_back();

    // did not take
    f(i+1, target, arr, seq, sum, ans);
}

void f1(int ind, vector<int> &arr, int target, vector<int> &seq, set<vector<int>> &ans){
    int n = arr.size();
    if(ind == n){
        if(target == 0){
            ans.insert(seq);
        }
        return;
    }

    // take and repeat
    if(arr[ind] <= target){
        seq.push_back(arr[ind]);
        f1(ind+1, arr, target - arr[ind], seq, ans);
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

    
    // cout << "first : "<< endl;
    // vector<int> seq;
    // set<vector<int>> ans;
    // f(0, target, arr, seq, 0, ans);
    // print2Dvector(ans);
    // cout << "Second : "<< endl;

    // vector<int> seq1;
    // set<vector<int>> ans1;
    // f1(0, arr, target, seq1, ans1);
    // print2Dvector(ans1);

    cout << "Uniqueu combinations : \n";
    sort(arr.begin(), arr.end());
    vector<int> seq;
    vector<vector<int>> ans;
    findUniqueSubsequence(0, arr, target, seq, ans);
    print2DVector(ans);

    return 0;
}