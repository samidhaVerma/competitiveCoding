#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;

    int countRegular = 0;
    int length = 0;
    int maxLength = 0;
    bool check = false;
    stack<char> temp;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            temp.push(str[i]);
            length++;
        }
        else if (!temp.empty() && str[i] == ')'){
            temp.pop();
            length++;
            check = true;
        }
        else if (temp.empty() && str[i] == ')')
            check = false;

        if(temp.empty() && !check){
            if(length > maxLength)
                maxLength = length;
            length = 0;
            countRegular++;
            check = false;
        }
    }

    if(countRegular == 0)
        cout << "0 1" << endl;
    else if (countRegular == 1)
        cout << maxLength << " " << countRegular << endl;
    else    
        cout << maxLength << " " << countRegular-1 << endl;

    return 0;
}