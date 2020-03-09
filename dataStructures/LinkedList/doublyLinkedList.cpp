// Performing basic operations for doubly linked list
#include<bits/stdc++.h>
using namespace std;

// Declaring the node of doubly linked list
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

// Declaring the nodes for the linked list
node *head = NULL;
node *tail = NULL;
node *curr = NULL;

void displayList (node* n){
    while (n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int get(int index){
    curr = head;
    for(int i = 0; i < index-1; i++) {
        if(curr->next == NULL)
            break;
        else
            curr = curr->next;       
    }
    return curr->data;
}

void displayReverseList (node* n){
    while(n != NULL){
        cout << n->data << " ";
        n = n->prev; 
    }
    cout << endl;
}

struct node* createNode(int data){
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void addAtHead(int data){
    node* temp = createNode(data);
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        head->prev = temp;
        temp->next= head;
        head = temp;
    }
}

void addAtTail(int data){
    node* temp = createNode(data);
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

int main(){
    // Initialising the linked list
    int initialSize;
    cin >> initialSize;

    int temp;
    for(int i = 0; i < initialSize; i++){
        cin >> temp;
        addAtTail(temp);
    }

    // Adding a node at the head
    int nodeAtHead;
    cin >> nodeAtHead;
    addAtHead(nodeAtHead);

    // Adding a node at the tail
    int nodeAtTail;
    cin >> nodeAtTail;
    addAtTail(nodeAtTail);

    // Getting value from the linked list
    int getIndex;
    cin >> getIndex;
    cout << get(getIndex) << endl;

    // Displaying the linked list
    displayList(head);
    displayReverseList(tail);

    return 0;
}