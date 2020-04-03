#include<bits/stdc++.h>
//backtracking
//leetcode problem.37
using namespace std;
vector<vector<char>> board;
map<pair<int,int>,int> m;
class point{
public:
    int row,col,block;
    vector<int> num;
    bool nums[10];
    point(int x,int y){
        row=x;
        col=y;
        memset(nums,1,sizeof(nums));
        block=m[{x,y}];
    }
    void clr(){
        for(int i=0;i<9;++i){
            if(board[row][i]!='.'){
                nums[board[row][i]-48]=0;
            }
        }
        for(int i=0;i<9;++i){
            if(board[i][col]!='.'){
                nums[board[i][col]-48]=0;
            }
        }
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(m[{i,j}]==block&&board[i][j]!='.'){
                    nums[board[i][j]-48]=0;
                }
            }
        }
        for(int i=1;i<10;++i){
            if(nums[i]==1){
                num.push_back(i);
            }
        }
    }
};

void print(){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool is_valid(int n,int r,int c){
    bool s=true;
    for(int i=0;i<9;++i){
        if(board[r][i]-48==n){
            s=false;
            break;
        }
    }
    for(int i=0;i<9;++i){
        if(board[i][c]-48==n){
            s=false;
            break;
        }
    }
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if(m[{i,j}]==m[{r,c}]&&board[i][j]-48==n){
                s=false;
                break;
            }
        }
    }
    return s;
}
bool success=false;
void sol(vector<point> &vec,int i){
    if(success){
        return ;
    }
    if(i==vec.size()){
        print();
        success=true;
        return ;
    }


    for(int j=0;j<vec[i].num.size();++j){
        if(is_valid(vec[i].num[j],vec[i].row,vec[i].col)){
            board[vec[i].row][vec[i].col]=vec[i].num[j]+48;
            sol(vec,i+1);
            board[vec[i].row][vec[i].col]='.';
        }
    }
}

void solveSudoku(){
    vector<point> empty_point;
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if(board[i][j]=='.'){
                point p(i,j);
                p.clr();
                empty_point.push_back(p);
            }
        }
    }
    sol(empty_point,0);
}

int main(){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if(i>=0&&i<=2&&j>=0&&j<=2){
                m[{j,i}]=0;
            }else if(i>=3&&i<=5&&j>=0&&j<=2){
                m[{j,i}]=1;
            }else if(i>=6&&i<=8&&j>=0&&j<=2){
                m[{j,i}]=2;
            }else if(i>=0&&i<=2&&j>=3&&j<=5){
                m[{j,i}]=3;
            }else if(i>=3&&i<=5&&j>=3&&j<=5){
                m[{j,i}]=4;
            }else if(i>=6&&i<=8&&j>=3&&j<=5){
                m[{j,i}]=5;
            }else if(i>=0&&i<=2&&j>=6&&j<=8){
                m[{j,i}]=6;
            }else if(i>=3&&i<=5&&j>=6&&j<=8){
                m[{j,i}]=7;
            }else if(i>=6&&i<=8&&j>=6&&j<=8){
                m[{j,i}]=8;
            }
        }
    }
    char b[9][9]={
    {'.','.','.','.','.','7','.','.','9'},
    {'.','4','.','.','8','1','2','.','.'},
    {'.','.','.','9','.','.','.','1','.'},
    {'.','.','5','3','.','.','.','7','2'},
    {'2','9','3','.','.','.','.','5','.'},
    {'.','.','.','.','.','5','3','.','.'},
    {'8','.','.','.','2','3','.','.','.'},
    {'7','.','.','.','5','.','.','4','.'},
    {'5','3','1','.','7','.','.','.','.'}
    };
    vector<char> v1(b[0],b[0]+9);
    vector<char> v2(b[1],b[1]+9);
    vector<char> v3(b[2],b[2]+9);
    vector<char> v4(b[3],b[3]+9);
    vector<char> v5(b[4],b[4]+9);
    vector<char> v6(b[5],b[5]+9);
    vector<char> v7(b[6],b[6]+9);
    vector<char> v8(b[7],b[7]+9);
    vector<char> v9(b[8],b[8]+9);
    board.push_back(v1);
    board.push_back(v2);
    board.push_back(v3);
    board.push_back(v4);
    board.push_back(v5);
    board.push_back(v6);
    board.push_back(v7);
    board.push_back(v8);
    board.push_back(v9);
    solveSudoku();

return 0;
}
/*
test1:
{
{'.','.','.','2','.','.','.','6','3'},
{'3','.','.','.','.','5','4','.','1'},
{'.','.','1','.','.','3','9','8','.'},
{'.','.','.','.','.','.','.','9','.'},
{'.','.','.','5','3','8','.','.','.'},
{'.','3','.','.','.','.','.','.','.'},
{'.','2','6','3','.','.','5','.','.'},
{'5','.','3','7','.','.','.','.','8'},
{'4','7','.','.','.','1','.','.','.'}
}
test2:
{
{'5','3','.','.','7','.','.','.','.'},
{'6','.','.','1','9','5','.','.','.'},
{'.','9','8','.','.','.','.','6','.'},
{'8','.','.','.','6','.','.','.','3'},
{'4','.','.','8','.','3','.','.','1'},
{'7','.','.','.','2','.','.','.','6'},
{'.','6','.','.','.','.','2','8','.'},
{'.','.','.','4','1','9','.','.','5'},
{'.','.','.','.','8','.','.','7','9'}
}
test3:
{
{'.','.','.','.','.','7','.','.','9'},
{'.','4','.','.','8','1','2','.','.'},
{'.','.','.','9','.','.','.','1','.'},
{'.','.','5','3','.','.','.','7','2'},
{'2','9','3','.','.','.','.','5','.'},
{'.','.','.','.','.','5','3','.','.'},
{'8','.','.','.','2','3','.','.','.'},
{'7','.','.','.','5','.','.','4','.'},
{'5','3','1','.','7','.','.','.','.'}
}
*/


