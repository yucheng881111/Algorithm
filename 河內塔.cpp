#include<iostream>
using namespace std;

void hanoi(int,char,char,char);
int main(){
	hanoi(4,'A','B','C');


system("pause");
return 0;
}


void hanoi(int n,char start,char temp,char end){
	if(n>0){
		hanoi(n-1,start,end,temp);
		cout<<n<<start<<"->"<<end<<endl;
		hanoi(n-1,temp,start,end);
	}
	
}













































