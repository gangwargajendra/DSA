#include<iostream>
#include<vector>
using namespace std;

// time complexity = O(V + E) because it is a directed graph so each edges will weighted in only one direction
// space complexity = O(2 * N)
void printVector(vector<int> &path){
    cout << "Path : ";
    for(auto it : path){
        cout << it << " " ;
    }
    cout << endl;
}

bool DFS(vector<int> adj[] , vector<int> &vis, vector<int> &path , int src){
    vis[src] = 1;
    path[src] = 1;
    // cout << "After neoghbour " << neigh << "  " << endl;
    // printVector(vis);
    // printVector(path);
    for(auto neigh : adj[src]){
        // when node is not visited
        if(!vis[neigh]){
            if(DFS(adj , vis ,path, neigh) == true){
                return true;
            }
        }else{
            // if node has previously visiited
            // but it has to be visited on the same path
            if(path[neigh] == 1){
                return true;
            }
        }
    }
    path[src] = 0;
    return false;
}

bool detectCycleByDFS(vector<int> adj[] , int V){
    vector<int> vis(V+1 , 0);
    vector<int> path(V+1 , 0);

    for(int i=1 ; i<V+1 ; i++){
        if(!vis[i]){
            if(DFS(adj , vis , path, i) == true){
                return true;
            }
        }
    }
    return false;
}


int main(){
    int n,m;
    cout <<"Enter vertex and edges : ";
    cin >> n >> m;

    vector<int> adj[n+1];
    cout << "Enter edges : ";
    for(int i=0 ; i<m ; i++){
        int x , y;
        cin >>x >> y;
        adj[x].push_back(y);
    }

    bool ans = detectCycleByDFS(adj , n);

    if(ans){
        cout << "There is a cycle in this graph....";
    }else {
        cout << "There is not cycle in this graph...";
    }
}