#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

// to draw to grpah List
void drawList(vector<int> adj[] , int n){
    cout << "graph List : "<< endl;
    for(int i=0 ; i<n; i++){
        cout << "for " << i << "=> ";
        for(auto it : adj[i]){
            cout << it << " ";
        }
        cout << endl;
    }
}

// for printing vector
void printVector(vector<int> arr){
    cout << "vector element : ";
    for(auto it : arr){
        cout << it << " ";
    }
    cout <<endl;
} 

// BFS (level order traversal)
vector<int> BFS(vector<int> adj[] , int n , int startNode){
    // for storing nodes during bfs traversal
    vector<int> BFSArray;
    // for tracking which is visited or not
    int *visited = new int[n+1](); 

    queue<int> myQueue;
    // put straing node in queue and also set it as visited
    myQueue.push(startNode);
    visited[startNode] = 1;

    while(!myQueue.empty()){
        int currentNode = myQueue.front();
        BFSArray.push_back(currentNode);
        myQueue.pop();
        // for traversing all currentNode's neighbours
        for(auto it : adj[currentNode]){
            if(!visited[it]){
                myQueue.push(it);
                visited[it] = 1;
            }
        }
        // int i = 0;
        // while(i < adj[currentNode].size()){
        //     if(!visited[adj[currentNode][i]]){
        //         myQueue.push(adj[currentNode][i]);
        //         visited[adj[currentNode][i]] = 1;
        //     }
        //     i++;  
        // }
    }
    return BFSArray;
}

// DFS (depth order traversal)
void DFSHelper(vector<int> adj[] , int n , int startNode , vector<int> &DFSArray , int *visited){
    visited[startNode] = 1;
    DFSArray.push_back(startNode);

    // for traversing all of its's neighbour
    for(auto it : adj[startNode]){
        if(!visited[it]){
            DFSHelper(adj , n , it , DFSArray , visited);
        }
    }
}

vector<int> DFSRecursion(vector<int> adj[] , int n , int startNode){
    int *visited = new int[n+1]();
    vector<int> DFSArray;
    DFSHelper(adj , n , startNode ,DFSArray , visited);
    return DFSArray;
}

// DFS using Stack
vector<int> DFSStack(vector<int> adj[] , int n , int startNode){
    int *visited = new int[n+1]();
    stack<int> myStack;
    vector<int> DFSArray;

    // push the staring node in stack
    myStack.push(startNode);
    visited[startNode] = 1;

    while(!myStack.empty()){
        int currentNode = myStack.top();
        myStack.pop();
        DFSArray.push_back(currentNode);

        // for traversing all of it's neighbours
        for(auto it : adj[currentNode]){
            if(!visited[it]){
                myStack.push(it);
                visited[it] = 1;
            }
        }
    }
    return DFSArray;
}

// for province in a graph
int province(vector<int> adj[] , int n){
    vector<int> visited(n+1 , 0);
    int counter = 0;
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            // we can do it on constant time by writing BFS code here then we don't need to copy returnArray to visited
            vector<int> returnArray = BFS(adj , n , i);
            for(auto it : returnArray){
                visited[it] = 1;
            }
            counter++;
        }
    }
    return counter;
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
        adj[v].push_back(u);
    }

    drawList(adj , n+1);

    // // BFS traversal
    // vector<int> BFSArray = BFS(adj , n+1 , 1);
    // printVector(BFSArray);

    // // DFS traversal
    // vector<int> DFSArray = DFSRecursion(adj , n+1 , 1);
    // printVector(DFSArray);
    // DFSArray = DFSRecursion(adj , n+1 , 4);
    // printVector(DFSArray);
    // DFSArray = DFSStack(adj , n+1 , 1);
    // printVector(DFSArray);
    // DFSArray = DFSStack(adj , n+1 , 4);
    // printVector(DFSArray);

    // for province
    int totalProvince = province(adj , n);
    cout << "Total no of province = " << totalProvince << endl;
}