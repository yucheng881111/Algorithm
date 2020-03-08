#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int board[8][8]={0};
class point{
	public:
		void set(int a,int b,int c);
		int getX();
		int getY();
		void print();
	private:
		int x;
		int y;
};
void point::print(){
	cout<<setw(3)<<x<<setw(3)<<y<<endl;
	cout<<"----------"<<endl;
}
void point::set(int a,int b,int c){
	x=a;
	y=b;
	board[x][y]=c;
	print();
}
int point::getX(){
	return x;
}
int point::getY(){
	return y;
}


int main(){
	point p;
	p.set(0,0,1);
	const int moveX[8]={-2,-1, 1, 2,2,1,-1,-2};
	const int moveY[8]={-1,-2,-2,-1,1,2, 2, 1};
	int c=1;
	while(1){
		vector<int> temp1;
		vector<int> temp2;
		for(int i=0;i<8;i++){
			int tempX=p.getX()+moveX[i];
			int tempY=p.getY()+moveY[i];
			if(tempX>=0&&tempX<=7&&tempY>=0&&tempY<=7&&board[tempX][tempY]==0){ //合法步
				temp1.push_back(tempX);
				temp2.push_back(tempY);
			}
		}
		if(temp1.empty()){
			break;
		}
		vector<int> count(temp1.size(),0);
		for(int i=0;i<temp1.size();i++){
			for(int j=0;j<8;j++){
				int tempX=temp1[i]+moveX[j];
				int tempY=temp2[i]+moveY[j];
				if(tempX>=0&&tempX<=7&&tempY>=0&&tempY<=7&&board[tempX][tempY]==0){ //合法步
					count[i]++;
				}
			}
		}

		vector<int>::iterator result=min_element(count.begin(),count.end()); //最難走的先走
		int d=distance(count.begin(),result);
		c++;
		p.set(temp1[d],temp2[d],c);
	}
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			cout<<setw(2)<<board[i][j]-1<<" ";
		}
		cout<<endl;
	}

return 0;
}













