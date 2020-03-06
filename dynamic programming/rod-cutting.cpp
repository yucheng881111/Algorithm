#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<memory.h>
using namespace std;

int rod_cut_r[11];
int p[11]={0,1,5,8,9,10,17,17,20,24,30};
int memorized_rod_cut_aux(int n);
int memorized_rod_cut(int n){
    memset(rod_cut_r,0,sizeof(rod_cut_r));
    return memorized_rod_cut_aux(n);
}

int memorized_rod_cut_aux(int n){
    if(rod_cut_r[n]>0){
        return rod_cut_r[n];
    }
    int q;
    if(n==0){
        q=0;
    }else{
        q=-999;
        for(int i=1;i<=n;++i){
            if(q<p[i]+memorized_rod_cut_aux(n-i)){
                q=p[i]+memorized_rod_cut_aux(n-i);
            }
        }
    }
    rod_cut_r[n]=q;
    return q;
}

int main(){
    int r[11];
    memset(r,0,sizeof(r));
    //bottom up
    for(int i=1;i<11;++i){
        r[i]=p[i];
        for(int j=1;j<=i;++j){
            if(p[i]<r[i-j]+p[j]){
                r[i]=r[i-j]+p[j];
            }
        }
    }

    cout<<"Bottom-up:"<<endl;
    for(int i=1;i<11;++i){
        cout<<r[i]<<" ";
    }
    memorized_rod_cut(10);
    cout<<endl<<"Top-down:"<<endl;
    for(int i=1;i<11;++i){
        cout<<rod_cut_r[i]<<" ";
    }


return 0;
}









