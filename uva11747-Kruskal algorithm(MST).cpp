#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<fstream>
#include<memory.h>
using namespace std;
class edge{
public:
    int x,y;
    long long weight;
    edge(int a,int b,long long c){
        x=a;
        y=b;
        weight=c;
    }

};

bool cmp(const edge &a,const edge &b){
    return a.weight<b.weight;
}

int subset[1001];
int find_root(int x){
    int t=x;
    while(subset[t]>=0){
        t=subset[t];
    }
    return t;
}
// Kruskal algorithm
int main(){
    while(1){
        memset(subset,-1,sizeof(subset));
        vector<int> ans;
        int n,e;
        cin>>n>>e;
        if(n==0&&e==0){
            break;
        }
        int a,b;
        long long w;
        bool forest=true;
        vector<edge> vec;
        for(int i=0;i<e;++i){
            cin>>a>>b>>w;
            edge E(a,b,w);
            vec.push_back(E);
        }
        stable_sort(vec.begin(),vec.end(),cmp);
        for(int i=0;i<e;++i){
            int a=find_root(vec[i].x);
            int b=find_root(vec[i].y);
            if((a!=b)||(subset[a]<0&&subset[b]<0&&a!=b)){
                subset[b]=a;
            }else{
                forest=false;
                ans.push_back(vec[i].weight);
            }
        }
        if(forest){
           cout<<"forest";
        }else{
            for(int j=0;j<ans.size();++j){
                if(j==ans.size()-1){
                    cout<<ans[j];
                }else{
                    cout<<ans[j]<<" ";
                }
            }
        }
        cout<<endl;
    }


return 0;
}
