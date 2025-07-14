// gfg - introduction to DP

#include<iostream>
#include<vector>
using namespace std;

// using memoization TC=(N)  SC=O(N) + O(N) // recursion stack and DP array
int fM(int n , vector<int> &DP){
    // first base case
    if(n <= 1) return n;

    //STEP 2: check whether subproblem is solved previously or not
    if(DP[n] != -1) return DP[n];

    // STEP 3: store the result of all subproblems 
    return DP[n] = fM(n-1 , DP) + fM(n-2 , DP);
}

// using Tabulation TC=O(N) SC=O(N)  // only for DP Array
int fT(int n , vector<int> & DP){
    // base condition
    DP[0] = 0;
    DP[1] = 1;

    for(int i=2 ; i<=n ; i++){
        DP[i] = DP[i-1] + DP[i-2];
    }

    return DP[n];
}

// using twi variable approach TC=O(N) SC=O(1) 
int FTwoVariable(int n){
    if(n <= 1) return n;

    int prev = 1;
    int scndPrev = 0;
    int crnt;
    for(int i=2 ; i<=n ; i++){
        crnt = prev + scndPrev;
        scndPrev = prev;
        prev = crnt; 
    }

    return crnt;
}

int main(){
    int n ;
    cout << "Enter number : ";
    cin >> n;

    // Step 1: declear memoization array to store the result of subproblems
    vector<int> DP(n+1 , -1);
    
    cout << n << "th fibonacci number using memoization : " << fM(n , DP);
    cout << endl;
    for(int i=0 ; i<n+1 ; i++){
        cout << DP[i] << " ";
    }
    cout << endl;
    fill(DP.begin(),DP.end(),-1);

    cout << n << "th fibonacci number using tabulation : " << fT(n , DP);
    cout << endl;
    for(int i=0 ; i<n+1 ; i++){
        cout << DP[i] << " ";
    }
    cout << endl;
    
    cout << n << "th fibonacci number using two variable approach : " << FTwoVariable(n);
    cout << endl;

    return 0;
}