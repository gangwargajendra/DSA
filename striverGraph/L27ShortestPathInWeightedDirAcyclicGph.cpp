#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

// time complexity = O(N + M)

void printEdges(vector<int> edges[] , int m){
    cout << "Edges with weight : " << endl;
    for(int i=0 ; i<m ; i++){
        cout << "[(" << edges[i][0] << "," << edges[i][1] << ")," << edges[i][2] << "],";
    }
    cout << endl;
}

// performing topo sort and returnig stack by reference
void topoSort(vector<pair<int , int>> adj[] , int src ,
vector<int> &vis , stack<int> &myStack){
    vis[src] = 1;
    for(auto it : adj[src]){
        int v = it.first;
        if(!vis[v]){
            topoSort(adj , v , vis ,myStack);
        }
    }
    myStack.push(src);
}

vector<int> shortestPath(int N , int M , vector<int> edges[] , int src){
    // for making adjacency list
    vector<pair<int , int>> adj[N];
    for(int i=0 ; i<M ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v , w});
    }

    // step  1: to perform topo sort and get stack
    stack<int> myStack;
    vector<int> vis(N , 0);
    topoSort(adj , src , vis , myStack);
    // time complexity = O(N + M)  M = edges
    for(int i=0 ; i<N ; i++){
        if(!vis[i]){
            topoSort(adj , i ,vis ,myStack);
        }
    }
    
    //step 2 : to do thing in distance
    vector<int> distance(N , INT_MAX);
    distance[src] = 0; // put source as distance = 0
    // time complexity = O(N + M)  M = edges
    while(!myStack.empty()){
        int crnt = myStack.top();
        myStack.pop();
        for(auto neigh : adj[crnt]){
            int v = neigh.first;
            int w = neigh.second;
            // if(distance[crnt]+w < distance[v]){
            //     distance[v] = distance[crnt] + w;
            // }
            // ********OR*********
            if(distance[crnt] != INT_MAX){
                distance[v] = min(distance[v] , distance[crnt] + w);
            }
        }
    }

    // if any node is not reachible from src then put -1
    for(int i=0 ; i<N ; i++){
        if(distance[i] == INT_MAX) distance[i] = -1;
    }
    return distance;
}

int main(){
    int n,m;
    cout << "Enter total Number of nodes and edges : ";
    cin >> n >> m ;

    vector<int> edges[m];
    cout << "Enter edges with weight : ";
    for(int i=0 ; i<m ; i++){
        int x , y , w;
        cin >> x >> y >> w;
        edges[i].push_back(x);
        edges[i].push_back(y);
        edges[i].push_back(w);
    }

    printEdges(edges , m);
    int src;
    cout << "Enter source : ";
    cin >> src;

    vector<int> ans = shortestPath(n , m , edges , src);

    cout << "Shortest distance : ";
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}