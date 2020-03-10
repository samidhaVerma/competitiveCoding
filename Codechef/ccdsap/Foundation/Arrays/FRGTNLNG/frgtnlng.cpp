#include <iostream>
using namespace std;

int main () {
    int test;
    cin >> test;

    while(test){
        
        // Reading input data
        int N, K;
        cin >> N >> K;

        string dict[N];
        int count[N] = {};
        for(int i = 0; i < N; i++){
            getline(cin, dict[i]);
        }

        int L[K];
        for(int i = 0; i < K; i++){
            cin >> L[i];

            string phrases[L[i]];
            for (int j = 0; j < L[i]; j++) {
                getline(cin, phrases[j]);
                
                for (int temp = 0; temp < N; temp++){
                    if(phrases[j] == dict[temp])
                        count[temp]++;
                }
            }
        }
        
        for (int g = 0; g < N; g++){
                if(count[g] > 0)
                    cout << "YES ";
                else
                    cout << "NO ";                
            }
        cout << endl;
            
        test--;
    }

    return 0;
}