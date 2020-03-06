#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
/*find pos of x*/
void Search(int &pos1,int &pos2,int in[],int x,int n){
    for(int i=0;i<n;++i){
        if(in[i]==x&&pos1==-1){
            pos1=i;
        }else if(in[i]==x&&pos1!=-1){
            pos2=i;
        }
    }
}
void printPos(int pre[],int in[],int n);
int main(){
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int k,x;
    cin>>k;
    int pre[k];
    int in[k*2];
    for(int i=0;i<k;++i){
        cin>>x;
        pre[i]=x;
    }
    for(int i=0;i<k*2;++i){
        cin>>x;
        in[i]=x;
    }

    printPos(pre,in,k*2);

return 0;
}

void printPos(int pre[],int in[],int n){
    if(n==0){
        return;
    }
    int pos1=-1;
    int pos2=-1;
    Search(pos1,pos2,in,pre[0],n);
    if(pos1!=-1&&pos2!=-1){
        printPos(pre+1,in,pos1);
        printPos(pre+(pos1/2)+1,in+pos1+1,pos2-pos1-1);
        printPos(pre+(pos2/2)+1,in+pos2+1,n-pos2-1);
    }

    cout<<pre[0]<<" ";
}


