#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<bitset>
#include<iomanip>
#include<memory.h>
using namespace std;

const int n=4;
const int adj[n+1][n+1]={{0,0,0,0,0},
                         {0,0,10,15,20},
                         {0,5,0,9,10},
                         {0,6,13,0,12},
                         {0,8,8,9,0}};
int s=1<<n;       //1*(2^4)
int a[n+1][1<<n]; //a[5][16]
int r[n+1][1<<n]; //routes
int state_to_index(vector<int> &v){
    int s=0;
    for(int i=0;i<v.size();++i){
        if(v[i]!=0){
            s+=(1<<(v[i]-1));
        }
    }
    return s;
}

void index_to_state(int index,vector<int> &v){
    v.clear();
    bitset<n> b(index);
    for(int i=0;i<n;++i){
        if(b[i]==1){
            v.push_back(i+1);
        }
    }
}
/*
bitmask method: way to compress set to int
state table:
4 3 2 1 index set

0 0 0 0  0    {}
0 0 0 1  1    {1}
0 0 1 0  2    {2}
0 0 1 1  3    {1,2}
0 1 0 0  4    {3}
0 1 0 1  5    {1,3}
0 1 1 0  6    {2,3}
0 1 1 1  7    {1,2,3}
1 0 0 0  8    {4}
1 0 0 1  9    {1,4}
1 0 1 0  10   {2,4}
1 0 1 1  11   {1,2,4}
1 1 0 0  12   {3,4}
1 1 0 1  13   {1,3,4}
1 1 1 0  14   {2,3,4}
1 1 1 1  15   {1,2,3,4}
*/
int return_to_start(int x,vector<int> v){
    v.erase(find(v.begin(),v.end(),0));
    int e=r[x][state_to_index(v)];
    while(v.size()!=1){
        vector<int>::iterator it=find(v.begin(),v.end(),e);
        v.erase(it);
        e=r[e][state_to_index(v)];
    }
    return e; //end vertex
}

int main(){

    memset(a,0,sizeof(a));
    memset(r,0,sizeof(r));
    vector<int> vec;
    for(int j=1;j<s;++j){       //index of states
        index_to_state(j,vec);
        for(int i=1;i<=n;++i){  //vertexes
            if(find(vec.begin(),vec.end(),i)!=vec.end()){
                a[i][j]=999;
                r[i][j]=0;
            }else{
                if(vec.size()==1){
                    a[i][j]=adj[i][vec[0]];
                    r[i][j]=vec[0];
                }else if(vec.size()==n-1){ //n=3 -> return to start
                    a[i][j]=999;
                    for(int k=0;k<vec.size();++k){
                        int t=vec[k];
                        vec[k]=0;
                        if(a[i][j]>adj[i][t]+a[t][state_to_index(vec)]+adj[return_to_start(t,vec)][i]){
                            a[i][j]=adj[i][t]+a[t][state_to_index(vec)]+adj[return_to_start(t,vec)][i];
                            r[i][j]=t;
                        }
                        vec[k]=t;
                    }
                }else{
                    a[i][j]=999;
                    for(int k=0;k<vec.size();++k){
                        int t=vec[k];
                        vec[k]=0;
                        if(a[i][j]>adj[i][t]+a[t][state_to_index(vec)]){
                            a[i][j]=adj[i][t]+a[t][state_to_index(vec)];
                            r[i][j]=t;
                        }
                        vec[k]=t;
                    }
                }
            }
        }
    }
    cout<<"a: "<<endl;
    for(int i=0;i<5;++i){
       for(int j=0;j<16;++j){
            cout<<setw(3)<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"r: "<<endl;
    for(int i=0;i<5;++i){
       for(int j=0;j<16;++j){
            cout<<setw(3)<<r[i][j]<<" ";
        }
        cout<<endl;
    }


    int v[4]={1,2,3,4};
    for(int x=1;x<=4;++x){
        vector<int> vertex(v,v+4);
        int start=x; //start at x
        int e=start;
        int ans;
        cout<<"\nroute: ";
        while(1){
            cout<<e<<" ";
            vector<int>::iterator it=find(vertex.begin(),vertex.end(),e);
            vertex.erase(it);
            if(vertex.empty()){
                break;
            }
            if(e==start){
                ans=a[e][state_to_index(vertex)];
            }
            e=r[e][state_to_index(vertex)];
        }
        cout<<start<<endl;
        cout<<"ans: "<<ans<<endl;
    }

return 0;
}
