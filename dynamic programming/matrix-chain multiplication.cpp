#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;
int s[7][7];
void print(int i,int j){
    int k=s[i][j];
    if(i==j){
        cout<<"A"<<i;
    }else{
        cout<<"(";
        print(i,k);
        print(k+1,j);
        cout<<")";
    }
}

int main(){
    int n=6;
    int d[7]={30,35,15,5,10,20,25};
    //A1=30x35;
    //A2=35x15;
    //A3=15x5;
    //A4=5x10;
    //A5=10x20;
    //A6=20x25;
    int m[7][7];
    for(int i=0;i<7;++i){
        for(int j=0;j<7;++j){
            m[i][j]=0;
            s[i][j]=0;
        }
    }
    for(int dia=1;dia<=n-1;++dia){
        for(int i=1;i<=n-dia;++i){
            int j=i+dia;
            m[i][j]=99999999;
            for(int k=i;k<=j-1;++k){
                if(m[i][j]>m[i][k]+m[k+1][j]+d[i-1]*d[k]*d[j]){
                    m[i][j]=m[i][k]+m[k+1][j]+d[i-1]*d[k]*d[j];
                    s[i][j]=k;
                }
            }
        }
    }
    cout<<"min-cost: "<<m[1][n]<<endl;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<setw(5)<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    print(1,6);





return 0;
}
