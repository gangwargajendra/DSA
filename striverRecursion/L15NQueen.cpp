#include<bits/stdc++.h>
using namespace std;

void displayAnswers(vector<vector<string>> &ans){
    cout << "chess borad : " << endl;
    for(auto pAns : ans){  // pAns = particular ans
        cout << "Answer : " << endl;
        for(auto row : pAns){
            for(auto square : row){
                cout << square << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
}

// we have to check in only three direction because (0 to col-1) tak ho queen place h 
//   \ (A)
//    \
// -B--Q
//    /
//   / (c)
bool isSafe(int row, int col, vector<string> &board, int n){
    // check upper digonal : A direction
    int dupRow = row;
    int dupCol = col;
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q') return false;
        row--, col--;
    }

    // checking b direction
    col = dupCol;
    row = dupRow;
    while (col >= 0){
        if(board[row][col] == 'Q') return false;
        col--;
    }

    // checking C direction
    col = dupCol;
    row = dupRow;
    while (row<n && col>=0){
        if(board[row][col] == 'Q') return false;
        row++, col--;
    }
    
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row=0 ; row<n ; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;

    vector<vector<string>> ans;
    vector<string> borad(n);
    string s(n, '.'); // create n sized string with initialize with '.' each index
    for(int i=0 ; i<n ; i++){
        borad[i] = s; 
    }


    solve(0, borad, ans, n);

    displayAnswers(ans);

    return 0;
}