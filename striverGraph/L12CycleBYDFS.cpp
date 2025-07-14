#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// by using stack DFS
bool cycleByStackDFS(vector<int> adj[], int src , vector<int> &vis){
    vis[src] = 1;
    stack<pair<int , int>> stk;
    stk.push({src , -1});

    while(!stk.empty()){
        int crnt = stk.top().first;
        int prnt = stk.top().second;
        stk.pop();

        for(auto neighbour : adj[crnt]){ 
            if(!vis[neighbour]){
                stk.push({neighbour , crnt});
                vis[neighbour] = 1;
            }else if(neighbour != prnt){
                return true;
            }
        }
    }
    return false;
}

// by using recursive DFS

// time complexity = O(N + 2E) + O(N)->for checking the connecting components
// space complecity = O(N) + O(N)
bool cycleByRecursiveDFS(vector<int> adj[] , int src ,int prnt, vector<int> &vis){
    vis[src] = 1;
    
    for(auto neighbour : adj[src]){
        if(!vis[neighbour]){
            cycleByRecursiveDFS(adj , neighbour ,src, vis);
        }else if(neighbour != prnt){
            return true;
        }
    }
    return false;
}

bool detectCycle(vector<int> adj[] , int V , int src){
    vector<int> vis(V+1 , 0);
    // if graph is not connected
    for(int i=1 ; i<V+1 ; i++){
        if(!vis[i]){  
            // if(cycleByStackDFS(adj , i , vis)) 
            if(cycleByRecursiveDFS(adj , i ,-1 , vis))  // node, parent
                return true;
        }
    }
    return false;
}

int main(){
    int V , m;
    cout << "Enter total vertex and edges : ";
    cin >> V >> m;

    vector<int> adj[V+1];

    for(int i=0 ; i<m ; i++){
        int x ,y;
        cout << "Enter edges : ";
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int sn;
    cout << "Enter starting node : ";
    cin >> sn;

    bool ans = detectCycle(adj , V , sn);  

    if(ans){
        cout <<"Cycle is present..."<< endl;
    }else{
        cout <<"cycle is not present....." << endl;
    }
    return 0;
}