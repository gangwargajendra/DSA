#include<bits/stdc++.h>
using namespace std;

// time complexity = O(2^n)
int fibonacci(int n){
    if(n <= 1) return n;

    return fibonacci(n-1) + fibonacci(n-2);
}


int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;

    cout << fibonacci(n);
}