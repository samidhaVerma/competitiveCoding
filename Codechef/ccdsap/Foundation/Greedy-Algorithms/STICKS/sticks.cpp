#include<bits/stdc++.h>
using namespace std;

vector<int> readData(int n){
    vector<int> data;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        data.push_back(temp);
    }
    return data;
}

int main(){
    int test;
    cin >> test;

    while(test--){
        int N;
        cin >> N;

        vector<int> sticks = readData(N);
        sort(sticks.begin(), sticks.end());

        int tempFreq = 0, area = 1;
        for(int i = sticks.size()-1; i > 0; i--){
            if(sticks[i] == sticks[i-1]){
                area = area * sticks[i];
                i--;
                tempFreq++;
            }     

            if(tempFreq == 2)
                break;
        }

        if(tempFreq == 2)
            cout << area << endl;
        else 
            cout << -1 << endl;
    }

    return 0;
}