#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//time complexity = O(V + E) fpr DFS
// space complexity = O(V) + O(V)

void DFS(vector<int> adj[] , vector<int> &vis , stack<int> &myStack , int src){
    vis[src] = 1;

    for(auto neigh : adj[src]){
        if(!vis[neigh]){
            DFS(adj ,vis ,myStack , neigh);
        }
    }
    myStack.push(src);
}

vector<int> topologicalSort(vector<int> adj[] , int V){
    vector<int> vis(V+1 , 0);
    stack<int> myStack;

    for(int i=1 ; i<V+1 ; i++){
        if(!vis[i]){
            DFS(adj , vis , myStack , i);
        }
    }
    cout << "Stack size : " << myStack.size() << endl;
    vector<int> ans;
    while (!myStack.empty()) {
        ans.push_back(myStack.top());
        myStack.pop();
    }

    return ans;
}

int main(){
    int n,m;
    cout << "Enter vertex and edges : ";
    cin >> n >> m;

    vector<int> adj[n+1];

    cout << "Enter edges : ";
    for(int i=0 ; i<m ; i++){
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<int> ans = topologicalSort(adj , n);

    cout << "Topological sort : ";
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
}