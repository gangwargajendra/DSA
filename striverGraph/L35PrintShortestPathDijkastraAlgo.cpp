//find the shortest path from vertex '1' to vertex 'n' in weighted directed graph
// return a vector in which first element -> weight and following are path element

#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<algorithm>
using namespace std;

vector<int> shortestPath(vector<pair<int , int>> adj[] , int n){
    vector<int> parent(n , -1);
    vector<int> distance(n , INT_MAX);
    set<pair<int, int>> mySet;
    mySet.insert({0 , 0}); // distance , node
    distance[0] = 0;

    while(!mySet.empty()){
        pair<int , int> crnt = *(mySet.begin());
        int node = crnt.second;
        int nodeW = crnt.first;
        mySet.erase(crnt);

        for(auto it : adj[node]){
            int neigh = it.first;
            int neighW = it.second;
            if(distance[neigh] > distance[node] + neighW){
                if(distance[neigh] != INT_MAX){
                    mySet.erase({distance[neigh] , neigh});
                }
                distance[neigh] = distance[node] + neighW;
                parent[neigh] = node;
                mySet.insert({distance[neigh] , neigh});
            }
        }
    }

    if(distance[n-1] == INT_MAX){
        return {-1};
    }
    //time complexity = O(n) extra then dijkstra algorithm
    vector<int> ans;
    int i=n-1;
    while(i != -1){
        ans.insert(ans.begin(),i);
        i = parent[i];
    }
    ans.insert(ans.begin(),distance[n-1]);
    return ans;
}

int main(){
    int n,m;
    cout << "Enter number of vertex and edges : ";
    cin >> n >> m;

    vector<pair<int , int>> adj[n];

    cout << "Enter edges : ";
    for(int i=0 ; i<m ; i++){
        int x , y ,w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    vector<int> ans = shortestPath(adj , n);

    if(ans.size() == 1 && ans[0] == -1){
        cout << "path is not exist....";
    }else{
        cout << "Weight of the path : " << ans[0] << endl;
        cout << "path is given by : ";
        for(int i=1 ; i<ans.size() ; i++){
            cout << ans[i] << "->";
        }
    }
    return 0;
}