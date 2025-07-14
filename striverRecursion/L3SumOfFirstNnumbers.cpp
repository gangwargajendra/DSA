#include<bits/stdc++.h>
using namespace std;

// finding sum of first n natural numbers using parameterized way
void sumByParameterized(int i, int sum){
    if(i < 1){
        cout << "Sum : " << sum << endl;
        return;
    }
    sumByParameterized(i-1, sum + i);
}

// functional way to calculate sum of first n natural numbers
int sumByFunctional(int n){
    if(n == 0) return 0;
    return n + sumByFunctional(n-1);
}

// Factoraial of n
int factorial(int n){
    // if(n == 0) return 1;
    if(n == 1) return 1;
    return n * factorial(n-1);
}

int main(){
    int n;
    cout << "enter n : ";
    cin >> n;

    sumByParameterized(n, 0);

    int sum = sumByFunctional(n);
    cout << "sum : " << sum << endl;

    int fac = factorial(n);
    cout << "factorial : " << fac << endl;
}