#include<iostream>
#include<vector>
using namespace std;

bool DFS(vector<int> adj[] , vector<int> &vis , vector<int> &pathVis , vector<int> &sfNodes , int src){
    vis[src] = 1;
    pathVis[src] = 1;

    for(auto neigh : adj[src]){
        if(!vis[neigh]){
            if(DFS(adj , vis, pathVis , sfNodes , neigh) == true){
                return true;
            }
        }else{
            if(pathVis[neigh] == 1){
                return true;
            }
        }
    }
    // if there is a cyclic node that time this function will terminate 
    // in upper side ,, if function will reach here means that,this node is  
    // not forming a cycle and also not leading to a cyclic part
    pathVis[src] = 0;
    sfNodes[src] = 1;
    return false;
}

vector<int> safeNodes(vector<int> adj[] , int V){
    vector<int> vis(V+1 , 0);
    vector<int> pathVis(V+1 , 0);
    // for checking which will be safe nodes 
    vector<int> sfNodes(V+1 , 0);

    for(int i=1 ; i<V+1 ; i++){
        if(!vis[i]){
            DFS(adj , vis, pathVis , sfNodes , i);
        }
    }

    // terminateing all the safe node to an vector
    vector<int> ans;
    for(int i=1 ; i<V+1 ; i++){
        if(sfNodes[i] == 1){
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    int n , m;
    cout << "Enter vertex and edges :";
    cin >> n >> m;
    vector<int> adj[n+1];

    cout << "Enter edges : ";
    for(int i=0 ; i<m ; i++){
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<int> sfnode = safeNodes(adj , n);

    cout << "safe Nodes : ";
    for(auto it : sfnode){
        cout << it << " ";
    }
    return 0;
}