#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findCity(int n, int m, vector<vector<int>> &edges, int thresholdDis){
    vector<vector<int>> mat(n, vector<int>(n , INT_MAX));
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        mat[u][v] = w;
        mat[v][u] = w;
    }
    // make digonal as 0 as to reach i to i is zero
    for(int i=0 ; i<n ; i++){
        mat[i][i] = 0;
    }
    // floyd warshall algorithm
    for(int k=0 ; k<n ; k++){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(mat[i][k] != INT_MAX && mat[k][j] != INT_MAX
                && mat[i][k] + mat[k][j] < mat[i][j]){
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }
    
    int minCity = n+1;  // initially we take more than nodes that are reachble  
    int ans = -1 , cntr;
    for(int i=0 ; i<n ; i++){
        cntr = 0;
        for(int j=0 ; j<n ; j++){
            if(mat[i][j] <= thresholdDis){
                cntr++;
            }
        }
        if(cntr < minCity){
            minCity = cntr;
            ans = i;
        }else if(cntr == minCity){
            ans = i;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cout << "Enter number of cities and edges : ";
    cin >> n >> m;

    vector<vector<int>> edges;
    cout << "Enter all edges : ";
    for(int i=0 ; i<m ; i++){
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x,y,w});
    }

    int thresholdDis ;
    cout << "Enter thresHold distance : ";
    cin >> thresholdDis;

    int ans = findCity(n , m , edges , thresholdDis);

    cout << "desired city : " << ans;
    return 0;
}