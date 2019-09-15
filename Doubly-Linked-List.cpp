#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *next, *prev;
};

Node* nil;

void init(){
    nil = new Node();
    nil->next = NULL;
    nil->prev = NULL;
}

void insert(int key){
    Node *tmp = new Node();
    tmp->key = key;
    tmp->next = nil->next;
    if (nil->next != NULL) {
        nil->next->prev = tmp;    
    }
    tmp->prev = nil;
    nil->next = tmp;
}

void deleteNode(Node* t){
    if (t == NULL) {
        return ;
    } 
    t->prev->next = t->next;
    t->next->prev = t->prev;
    delete t;
}



Node* search(int key){
    Node* p = nil->next;
    while(p != NULL && p->key != key){
        p = p->next;
    }
    return p;
}

void deleteKey(int key){
    deleteNode(search(key));
}

void printList(){
    Node* p = nil->next;
    while (p != NULL) {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}

int main(){
    init();
    insert(1);
    insert(2);
    insert(3);
    printList();
    deleteKey(3);
    printList();
    return 0;
}