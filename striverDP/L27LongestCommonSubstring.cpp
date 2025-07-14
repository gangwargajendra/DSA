// gfg : Longest Common Substring
// isme agar recursion se calculate chahte ho to har
// ke liye ComputeDP function run karna padega , kyuki isme 
// isme i , j only i-1 and j-1 par depend karta h 

#include<bits/stdc++.h>
using namespace std;

// using memoization ---->>>>zero base indexing <<----
// ***********not a good approch****************
int computeDP(int i ,int j ,string s1 ,string s2 ,vector<vector<int>> &DP){
    if(i == -1 || j == -1){
        return 0;
    }

    if(DP[i][j] != -1) return DP[i][j];
    
    int ans = 0;

    if(s1[i] == s2[j]){
        ans = 1 + computeDP(i-1 , j-1 ,s1, s2 ,DP);
    }

    return DP[i][j] = ans;
}

int longestCommonSubstrM(string s1 , string s2){
    int l1 = s1.size();
    int l2 = s2.size();

    if(l1 == 0 || l2 == 0) return 0;
    vector<vector<int>> DP(l1 , vector<int>(l2 , -1));

    // compute the DP table
    for(int i=0 ; i<l1 ; i++){
        for(int j=0 ; j<l2 ; j++){
            int t = computeDP(i , j ,s1 ,s2, DP);
        }
    }

    // find the maximum in the table
    int ans = -1;
    for(int i=0 ; i<l1 ; i++){
        for(int j=0 ; j<l2 ; j++){
            ans = max(ans , DP[i][j]);
        }
    }
    return ans;
}

// using tabulation 
// ***************Good approach **************
int longestCommonSubstrT(string s1 , string s2){
    int l1 = s1.size();
    int l2 = s2.size();

    vector<vector<int>> DP(l1+1 , vector<int>(l2+1 , 0));

    // calculation DP and also finding maximum i.e. answer
    int ans = 0;
    for(int i=1 ; i<=l1 ; i++){
        for(int j=0 ; j<=l2 ; j++){
            if(s1[i-1] == s2[j-1]){
                DP[i][j] = 1 + DP[i-1][j-1];
            }else{
                DP[i][j] = 0;  // also we initialized by Zero ,so not necessary
            }
            
            ans = max(ans , DP[i][j]);
        }
    }

    return ans;
}

int main(){
    string s1 , s2;
    cout << "Enter both string : ";
    cin >> s1 >> s2;

    cout << "longest common substring using memoization : " << longestCommonSubstrM(s1,s2) << endl;
    cout << "longest common substring using tabulation : " << longestCommonSubstrT(s1 , s2);
    return 0;
}