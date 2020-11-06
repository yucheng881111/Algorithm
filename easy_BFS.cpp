#include<bits/stdc++.h>

using namespace std;
int M[1000][1000];
int R[1000][1000];
int m,n;
int start_i,start_j;
int finish_i,finish_j;
void BFS(){
    queue<pair<int,int>> q;
    pair<int,int> p(start_i,start_j);
    R[start_i][start_j]=0;
    q.push(p);
    int i;
    while(!q.empty()){
        pair<int,int> curr=q.front();
        i=R[curr.first][curr.second];
        M[curr.first][curr.second]=-1;
        q.pop();

        if(curr.first+1<m&&M[curr.first+1][curr.second]==-3){
            R[curr.first+1][curr.second]=i+1;
            break;
        }
        if(curr.first+1<m&&M[curr.first+1][curr.second]==0){
            R[curr.first+1][curr.second]=i+1;
            q.push({curr.first+1,curr.second});
        }

        if(curr.second+1<n&&M[curr.first][curr.second+1]==-3){
            R[curr.first][curr.second+1]=i+1;
            break;
        }
        if(curr.second+1<n&&M[curr.first][curr.second+1]==0){
            R[curr.first][curr.second+1]=i+1;
            q.push({curr.first,curr.second+1});

        }

        if(curr.first-1>=0&&M[curr.first-1][curr.second]==-3){
            R[curr.first-1][curr.second]=i+1;
            break;
        }
        if(curr.first-1>=0&&M[curr.first-1][curr.second]==0){
            R[curr.first-1][curr.second]=i+1;
            q.push({curr.first-1,curr.second});

        }

        if(M[curr.first][curr.second-1]==-3){
            R[curr.first][curr.second-1]=i+1;
            break;
        }
        if(curr.second-1>=0&&M[curr.first][curr.second-1]==0){
            R[curr.first][curr.second-1]=i+1;
            q.push({curr.first,curr.second-1});

        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;

    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            int x;
            cin>>x;
            if(x==-2){
                start_i=i;
                start_j=j;
            }else if(x==-3){
                finish_i=i;
                finish_j=j;
            }
            M[i][j]=x;
        }
    }
    BFS();

    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cout<<R[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Route len: "<<R[finish_i][finish_j]<<endl;

return 0;
}
/*
3 5
-3 0 0 0 0
0 -1 0 -1 0
0 0 -2 0 0

-2==start
-3==end
*/
