#include<bits/stdc++.h>
//f(x+1)=2f(x)+4f(x-1); f(0)=1, f(1)=4 ans%=1000000007
using namespace std;

void mul(vector<vector<long long>> &a,vector<vector<long long>> &b,vector<vector<long long>> &ans){
    //size=2x2
    vector<vector<long long>> temp(2,vector<long long>(2,0));
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            for(int k=0;k<2;++k){
                temp[i][j]+=(a[i][k]*b[k][j])%1000000007;
            }
        }
    }
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            temp[i][j]%=1000000007;
        }
    }
    ans=temp;
}

vector<vector<long long>> fastpow(long long n){
    vector<vector<long long>> base(2,vector<long long>(2,0));
    base[0][0]=2;base[0][1]=4;
    base[1][0]=1;base[1][1]=0;
    vector<vector<long long>> ans(2,vector<long long>(2,0));
    ans[0][0]=1;ans[0][1]=0;
    ans[1][0]=0;ans[1][1]=1;
    while(n!=0){
        if(n&1){
            mul(base,ans,ans);
        }
        mul(base,base,base);
        n>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin>>n;
    if(n==1){
        cout<<"1"<<endl;
        return 0;
    }else if(n==2){
        cout<<"4"<<endl;
        return 0;
    }

    vector<vector<long long>> vec=fastpow(n-2);

    long long sum=vec[0][0]*4+vec[0][1]*1;
    cout<<sum%1000000007;




return 0;
}
