#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;

    vector<char> vec;
    for(int i = 0; i < str.size(); i++){
        vec.push_back(str[i]);
    }

    sort(vec.begin(), vec.end());

    stack<char> t;
    int j = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == vec[j]){
            cout << str[i];
            j++;
        }
        else if(!t.empty() && vec[j] == t.top()){
            cout << t.top();
            t.pop();
            j++;
        }
        else
            t.push(str[i]);
    }

    while(!t.empty()){
        cout << t.top();
        t.pop();
    }

    cout << endl;

    return 0;
}