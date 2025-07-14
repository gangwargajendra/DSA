// Leetcode - 70. Climbing Stars

#include<iostream>
#include<vector>
using namespace std;

// using recursion
int usingRecur(int n){
    if(n == 0 || n == 1) return 1;

    int left = usingRecur(n-1);  // jab 1 stair neeche aayege
    int right = usingRecur(n-2); // jab 2 stair neeche aayenge

    return left + right;
}

// by using simple fibonacchi series
int UsingFibonacchi(int n , vector<int> &DP){
    if(n <= 2) return n;

    if(DP[n] != -1) return DP[n];

    return DP[n] = UsingFibonacchi(n-1 , DP) + UsingFibonacchi(n-2 , DP);
}


int main(){
    int n;
    cout << "Enter number of stairs : ";
    cin >> n;

    vector<int> DP(n+1 , -1);
    int ans = UsingFibonacchi(n , DP);

    cout << "Total number of ways to reach using Fibonacchi: " << ans;
    cout << endl;

    for(int i=0 ; i<n+1 ; i++){
        cout << DP[i] << " ";
    }

    cout << "Total number of ways to reach using simple recursion : " << usingRecur(n);
    cout << endl;
    return 0;
}