#include <bits/stdc++.h>
using namespace std;

int gradientChecking(vector<int> arr, int size){
    int temp = -1;
    for (int i = size-1; i > 0; i--){
        if(arr[i-1] < arr[i]){
            temp = i;
            break;
        }
    }
    return temp;
}

int swappingNumber(int checkPoint, vector<int> arr, int size){
    int swap = -1;
    for (int i = size-1; i >= checkPoint; i--) {
        if(arr[checkPoint-1] < arr[i]){
            swap = i;
            break;
        }
            
    }
    return swap;
}

int main () {
    int test;
    cin >> test;

    while(test){
        int n;
        cin >> n;

        vector<int> A;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            A.push_back(temp);
        }

        int criticalPoint = gradientChecking(A, n);
        int swapNumber = swappingNumber(criticalPoint, A, n);

        if(criticalPoint == -1)
            cout << "-1";
        else {
            swap(A[swapNumber], A[criticalPoint-1]);
            sort(A.begin()+criticalPoint, A.end());
            for(int i = 0; i < n; i++)
                cout << A[i];
        }
        cout << endl;

        test--;
    }

    return 0;
}