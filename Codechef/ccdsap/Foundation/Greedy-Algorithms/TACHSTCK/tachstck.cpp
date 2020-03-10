#include <bits/stdc++.h>
using namespace std;

vector<int> readData(int n){
    vector<int> resultVector;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        resultVector.push_back(temp);
    }
    return resultVector;
}

int creatingPairs(vector<int> nums, int minHeight){
    int count = 0;
    for(int i = 0; i < nums.size()-1; i++)
        if(nums[i+1]-nums[i] <= minHeight){
            count++;
            i++;
        }
    return count;
}

int main(){
    int N, D;
    cin >> N >> D;

    vector<int> L = readData(N);
    sort(L.begin(), L.end());

    int count = creatingPairs(L, D);
    cout << count << endl;

    return 0;
}