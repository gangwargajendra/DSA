// Leetcode : 1143 Longest Common Subsequence

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;

// using memoization
int f(int i,int j,string s1,string s2, vector<vector<int>> &DP){
    if(j == -1){
        // we have to delete from s1 from (0---i), will take i+1 operation
        return i+1;
    }
    if(i == -1){
        // we have to insert in s1 from (0---j), will take j+1 opeation
        return j+1;
    }
    if(DP[i][j] != -1) return DP[i][j];

    if(s1[i] == s2[j]){
        DP[i][j] = f(i-1 , j-1 , s1,s2 ,DP);
    }else{
        int a1 = 1 + f(i , j-1 ,s1, s2 ,DP);  // insertion
        int a2 = 1 + f(i-1 , j ,s1,s2,DP);   // deletion
        int a3 = 1 + f(i-1 , j-1 ,s1, s2 ,DP); // replacing
        
        DP[i][j] = min({a1,a2,a3});
    }

    return DP[i][j];
}

int minDistanceM(string s1, string s2){
    int l1 = s1.size();
    int l2 = s2.size();

    vector<vector<int>> DP(l1 , vector<int>(l2 ,-1));

    return f(l1-1,l2-1 ,s1,s2,DP);
}

// using tabulation
int minDistanceT(string s1,string s2){
    int l1 = s1.size();
    int l2 = s2.size();
    if(l1 == 0) return l2;

    vector<vector<int>> DP(l1+1,vector<int>(l2+1 , 0));

    for(int i=1 ; i<=l1 ; i++){
        DP[i][0] = i;
    }
    for(int j=1 ; j<=l2 ; j++){
        DP[0][j] = j;
    }

    for(int i=1 ; i<=l1 ; i++){
        for(int j=1 ; j<=l2 ; j++){
            if(s1[i-1] == s2[j-1]){
                DP[i][j] = DP[i-1][j-1];
            }else{
                int a1 = 1 + DP[i][j-1]; // insertion
                int a2 = 1 + DP[i-1][j]; // deletion
                int a3 = 1 + DP[i-1][j-1]; // replacing
                DP[i][j] = min({a1,a2,a3});
            }
        }
    }
    return DP[l1][l2];
}

int main(){
    string s1 , s2;
    cout << "Enter both string : ";
    cin >> s1 >> s2;

    cout << "min Operation to make word1 to word2 using memoization : " << minDistanceM(s1,s2);
    cout << "\nmin Operation to make word1 to word2 using tabulation : " << minDistanceT(s1,s2);
    return 0;
}