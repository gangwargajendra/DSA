// Leetcode : 1143 Longest Common Subsequence

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// using memoization  --->>>Zero base indexing<<<----
int f(int i , int j , string s1 , string s2, vector<vector<int>> &DP){
    if(i == -1 || j == -1){
        return 0;
    }
    
    if(DP[i][j] != -1) return DP[i][j];

    int ans = 0;
    if(s1[i] == s2[j]){
        ans = 1 + f(i-1 , j-1 ,s1 ,s2, DP);
    }else{
        ans = max( f(i-1 , j ,s1 ,s2, DP) , f(i , j-1 , s1 ,s2, DP) );
    } 

    return DP[i][j] = ans;
}

int longestPalindromeSubseqM(string s1){  //  s1 -> original & s2 -> reversed
    string s2 = s1;
    reverse(s2.begin() , s2.end());
    int l = s1.size();
    if(l == 0) return 0;
    vector<vector<int>> DP(l , vector<int>(l , -1));
    
    return f(l-1 , l-1 , s1 , s2 ,DP);
}

// using tabulation ---->>> 1 base indexing <<<<------
int longestPalindromeSubseqT(string s1){  // s1-> original & s2-> reversed
    int l = s1.size();
    string s2 = s1;
    reverse(s2.begin() , s2.end());
    vector<vector<int>> DP(l+1 , vector<int>(l+1 , 0));

    for(int i=1 ; i<=l ; i++){
        for(int j=1 ; j<=l ; j++){
            int ans = 0;
            if(s1[i-1] == s2[j-1]){
                ans = 1 + DP[i-1][j-1];
            }else{
                ans = max( DP[i-1][j] , DP[i][j-1]);
            }
            DP[i][j] = ans;
        }
    }
    return DP[l][l];
}

int main(){
    string s;
    cout << "Enter string : ";
    cin >> s;

    cout << "Longest palindromic subsequence using memoization : " << longestPalindromeSubseqM(s) << endl;
    cout << "Longest palindromic subsequence using tabulation : " << longestPalindromeSubseqT(s) << endl;
}