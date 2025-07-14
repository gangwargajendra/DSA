// Leetcode : 1143 Longest Common Subsequence

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;

// using tabulation
vector<vector<int>> computeDP(string s1,string s2){
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
    return DP;
}

void computeWords(int i, int j, string s1, string s2,vector<vector<int>> &DP, set<string> &words ,string currnt){
    if(i == 0 || j == 0){
        words.insert(currnt);
        return ;
    }

    if(s1[i-1] == s2[j-1]){
        computeWords(i-1 ,j-1,s1,s2,DP,words,s1[i-1]+currnt);
    }else{
        if(DP[i-1][j] == DP[i][j]){
            computeWords(i-1,j,s1,s2,DP,words,currnt);
        }
        if(DP[i][j-1] == DP[i][j]){
            computeWords(i,j-1 ,s1,s2,DP,words,currnt);
        }
    }
}

vector<string> all_longest_common_subsequencesT(string s1, string s2){
    int l1 = s1.size();
    int l2 = s2.size();

    if(l1 == 0 || l2 == 0) return {""};
    vector<vector<int>> DP = computeDP(s1 , s2);

    set<string> words;
    computeWords(l1 , l2 ,s1 , s2 , DP , words , "");

    vector<string> ans;
    // storing only unique words
    for(auto it : words){
        ans.push_back(it);
    }
    return ans;
}


///////////////////////////////////////////////////////////
/********************************************************* */
// for printing only one common subsequence
string printLongestCommonSubsequence(string s1, string s2){
    int l1 = s1.size();
    int l2 = s2.size();

    if(l1 == 0 || l2 == 0) return "";
    
    vector<vector<int>> DP = computeDP(s1,s2);

    string ans = "";
    int i=l1 , j = l2;
    while(i != 0 && j != 0){
        if(s1[i-1] == s2[j-1]){
            ans = s1[i-1] + ans;
            i--;
            j--;
        }else{
            if(DP[i-1][j] == DP[i][j]){
                i--;
            }else if(DP[i][j-1] == DP[i][j]){
                j--;
            }
        }
    }
    return ans;
}

int main(){
    string s1 , s2;
    cout << "Enter both string : ";
    cin >> s1 >> s2;

    // vector<string> ans = all_longest_common_subsequencesT(s1 , s2);
    // cout << "All wrods : ";
    // for(int i=0 ; i<ans.size() ; i++){
    //     cout << ans[i] << " ";
    // }

    cout << "\n\none common word : " << printLongestCommonSubsequence(s1,s2);
    return 0;
}




///////////////////////// standard ans //////////////////////////////////
//********************************************************************/
// class Solution {
//     int dp[101][101];
//     int lcs_len = 0;
//     vector<string> res;

//   private:
//     int lcs(string s, string t, int pos1, int pos2) {
//         // base condition
//         if (pos1 == s.size() or pos2 == t.size())
//             return 0;
//         int &ans = dp[pos1][pos2];
//         // if lcs has been computed
//         if (ans != -1)
//             return ans;
//         // if characters are same return previous + 1 else
//         // max of two sequences after removing i'th and j'th
//         // char one by one
//         if (s[pos1] == t[pos2])
//             return ans = 1 + lcs(s, t, pos1 + 1, pos2 + 1);
//         return ans = max(lcs(s, t, pos1 + 1, pos2), lcs(s, t, pos1, pos2 + 1));
//     }

//   private:
//     void helper(string s, string t, string cur, int pos1, int pos2, int cur_lcs) {
//         // if currlcs is equal to lcslen then store it
//         if (cur_lcs == lcs_len) {
//             res.push_back(cur);
//             return;
//         }
//         // if we are done with all the characters of both string
//         if (pos1 == s.size() or pos2 == t.size())
//             return;
//         // here we have to print all sub-sequences lexicographically,
//         // that's why we start from 'a'to'z' if this character is
//         // present in both of them then append it in cur and same
//         // remaining part
//         for (char ch = 'a'; ch <= 'z'; ch++) {
//             // f is a flag to tell that we have printed all the
//             // subsequences corresponding to current character
//             bool f = false;
//             for (int i = pos1; i < s.size(); i++) {
//                 if (s[i] == ch) {
//                     for (int j = pos2; j < t.size(); j++) {
//                         // if ch is present in both of them and
//                         // remaining length is equal to remaining
//                         // lcs length then add ch in sub-sequenece
//                         if (t[j] == ch and lcs(s, t, i, j) == lcs_len - cur_lcs) {
//                             string new_cur = cur + ch;
//                             helper(s, t, new_cur, i + 1, j + 1, cur_lcs + 1);
//                             f = true;
//                             break;
//                         }
//                     }
//                 }
//                 // If we found LCS beginning with current character
//                 if (f)
//                     break;
//             }
//         }
//     }

//   public:
//     vector<string> all_longest_common_subsequences(string s, string t) {
//         memset(dp, -1, sizeof(dp));
//         // Find lcs_length
//         lcs_len = lcs(s, t, 0, 0);
//         // function to get all longest common subsequences
//         helper(s, t, "", 0, 0, 0);
//         return res;
//     }
// };