#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

vector<LL> readData(LL n){
    vector<LL> data;
    int temp;
    for(LL i = 0; i < n; i++){
        cin >> temp;
        data.push_back(temp);
    }
    return data;
}

vector<LL> subtractVectors(vector<LL> A, vector<LL> B, LL n){
    vector<LL> difference;
    for(LL i = 0; i < n; i++){
        difference.push_back(A[i] - B[i]);
    }
    return difference;
}

vector<LL> concatenateVectors(vector<LL> C, vector<LL> D){
    for(LL i = 0; i < D.size(); i++)
        C.push_back(D[i]);
    return C;
}

LL timeMachine(vector<LL> diff, vector<LL> con){
    LL result = 0;
    LL temp = 0;
    for(LL i = 0; i < diff.size(); i++){
        for(LL j = temp; j < con.size(); j++){
            if(diff[i] >= con[j]){
                result += diff[i] - con[j];
                temp = j + 1;
                break;
            }
        }      
    }
    return result;
}

int main() {
    int test;
    cin >> test;

    while(test--){
        LL N, K, M;
        cin >> N >> K >> M;

        vector<LL> A = readData(N);
        vector<LL> B = readData(N);

        vector<LL> C = readData(K);
        vector<LL> D = readData(M);

        vector<LL> difference = subtractVectors(A, B, N);
        vector<LL> concatenate = concatenateVectors(C, D);

        sort(difference.begin(), difference.end());
        sort(concatenate.begin(), concatenate.end());

        LL uncompletedTasks = timeMachine(difference, concatenate);
        cout << uncompletedTasks << endl;
    }
    return 0;
}