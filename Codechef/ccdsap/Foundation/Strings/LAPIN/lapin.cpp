#include <iostream>
#include <string>
using namespace std;

int main () {
    int test;
    cin >> test;

    while(test){
        string str;
        cin >> str;

        int firstHalf[26] = {};
        int secondHalf[26] = {};
        int differenceArray[26] = {};

        // Keeping a record of consistency of alphabets
        int temp;
        for(int i = 0; i < str.length()/2; i++){
            temp = str[i] - 97;
            firstHalf[temp]++;

            temp = str[str.length()-1-i] - 97;
            secondHalf[temp]++;
        }

        // Checking if both halves have equal consistency
        bool check = true;
        for(int i = 0; i < 26; i++){
            differenceArray[i] = firstHalf[i] - secondHalf[i];
            if(differenceArray[i] != 0)
                check = false;
        }

        if(check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;    
            
        test--;
    }

    return 0;
}