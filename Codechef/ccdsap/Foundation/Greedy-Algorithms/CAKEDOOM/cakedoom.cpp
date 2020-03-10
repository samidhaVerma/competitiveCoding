#include <bits/stdc++.h>
using namespace std;

char replacingQ (string str, int cur, int pre, int pos, int k, bool &check){
    check = true;
    for(char temp = '0'; temp < '0'+k; temp++){
        str[cur] = temp;
        if(str[cur] == str[pre] || str[cur] == str[pos])
            temp++;
        else
           break; 
    }
    if(str[cur] == str[pre] || str[pos] == str[cur])
        check = false;
    return str[cur];
}

int main(){
    int test;
    cin >> test;

    while(test--){
        int k;
        cin >> k;
        string str;
        cin >> str;

        char temp = '0';
        bool check = true;
        for(int i = 0; i < str.size(); i++){
            if(str.size() == 1){
                if(str[0] == '?')
                    str[0] == '0';
                else if(str[0] > k)
                    check = false;
                break;
            }

            if(str[i] == '?'){
                check = true;
                if(i == str.size()-1)
                    str[i] = replacingQ(str, str.size()-1, str.size()-2, 0, k, check);
                else if (i == 0)
                    str[i] = replacingQ(str, 0, str.size()-1, 1, k, check);
                else
                    str[i] = replacingQ(str, i, i-1, i+1, k, check);
            }
            else if (i == 0 && (str[i] != str[str.size()-1] || str[i] != str[i+1]))
                check = false;
            else if (i == str.size()-1 && (str[i] != str[i-1] || str[i] != str[0]))
                check = false;
            else if (str[i] != str[i+1] || str[i] != str[i-1])
                check = false;
            
            if(!check)
                break;
        }

        if(!check)
            cout << "NO" << endl;
        else
            cout << str << endl;
    }

    return 0;
}