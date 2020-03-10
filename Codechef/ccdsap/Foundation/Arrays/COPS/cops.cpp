#include <iostream>
using namespace std;

int main () {
    int test;
    cin >> test; 

    while(test){
        int M, x, y;
        cin >> M >> x >> y;

        int houses[100] = {};
        int maxDistance = x * y + 1;

        int cops[M];
        for(int i = 0; i < M; i++) {
            cin >> cops[i];
            houses[cops[i]-1] = 1;

            // Marking houses which are in reach of cops
            for(int k = 0; k < maxDistance; k++){
                if ((cops[i]-1-k) >= 0)
                    houses[cops[i]-1-k] = 1;
                if ((cops[i]-1+k) < 100)
                    houses[cops[i]-1+k] = 1;
            }
        }

        // Counting safe houses
        int count = 0;
        for(int j = 0; j < 100; j++){
            if(houses[j] == 0)
                count++;
        }

        cout << count << endl;
    test--; 
    }

    return 0;
}