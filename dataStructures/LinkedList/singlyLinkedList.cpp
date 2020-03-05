// Performing basic operations on singly linked list

#include<bits/stdc++.h>
using namespace std;

// Declaring node for the linked list
struct node {
    int data;
    struct node* next;
};

node* head = NULL;
node* curr = NULL;
node* tail = NULL;

void displayList (node* n){
    while (n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
}

struct node* createNode(int data){
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void addNodeAtTail(int data){
    // Time complexity: O(n)
    node* temp = createNode(data);

    if(head != NULL) {
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }
    else{
        head = temp;
    }

    tail = temp;
}

void addNodeAtHead(int data){
    // Time complexity: O(1)
    node* temp = createNode(data);

    if(head == NULL){
        head = temp;
    }
    else{
        temp->next = head;
    }
    head = temp;
}

void addNodeAtIndex(int index, int data){
    // Time complexity: O(n)
    node* addData = createNode(data);
    node* temp = new node;
    int iterator = 0;

    if(head != NULL){
        curr = head;
        while(iterator != index-2){
            curr = curr->next;
            iterator++;
        }
        temp = curr-> next;
        curr->next = addData;
        addData->next = temp;
    }
}

void deleteNodeAtHead(int val){
    if(head == tail){
        head == NULL;
        tail = NULL;
    }
    else{
        head = head->next;
    }
}

void deleteNodeValue(int val){
    // Time complexity: O(n)
    node* prev = new node;
    bool foundNode = false;

    if(head != NULL){
        curr = head;
        prev = curr;
        if(val == head->data)
            deleteNodeAtHead(val);
        while(curr != NULL){
            if(val == curr->data){
                if(curr->next != NULL)
                    prev->next = curr->next;
                else{
                    prev->next = NULL;
                    tail = prev;
                }    
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }
}

int main () {

    // Initialising the linked list
    int initialSize;
    cin >> initialSize;

    int temp;
    for(int i = 0; i < initialSize; i++){
        cin >> temp;
        addNodeAtTail(temp);
    }

    // Adding a node at the head
    int nodeAtHead;
    cin >> nodeAtHead;
    addNodeAtHead(nodeAtHead);

    // Adding a node at the tail
    int nodeAtTail;
    cin >> nodeAtTail;
    addNodeAtTail(nodeAtTail);

    // Adding a node at index
    int index, nodeValue;
    cin >> index >> nodeValue;
    addNodeAtIndex(index, nodeValue);

    // Deleting a node with value 
    int deleteNode;
    cin >> deleteNode;
    deleteNodeValue(deleteNode);

    displayList(head);

    return 0;
}