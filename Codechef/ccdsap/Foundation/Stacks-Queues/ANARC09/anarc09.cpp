#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;

    int k = 1;
    stack<char> temp;
    int counter = 0;

    while(str[0] != '-'){
        for(char s: str){
            if(s == '{')
                temp.push(s);
            else if (s == '}' && temp.empty()){
                counter++;
                temp.push('{');
            }
            else
                temp.pop();
        }

        while(!temp.empty()){
            counter++;
            temp.pop();
            temp.pop();
        }

        cout << k << ". " << counter << endl;
        
        counter = 0;
        k++;

        cin >> str;
    }

    return 0;
}