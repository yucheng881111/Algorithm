#include<bits/stdc++.h>

using namespace std;

const int Size=16;

void add(vector<int> &a,vector<int> &b){
    for(int i=0;i<a.size();++i){
        a[i]=a[i]+b[i];
    }
}

void sub(vector<int> &a,vector<int> &b){
    for(int i=0;i<a.size();++i){
        a[i]=a[i]-b[i];
    }
}

void mul(vector<int> &a,vector<int> &b,vector<int> &store){
    if(a.size()==1){
        store[0]=a[0]*b[0];
        store[1]=0;
        return ;
    }
    int n=a.size()/2;
    vector<int> ah(n),bh(n),al(n),bl(n);
    for(int i=0;i<n;++i){
        ah[i]=a[i+n];
        bh[i]=b[i+n];
        al[i]=a[i];
        bl[i]=b[i];
    }
    vector<int> ahbh(n*2),albl(n*2);
    mul(ah,bh,ahbh);
    mul(al,bl,albl);

    add(ah,al); //ah=ah+al
    add(bh,bl); //bh=bh+bl
    vector<int> c(n*2);
    mul(ah,bh,c); //c=(ah+al)*(bh+bl)
    sub(c,ahbh); //c=c-ahbh
    sub(c,albl); //c=c-albl

    for(int i=0;i<n*2;++i){
        store[i]+=albl[i];
    }
    for(int i=0;i<n*2;++i){
        store[i+n]+=c[i];
    }

    for(int i=0;i<n*2;++i){
        store[i+n*2]+=ahbh[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a[Size]={1,0,3,0,0,5,0,0,0,6,0,0,0,0,0,0};
    int b[Size]={0,1,0,4,0,0,0,7,10,0,0,0,0,0,0,0};
    //Let a,b size be the smallest power of 2, so we can easily split a into ah and bh.
    vector<int> vec1(a,a+Size);
    vector<int> vec2(b,b+Size);
    vector<int> ans(2*Size);
    mul(vec1,vec2,ans);

    for(int i=0;i<18;++i){ //最高次項為x^17
        cout<<ans[i]<<" ";
    }



return 0;
}
