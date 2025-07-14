#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Time complexity = O(N+2E) + O(N) 
// space complexity = O(N) + O(N)/

bool cycleByBFS(vector<int> adj[], int src , vector<int> &vis){
    queue<pair<int , int>> q;
    vis[src] = 1;
    q.push({src , -1});  // node and parent

    while(!q.empty()){
        int crntNode = q.front().first;
        int prntNode = q.front().second;
        q.pop();
        for(auto adjacentNode : adj[crntNode]){
            if(!vis[adjacentNode]){
                q.push({adjacentNode , crntNode});
                vis[adjacentNode] = 1;
            }else if(adjacentNode != prntNode){
            // if it is not visited and also it is not parent node means
            // that somebody has been visited it from another path i.e it has a cycle
                return true;
            }
        }
    }
    return false;
}

bool detectCycle(vector<int> adj[] , int V , int src){
    vector<int> vis(V+1 , 0);
    // if graph is not connected
    for(int i=1 ; i<V+1 ; i++){
        if(!vis[i]){  
            if(cycleByBFS(adj , i , vis)) 
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