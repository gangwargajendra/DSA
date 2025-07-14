#include<iostream>
using namespace std;

// for drawing the graph adjacent matrix
void drawGraph(int **adj , int n){
    cout << "graph representation : " << endl;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n, m;
    cout << "Enter total vertex and edges : ";
    cin >> n >> m;

    // for making 1D array of size (int *) which will store pointer of 1D array
    int **adj = new int*[n+1];
    
    // for making 1D array of size (int) and store it on upper array
    for(int i=0 ; i<n+1 ; i++){
        adj[i] = new int[n+1]();
    }

    // for taking input of edges
    for(int i=0 ; i<m ; i++){
        int u,v;
        cout << "Enter edges between : ";
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    drawGraph(adj , (n+1));

}