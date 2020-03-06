#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<stack>
using namespace std;

int main(){
    int adj[6][6]={
        0  ,1  ,12 ,999,999,999,
        999,0  ,9  ,3  ,999,999,
        999,999,0  ,999,5  ,999,
        999,999,4  ,0  ,6  ,15,
        999,999,999,999,0  ,4,
        999,999,999,999,999,0
    };
    int dis[6];
    int previous[6];
    int source=0; /*let 0 be the source point.*/
    int finish=5; /*let 5 be the end point.*/
    vector<int> all_vertices;
    for(int i=0;i<6;++i){
        all_vertices.push_back(i);
        dis[i]=999;
        previous[i]=-1;
    }
    dis[source]=0;
    vector<int> S;
    while(!all_vertices.empty()){
        vector<int>::iterator iter=min_element(all_vertices.begin(),all_vertices.end());
        int u=*iter;
        all_vertices.erase(iter);
        S.push_back(u);
        for(int i=0;i<6;++i){
            if(adj[u][i]!=999){
                if(dis[i]>dis[u]+adj[u][i]){
                    dis[i]=dis[u]+adj[u][i];
                    previous[i]=u;
                }
            }
        }
    }
    //method 2:
    /*for(int u=0;u<6;++u){
        for(int i=0;i<6;++i){
            if(adj[u][i]!=999){
                if(dis[i]>dis[u]+adj[u][i]){
                    dis[i]=dis[u]+adj[u][i];
                    previous[i]=u;
                }
            }
        }
    }*/


    stack<int> path;
    int u=finish;
    while(u!=-1){
        path.push(u);
        u=previous[u];
    }
    cout<<"ans: "<<dis[finish]<<endl;
    cout<<"path: ";
    while(!path.empty()){
        cout<<path.top()<<" ";
        path.pop();
    }

    cout<<endl<<endl;
    for(int i=0;i<6;++i){
        if(dis[i]==999){
            cout<<"-1 ";
        }else{
            cout<<dis[i]<<" ";
        }
    }
    cout<<endl;
return 0;
}
