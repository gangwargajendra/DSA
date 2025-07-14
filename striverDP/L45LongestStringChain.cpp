// Leetcode 1048. Longest String Chain
// not submitted

#include<bits/stdc++.h>
using namespace std;

void printWords(vector<string> &words){
    cout << "words are : ";
    for(int i=0 ; i<words.size() ; i++){
        cout << words[i] << " ";
    }
    cout << endl;
}

bool isPredecessor(string s ,string pS){
    if(s.size() != pS.size()+1) return false;
    int f = false;
    int i=0 ,j=0;
    while(i != s.size()){
        if(s[i] != pS[j]){
            cout << s[i] << " " << pS[j] <<  " " << f << endl;
            if(f)  return false;
            f = true;
            i++;
        }else{
            i++ , j++;
        }
    }
    return true;
}

int f(int ind ,int prevInd ,vector<string> &words ,vector<vector<int>> &DP){
    if(ind == words.size()) return 0;

    if(DP[ind][prevInd+1] != -1) return DP[ind][prevInd+1];

    int notPick = f(ind+1 , prevInd , words ,DP);
    int pick = 0;
    if(prevInd == -1 || isPredecessor(words[ind] , words[prevInd])){
        pick = 1 + f(ind+1 , ind, words ,DP);
    }

    return DP[ind][prevInd+1] = max(pick , notPick);
}

int longestStrChain(vector<string> &words){
    int n = words.size();
    if(n == 0) return 0;
    printWords(words);

    sort(words.begin() , words.end() , [](const string &a, const string &b){
        return a.size() < b.size();
    });

    printWords(words);

    vector<vector<int>> DP(n , vector<int>(n+1 , -1));

    return f(0 , -1 ,words ,DP);
}   


int main(){
    int n;
    cout << "Enter number of words : ";
    cin >> n;

    vector<string> words(n);
    cout << "Enter all words : ";
    for(int i=0 ; i<n ; i++){
        string s;
        cin >> s;
        words[i] = s;
    }

    int ans = longestStrChain(words);
    cout << "answer is using memoization : " << ans << endl;

    // ans = longestStrChainT(words);
    // cout << "answer is using tabulation : " << ans;

    return 0;
}
