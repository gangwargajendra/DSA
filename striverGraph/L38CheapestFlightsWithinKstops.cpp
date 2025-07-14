// gfg cheapest Flights within K stops

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int cheapestFlight(int n,vector<pair<int,int>> flights[] ,
    int src,int dst,int k){
    // fare , node , stops
    queue<pair<pair<int,int>,int>> q;
    vector<int> fare(n ,INT_MAX);
    fare[src] = 0;
    q.push({{0 ,src} , -1});
    // time complexity = E log(V) , as we remove PQ so
    // time com = E =  m from main function;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int nodeFare = it.first.first;
        int node = it.first.second;
        int nodeStop = it.second;

        for(auto neigh : flights[node]){
            int neighNode = neigh.first;
            int neighNodeFare = nodeFare + neigh.second;
            int neighNodeStop = nodeStop + 1;
            if(neighNodeStop <= k){
                if(neighNodeFare < fare[neighNode]){
                    fare[neighNode] = neighNodeFare;
                    q.push({{neighNodeFare,neighNode},neighNodeStop});
                }
            }
        }
    }
    if(fare[dst] != INT_MAX) return fare[dst];
    return -1;
}

int main(){
    int n , m;
    cout << "Enter total number of cities and flights : ";
    cin >> n >> m ;

    vector<pair<int,int>> flights[n];
    cout << "Enter flights and their fares : ";
    for(int i=0 ; i<m ; i++){
        int x , y , f;
        cin >> x >> y >> f;
        flights[x].push_back({y ,f});
    }

    for(int i=0 ; i<n ; i++){
        cout << "for city "<< i << " ";
        for(auto it : flights[i]){
            cout << " to city = "<< it.first << "& fare : "<< it.second << " ";
        }
        cout << endl;
    }

    int src, dst;
    cout << "Enter source city and destination city : ";
    cin >> src >> dst;
    int k;
    cout << "Enter maximum stops : ";
    cin >> k;

    int minFare = cheapestFlight(n , flights ,src,dst,k);

    cout << "minimum fare : " << minFare <<  endl;
    return 0;
}