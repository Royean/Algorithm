#include <iostream>
using namespace std;

void merge_sort(int a[],int b[],int start,int end){
	if(start==end){
		return ;
	}
	int mid=(start+end)/2;
	merge_sort(a,b,start,mid);
	merge_sort(a,b,mid+1,end);
	for(int i=start;i<=end;i++) b[i]=a[i]; 
	int cur1=start,cur2=mid+1;
	for(int i=start;i<=end;i++){
		if(cur1==mid+1){
			a[i]=b[cur2++];
		}
		else if(cur2>end){
			a[i]=b[cur1++];
		}
		else if(b[cur1]>b[cur2]){
			a[i]=b[cur2++];
		} 
		else 
			a[i]=b[cur1++];
	}
	
}


int main(){
	int a[]={1,5,7,4,2};
	int b[5];
	merge_sort(a,b,0,4);
	for(int i=0;i<5;i++){
		printf("%d ",a[i]);	
	}
	return 0;
}
