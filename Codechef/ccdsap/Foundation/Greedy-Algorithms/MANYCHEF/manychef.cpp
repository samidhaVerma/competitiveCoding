#include <bits/stdc++.h>
using namespace std;

bool checkFurther(string str, int pos){
    if((str[pos-1] == '?' || str[pos-1] == 'E') && (str[pos-2] == '?' || str[pos-2] == 'H') && (str[pos-3] != '?' || str[pos-3] != 'C'))
        return true;
    return false;
}

int main(){
    int test;
    cin >> test;

    while(test--){
        string str;
        cin >> str;

        bool check = false;
        for(int i = str.length()-1; i >= 0; i--){
            if ((str[i] == '?' || str[i] == 'F')){
                check = checkFurther(str, i);
                if(check){
                    str[i] = 'F';
                    str[i-1] = 'E';
                    str[i-2] = 'H';
                    str[i-3] = 'C';
                    i = i - 3;
                }
                else
                    str[i] = 'A';
            }
        }
        cout << str << endl;

    }
    return 0;
}