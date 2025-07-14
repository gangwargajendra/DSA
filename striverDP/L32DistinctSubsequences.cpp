// 115.Distinct Subsequences

#include<bits/stdc++.h>
using namespace std;

// using memoization
int f(int i, int j, string s1,string s2,vector<vector<int>> &DP){
    if(j == -1) return 1;
    if(i == -1) return 0;

    if(DP[i][j] != -1) return DP[i][j];

    int ans = 0;
    if(s1[i] == s2[j]){
        ans = f(i-1 , j-1 , s1,s2,DP) + f(i-1 , j ,s1,s2,DP);
    }else{
        ans = f(i-1, j ,s1 ,s2,DP);
    }

    return DP[i][j] = ans;
}

int numDistinctM(string s1, string s2){
    int l1 = s1.size();
    int l2 = s2.size();

    if(l1 == 0 || l2 == 0) return 0;
    vector<vector<int>> DP(l1 , vector<int>(l2,-1));
    return f(l1-1,l2-1,s1,s2, DP);
}

// using tabulation
int numDistinctT(string s1, string s2) {
    int l1 = s1.size();
    int l2 = s2.size();

    if(l1 == 0 || l2 == 0) return 0;

    vector<vector<int>> DP(l1+1 ,vector<int>(l2+1 ,0));

    for(int i=0 ; i<l1 ; i++){
        DP[i][0] = 1;
    }

    for(int i=1 ; i<=l1 ; i++){
        for(int j=1 ; j<=l2 ; j++){
            if(s1[i-1] == s2[j-1]){
                DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
            }else{
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    return DP[l1][l2];
}

int main(){
    string s1 , s2;
    cout << "Enter both string : ";
    cin >> s1 >> s2;

    cout << "min deletion to make smae word using memoization : " << numDistinctM(s1,s2) << endl;
    cout << "min deletion to make smae word using tabulation : " << numDistinctT(s1,s2) << endl;
}