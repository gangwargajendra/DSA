#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

// normal way to sovle the word ladderII problem
vector<vector<string>> wordLadderLength(string startWord , string targetWord , vector<string> &wordList){
    int n = wordList.size();
    int m = startWord.size();
    vector<vector<string>> ans; 

    set<string> mySet(wordList.begin() , wordList.end());

    queue<vector<string>> q;
    q.push({startWord});
    mySet.erase(startWord);
    set<string> crntLevelWord; // it will use to store all new words that has been used in new level
    bool found = false;

    while(!q.empty()){
        int levelSize = q.size();
        for(int i=0 ; i<levelSize ; i++){
            vector<string> sequence = q.front();
            string word = sequence.back();
            q.pop();
            if(word == targetWord){
                ans.push_back(sequence);
            }

            for(int j=0 ; j<m ; j++){
                char original = word[j];

                for(char ch='a' ; ch<='z' ; ch++){
                    word[j] = ch;
                    if(mySet.find(word) != mySet.end()){
                        vector<string> newSequence(sequence);
                        // for(auto it : sequence){
                        //     newSequence.push_back(it);
                        // }
                        newSequence.push_back(word);
                        q.push(newSequence);
                        crntLevelWord.insert(word);
                    }
                }
                word[j] = original;
            }
        }
        for(auto newWord : crntLevelWord){
            mySet.erase(newWord);
        }
        crntLevelWord.clear();
        if(found) break;
    }
    return ans;
}

// for leetcode, which will not give TLE

void DFS(string startWord, string word, vector<string> &seq, vector<vector<string>> &ans, unordered_map<string, int> &map){
    if(word == startWord){
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }
    int steps = map[word];
    for(int i=0 ; i<word.size() ; i++){
        char original = word[i];
        for(char ch='a' ; ch<='z' ; ch++){
            word[i] = ch;
            if(map.find(word) != map.end() && map[word] + 1== steps){
                seq.push_back(word);
                DFS(startWord, word, seq, ans, map);
                seq.pop_back();
            }
        }
        word[i] = original;
    }
}


vector<vector<string>> wordLadderIILeetcode(string startWord, string targetWord, vector<string> &wordList){
    unordered_set<string> st(wordList.begin(), wordList.end());
    unordered_map<string, int> map;
    queue<string> q;
    q.push(startWord);
    map[startWord] = 1;
    int size = startWord.size();
    st.erase(startWord);
    // step 1: BFS to find the minimum steps to reach target word
    while(!q.empty()){
        string word = q.front();
        int steps = map[word];
        q.pop();
        if(word == targetWord) break;
        for(int i=0 ; i<size ; i++){
            char original = word[i];
            for(char ch='a' ; ch<='z' ; ch++){
                word[i] = ch;
                if(st.count(word)){
                    q.push(word);
                    st.erase(word);
                    map[word] = steps + 1;
                }
            }
            word[i] = original;
        }
    }
    
    // step 2: Backtrack to find all the paths using DFS
    vector<vector<string>> ans;
    
    if(map.find(targetWord) != map.end()){
        vector<string> seq;
        seq.push_back(targetWord);
        DFS(startWord, targetWord, seq, ans, map);
    }

    return ans;
}

int main(){
    int n;
    cout << "Enter number of words : ";
    cin >> n ;

    vector<string> wordList(n);
    cout << "Enter words : ";
    for(int i=0 ; i<n ; i++){
        cin >> wordList[i];
    }

    string startWord , targetWord;
    cout << "Enter start and target word : ";
    cin >> startWord >> targetWord;

    vector<vector<string>> ans = wordLadderIILeetcode(startWord , targetWord ,wordList);

    cout << "Answer of given problem : "<< endl;
    for(int i=0 ; i<ans.size() ; i++){
        for(auto word : ans[i]){
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}


/* standard way 

vector<vector<string>> wordLadderLength(string startWord , string targetWord , vector<string> &wordList){
    vector<vector<string>> ans; 
    set<string> mySet(wordList.begin() , wordList.end());

    queue<vector<string>> q;
    q.push({startWord});
    mySet.erase(startWord);
    vector<string> usedOnLevel // it will use to store all new words that has been used in new level
    usedOnLevel.push_back(startWord);
    int level = 0;

    while(!q.empty()){
        vector<string> sequence = q.front();
        q.pop();
        // erase all words that has been used in previous levels to transform
        if(sequence.size() > level){
            level++;
            for(auto it : usedOnLevel){
                mySet.erase(it);
            }
            usedOnLevel.clear();
        }
        string word = sequence.back();
        if(word == targetWord){
            if(ans.size() == 0){
                ans.push_back(sequence);
            }else if(ans[0].size() == sequence.size()){
                ans.push_back(sequence);
            }
        }

        for(int i=0 ; i<word.size() ; i++){
            char original = word[j];
            for(char ch='a' ; ch<='z' ; ch++){
                word[i] = ch;
                if(mySet.count(word) > 0){
                    sequence.push_back(word);
                    q.push_back(sequence);
                    usedOnLevel.push_back(word);
                    sequence.pop_back();
                }
                word[j] = original;
            }
        }
    }
    return ans;
}

*/
