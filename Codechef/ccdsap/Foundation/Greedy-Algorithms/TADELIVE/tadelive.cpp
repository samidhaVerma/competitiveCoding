#include <bits/stdc++.h>
using namespace std;

vector<int> readData(int n){
    vector<int> data;
    int temp;
    for (int i = 0; i < n; i++){
        cin >> temp;
        data.push_back(temp);
    }
    return data;
}

int sumOfVector (vector<int> vec, int startIndex, int maxIndex){
    int totalSum = 0;
    for(int i = startIndex; i < maxIndex; i++)
        totalSum += vec[i];
    return totalSum;
}

int main(){
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> aTips = readData(N);
    vector<int> bTips = readData(N);

    int aSum = sumOfVector(aTips, 0, X);
    int bSum = sumOfVector(bTips, X, N);
    int maxTips = aSum + bSum;
    int tempSum = aSum + bSum;

    for(int i = 0; i < Y; i++){
        tempSum += bTips[X-1-i] - aTips[X-1-i];
        cout << tempSum;
        if(tempSum > maxTips)
            maxTips = tempSum;   
    }

    cout << maxTips;

    return 0;
}