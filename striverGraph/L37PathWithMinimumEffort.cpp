// gfg = path with minimum effort
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

//time complexity = O(E * log(v))   as E = N X M X 4  & V = N X M
// time com ======= O(n X m X 4 X log(n X M))
// check destination during pop not inserting in pq

int minimumEffort(int rows, int columns, vector<vector<int>> &heights) {
    vector<vector<int>> efforts(rows , vector<int>(columns , INT_MAX));
    efforts[0][0] = 0;
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> 
    ,greater<pair<int,pair<int,int>>>> pq;

    pq.push({0 , {0 ,0}}); // efforts ,row,column

    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    // jaise hi ek baar PQ mai destination kisi path se mil jata h 
    // to us pair ko pop karne ke liye usse choote efforts ke sabhi pairs
    // ko pahle pop karna padega
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int minEfforts = it.first;
        int x = it.second.first;
        int y = it.second.second;
        // idhar likh dene se ans mil jayega kyuki agar hamne destination get kar 
        // liya h , kyuki minHeap hamesha minimum pairs ko degi agar koi aur bhi 
        // minHeap mai hoga
        if(x == rows-1 && y == columns-1){
            return minEfforts;
        }
        // but ye below likh dene se kaam nhi karega kyuki pahle destination
        // mil sakta h but uska koi dusra path bhi ho sakta hai

        for(int i=0 ; i<4 ; i++){
            int nX = x + delRow[i];
            int nY = y + delCol[i];
            if(nX>=0 && nX<rows && nY>=0 && nY<columns){  // for valid row and column
                // what is the efforts from coming to new cell from previous
                int newEffort = abs(heights[nX][nY] - heights[x][y]);
                // what is the maximum efforts of that path 
                int x = max(minEfforts , newEffort);
                // if maximum efforts of that path is less then current path effots 
                // then update it with new path efforts
                if(efforts[nX][nY] > x){
                    pq.push({x ,{nX,nY}});
                    efforts[nX][nY] = x;                    
                }
            }
        }
    }
    return -1;
}

int main(){
    int n , m;
    cout << "Enter rows and columns : ";
    cin >> n >> m;

    vector<vector<int>> heights(n , vector<int>(m));
    cout << "Enter heights of each cell : ";
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            int x;
            cin >> x;
            heights[i][j] = x;
        }
    }

    int minEffors = minimumEffort(n , m ,heights);

    cout << "minimum efforts : "<< minEffors<< endl;

    return 0;
}