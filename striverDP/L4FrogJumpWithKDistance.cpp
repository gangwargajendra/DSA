// gfg - Geek Jump

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// unsing memoization TC=O(N*K) SC=O(N)+O(N) // for DP array and for recursion stack
int compute(vector<int> &height , vector<int> &DP , int indx,int k){
    if(indx == 0) return 0;
    
    if(DP[indx] != -1) return DP[indx];
    
    int crntMinEnergy = INT_MAX;
    for(int j = 1 ; j <= k ; j++){
        if(indx-j >= 0){
            int x = compute(height , DP , indx-j , k) + abs(height[indx] - height[indx-j]);
            crntMinEnergy = min(crntMinEnergy , x);
        }
    }
    return DP[indx] = crntMinEnergy;
}

int minimumEnergyM(vector<int>& height, int n, int k) {
    vector<int> DP(n , -1);
    return compute(height , DP , n-1,k);
}

// using tabulation TC=O(N*K) SC=O(N) // for DP array
int minimumEnergyT(vector<int> &height , int n , int k){
    vector<int> DP(n , -1);
    
    DP[0] = 0;
    for(int indx = 1 ; indx < n ; indx++){
        int crntMinEnery = INT_MAX;
        for(int j = 1 ; j <= k ; j++){
            if(indx-j >= 0){
                int x = DP[indx-j] + abs(height[indx] - height[indx-j]);
                crntMinEnery = min(crntMinEnery , x);
            }
        }
        DP[indx] = crntMinEnery;
    }
    return DP[n-1];
}

// for space optimization, we can do O(N) to O(K) by storing last K
// elements minimum Energy in a list or array ,like in L2 we store 
// only two value because there is k=2. but it unnecessary because 
// if k = n then again space complexity will be O(N).

int main(){
    int n , k;
    cout << "Enter number of stairs and Maximum jump : ";
    cin >> n >> k;

    vector<int> height(n);

    cout << "Enter height of stairs : ";
    for(int i=0 ; i<n ; i++){
        cin >> height[i];
    }

    cout << "minimum Energy to reach last stair using memoization : " << minimumEnergyM(height,n , k);

    cout << "\nminimum Energy to reach last stair using tabulation : " << minimumEnergyT(height , n , k);
    return 0;
}