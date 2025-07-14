#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &arr){
    cout << "Array : ";
    for(auto num : arr){
        cout << num << " ";
    }
    cout << endl;
}

int partition(int low, int high, vector<int> &arr){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        // this will find first greater element from left 
        while(arr[i] <= pivot && i <= high-1){
            i++;
        }

        // this will find first smaller element from right
        while(arr[j] > pivot && j >= low+1){
            j--;
        }

        if(i < j) swap(arr[i], arr[j]);
    }

    // swapping between pivot and last index of smaller left group
    swap(arr[low], arr[j]);

    return j; // partition (pivot) index
}


// time complexity = O(nlogn) :: logn = depth of recursion :: n = for arranging the array acc to pivot element 
// space complexity = O(1)
void quickSort(int low, int high, vector<int> &arr){
    if(low < high){
        int partitionIndex = partition(low, high, arr);
        quickSort(low, partitionIndex-1, arr);
        quickSort(partitionIndex+1, high, arr);
    }
}

int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter numbers : ";
    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }

    printVector(arr);

    quickSort(0 , n-1, arr);

    printVector(arr);

}