#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

// first simple approach
vector<int> shortestPath(vector<int> adj[] , int n){
    vector<int> vis(n , 0);
    vector<int> ans(n , -1);
    queue<pair<int, int>> q;
    q.push({0 , 0}); // taking src 0 which will at a distance 0
    vis[0] = 1;

    while(!q.empty()){
        int crnt = q.front().first;
        int dist = q.front().second;
        ans[crnt] = dist;
        q.pop();

        for(auto neigh : adj[crnt]){
            if(!vis[neigh]){
                vis[neigh] = 1;
                q.push({neigh,dist+1});
            }
        }
    }
    return ans;
}

// second approach (standard way)
vector<int> shortestPath1(vector<int> adj[] , int n){
    vector<int> dist(n , INT_MAX);
    dist[0] = 0;  // taking src 0 which will at a distance 0
    queue<int> q;
    q.push(0); // push src in queue

    while(!q.empty()){
        int crnt = q.front();
        q.pop();

        for(auto neigh : adj[crnt]){
            if(dist[crnt] + 1 < dist[neigh]){
                dist[neigh] = 1 + dist[crnt];
                q.push(neigh);
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        if(dist[i] == INT_MAX) dist[i] = -1;
    }
    return dist;
}

int main(){
    int n , m;
    cout << "Enter total nodes and edges : ";
    cin >> n >> m;

    vector<int> adj[n];
    cout << "Enter edges : ";
    for(int i=0 ; i<m ; i++){
        int x ,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> ans = shortestPath(adj , n);

    cout << "Shortest path  : ";
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}