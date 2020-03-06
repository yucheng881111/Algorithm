#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;
double sum(vector<double> &v,int i,int j){
    double s=0;
    for(int k=i;k<=j;++k){
        s+=v[k];

    }
    return s;
}
int main(){
    int n;
    cout<<"How many node: ";
    cin>>n;
    cout<<endl;
    cout<<"Input each probability: ";
    double d;
    vector<double> p;
    p.push_back(0);
    for(int i=0;i<n;++i){
        cin>>d;
        p.push_back(d);
    }

    int i,j,k,diagonal;
    double A[n+2][n+1];
    int R[n+2][n+1];
    for(int i=0;i<n+2;++i){
        for(int j=0;j<n+1;++j){
            A[i][j]=999;
            R[i][j]=999;
        }
    }
    for(i=1;i<=n;i++){
        A[i][i-1]=0;
        A[i][i]=p[i];
        R[i][i]=i;
        R[i][i-1]=0;
    }
    A[n+1][n]=0;
    R[n+1][n]=0;
    for(diagonal=1;diagonal<=n-1;diagonal++){
        for(i=1;i<=n-diagonal;i++){
            j=i+diagonal;
            for(int m=i;m<=j;++m){
                if(A[i][m-1]+A[m+1][j]+sum(p,i,j)<A[i][j]){
                    A[i][j]=A[i][m-1]+A[m+1][j]+sum(p,i,j);
                    k=m;
                }
            }
            R[i][j]=k;
        }
    }


    cout<<"min-cost: "<<A[1][n]<<endl<<endl;
    cout<<"A:"<<endl;
    for(int i=1;i<=n+1;++i){
        for(int j=0;j<=n;++j){
            cout<<setw(4)<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"R:"<<endl;
    for(int i=1;i<=n+1;++i){
        for(int j=0;j<=n;++j){
            cout<<setw(3)<<R[i][j]<<" ";
        }
        cout<<endl;
    }


return 0;
}
//0.04 0.06 0.08 0.02 0.1 0.12 0.14
