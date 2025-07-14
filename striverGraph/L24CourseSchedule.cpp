// gfg -> prerequisite task
// [1 , 0] represents that to do task 0 you have to first complete task 1 
// there is total n tasks and a list of prerequisite pairs P ,
// find if it is possible to finish all tasks

// intution -> if there is a cycle then it is not possible otherwiese yes

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// to find whether sechuduing is possible or not
bool detectCycle(vector<int> adj[] , int V){
    vector<int> inDegree(V , 0);
    for(int i=0 ; i<V ; i++){
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0 ; i<V ; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    int cntr = 0;
    while(!q.empty()){
        int crnt = q.front();
        cntr++; // it will count how many element is in topos sort
        q.pop();
        for(auto neigh : adj[crnt]){
            inDegree[neigh]--;
            if(inDegree[neigh] == 0){
                q.push(neigh);
            }
        }
    }
    if(cntr != V) return true;
    return false;
}

bool isPossible(vector<pair<int, int>> &pre ,int n){
    vector<int> adj[n];
    for(int i=0 ; i<pre.size() ; i++){
        adj[pre[i].first].push_back(pre[i].second);
    }

    return !detectCycle(adj , n);
}

// to find the order of that schuduing courses
vector<int> topoSort(vector<int> adj[] , int V){
    vector<int> inDegree(V , 0);
    for(int i=0 ; i<V ; i++){
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0 ; i<V ; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int crnt = q.front();
        ans.push_back(crnt);
        q.pop();
        for(auto neigh : adj[crnt]){
            inDegree[neigh]--;
            if(inDegree[neigh] == 0){
                q.push(neigh);
            }
        }
    }
    if(ans.size() != V) return {}; //  means that there is a cycle so scheduing is not possible
    return ans;
}

vector<int> findOrder(vector<pair<int, int>> &pre ,int n){
    vector<int> adj[n];
    for(int i=0 ; i<pre.size() ; i++){
        adj[pre[i].first].push_back(pre[i].second);
    }
    vector<int> ans = topoSort(adj , n);
    reverse(ans.begin() , ans.end());
    return ans;
}

int main(){
    int n , p;
    cout << "Enter total tasks and prerequisites : ";
    cin >> n >> p;

    vector<pair<int , int>> pre(p);

    cout << "Enter prerequisite : ";
    for(int i=0 ; i<p ; i++){
        cin >> pre[i].first;
        cin >> pre[i].second;
    }

    bool ans = isPossible(pre , n);

    if(ans) cout << "It is possible....";
    else cout << "It is not possible...";

    vector<int> course = findOrder(pre , n);
    cout << "\nCourse scheduing : ";
    for(auto it : course){
        cout << it << " ";
    }
    return 0;
}