#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
public:
    vector<int> parent , rank ,size;  // rank is like height with slight change

public:
    DisjointSet(int n) {
        rank.resize(n+1 , 0);
        parent.resize(n+1);
        size.resize(n+1 , 1);

        for(int i=0 ; i<n+1 ; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u , int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void UnionBySize(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        // this peace of line code is same as else condition so we can ignore this
        // else if(size[ulp_u] > size[ulp_v]){
        //     parent[ulp_v] = ulp_u;
        //     size[ulp_u] += size[ulp_v];
        // }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];  
        }
    }
};

int main(){
    DisjointSet ds(7);  // 7 is the number of node

    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);
    // if 3 and 7 are belonging to same component
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout << "belonging from same...." << endl;
    }else{
        cout << "not bolonging from same...." << endl;
    }
    ds.UnionBySize(3,7);
    // if 3 and 7 are belonging to same component
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout << "belonging from same...." << endl;
    }else{
        cout << "not bolonging from same...." << endl;
    }

    cout << "parent vector : ";
    for(int i=1 ; i<8 ; i++){
        cout << ds.parent[i] << " ";
    }
    cout << "\nsize vector : ";
    for(int i=1 ; i<8 ; i++){
        cout << ds.size[i] << " ";
    }
    return 0;
}