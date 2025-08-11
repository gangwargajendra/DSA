#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// time complexity = O(V + E)

vector<int> topoSortByBFS(vector<int> adj[] , int V){
    vector<int> inDegree(V , 0);
    for(int i=0 ; i<V ; i++){
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }

    queue<int> q;
    // we can also skip visited vector
    // there is no need fo vis vector so we can remove it totally
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
        q.pop();
        ans.push_back(crnt);
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
    return ans;
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

    vector<int> ans = topoSortByBFS(adj , n);

    cout << "Topological Sort : ";
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
