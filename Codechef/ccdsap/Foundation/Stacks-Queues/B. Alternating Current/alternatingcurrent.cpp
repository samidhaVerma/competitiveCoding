#include <bits/stdc++.h>
using namespace std;

int main () {
    string str;
    cin >> str;

    stack<char> temp;

    for(int i = 0; i < str.size(); i++){
        if(temp.empty())
            temp.push(str[i]);
        else if (str[i] == temp.top())
            temp.pop();
        else
            temp.push(str[i]);        
    }

    if(temp.empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}