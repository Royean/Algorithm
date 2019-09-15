#include <iostream>
using namespace std;

void swap(int a[],int src,int dest){
	int tmp=a[src];
	a[src]=a[dest];
	a[dest]=tmp;
}

void quick_sort(int a[],int start,int end){
	if(start==end){
		return ;
	}
	//以中间位置的数作为枢纽； 
	int mid=(start+end)/2;
	//把中间的数放到最后
	swap(a,mid,end);
	int cur1=start,cur2=end-1;
	while(cur1 < cur2){
		while(a[cur1] < a[end]) cur1++; 
		while(a[cur2] >= a[end] && cur2>cur1)  cur2--;
		swap(a,cur1,cur2);
	}
	swap(a,cur1,end);
	quick_sort(a,start,cur1-1);
	quick_sort(a,cur1+1,end); 
}

int main(){
	int a[]={1,4,7,9,2};
	quick_sort(a,0,4);
	for(int i=0;i<5;i++){
		printf("%d ",a[i]);
	}
	return 0;
} 
