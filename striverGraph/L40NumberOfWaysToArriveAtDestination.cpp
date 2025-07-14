// gfg :- number of ways to reach at destination

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

// optimise code best way to do
//for large time ,store time in long long data type 
int countPaths(int n,vector<pair<int,int>> adj[]){
    priority_queue< pair<int,int>,
                    vector<pair<int,int>> , 
                    greater<pair<int,int>>> pq;
    
    vector<int> time(n , INT_MAX);
    vector<int> pathCount(n , 0);
    pathCount[0] = 1;
    time[0] = 0;
    pq.push({0 ,0});  // time , node
    
    // time complexity = E log(V)
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int nodeTime = it.first;

        for(auto neigh : adj[node]){
            int neighNode = neigh.first;
            int neighTime = neigh.second;
            int newTime = nodeTime + neighTime;

            // this time the first time, i am coming with this 
            // short distance
            if(newTime < time[neighNode]){
                time[neighNode] = newTime;
                pathCount[neighNode] = pathCount[node];
                pq.push({newTime , neighNode});
            }else if(newTime == time[neighNode]){
                pathCount[neighNode] = pathCount[neighNode] + pathCount[node];
            }
        }
    }
    return pathCount[n-1];
}


// it will give ans but it's not much optimmimse technique
int countPaths2(int n,vector<pair<int,int>> adj[]){
    priority_queue< pair<int,int>,
                    vector<pair<int,int>> , 
                    greater<pair<int,int>>> pq;
    
    vector<int> time(n , INT_MAX);
    time[0] = 0;
    pq.push({0 ,0});  // time , node
    int totalPath = 0;


    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int nodeTime = it.first;
        if(node == n-1){
            totalPath++;
        }

        for(auto neigh : adj[node]){
            int neighNode = neigh.first;
            int neighTime = neigh.second;

            int newTime = nodeTime + neighTime;
            if(newTime <= time[neighNode]){
                time[neighNode] = newTime;
                pq.push({newTime , neighNode});
            }
        }
    }
    return totalPath;
}

int main(){
    int n , m;
    cout << "Enter numbers of nodes and edges : ";
    cin >> n >> m;

    vector<pair<int,int>> roads[n];
    cout << "Enter all edges : ";
    for(int i=0 ; i<m ;i++){
        int x , y , t;
        cin >> x >> y >> t;
        roads[x].push_back({y, t});
        roads[y].push_back({x, t});
    }

    int ans = countPaths(n , roads);

    cout << "total number of ways to reach at destination : " << ans << endl;
    return 0;
}