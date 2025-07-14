// gfg -> Geek's training

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// using memoization TC=O(N*4*3) SC=O(N)+O(N*4)
int compute(vector<vector<int>> &arr ,vector<vector<int>> &DP ,int day ,int last){
    if(day == 0){
        int maxPoints = 0;
        for(int task=0 ; task<3 ; task++){
            if(task != last){
                maxPoints = max(maxPoints ,arr[day][task]);
            }
        }
        return maxPoints;
    }

    if(DP[day][last] != -1) return DP[day][last];

    int maxPoint = 0;
    for(int task=0 ; task<3 ;task++){
        if(task != last){
            int point = arr[day][task] + compute(arr, DP, day-1, task);
            maxPoint = max(maxPoint, point);
        }
    }
    return DP[day][last] = maxPoint;
}

int maximumPointsM(vector<vector<int>> &arr ,int n){
    vector<vector<int>> DP(n ,vector<int>(4,-1));
    return compute(arr ,DP ,n-1 , 3);  // 3 means nth day, he did nothing. so that on n-1 day he can do job 0,1,2.
}

// using tabulation TC=O(N*4*3) SC=O(N*4)
int maximumPointsT(vector<vector<int>> &arr , int n){
    vector<vector<int>> DP(n , vector<int>(4,0));

    // for only day 0
    DP[0][0] = max(arr[0][1] , arr[0][2]);
    DP[0][1] = max(arr[0][0] , arr[0][2]);
    DP[0][2] = max(arr[0][0] , arr[0][1]);
    DP[0][3] = max(arr[0][0] , max(arr[0][1] , arr[0][2]));

    // computing point from day 1 to n-1
    for(int day=1 ; day<n ; day++){
        for(int last=0 ; last<4 ; last++){
            int maxPoint = 0;
            for(int task=0 ; task<3 ; task++){
                if(task != last){
                    int point = arr[day][task] + DP[day-1][task];
                    maxPoint = max(maxPoint , point);
                }
            }
            DP[day][last] = maxPoint;
        }
    }
    return DP[n-1][3];
}

// using space optimization TC=O(N*4*3) SC=O(2*4)
int maximumPointsS(vector<vector<int>> &arr , int n){
    vector<int> prev(4,0);

    // for only day 0
    prev[0] = max(arr[0][1] , arr[0][2]);
    prev[1] = max(arr[0][0] , arr[0][2]);
    prev[2] = max(arr[0][0] , arr[0][1]);
    prev[3] = max(arr[0][0] , max(arr[0][1] , arr[0][2]));

    // computing point from day 1 to n-1
    for(int day=1 ; day<n ; day++){
        vector<int> temp(4,0);

        for(int last=0 ; last<4 ; last++){
            int maxPoint = 0;
            for(int task=0 ; task<3 ; task++){
                if(task != last){
                    int point = arr[day][task] + prev[task];
                    maxPoint = max(maxPoint , point);
                }
            }
            temp[last] = maxPoint;
        }
        // update DP with temp
        prev = temp;
    }
    return prev[3];
}

int main(){
    int n;
    cout << "Enter number of days : ";
    cin >> n;

    vector<vector<int>> arr;
    cout << "Enter each days merit points : ";
    for(int i=0 ; i<n ; i++){
        int x , y ,z;
        cin >> x >> y >> z;
        arr.push_back({x,y,z});
    }

    cout << "Maximum merits points using memoization : " << maximumPointsM(arr, n);
    cout << "\nMaximum merits points using tabulation : " << maximumPointsT(arr, n);
    cout << "\nMaximum merits points using space optimazatoin : " << maximumPointsS(arr, n);

}