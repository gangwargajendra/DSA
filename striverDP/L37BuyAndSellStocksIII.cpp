// 123. Best time to buy and sell stock III

#include<bits/stdc++.h>
using namespace std;

//  1 -> can sold stock that day
//  0 -> cann't sold stock that day

// using memoization
int f(int day, int canBuy ,int cap ,vector<int> &prices,vector<vector<vector<int>>> &DP){
    if(cap == 0) return 0;   // no more transaction is allowed
    if(day == prices.size()) {
        return 0;   // means last day 
    }

    if(DP[day][canBuy][cap] != -1) return DP[day][canBuy][cap];

    int profit = 0;
    if(canBuy == 1){  // means that this we can buy that stock
        int buy = -prices[day] + f(day+1 , 0,cap, prices, DP);
        int notBuy = 0 + f(day+1 , 1 ,cap,prices,DP);

        profit = max(buy , notBuy);
    }else{   // bought stock can sell
        int sold = prices[day] + f(day+1 , 1 ,cap-1 ,prices,DP);
        int notSold = 0 + f(day+1, 0 ,cap , prices,DP);

        profit = max(sold , notSold);
    }

    return DP[day][canBuy][cap] = profit;
}

int maxProfitM(vector<int> &prices){
    int n = prices.size();

    vector<vector<vector<int>>> DP(n , vector<vector<int>>(2 , vector<int>(3 , -1)));

    return f(0 , 1,2 ,prices,DP); // day, canBuy ,Capacity
}

// using tabulation
int maxProfitT(vector<int> &prices){
    int n = prices.size();
    if(n == 0) return 0;

    vector<vector<vector<int>>> DP(n+1 , vector<vector<int>>(2 , vector<int>(3 , 0)));
    // base case is automaticly being Zero.a

    for(int day = n-1 ; day>=0 ; day--){
        for(int canBuy = 0 ; canBuy<2 ; canBuy++){
            for(int cap=1 ; cap<=2 ; cap++){
                if(canBuy == 1){
                    int buy = -prices[day] + DP[day+1][0][cap];
                    int notBuy = 0 + DP[day+1][1][cap];

                    DP[day][canBuy][cap] = max(buy , notBuy);
                }else{
                    int sold = +prices[day] + DP[day+1][1][cap-1];
                    int notSold = 0 + DP[day+1][0][cap];

                    DP[day][canBuy][cap] = max(sold , notSold);
                }
            }
        }
    }

    return DP[0][1][2];
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

    cout << "Maximum profit can make using memoization : " << maxProfitM(prices);
    cout << "\nMaximum profit can make using tabulation : " << maxProfitT(prices);

    return 0;
}