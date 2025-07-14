#include<bits/stdc++.h>
using namespace std;

int printVector(vector<int> &arr){
    cout << "Array : ";
    for(auto num : arr){
        cout << num << " ";
    }
    cout << endl;
}

void merge(int low, int mid, int high, vector<int> &arr){
    int l1 = mid - low + 1;
    int l2 = high - mid;

    int arr1[l1];
    int arr2[l2];
    for(int i=0; i<l1 ; i++){
        arr1[i] = arr[low+i];
    }
    for(int i=0 ; i<l2; i++){
        arr2[i] = arr[mid+i+1];
    }

    int i = 0, j = 0, k = low;
    while(i < l1 && j < l2){
        if(arr1[i] < arr2[j]){
            arr[k++] = arr1[i++];
        }else{
            arr[k++] = arr2[j++];
        }
    }
    while(i < l1){
        arr[k++] = arr1[i++];
    }
    while(j < l2){
        arr[k++] = arr2[j++];
    }
}

// timeComplexity = O(logn*n) :: logn = depth of each recursion :: n : for merging
// space complexity = O(n)
void mergeSort(int low, int high, vector<int> &arr){
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(low, mid, arr);
    mergeSort(mid+1, high, arr);

    merge(low, mid, high, arr);
}


int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter numbers : ";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    cout << "Before ";
    printVector(arr);

    mergeSort(0 , n-1, arr);
    
    cout << "After "; 
    printVector(arr);
}