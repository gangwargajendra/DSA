// 121. Best time to buy and sell stock

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices){
    int mini = prices[0];
    int profit = 0;

    for(int i=0 ; i<prices.size() ; i++){
        int pro = prices[i] - mini;
        profit = max(profit , pro);
        mini = min(mini , prices[i]); 
    }

    return profit;
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

    int ans = maxProfit(prices);

    cout << "Maximum profit can make : " << ans;

    return 0;
}