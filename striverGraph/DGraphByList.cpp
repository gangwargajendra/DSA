#include<iostream>
#include<vector>
using namespace std;

// to draw to grpah List
void drawList(vector<int> *adj , int n){
    cout << "graph List : "<< endl;
    for(int i=0 ; i<n; i++){
        cout << "for " << i << "=> ";
        for(int j=0 ; j < adj[i].size() ; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n,m;
    cout << "Enter total vertex and edges : ";
    cin >> n >> m;

    // make a array with fixed size (n+1) of vectors
    //   int    adj[n+1];
    vector<int> adj[n+1];

    // taking input of edges
    for(int i=0 ; i<m ; i++){
        int u, v;
        cout << "Enter edge : ";
        cin >> u >> v;
        adj[u].push_back(v);
    }

    drawList(adj , n+1);
}