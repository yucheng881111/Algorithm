// union-find algorithm 並查集 
#include<iostream>
#include<vector>
using namespace std;
// student=10
// leads=9
int _find(int p);
vector<int> s;
int main(){
	int student[11];
	for(int i=0;i<11;++i){
		student[i]=i;
	}
	s.assign(student,student+11);
	vector<int> A;
	vector<int> B;
	for(int i=0;i<5;++i){
		int a,b;
		cin>>a>>b;
		A.push_back(a);
		B.push_back(b);
		int t1 = _find(a);
		int t2 = _find(b);
		if(t1!=t2){
			s[t2]=t1; // 靠左原則 
		}
	}
	for(int i=0;i<A.size();++i){ // 只做一次有可能換不乾淨 
		int t1 = _find(A[i]);
		int t2 = _find(B[i]);
		if(t1!=t2){
			s[t2]=t1;
		}
	}
	
	cout<<endl;cout<<endl;
	for(int i=1;i<s.size();++i){
		cout<<s[i]<<" ";
	}
	
	
	
	
return 0;	
}
int _find(int p){
	if(s[p]==p){
		return p; // 擒賊先擒王 find leader/root 
	}else{
		s[p]=_find(s[p]);
	}
}



/*
1 2
3 4
5 2
4 6
2 6
8 7
9 7
1 6
2 4
*/
	

/*

2 3
3 4
6 4
9 4
10 4


*/



