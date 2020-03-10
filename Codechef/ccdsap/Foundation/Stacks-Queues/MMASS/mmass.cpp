#include <bits/stdc++.h>
using namespace std;

int mass(char x){
    if(x == 'C')
        return 12;
    else if (x == 'H')
        return 1;
    else if (x == 'O')
        return 16;
    else
        return 0;
}

int main() {
    string formula;
    cin >> formula;

    int mmass = 0;
    bool check = false;
    stack<int> temp;
    int digit;
    int bracketMass = 0;

    for(int i = 0; i < formula.size(); i++){
        if(formula[i] == '(')
            check = true;
        else if(formula[i] == ')')
            check = false;
        
        if(check && isalpha(formula[i]))
            temp.push(mass(formula[i]));
        else if (check && isdigit(formula[i])) {
            digit = formula[i] - 48;
            temp.push((digit-1) * mass(formula[i-1]));
        }
        else if (!check && isalpha(formula[i])){
            if(formula[i-1] == ')'){
                bracketMass = 0;
                while(!temp.empty()){
                    bracketMass = bracketMass + temp.top();
                    temp.pop();
                }
                mmass = mmass + bracketMass;
            }
            else
                mmass = mmass + mass(formula[i]);            
        }
            
            
        else if (!check && isdigit(formula[i])) {
            digit = formula[i] - 48;

            if(formula[i-1] == ')'){
                bracketMass = 0;
                while(!temp.empty()){
                    bracketMass = bracketMass + temp.top();
                    temp.pop();
                }
                mmass = mmass + digit * bracketMass;
            }
            else{
                mmass = mmass + (digit - 1) * mass(formula[i-1]);
            }
        }
    }

    cout << mmass << endl;

    return 0;
}