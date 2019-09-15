#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int>* tmp=new vector<int>;
	int a[]={1,2};
	tmp->assign(a,a+2);
	delete[] tmp;	
	cout<<tmp->size();
} 
