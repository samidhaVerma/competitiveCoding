#include <iostream>
using namespace std;

int main() {
   
    int test;
    cin >> test;

    while (test > 0) {
        int N, C;
        cin >> N >> C;

        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        for (int j = 0; j < N; j++) {
            C = C - A[j];
        }

        if (C >= 0) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }

        test--;
    }
    return 0;
}