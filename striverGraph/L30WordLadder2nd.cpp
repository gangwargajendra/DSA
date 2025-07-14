#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

vector<vector<string>> wordLadderLength(string startWord , string targetWord , vector<string> &wordList){
    int n = wordList.size();
    int m = startWord.size();
    vector<vector<string>> ans; 

    set<string> mySet(wordList.begin() , wordList.end());

    queue<vector<string>> q;
    q.push({startWord});
    mySet.erase(startWord);
    set<string> tempSet; // it will use to store all new words that has been used in new level

    while(!q.empty()){
        int levelSize = q.size();
        for(int i=0 ; i<levelSize ; i++){
            vector<string> sequence = q.front();
            string word = sequence.back();
            q.pop();
            if(word == targetWord){
                ans.push_back(sequence);
            }
            if(i == levelSize-1 && !ans.empty()){
                break;
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
                        tempSet.insert(word);
                    }
                }
                word[j] = original;
            }
        }
        for(auto newWord : tempSet){
            mySet.erase(newWord);
        }
        tempSet.clear();
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

    vector<vector<string>> ans = wordLadderLength(startWord , targetWord ,wordList);

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