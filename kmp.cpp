#include <iostream>
#include <string.h>
using namespace std;


void get_next(char* p,int *next){
	next[0]=-1;
	int i=0,j=-1;
	while(i<strlen(p)){
		if(j==-1 || p[i]==p[j]){
			++i;
			++j;
			next[i]=j;
		}
		else 
			j=next[j];
	}
}

int kmp(char* t,char* p){
	int i=0,j=0;
	int next[4];
	get_next(p,next);
	while(i<strlen(t) && j<strlen(p)){
		if(j==1 || t[i]== p[i]){
			i++;
			j++;
		}
		else 
			j=next[j];
	}
	if(j==strlen(p))
		return i-j;
	else 
		return -1;
}


int main(){  
	
	char* t="asdfasf";
	char* p="dfa";
	int res=kmp(t,p);
	cout<<res;
	return 0;
} 
