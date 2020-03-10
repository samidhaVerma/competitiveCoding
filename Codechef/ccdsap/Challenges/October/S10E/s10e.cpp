#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;

        vector<int> phonePrices(n);
        int count = 1;
        int prev;

        for(int i = 0; i < n; i++){
            cin >> phonePrices[i];
            if(i < 5)
                prev = i;
            else
                prev = 5;

            for(int j = 1; j <= prev; j++){
                if(phonePrices[i-j] < phonePrices[i])
                    break;
                if(j == prev)
                    count++;
            }          
        }

        cout << count << endl;
    }
    return 0;
}