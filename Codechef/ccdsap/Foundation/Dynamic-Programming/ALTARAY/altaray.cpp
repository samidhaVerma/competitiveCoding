#include <bits/stdc++.h>
using namespace std;

int dynamicLoop(int arr[], int size, int index, int memo[]){
    if (index == size-1)
        memo[index] = 1;
    else if ((arr[index+1] < 0 && arr[index] > 0) || (arr[index+1] > 0 && arr[index] < 0))
        memo[index] = 1 + memo[index+1];
    else
        memo[index] = 1;
    return memo[index];
}

int main(){
    int test;
    cin >> test;

    while(test--){
        int N;
        cin >> N;
        
        int nums[N];
        for(int i = 0; i < N; i++)
            cin >> nums[i];
    
        int memo[N] = {};
        for(int i = N-1; i >= 0; i--)
            memo[i] = dynamicLoop(nums, N, i, memo);
        
        for(int i = 0; i < N; i++)
            cout << memo[i] << " ";
        cout << endl;
    }

    return 0;
}