#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &arr){
    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


//time complexity = O(2^n * n) :: 2^n = for recursion :: n = for printing vector in each recursion
// space complexity = O(n) :: max depth of recursion is n
void printSubsequence(int i, vector<int> &arr, vector<int> &seq){
    int n = arr.size();
    if(i == n){
        printVector(seq);
        return;
    }

    // take in subsequence
    seq.push_back(arr[i]);
    printSubsequence(i+1, arr, seq);

    // not take in subsequence
    seq.pop_back();
    printSubsequence(i+1, arr, seq);
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter numbers : ";
    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }

    vector<int> seq;
    printSubsequence(0 ,arr, seq);
}