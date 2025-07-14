#include<bits/stdc++.h>
using namespace std;

// time complexity = E * log(V)  // E -> edges & V -> nodes

vector <int> dijkstraUsingPQ(int n, vector<vector<int>> adj[], int src){
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minHeap;
    
    vector<int> distance(n , INT_MAX);
    minHeap.push({0 , src});
    distance[src] = 0;
    int cntr = 0;  // only to check iteration

    while(!minHeap.empty()){
        cntr++;
        int dis = minHeap.top().first;   // crnt node
        int crnt = minHeap.top().second;
        minHeap.pop();

        for(auto neigh : adj[crnt]){
            int neighNode = neigh[0];
            int neighDis = neigh[1];
            if(distance[neighNode] > dis + neighDis){
                distance[neighNode] = dis + neighDis;
                minHeap.push({distance[neighNode] , neighNode});
            }
        }
    }
    cout <<"counter using priority Queue " << cntr << endl;
    return distance;
}


// it will take less time because agar koi node ki kam distance ki path mil gyi
// h and usse pahle bhi vo node kisi dusre path tak pahuch chuke h to ham 
// set data structure se purane vale path ki pair ko mySet data structure
// se hta sakte h . to isse priproty queue se less iteration lagenge
vector<int> dijkstraUsingSet(int n , vector<vector<int>> adj[] , int src){
    set<pair<int , int>> mySet;  // distance , node
    vector<int> distance(n , INT_MAX);
    mySet.insert({0, src}); // distance, node
    distance[src] = 0;
    int cntr = 0;// only to check iteration

    while(!mySet.empty()){
        cntr++;
        pair<int , int> crnt = *mySet.begin();
        // auto it = *mySet.begin();
        mySet.erase(crnt);

        for(auto neigh : adj[crnt.second]){
            int neighNode = neigh[0];
            int neighDis = neigh[1];
            if(distance[neighNode] > crnt.first + neighDis){
                // this will reduce iteration if this node is existed 
                if(distance[neighNode] != INT_MAX){
                    mySet.erase({distance[neighNode] , neighNode});
                }
                distance[neighNode] = crnt.first + neighDis;
                mySet.insert({distance[neighNode] , neighNode});
            }
        }
    }
    cout << endl << "counter using set " << cntr << endl;
    return distance;
}


int main(){
    int n,m;
    cout << "Enter vertex and edges : ";
    cin >> n >> m;


    vector<vector<int>> adj[n];
    cout << "Enter edges and weight : ";
    for(int i=0 ; i<m ; i++){
        int x ,y ,w;
        cin >> x >> y >> w;
        adj[x].push_back({y , w});
        adj[y].push_back({x , w});
    }

    int src;
    cout << "Enter source : ";
    cin >> src;

    vector<int> ans = dijkstraUsingPQ(n , adj , src);

    cout << "shortest distance using priority queue : ";
    for(auto it : ans){
        cout << it << " ";
    }

    vector<int> ans1 = dijkstraUsingSet(n , adj , src);

    cout << "\nshortest distance using set : ";
    for(auto it : ans1){
        cout << it << " ";
    }
    return 0;
}