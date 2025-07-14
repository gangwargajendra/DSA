// gfg - Geek Jump

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// unsing memoization TC=O(N) SC=O(N)+O(N) // for DP array and for recursion stack
int compute(vector<int> &height , vector<int> &DP , int indx){
    if(indx == 0) return 0;
    
    if(DP[indx] != -1) return DP[indx];
    
    int left = compute(height , DP , indx-1) + abs(height[indx] - height[indx-1]);
    
    int right = INT_MAX;
    if(indx > 1)
        right = compute(height , DP , indx-2) + abs(height[indx] - height[indx-2]);

    return DP[indx] = min(left , right);
}

int minimumEnergyM(vector<int>& height, int n) {
    vector<int> DP(n , -1);
    return compute(height , DP , n-1);
}

// using tabulation TC=O(N) SC=O(N) // only for DP array
int minimumEnergyT(vector<int> &height , int n){
    vector<int> DP(n , -1);
    
    DP[0] = 0;
    for(int i=1 ; i<n ; i++){
        int left = DP[i-1] + abs(height[i] - height[i-1]);
        int right = INT_MAX;
        if(i > 1) 
            right = DP[i-2] + abs(height[i] - height[i-2]);
        DP[i] = min(left , right);
    }
    return DP[n-1];
}

// making more scape optimise TC=O(N) SC=O(1)
int minimumEnergyS(vector<int> &height , int n){
    int prev = 0;
    int scndPrev = 0;
    int crntI;
    for(int i=1 ; i<n ; i++){
        int left = prev + abs(height[i] - height[i-1]);
        int right = INT_MAX;
        if(i > 1) 
            right = scndPrev + abs(height[i] - height[i-2]);

        int crntI = min(left , right);
        scndPrev = prev;
        prev = crntI;
    }
    return crntI;
}

int main(){
    int n;
    cout << "Enter number of stairs : ";
    cin >> n ;

    vector<int> height(n);

    cout << "Enter height of stairs : ";
    for(int i=0 ; i<n ; i++){
        cin >> height[i];
    }

    cout << "minimum Energy to reach last stair using memoization : " << minimumEnergyM(height,n);

    cout << "\nminimum Energy to reach last stair using tabulation : " << minimumEnergyT(height , n);
    
    cout << "\nminimum Energy to reach last stair using space optimization : " << minimumEnergyS(height , n);
    return 0;
}