// use annular array to implement the Queue
// the actual capcity of queue is LEN - 1, because we need one empty slot to check the 
// state of the queue.
#include <iostream>
#include <cstring> 
using namespace std;
#define LEN 3

int head, tail;
int Q[LEN];

bool isEmpty(){
    return head == tail;
}

bool isFull(){
    return head == (tail + 1) % LEN;
}

// element a queues up
void enqueue(int a){
    if(isFull()){
        printf("full queue\n");
        return ;
    }
    Q[tail] = a;
    tail = (tail + 1) % LEN;
}

// head element pops out
int dequeue(){
    if(isEmpty()){
        printf("empty queue\n");
        return -1;
    }
    int a = Q[head];
    head = (head + 1) % LEN;
    return a;
}


int main(){
    for(int i = 0;i < 5;i++){
        enqueue(i);
    }
    for(int i = 0;i < 5;i++){
        int a = dequeue();
        printf("%d ", a);
    }
    return 0;
}