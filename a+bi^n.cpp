#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void complex_mul(vector<ll> &a,vector<ll> &b,vector<ll> &c){
    //c=a*b
    //(a+bi)*(c+di)=(ac-bd)+(ad+bc)i
    ll ans1=((a[0]*b[0])-(a[1]*b[1]))%1000000007;
    ll ans2=((a[0]*b[1])+(a[1]*b[0]))%1000000007;
    c.clear();
    c.push_back(ans1);
    c.push_back(ans2);
}

vector<ll> fastpow(ll a,ll b,ll n){
    vector<ll> base;
    base.push_back(a);
    base.push_back(b);
    vector<ll> ans;
    ans.push_back(1);
    ans.push_back(0);

    while(n!=0){
        if(n&1){
            complex_mul(ans,base,ans);
        }
        complex_mul(base,base,base);
        n>>=1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a,b,n;
        cin>>a>>b>>n;
        vector<ll> ans=fastpow(a,b,n);
        cout<<ans[0]<<" "<<ans[1]<<endl;

    }





return 0;
}
