#include <bits/stdc++.h>
#include <string>
using namespace std;

void poppingStack(queue<char> &postfix, stack<char> &temp){
    while(temp.top() != '('){
        postfix.push(temp.top());
        temp.pop();
    }
    temp.pop();
}

int main () {
    int test;
    cin >> test;

    while(test){
        string str;
        cin >> str;

        stack<char> temp;
        queue<char> postfix;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(')
                temp.push(str[i]);
            else if (str[i] == ')')
                poppingStack(postfix, temp);
            else if (isalpha(str[i]))
                postfix.push(str[i]);
            else
                temp.push(str[i]); 
        }

        while(!postfix.empty()){
            cout << postfix.front();
            postfix.pop();
        }

        cout << endl;

        test--;
    }

    return 0;
}