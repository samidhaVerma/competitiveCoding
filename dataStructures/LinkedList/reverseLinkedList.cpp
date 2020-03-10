// Reversing a linked list
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};

node* head = NULL;

struct node* createNode(int val){
    node* temp = new node;
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void displayList (node* n){
    while (n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
}

void getLinkedList(){
    int temp = 0;
    node* tempNode, *prevNode;
    int size = 0;
    cin >> temp;
    while(temp != -1){
        tempNode = createNode(temp);
        if(size == 0)
            head = tempNode;
        else{
            prevNode->next = tempNode;
        }
        prevNode = tempNode;
        size++;
        cin >> temp;
    }
}

void reverseLinkedList(node* n){
    // Time complexity: O(n), space complexity: O(1)
    node *prevNode, *currNode, *nextNode;
    currNode = head;
    prevNode = NULL;
    while(currNode != NULL){
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;
}

int main(){

    // Enter elements for the linked list till the input is -1
    getLinkedList();

    // Reversing the linked list
    reverseLinkedList(head);

    // Displaying list
    displayList(head);

    return 0;
}