#include <iostream>
using namespace std;

#define rep(i, n) for(register int i = 0; i < n; i++)

int* readData(int size){
    int* arr = (int*) malloc(size * sizeof(int));
    rep(i, size){
        cin >> arr[i];
    }
    return arr;
}

int mySum(int arr[], int size){
    int sum = 0;
    rep(i, size)
        sum += arr[i];
    return sum;
}

int myMin(int arr[], int size){
    int min = arr[0];
    rep(i, size)
        if(arr[i] < min)
            min = arr[i];
    return min;
}

int main(){
    int test;
    cin >> test;
    while(test) {
        int N;
        cin >> N;
        int* W = readData(N);
        cout << mySum(W, N) - N * myMin(W, N) << endl;
        test--;
    }
    return 0;
}
