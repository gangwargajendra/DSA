// 714. Best time to buy and sell stock with Transaction Fee

#include<bits/stdc++.h>
using namespace std;

//  1 -> can sold stock that day
//  0 -> cann't sold stock that day

// using memoization
int f(int day, int canBuy , int fee ,vector<int> &prices,vector<vector<int>> &DP){
    if(day >= prices.size()) {
        return 0;   // means last day 
    }

    if(DP[day][canBuy] != -1) return DP[day][canBuy];

    int profit = 0;
    if(canBuy == 1){  // means that this we can buy that stock
        int buy = -prices[day] + f(day+1 , 0, fee,prices, DP);
        int notBuy = 0 + f(day+1 , 1 ,fee,prices,DP);

        profit = max(buy , notBuy);
    }else{   // bought stock can sell
        int sold = prices[day] - fee + f(day+1 , 1 ,fee ,prices,DP);
        int notSold = 0 + f(day+1, 0 , fee,prices,DP);

        profit = max(sold , notSold);
    }

    return DP[day][canBuy] = profit;
}

int maxProfitM(vector<int> &prices, int fee){
    int n = prices.size();

    vector<vector<int>> DP(n , vector<int>(2 , -1));

    return f(0 , 1,fee, prices,DP);
}

// using tabulation
int maxProfitT(vector<int> &prices, int fee){
    int n = prices.size();
    if(n == 0) return 0;

    vector<vector<int>> DP(n+2 , vector<int>(2 , 0));
    // base case is automaticly being Zero.a

    for(int day = n-1 ; day>=0 ; day--){
        for(int canBuy = 0 ; canBuy<2 ; canBuy++){
            if(canBuy == 1){
                int buy = -prices[day] + DP[day+1][0];
                int notBuy = 0 + DP[day+1][1];

                DP[day][canBuy] = max(buy , notBuy);
            }else{
                int sold = +prices[day] - fee + DP[day+1][1];
                int notSold = 0 + DP[day+1][0];

                DP[day][canBuy] = max(sold , notSold);
            }
        }
    }

    return DP[0][1];
}

int main(){
    int n;
    cout << "Enter number of days : ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter each day price : ";
    for(int i=0 ; i<n ; i++){
        cin >> prices[i];
    }

    int fee;
    cout << "Enter transaction fee : ";
    cin >> fee;

    cout << "Maximum profit can make using memoization : " << maxProfitM(prices , fee);
    cout << "\nMaximum profit can make using tabulation : " << maxProfitT(prices , fee);

    return 0;
}