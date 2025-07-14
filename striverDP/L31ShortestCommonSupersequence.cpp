// Leetcode 1092. Shortest Common Supersequence 

#include<bits/stdc++.h>
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

string computeCommonWord(string s1, string s2,int l1,int l2, vector<vector<int>> DP){
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

string mergeBothWithMinSize(string s1 ,string s2,int l1,int l2 ,string commonWord){
    string result = "";
    int i=0 , j=0;
    int k = 0;
    while(i != l1 || j != l2){
        while(i < l1 && s1[i] != commonWord[k]){
            result.push_back(s1[i]);
            i++;
        }
        while(j < l2 && s2[j] != commonWord[k]){
            result.push_back(s2[j]);
            j++;
        }
        if(k < commonWord.size()){
            result.push_back(s1[i]);
            i++,j++,k++;
        }
    }
    return result;
}

string shortestCommonSupersequenceT(string s1, string s2) {
    int l1 = s1.size();
    int l2 = s2.size();

    if(l1 == 0 || l2 == 0) return "";
    
    vector<vector<int>> DP = computeDP(s1,s2);

    string commonWord = computeCommonWord(s1,s2,l1,l2,DP);

    
    return mergeBothWithMinSize(s1,s2 , l1 ,l2 ,commonWord);
}

int main(){
    string s1 , s2;
    cout << "Enter both string : ";
    cin >> s1 >> s2;

    //cout << "min deletion to make smae word using memoization : " << minDistanceM(s1,s2) << endl;
    cout << "min deletion to make smae word using tabulation : " << shortestCommonSupersequenceT(s1,s2) << endl;
}