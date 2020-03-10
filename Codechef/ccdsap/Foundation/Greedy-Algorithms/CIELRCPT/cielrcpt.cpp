#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;

    int p, k;
    int count;
    while(test--){
        cin >> p;
        count  = 0;

        while(p != 0){
            k = (int) log2(p);
            if(k > 11)
                k = 11;
            p = p - pow(2, k);
            count++;
        }
        cout << count << endl;
    }
    return 0;
}