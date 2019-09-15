#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	cin>>n;
	int* dp=new int[n];
	int* a=new int[n];
	for(int i=0;i<n;i++)
		dp[i]=1;
	int k=0;
	int tmp=n;
	while(tmp--){
		cin>>a[k];
		k++;
	}
	int max=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j]<a[i] && (dp[j]+1)>dp[i]){
				dp[i]=dp[j]+1;
			}
		}
		if(max < dp[i])
			max = dp[i];
	}
	cout<<max;
	return 0;
} 
