#include <iostream>
using namespace std;

int par[1000];  //the parent of the node
int ranks[1000]; //the height of the tree 

void init(int n){
	for(int i=0;i<n;i++){
		par[i]=i;                 //initialize every element ,and every node acts as root at first
		ranks[i]=0;
	}
}

int find(int x){
	if(par[x]==x){
		return x;                           //if find the root ,return; 
	}
	else{
		return par[x] = find(par[x]);      //get the current parent , and recursively find the parent of its parent until root is reached.
	}
}

void unite(int x,int y){
	x = find(x);
	y = find(y);                       // find the parents of x and y .
	if(x==y) return ;
	if(ranks[x] < ranks[y]){          //compare x with y.let the the root with higer ranks be the new root.
		par[x]=y;
	}
	else{
		par[y]=x;
		if(ranks[y] == ranks[x]) ranks[x]++;     // after the combination , ranks of new root increases by one.
	}
}

bool same(int x,int y){
	return find(x) == find(y);
}


int main(){
	init(1000);
	cout<<find(1)<<endl;	
	cout<<find(2)<<endl;
	unite(1,2);
	cout<<find(2)<<endl;
	cout<<ranks[1]<<endl;
	
	return 0;
} 
