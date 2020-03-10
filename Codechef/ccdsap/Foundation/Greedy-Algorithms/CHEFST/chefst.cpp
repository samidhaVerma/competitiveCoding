#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;

    while(test--){
        long long int n1, n2, m, sumSubtracted;
        cin >> n1 >> n2 >> m;

        sumSubtracted = m * (m + 1);

        cout << max(max(n1-n2, n2-n1), n1 + n2 - sumSubtracted) << endl;
    }
    return 0;
}