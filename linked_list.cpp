#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;	
	node(){
		data=-1;
		next=nullptr;
	}	
	node(int data){
		this->data=data;
		next=nullptr;
	}
};

struct linked_list{
	node* head;
	node* tail;
	linked_list(){
		head=new node();
		tail=head;
	}	
	void add(int data){
		tail=tail->next=new node(data);
	}
	void traverse(){
		node* tmp=head->next;
		while(tmp!=nullptr){
			printf("%d ",tmp->data);
			tmp=tmp->next;
		}
	}
};

int main(){
	linked_list la;
	la.add(1);
	la.add(2);
	la.traverse();
	return 0;
} 
