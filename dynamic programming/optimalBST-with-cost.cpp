#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;

int main(){
    int n=7;
    double p[8]={0   ,0.04,0.06,0.08,0.02,0.1 ,0.12,0.14};
    double q[8]={0.06,0.06,0.06,0.06,0.05,0.05,0.05,0.05};
    double e[n+2][n+1];
    double w[n+2][n+1];
    int R[n+1][n+1];
    for(int i=0;i<n+2;++i){
        for(int j=0;j<n+1;++j){
            e[i][j]=0;
            w[i][j]=0;
        }
    }
    for(int i=0;i<n+1;++i){
        for(int j=0;j<n+1;++j){
            R[i][j]=0;
        }
    }

    for(int i=1;i<=n+1;++i){
        e[i][i-1]=q[i-1];
        w[i][i-1]=q[i-1];
    }

    for(int l=1;l<=n;++l){
        for(int i=1;i<=n-l+1;++i){
            int j=i+l-1;
            e[i][j]=999;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            for(int r=i;r<=j;++r){
                double t=e[i][r-1]+e[r+1][j]+w[i][j];
                if(t<e[i][j]){
                    e[i][j]=t;
                    R[i][j]=r;
                }
            }
        }
    }
    cout<<"e:"<<endl;
    for(int i=1;i<n+2;++i){
        for(int j=0;j<n+1;++j){
            cout<<setw(4)<<e[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"w:"<<endl;
    for(int i=1;i<n+2;++i){
        for(int j=0;j<n+1;++j){
            cout<<setw(4)<<w[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"r:"<<endl;
    for(int i=1;i<n+1;++i){
        for(int j=1;j<n+1;++j){
            cout<<setw(4)<<R[i][j]<<" ";
        }
        cout<<endl;
    }




return 0;
}
