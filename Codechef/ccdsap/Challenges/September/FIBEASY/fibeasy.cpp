#include <bits/stdc++.h>
using namespace std;

int generateFibonacci(int n){
    int prevprevNumber = 0;
    int prevNumber = 1;
    int currentNumber = 1;

    if(n == 0)
        return 0;
    
    if(n == 1 || n == 2)
        return 1;

    for(int i = 2; i < n+1; i++){
        currentNumber = prevNumber + prevprevNumber;
        
        prevprevNumber = prevNumber%10;
        prevNumber = currentNumber%10;
        currentNumber = currentNumber%10;
    }

    return currentNumber;
}

int main (){
    long long int test;
    cin >> test;

    while(test--){
        long long int n;
        cin >> n;
        
        long long int k = (long long int) log2(n);
        long long int l = pow(2,k);
        int fibonacci = generateFibonacci(l%60);
        
        cout << fibonacci << endl;
    }

    return 0;
}