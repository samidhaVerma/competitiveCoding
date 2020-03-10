#include <bits/stdc++.h>
using namespace std;

int main(){
    long long test;
    cin >> test;

    while(test--){
        long long n, m, q;
        cin >> n >> m >> q;

        long long row[n+1] = {0};
        long long col[m+1] = {0};

        long long tempRow, tempCol;
        long long oddRow = 0, oddCol = 0;

        while(q--){
            cin >> tempRow >> tempCol;
            row[tempRow]++;
            col[tempCol]++;            
        }

        for(long long i = 1; i <= n; i++){
            if(row[i] % 2 != 0)
                oddRow++;
        }

        for(long long j = 1; j <= m; j++){
            if(col[j] % 2 != 0)
                oddCol++;
        }

        long long result = (m * oddRow) + (n * oddCol) - (2 * oddRow * oddCol);
        cout << result << endl;
    }

    return 0;
}