// used to find minimum spanning tree(MST) from a grph
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int,int>> primAlgo(vector<pair<int,int>> adj[] , int n){
    priority_queue< pair<pair<int,int>,int> 
                , vector<pair<pair<int,int>,int>> 
                , greater<pair<pair<int,int>,int>>> pq;
    
    pq.push({{0 , 0},-1}); // weight,node,parent
    int totalWeight = 0;

    vector<int> vis(n , 0);
    vector<pair<int,int>> ans;

    // number of runing this loop is almost equal to number of edges
    // time = O(ElogV+VlogV) = O(ElogV)
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int wgt = it.first.first;
        int node = it.first.second;
        int parent = it.second;
        // we have to take care for first time when when parent is -1 for node 0
        // not visited then we will take that node in ans and add weight to totalweight
        if(parent != -1 && !vis[node]){
            ans.push_back({node , parent});
            totalWeight += wgt;
        }else if(vis[node]){ 
            continue;
        }
        vis[node] = 1;

        for(auto neigh : adj[node]){
            int neighNode = neigh.first;
            int neighWeight = neigh.second;
            if(!vis[neighNode]){
                pq.push({{neighWeight , neighNode},node});
            }
        }
    }
    return ans;
}

int main(){
    int n , m;
    cout << "Enter total number of vertex and edges : ";
    cin >> n  >> m;

    vector<pair<int,int>> adj[n];

    cout << "Enter all edges : ";
    for(int i=0 ; i<m ; i++){
        int x,y,w;
        cin >>x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    vector<pair<int,int>> ans = primAlgo(adj , n);

    cout << "Edges that are part of the minimum spanning tree : ";
    for(auto it : ans){
        cout << "(" << it.first << "," << it.second<< "),";
    }
    return 0;
}