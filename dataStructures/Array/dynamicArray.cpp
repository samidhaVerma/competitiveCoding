// Performing basic operations on vectors

#include<bits/stdc++.h>
using namespace std;

void displayVector(vector<int> arr){
    // Time complexity : O(n)
    for (int i = 0; i < arr.size(); i++)
        cout << arr.at(i) << " ";         // or arr[i]
    cout << endl;
}

vector<int> inputElements(int size){
    // Time complexity: O(n)
    vector<int> arr;
    int temp;
    for(int i = 0; i < size; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    return arr;
}

vector<int> toDeleteElement(vector<int> arr, int element){
    // Time complexity: O(n)
    for(int i = element-1; i < arr.size()-1; i++){
        if(i != arr.size()-1){
            arr[i] = arr[i+1];
        }
    }
    arr.pop_back();
    return arr;
}

vector<int> toInsertElement(vector<int> arr, int element, int pos){
     // Time complexity: O(n)
    arr.insert(arr.begin()+pos, element);
    return arr;
}

int main(){
    
    // Declaration of a dynamic array
    int N;
    cin >> N;

    // Input elements in the array
    vector<int> array = inputElements(N);

    // Sorting a vector - time complexity: nlog(n)
    sort(array.begin(), array.end());

    // Deleting the last element - time complexity: O(1)
    array.pop_back();

    // Deleting a specific element - time complexity: O(n)
    int deleteElement;
    cin >> deleteElement; // position of the to-be deleted element
    array = toDeleteElement(array, deleteElement);

    // Inserting a specific element - time complexity: O(n)
    int insertElement, positionInsert;
    cin >> insertElement >> positionInsert;
    array = toInsertElement(array, insertElement, positionInsert);

    // Traversing the array - time complexity: O(n)
    displayVector(array);

    return 0;
}