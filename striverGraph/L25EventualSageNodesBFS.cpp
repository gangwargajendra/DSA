#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// firstly we can make reverse of an graph then put topo sort , it will
// all safe nodes

vector<int> topoSortByBFS(vector<int> adj[] , int V){
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
    return ans;
}

vector<int> eventualSafeNode(vector<int> adj[] , int V){
    vector<int> revAdj[V];
    for(int i=0 ; i<V ;i++){
        for(auto it : adj[i]){
            revAdj[it].push_back(i);
        }
    }

    vector<int> ans = topoSortByBFS(revAdj , V);
    sort(ans.begin() , ans.end());
    return ans;    
}

// second idea can be count outdegree of a given grpah for each node
// after that push all nodes in queue whose outdegree is 0 
// and after it reduces one outdegree of it neighbour corresponding 
// nodes. it is just reverse process of that upper approach

int main(){
    int n , m;
    cout << "Enter nodes and edges : ";
    cin >> n >> m;

    vector<int> adj[n];
    cout << "Enter edges : ";
    for(int i=0 ; i<m ; i++){
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<int> ans = eventualSafeNode(adj , n);
    cout << "Safe nodes : ";
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}