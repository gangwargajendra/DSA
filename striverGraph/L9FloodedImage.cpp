#include<iostream>
#include<vector>
using namespace std;

void printMatrix(vector<vector<int>> &matrix){
    cout << "matrix : " << endl;
    for(int i=0 ; i<matrix.size() ; i++){
        for(int j=0 ; j<matrix[i].size() ; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

    /****************** NOTE **********************************
        idhar ham visited ki jagah ye bhi check kar sakte hai
        ki visited node ke pass new colour hai ya nhi agar hai 
        matlab vo visit ho chuka h  
    ******************* NOTE ***********************/

// we can also do it by using BFS // ncol= new coloue ,iCOl = initial colour
void DFS(vector<vector<int>> &fImage , int sr , int sc , int nCol , int iCol, int delRow[] ,int delCol[]){
    fImage[sr][sc] = nCol;
    
    for(int i=0 ; i<4 ; i++){
        int neiRow = sr + delRow[i];
        int neiCol = sc + delCol[i];

        if(neiRow >= 0  && neiRow < fImage.size() && neiCol >= 0 && neiCol < fImage[0].size() && 
        fImage[neiRow][neiCol] == iCol && fImage[neiRow][neiCol] != nCol){
            DFS(fImage , neiRow , neiCol , nCol , iCol , delRow , delCol);
        }
    }
}

void floodedMatrix(vector<vector<int>> &fImage , int sr , int sc , int nCol){
    int iCol = fImage[sr][sc];   // initial colour
    // for neighbours 
    int delRow[] = {-1 , 0 , 1 , 0};
    int delCol[] = {0 , 1 , 0 , -1};

    DFS(fImage , sr , sc , nCol , iCol ,delRow , delCol);
}

int main(){
    int n, m;
    cout << "Enter rows and column : ";
    cin >> n >> m ;

    vector<vector<int>> fImage(n , vector<int>(m));

    for(int i=0 ; i<n ; i++){
        cout << "Enter " << i+1 << " rows elements : ";
        for(int j=0 ; j<m ; j++){
            cin >> fImage[i][j];
        }
    }

    int sr , sc; // sr = starting row ,sc = staring column
    cout << "Enter strating row and column : ";
    cin >> sr >> sc;

    int nCol;
    cout <<"Enter new colour : ";
    cin >> nCol;

    cout << "before : " << endl;    
    printMatrix(fImage);

    floodedMatrix(fImage , sr , sc, nCol);

    cout << "After : " << endl;
    printMatrix(fImage); 
    return 0;
}