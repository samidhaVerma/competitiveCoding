#include <iostream>
using namespace std;

int main () {

    int test;
    cin >> test;
    while (test) {

        // Reading inputs
        int X, Y, K, N;
        cin >> X >> Y >> K >> N;

        int P[N], C[N];

        for (int i = 0; i < N; i++) {
            cin >> P[i] >> C[i];
        }

        // Checking Chef's conditions
        int count = 0;
        for (int j = 0; j < N; j++) {
            int check =  (P[j] >= X-Y) && (K >= C[j]);
            if (check) {
                cout << "LuckyChef" << endl;
                count = 1;
                break;
            }
        }

        if(count == 0)
            cout << "UnluckyChef" << endl;

        test--;
    }

    return 0;
}