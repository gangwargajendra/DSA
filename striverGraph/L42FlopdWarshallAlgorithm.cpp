// Floyd warshall algorithm
// for finding shortest distance for each pair
// if there is no edge then always put INT_MAX

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void printMatrix(vector<vector<int>> &adjMat){
    cout << "Matrix : \n";
    for(int i=0 ; i<adjMat.size() ; i++){
        cout << "for " << i+1 << " row : ";
        for(int j=0 ; j<adjMat.size() ; j++){
            if(adjMat[i][j] == INT_MAX){
                cout << "-1" << " ";
            }else{
                cout << adjMat[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// time complexity = O(n^3 )
void shortest_distance(vector<vector<int>> &adjMat){
    int n = adjMat.size();
    // make all digonal 0 bcz to reach i to i = 0
    for(int i=0 ; i<n ; i++){
        adjMat[i][i] = 0;
    }

    for(int k=0 ; k<n ; k++){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(adjMat[i][k] != INT_MAX && adjMat[k][j] != INT_MAX 
                && adjMat[i][k] + adjMat[k][j] < adjMat[i][j]){
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                }
            }
        }
    }
    // for negative cycle detection
    for(int i=0 ; i<n ; i++){
        if(adjMat[i][i] < 0){
            cout << "There is a negative cycle in this given graph....";
        }
    }
}

int main(){
    int n,m;
    cout << "Enter total vertex and edges : ";
    cin >> n >> m;

    vector<vector<int>> adjMat(n , vector<int>(n , INT_MAX));
    cout << "Enter all edges and their weight : ";
    for(int i=0 ; i<m ; i++){
        int x , y , w;
        cin >> x >> y >> w;
        adjMat[x][y] = w;  // here if adj[i][j] != INT_MAX means there is an edge
    }

    shortest_distance(adjMat);

    cout << "Distance ";
    printMatrix(adjMat);
    
    return 0;
}