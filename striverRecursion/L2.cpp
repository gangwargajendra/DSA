#include<bits/stdc++.h>
using namespace std;

void printName(int i, int n){
    if(i > n) return;
    cout << i <<": Gajendra gangwar" << endl;
    printName(i+1, n);
}

void printNumber1toN(int i, int n){
    if(i > n) return;
    cout << i << " ";
    printNumber1toN(i+1, n);
}

void printNumberNto1(int i, int n){
    if(i < 1) return;
    cout << i << " ";
    printNumberNto1(i-1, n);
}

void printNumber1toNbackTrack(int i, int n){
    if(i < 1) return;
    printNumber1toNbackTrack(i-1, n);
    cout << i << " ";
}

void printNumberNto1backTrack(int i, int n){
    if(i > n) return;
    printNumberNto1backTrack(i+1, n);
    cout << i << " ";
}

int main(){
    int n;
    cout << "Enter  n : ";
    cin >> n;

    printName(1, n);

    printNumber1toN(1, n);
    cout << endl;

    printNumberNto1(n, n);
    cout << endl;

    printNumber1toNbackTrack(n, n);
    cout << endl;

    printNumberNto1backTrack(1 , n);
    cout << endl;
}