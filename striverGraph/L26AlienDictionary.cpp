#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// in two type of testcases , dictionary is not possible
// 1.  if s1 = abcd & s1 = abc
// 2. cycle abc , bat , adc

vector<int> topoSort(vector<int> adj[] , int V){
    vector<int> inDegree(V,0);

    for(int i=0 ; i<V ; i++){
        for(auto neigh : adj[i]){
            inDegree[neigh]++;
        }
    }

    queue<int> q;
    for(int i=0 ; i<V ; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int crnt = q.front();
        q.pop();
        ans.push_back(crnt);
        for(auto it : adj[crnt]){
            inDegree[it]--;
            if(inDegree[it] == 0){
                q.push(it);
            }
        }
    }
    return ans;
}

string AlienDictionary(string dictionary[] , int K , int N){
    vector<int> adj[K];
    for(int i=0 ; i<N-1 ; i++){
        string s1 = dictionary[i];
        string s2 = dictionary[i+1];
        int len = min(s1.size() , s2.size());
        for(int ptr = 0 ; ptr < len ; ptr++){
            if(s1[ptr] != s2[ptr]){
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> ansInInteger = topoSort(adj , K);
    string ans = "";
    for(auto it : ansInInteger){
        ans.push_back(char(it + 'a'));
    }
    return ans;
}

int main(){
    int n , k;
    cout << "Enter total number of words and alphabet : ";
    cin >> n >> k;

    string dictionary[n];
    cout << "Enter words : ";
    for(int i=0 ; i<n ; i++){
        cin >> dictionary[i];
    }

    string ans = AlienDictionary(dictionary , k , n);

    cout << "Alien Dictionary : ";
    cout << ans << endl;
    return 0;
}