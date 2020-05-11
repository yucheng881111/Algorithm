#include<bits/stdc++.h>

using namespace std;

int recur(int a,int p){
    if(p==1){
        return a;
    }
    int b=p/2;
    if(p%2==0){
        return recur(a,b)*recur(a,b);
    }else{
        return a*recur(a,b)*recur(a,b);
    }
}

int loop(int a,int p){
    int ans=1,base=a;
    while(p!=0){
        if(p&1){
            ans*=base;
        }
        base*=base;
        p>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,p;
    cin>>a>>p;
    //calculate a^p
    cout<<"recursive: "<<recur(a,p)<<endl;
    cout<<"loop: "<<loop(a,p)<<endl;
    cout<<"pow function: "<<pow(a,p)<<endl;





return 0;
}
