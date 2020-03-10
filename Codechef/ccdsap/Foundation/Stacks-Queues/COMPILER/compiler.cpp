#include <bits/stdc++.h>
using namespace std;

int main () {
    int test;
    cin >> test;

    while(test--){
        string str;
        cin >> str;

        stack<char> temp;
        int counter = 0;
        
        for(int i = 0; i < str.size(); i++){
            if (str[i] == '<')
                temp.push(str[i]);
            else if (str[i] == '>' && !temp.empty()) {
                if(temp.top() == '<') {
                    temp.pop();
                    counter = counter + 2;
                }
            }
            else
                break;
        }
        
        cout << counter << endl;
    }

    return 0;
}