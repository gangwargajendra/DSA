#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    cout << "Array : ";
    for(int i=0; i<n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// using two pointer
void reverseArr(int i, int j, int arr[]){
    if(i >= j) return;
    swap(arr[i], arr[j]);
    reverseArr(i+1, j-1, arr);
}

//using one pointer
void reverseArr1(int i, int n, int arr[]){
    if(i >= n/2) return;
    swap(arr[i], arr[n-i-1]);
    reverseArr1(i+1, n, arr);
}

// parameterized way
bool isPalindrome(int i, int j, string str){
    if(i < j){
        if(str[i] != str[j]) return false;
        return isPalindrome(i+1, j-1, str);
    }
    return true;
}

// functional way
bool isPalindrome1(int i, string str){
    int len = str.size();
    if(i < len/2){
        return str[i] == str[len-i-1] && isPalindrome1(i+1, str);
    }
    return true;
}

// another version
bool isPalindrome2(int i, string str){
    int len = str.size();
    if(i >= len/2) return true;
    if(str[i] != str[len-i-1]) return false;

    return isPalindrome2(i+1, str);
}


int main(){
    int arr[] = {1, 2, 3, 4, 2, 5};
    int n = sizeof(arr)/ sizeof(int);

    printArray(arr, n);
    reverseArr(0, n-1, arr);
    printArray(arr, n);

    printArray(arr, n);
    reverseArr1(0, n, arr);
    printArray(arr, n);

    string str = "abccba";
    int len = str.size();
    
    cout << isPalindrome(0, len-1, str) << endl;
    cout << isPalindrome1(0 , str) << endl;
    cout << isPalindrome2(0, str) << endl;
}