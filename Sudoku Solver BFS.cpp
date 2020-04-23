#include<bits/stdc++.h>

using namespace std;
map<pair<int,int>,int> m;
void m_clear(){
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
}
bool is_valid(string s,int r,int c,char x){
    char b[9][9];
    int p=0;
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            b[i][j]=s[p];
            p++;
        }
    }
    for(int i=0;i<9;++i){
        if(b[r][i]==x){
            return false;
        }
    }
    for(int i=0;i<9;++i){
        if(b[i][c]==x){
            return false;
        }
    }
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if(m[{i,j}]==m[{r,c}]&&b[i][j]==x){
                return false;
            }
        }
    }
    return true;
}
bool finish(string s){
    for(int i=0;i<81;++i){
        if(s[i]=='.'){
            return false;
        }
    }
    return true;
}
string bfs(string s){
    string start=s;
    queue<string> q;
    q.push(start);
    while(!q.empty()){
        string t=q.front();
        //cout<<t<<endl;
        q.pop();
        char b[9][9];
        int p=0;
        int wi,wj,wp;
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                b[i][j]=t[p];
                if(t[p]=='.'){
                    wi=i;wj=j;wp=p;
                }
                p++;
            }
        }
        for(int i=1;i<=9;++i){
            if(is_valid(t,wi,wj,(char)(i+'0'))){
                t[wp]=(char)(i+'0');
                if(finish(t)){
                    return t;
                }
                q.push(t);
            }
        }
    }

    return "-1";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    m_clear();
    char board[9][9];
    string s="";
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cin>>board[i][j];
            s+=board[i][j];
        }
    }
    string ans=bfs(s);
    if(ans=="-1"){
        cout<<"No solution!!!"<<endl;
        return 0;
    }
    int p=0;
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cout<<ans[p];
            p++;
        }
        cout<<endl;
    }

return 0;
}

/*
.....7..9
.4..812..
...9...1.
..53...72
293....5.
.....53..
8...23...
7...5..4.
531.7....
*/

/*
53..7....
6..195...
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79
*/
