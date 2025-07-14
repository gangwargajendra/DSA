// ******Word Ladder 1 ************ //

#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;


// standard way  // using set that will reduce time complexity
int wordLadderLength1(string startWord, string targetWord, vector<string>& wordList) {
    int n = wordList.size();
    int wordSize = startWord.size();
    set<string> mySet;
    
    for(int i=0 ; i<n ; i++){
        mySet.insert(wordList[i]);
    }

    queue<string> q;
    
    q.push(startWord);
    
    if(mySet.find(startWord) != mySet.end()){
        mySet.erase(startWord);
    }

    // here it will be 1 because we are not counting edges , we counting words(Nodes)
    int level = 1;

    //worst case all words in wordList will go in queue
    // time complexity = wordListLength * wordSize * 26 * log(n)->for set things
    while(!q.empty()){
        int levelSize = q.size();
        
        for(int i=0 ; i<levelSize ; i++){
            string crnt = q.front();
            q.pop();

            //time complexity = wordlength * 26
            for(int j=0 ; j<wordSize ; j++){
                char ch = crnt[j];
                
                for(int k=0 ; k<26 ; k++){
                    crnt[j] = (char)('a' + k); 
                    // if word is present in set
                    if(mySet.find(crnt) != mySet.end()){
                        if(crnt == targetWord) return level+1;
                        q.push(crnt);
                        mySet.erase(crnt);
                    }
                }
                crnt[j] = ch;
            }
        }
        level += 1;
    }

    /*
    // for this type of while loop , we have to store level with word in queue
    while(!q.empty()){
        string word = q.front();
        q.pop();
        for(int i=0 ; i<word.size() ; i++){
            char original = word[i];
            for(char ch = 'a' ; ch <= 'z' ; ch++){
                word[i] = ch;
                // word is exists in the set
                if(mySet.find(word) != mySet.end()){
                    mySet.erase(word);
                    q.push(word);
                }
            }
            word[i] = original;
        }
    }
    */

    return 0;
}

// totally brute fotrce way to check all the possibility

// to check whether word is present in wordlist or not if yes then retrun index
int isPresent(vector<string> &wordList , string word){
    for(int i=0 ; i<wordList.size() ; i++){
        if(wordList[i] == word){
            return i;
        }
    }
    return -1;
}

int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    int n = wordList.size();
    int wordSize = startWord.size();
    
    vector<int> vis(n , 0);  // for stroring visted words
    queue<string> q;
    
    q.push(startWord); 
    int t = isPresent(wordList , startWord);
    if(t != -1){
        vis[t] = 1;
    }
    // here it will be 1 because we are not counting edges , we counting words(Nodes)
    int level = 1;

    while(!q.empty()){
        int levelSize = q.size();
        
        // for checking that perticular level
        for(int i=0 ; i<levelSize ; i++){
            string crnt = q.front();
            q.pop();
            
            // for checking each alphabet of word(crnt)
            for(int j=0 ; j<wordSize ; j++){
                char ch = crnt[j];  // thid is for at the end of that index checking we can make word preveously 
                
                // for making a to z alphabet
                for(int k=0 ; k<26 ; k++){
                    crnt[j] = (char)('a' + k);  //replacing that alphabet with new alphabet 
                    t = isPresent(wordList , crnt);
                    // if word is present in wordlist and still not visited
                    if(t != -1 && !vis[t]){
                        if(crnt == targetWord) return level+1; // atrget find then return ans
                        q.push(crnt);   // push in queue
                        vis[t] = 1;    // and marked it as visited
                    }
                }
                crnt[j] = ch; // makring word(crnt) like as prevously
            }
        }
        level += 1;  // increase the level
    }
    return 0; // if startWord is reachible then return 0
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

    int minimumLength = wordLadderLength1(startWord , targetWord ,wordList);

    cout << "minimum length to reach : " << minimumLength;
    return 0;
}