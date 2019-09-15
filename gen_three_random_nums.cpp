#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void gen_three_nums(int boundary){
    int start_array[boundary];
    for(int i=0;i<boundary;i++) start_array[i]=i;
    for(int i=0;i<3;i++){
        int index=rand()%(boundary-i);
        printf("%d ",start_array[index]);
        start_array[index]=start_array[boundary-i-1];
    }
}

int main(){
	srand(unsigned(time(0)));
	gen_three_nums(9);
	return 0;
} 
