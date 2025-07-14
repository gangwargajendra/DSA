#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &arr){
    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// int sum(vector<int> &arr){
//     int s = 0;
//     for(auto element : arr){
//         s += element;
//     }
//     return s;
// }

//time complexity = O(2^n * n) :: 2^n = for recursion :: n = for printing vector in each recursion
// space complexity = O(n) :: max depth of recursion is n
void printSubsequence(int i, int k, vector<int> &arr, vector<int> &seq, int sum){
    int n = arr.size();
    if(i == n){
        if(sum == k)
            printVector(seq);
        return;
    }

    // take in subsequence
    seq.push_back(arr[i]);
    printSubsequence(i+1, k, arr, seq, sum + arr[i]);

    // not take in subsequence
    seq.pop_back();
    printSubsequence(i+1, k, arr, seq, sum);
}

// for printing only one subsequence
bool printSubsequenceOnly1(int i, int k, vector<int> &arr, vector<int> &seq, int sum){
    int n = arr.size();
    if(i == n){
        // condition satisfied means we find one solution
        if(sum == k){
            printVector(seq);
            return true;
        }
        // not found a solution 
        return false;
    }

    // take in subsequence
    seq.push_back(arr[i]);
    if(printSubsequenceOnly1(i+1, k, arr, seq, sum + arr[i])){
        return true;   // if we find a solution then return true
    }

    // not take in subsequence
    seq.pop_back();
    if(printSubsequenceOnly1(i+1, k, arr, seq, sum)){
        return true;  // if we find a solution then return true
    }
    
    return false;  // if we are not able to find a solution from
                   // both the upper recusive calls then return false  
}

// for couting no of subsequence whose sum is k
// time complexity = O(2^n)
int noOfSubsequence(int i, int k, vector<int> &arr, int sum){
    int n = arr.size();
    // condition will not satisfied 
    // strictly done if array contains positive only
    if(sum > k) return 0;
    
    if(i == n){
        if(sum == k) return 1;
        else return 0;
    }

    // take
    int take = noOfSubsequence(i+1, k, arr, sum+arr[i]);

    // not take
    int notTake = noOfSubsequence(i+1,k , arr, sum);

    return take + notTake;
}

int main(){
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    vector<int> arr(n);
    cout << "Enter numbers : ";
    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }

    vector<int> seq;
    printSubsequence(0 ,k, arr, seq, 0);
    cout << "only one subsequence : " ;
    printSubsequenceOnly1(0,k, arr, seq, 0);

    cout << "No of subsequence : " << noOfSubsequence(0, k, arr, 0);
}