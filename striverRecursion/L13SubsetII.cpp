#include<bits/stdc++.h>
using namespace std;


void print2DVector(vector<vector<int>> &ans){
    for(auto seq : ans){
        for(auto number : seq){
            cout << number << " ";
        }
        cout << endl;
    }
}


//method 1 : we can find all subset and can remove duplicate by using set


// method 2
void printAllUniqueSubset(int ind, vector<int> &arr, vector<int> &seq, vector<vector<int>> &ans){
    ans.push_back(seq);
    int n = arr.size();
    if(ind == n){
        return ;
    }

    for(int i=ind ; i<n ; i++){
        if(i > ind && arr[i] == arr[i-1]) continue;

        seq.push_back(arr[i]); // i is the first number's index among duplicate
        printAllUniqueSubset(i+1, arr, seq, ans);
        seq.pop_back();
    }
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
    sort(arr.begin(), arr.end());
    
    vector<vector<int>> ans;
    vector<int> seq;
    printAllUniqueSubset(0, arr, seq, ans);

    print2DVector(ans);

    return 0;
}