#include<iostream>
#include<vector>
using namespace std;

//for drawing graph adjacent matrix
void drawGraph(vector<vector<int>> &adj){
    cout << "graph representation : " << endl;
    for(int i=0 ; i < adj.size() ; i++){
        for(int j=0 ; j < adj.size() ; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n, m;
    cout << "Enter vertex and edge : ";
    cin >> n >> m;
    // initialising 2D vectors
    vector<vector<int>> adj(n+1 , vector<int>(n+1 , 0));

    // for input edges
    for(int i=0 ; i<m ; i++){
        int u,v;
        cout << "Enter edges between : ";
        cin >> u >> v;
        adj[u][v] = 1;
    }

    drawGraph(adj);
}