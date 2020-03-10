#include <iostream>
#include <vector>
using namespace std;

bool checkPalindrome(int arr[], int size){
    bool check = true;
    for (int i = 0; i < size; i++) {
        if(arr[i] != arr[size-1-i])
            check = false;
    }
    return check;
}

bool checkNumber(int arr[], int size){
    bool check = true;
    for (int i = 0; i < size/2; i++){
        if(!(arr[i+1] == arr[i] || arr[i+1] == arr[i]+1)){
            check = false;
            break;
        }
    }
    return check;
}

bool checkMiddle(int arr[], int size){
    bool check = false;
    if (arr[size/2] == 7)
        check = true;
    return check;
}

bool checkConstraints(int arr[], int size, int test){
    bool check;
    bool checkQuantity = true;
    int temp = arr[0];
    int count = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] == temp)
            count++;
        else {
            temp == arr[i];
            count = 1;
        }
        if(count > 10) {
            checkQuantity = false;
            break; 
        }
    }

    bool checkSize = false;
    if (size >= 7 && size <= 100)
        checkSize = true;

    bool checkTest = false;
    if (test >= 1 && test <= 100)
        checkTest = true;

    check = checkQuantity && checkSize && checkTest;
    return check;
}

int main () {
    int test;
    cin >> test;

    while(test){
        int N;
        cin >> N;

        int A[N];
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }

        // Checking Rainbow Array
        int palindromeCheck = checkPalindrome(A, N);
        int middleCheck = checkMiddle(A, N);
        int numberCheck = checkNumber(A, N);
        int constraintCheck = checkConstraints(A, N, test);

        if(palindromeCheck && middleCheck && numberCheck && constraintCheck)
            cout << "yes" << endl;
        else
            cout << "no" << endl;        

        test--;    
    }

    return 0;
}