#include <iostream>
using namespace std;

long long searchingOnes(string str, int size){
    long long sum = 0;
    for(int i = 0; i < size; i++)
        if(str[i] == '1')
            sum++;
    return sum;
}

int main() {
    int test;
    cin >> test;

    while(test){
        int N;
        cin >> N;
        
        string mainString;
        cin >> mainString;

        // Counting substrings satisfying the condition
        long long onesCount = searchingOnes(mainString, N);
        long long total = (onesCount * (onesCount + 1)) / 2;
        cout << total << endl;

        test--;

    }

    return 0;
}