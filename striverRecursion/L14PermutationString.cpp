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

//time com = O(n! * N) space com = O(N) + O(N)
// with extra space using picked array
void findAllPermutation(vector<int> &arr, vector<int> &seq, vector<vector<int>> &ans, vector<int> &pickedArr){
    int n = arr.size();
    if(seq.size() == n){
        ans.push_back(seq);
        return; 
    }

    for(int i=0 ; i<n ; i++){
        if(!pickedArr[i]){
            seq.push_back(arr[i]);
            pickedArr[i] = 1;
            findAllPermutation(arr, seq, ans, pickedArr);
            seq.pop_back();
            pickedArr[i] = 0;
        }
    }
}

// without using extra space
void findAllPermutation1(int ind, vector<int> &arr, vector<vector<int>> &ans){
    int n = arr.size();
    if(ind == n){
        ans.push_back(arr);
    }

    for(int i=ind; i<n; i++){
        swap(arr[ind], arr[i]);
        findAllPermutation1(ind+1, arr, ans);
        swap(arr[ind], arr[i]);
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
    
    // vector<vector<int>> ans;
    // vector<int> seq;
    // vector<int> pickedArr(n , 0);
    // findAllPermutation(arr, seq, ans, pickedArr);
    // print2DVector(ans);

    vector<vector<int>> ans;
    findAllPermutation1(0 , arr, ans);
    print2DVector(ans);

    return 0;
}