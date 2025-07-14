// gfg minimum multiplication to reach End 
// given start, end and an array of n number.At each step ,start is multiplied
// with any number in the array and then mod operation with 100000 is done 
// to get the new start

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

// simple bfs
int minminimumMultiplications1(vector<int> &arr , int start ,int end){
    if(start == end){
        return 0;
    }
    int mod = 100000;
    vector<int> visited(mod , 0);
    visited[start] = 1;
    queue<pair<int , int>> q;
    q.push({start , 0});   // start value , steps
    
    while(!q.empty()){
        int num = q.front().first;
        int step =  q.front().second;
        q.pop();
        for(auto it : arr){
            int nNum = (num * it) % mod;
            if(nNum == end){
                return step+1;
            }
            if(!visited[nNum]){
                visited[nNum] = 1;
                q.push({nNum , step+1});
            }
        }
    }
    return -1;
}

// little modification 
int minminimumMultiplications2(vector<int> &arr , int start ,int end){
    if(start == end){
        return 0;
    }
    int mod = 100000;
    vector<int> dis(mod , INT_MAX);
    dis[start] = 0;
    queue<pair<int,int>> q;
    q.push({start , 0});   // start value , steps
    
    // time complexity = O(10000 X arr.size()) // but it hypothetical
    // bcz all number between 0 to 9999 can be drwan. time com will depend on input
    while(!q.empty()){
        int num = q.front().first;
        int step =  q.front().second;
        q.pop();
        for(auto it : arr){
            int nNum = (num * it) % mod;
            if(nNum == end) return step+1;
            if(step+1 < dis[nNum]){
                dis[nNum] = step+1;
                q.push({nNum , step+1});
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cout << "Enter total number of element array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter all elements of array : ";
    for(int i=0 ;i<n ; i++){
        cin >> arr[i];
    }

    int st,end;
    cout << "Enter start and end : ";
    cin >> st >> end;

    int ans = minminimumMultiplications1(arr , st , end);
    cout << "minimum steps to reach end : " << ans << endl;

    int ans2 = minminimumMultiplications2(arr , st , end);
    cout << "minimum steps to reach end : " << ans2;
    return 0;
}