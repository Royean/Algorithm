#include <iostream>
#include <vector>
using namespace std;

struct Graph
{
    typedef vector<int> VI;
    VI info,next,to;
    Graph(int n=0,int m=0) : to(0),next(0){
        info.resize(n,-1);
        next.reserve(m);
        to.reserve(m);
    }

    int edgeSize(){
        return to.size();
    }

    int vertexSize(){
        return info.size();
    }

    void expand(int i){
        if(info.size()<i+1)
            info.resize(i+1,-1); 
    }

    void add(int i,int j){
        expand(i),expand(j);
        to.push_back(j);
        next.push_back(info[i]);
        info[i]=to.size()-1;
    }

    void delBack(){
        int i;
        for(i=0;i<info.size();i++){
            if(info[i]==to.size()-1){
                info[i]=next.back();
                break;
            }
            to.pop_back();
            next.pop_back();
        }
    }

    void traverse(){
    	int size=info.size();
    	for(int i=0;i<size;i++){
    		if(info[i]!=-1){
    			cout<<i<<" ";
    			for(int j=info[i];j!=-1;j=next[j]){
    				cout<<to[j]<<" ";
    			}	
    			cout<<endl;
    		}
    	}
    }

    void clear(){
        info.clear();
        next.resize(0);
        to.resize(0);
    }
};

int main(){
    //Graph g(6,4);
	Graph g;
	g.add(1,2);
	g.add(1,5);
	g.add(1,4);
	g.add(4,5);
	g.traverse();
    return 0;
}
