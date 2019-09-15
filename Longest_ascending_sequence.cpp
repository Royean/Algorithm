#include <iostream>
using namespace std;


int main(){
	int s=0;
	int n;
	cin>>n;
	a[0]=-1000000;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t>a[s]) a[++s]=t;
		else{
			int l=1,h=s,m;
			while(l<=h){
				m=(l+h)/2;
				if(t>a[m]) l=m+1;
				else h=m-1;
			}
			a[l]=t;
		}
	}
	cout<<s;
	return 0;
} 
