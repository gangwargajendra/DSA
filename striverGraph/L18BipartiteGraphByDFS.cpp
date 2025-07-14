#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// time complexity = O(V + 2E)
// space somplexity = O(V)

bool DFS(vector<int> adj[], vector<int> &color , int src){
    for(auto neigh : adj[src]){
        if(color[neigh] != -1){  // already coloured means visited
            if(color[neigh] == color[src]) {
                return false;
            }
        }else {
            color[neigh] = !color[src]; // assign opposite color to neighbour
            if(DFS(adj ,color ,neigh) == false){
                return false;
            }
        }
    }
    return true;
}

bool bipartiteGraph(vector<int> adj[] , int V){
    vector<int> vis(V+1 , -1);

    for(int i=1 ; i<V+1 ; i++){
        if(vis[i] == -1){
            vis[i] = 0;
            if(DFS(adj , vis , i) == false){
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