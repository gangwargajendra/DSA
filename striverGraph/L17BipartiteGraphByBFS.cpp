#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// time complexity = O(V + 2E)
// space somplexity = O(V)

bool BFS(vector<int> adj[] , int V , vector<int> &color , int src){
    color[src] = 0;  // mainly vis stored colour
    queue<int> q;   // src
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto neigh : adj[node]){
            if(color[neigh] != -1){  // already coloured means visited
                if(color[neigh] == color[node]) {
                    return false;
                }
            }else {
                q.push(neigh); 
                color[neigh] = !color[node]; // assign opposite color to neighbour
            }
        }
    }
    return true;
}

bool bipartiteGraph(vector<int> adj[] , int V){
    vector<int> vis(V+1 , -1);

    for(int i=1 ; i<V+1 ; i++){
        if(vis[i] == -1){
            if(BFS(adj , V+1 , vis , i) == false){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n , m;
    cout << "Enter vextex and nodes : ";
    cin >> n >> m;

    vector<int> adj[n+1];
    cout << "Enter edges : ";
    for(int i=0 ; i<m ; i++){
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool ans = bipartiteGraph(adj ,  n);

    if(ans){
        cout << "this graph is a bipartite graph...";
    }else{
        cout << "this graph is not a bipartite graph...";
    }

    return 0;
}