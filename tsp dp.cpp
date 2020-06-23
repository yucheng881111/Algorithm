#include<bits/stdc++.h>

using namespace std;

int dp[20+1][1<<20];
int r[20+1][1<<20];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;

    for(int i=0;i<n+1;++i){
        for(int j=0;j<(1<<n);++j){
            dp[i][j]=1023456789;
            r[i][j]=0;
        }
    }

    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        int u,v,w;
        cin>>u>>v>>w;
        dp[u][1<<(v-1)]=w;
        dp[v][1<<(u-1)]=w;
        r[u][1<<(v-1)]=v;
        r[v][1<<(u-1)]=u;
    }

    vector<int> Map(1<<n,1023456789);
    for(int i=1;i<=n;++i){
        Map[1<<(i-1)]=i;
    }


    for(int t=2;t<n;++t){
        for(int i=1;i<=n;++i){
            for(int j=0;j<(1<<n);++j){
                bitset<20> b(j);
                if(b.count()==t&&(((1<<(i-1))&j)==0)){
                    int temp=1;
                    int Min=1023456789;
                    for(int m=0;m<n;++m){
                        if((j&temp)!=0){
                            int tmp=dp[i][temp]+dp[Map[temp]][temp^j];
                            if(tmp<Min){
                                Min=tmp;
                                dp[i][j]=tmp;
                                r[i][j]=r[Map[temp]][temp^j];
                            }
                        }
                        temp<<=1;
                    }
                }
            }
        }

    }

    for(int i=1;i<=n;++i){
        for(int j=0;j<(1<<n);++j){
            if(dp[i][j]==1023456789){
                cout<<"oo"<<" ";
            }else{
                cout<<dp[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    //start from 1, pass all node, back to 1
    int start=1;
    int Min=1023456789;
    for(int i=1;i<=n;++i){
        if(i!=start){
            int temp=dp[start][1<<(i-1)]+dp[i][(((1<<n)-1)^(1<<(start-1))^(1<<(i-1)))]+dp[r[i][((1<<n)-1)^(1<<(start-1))^(1<<(i-1))]][1<<(start-1)];
            // temp<0 => int overflow
            if(temp>0&&temp<Min){
                Min=temp;
            }
        }

    }
    cout<<endl<<Min<<endl;








return 0;
}

/*
8 13
1 2 4
1 4 8
2 3 4
3 4 2
1 3 7
1 8 4
3 6 10
4 5 4
5 6 5
5 8 6
6 8 3
6 7 6
7 8 4
*/
