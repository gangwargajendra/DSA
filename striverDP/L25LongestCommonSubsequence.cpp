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

int longestCommonSubsequenceM(string s1 , string s2){
    int l1 = s1.size();
    int l2 = s2.size();
    if(l1 == 0 || l2 == 0) return 0;
    vector<vector<int>> DP(l1 , vector<int>(l2 , -1));
    
    return f(l1-1 , l2-1 , s1 , s2 ,DP);
}

// using tabulation ---->>> 1 base indexing <<<<------
int longestCommonSubsequenceT(string s1, string s2){
    int l1 = s1.size();
    int l2 = s2.size();
    vector<vector<int>> DP(l1+1 , vector<int>(l2+1 , 0));

    for(int i=1 ; i<=l1 ; i++){
        for(int j=1 ; j<=l2 ; j++){
            int ans = 0;
            if(s1[i-1] == s2[j-1]){
                ans = 1 + DP[i-1][j-1];
            }else{
                ans = max( DP[i-1][j] , DP[i][j-1]);
            }
            DP[i][j] = ans;
        }
    }
    return DP[l1][l2];
}

int main(){
    string s1 , s2;
    cout << "Enter both string : ";
    cin >> s1 >> s2;

    cout << "Longest common subsequence using memoization : " << longestCommonSubsequenceM(s1,s2) << endl;
    cout << "Longest common subsequence using tabulation : " << longestCommonSubsequenceT(s1,s2) << endl;
}