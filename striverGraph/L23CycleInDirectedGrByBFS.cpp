#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// time complexity = O(V + E)
// long way
bool detectCycle(vector<int> adj[] , int V){
    vector<int> inDegree(V , 0);
    for(int i=0 ; i<V ; i++){
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }

    queue<int> q;
    // we can also skip visited vector
    vector<int> vis(V , 0);
    for(int i=0 ; i<V ; i++){
        if(inDegree[i] == 0){
            q.push(i);
            vis[i] = 1;
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int crnt = q.front();
        ans.push_back(crnt);
        q.pop();
        // node is in topo sort
        // so please remove it from the indegree
        for(auto neigh : adj[crnt]){
            inDegree[neigh]--;
            if(inDegree[neigh] == 0 && !vis[neigh]){
                q.push(neigh);
                vis[neigh] = 1;
            }
        }
    }
    // as we know that Topo sort is not valid on cyclic directed graph
    // so if we apply topo sort in cycil directed graph then all nodes will
    // not visited all the nodes
    // second method can be that in ans(that stored topo sort) will 
    // have less element then V
    for(int i=0 ; i<V ; i++){
        if(!vis[i]){
            return true;
        }
    }
    return false;
}

// standard way
bool detectCycle1(vector<int> adj[] , int V){
    vector<int> inDegree(V , 0);
    for(int i=0 ; i<V ; i++){
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0 ; i<V ; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    int cntr = 0;
    while(!q.empty()){
        int crnt = q.front();
        cntr++; // it will count how many element is in topos sort
        q.pop();
        for(auto neigh : adj[crnt]){
            inDegree[neigh]--;
            if(inDegree[neigh] == 0){
                q.push(neigh);
            }
        }
    }
    if(cntr != V) return true;
    return false;
}

int main(){
    int n,m;
    cout << "Enter no of vertex and edges : ";
    cin >> n >> m;

    vector<int> adj[n];
    cout << "Enter edges : ";
    for(int i=0 ; i<m ; i++){
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    bool ans = detectCycle1(adj , n);
 
    if(ans){
        cout << "There is a cycle in graph....";
    }else{
         cout << "There is not a cycle in this graph..." <<endl;
    }

    return 0;
}