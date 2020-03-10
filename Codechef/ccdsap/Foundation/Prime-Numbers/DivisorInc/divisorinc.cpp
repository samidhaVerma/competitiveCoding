#include <bits/stdc++.h>
using namespace std;

int counter = 0;
int total = 0;

bool checkPrime(int a){
    int count = 0;
    for(int i = 2; i < sqrt(a); i++)
        if(a%i == 0)
            return false;
    return true;
}

int greatestDivisor(int b){
    for(int i = 2; i < b; i++)
        if(b%i == 0)
            return b/i;
    return 0;
}

int recursiveSplit(int x, int N){
    total += x;
    int temp = greatestDivisor(total);
    counter++;
    if((temp > N-temp) && (temp%(N-temp) == 0))
        return counter;
    return recursiveSplit(temp, N-temp);
}

int main(){
    int N, M;
    cin >> N >> M;

    int Y = M - N;
    if(Y == 0)
        cout << "0" << endl;
    else if(checkPrime(M))
        cout << "-1" << endl;
    else
        cout << recursiveSplit(N, Y) << endl;
    
    return 0;
}