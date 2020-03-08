#include<iostream>
#include<vector>
#define N 8 
using namespace std;
int column[N]={0};
int slash[2 * N]={0};
int backSlash[2 * N]={0};
vector<int> queen;
int count=0;
void BackTrack(int* col, int* s, int* bs, vector<int> &q, int i);
int main(){
	for(int i=0;i<N;++i){
		queen.push_back(0);
	}
	BackTrack(column,slash,backSlash,queen,0);
	cout<<endl<<count<<endl;
return 0;	
}

void BackTrack(int* col, int* s, int* bs, vector<int> &q, int i){
	if(i==N){
		for(int n=0;n<N;++n){
			cout<<q[n]<<" ";
		}
		cout<<endl;
		count++;
		return ;
	}
	
	for(int j=0;j<N;++j){
		if(col[j]!=1&&s[i+j]!=1&&bs[i-j+N]!=1){
			q[i]=j;
			col[j]=1;
			s[i+j]=1;
			bs[i-j+N]=1;
			BackTrack(column,slash,backSlash,q,i+1);
			col[j]=0;
			s[i+j]=0;
			bs[i-j+N]=0;
		}
	}
}



