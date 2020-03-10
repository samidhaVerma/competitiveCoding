#include <bits/stdc++.h>
using namespace std;

vector<int> readData(int n){
    vector<int> result;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        result.push_back(temp);
    }
    return result;
}

int totalSumFunc(vector<int> arr){
    int sum = 0;
    for(int i = 0; i < arr.size(); i++)
        sum += arr[i];
    return sum;
}

int mininK(vector<int> nums, int k, int total){
    int kSum = 0;
    for(int i = 0; i < k; i++)
        kSum += nums[i];
    return total - 2*kSum;
}

int maxinK(vector<int> nums, int k, int total){
    int kSum = 0;
    for(int i = 0; i < k; i++)
        kSum += nums[nums.size() - 1 - i];
    return total - 2*kSum;
}

int main(){
    int test;
    cin >> test;

    while(test--){
        int N, K;
        cin >> N >> K;

        vector<int> W = readData(N);
        sort(W.begin(), W.end());
        int totalSum = totalSumFunc(W);
        
        int sum1 = mininK(W, K, totalSum);
        int sum2 = maxinK(W, K, totalSum);

        cout << max(abs(sum1), abs(sum2)) << endl;
    }
    return 0;
}