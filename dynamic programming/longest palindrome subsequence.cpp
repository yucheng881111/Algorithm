#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int path[100][100];
void print(vector<char>&v,int i,int j);
int main(){
    string s;
    cin>>s;
    int len=s.size()+1;
    int a[len][len];
    for(int i=0;i<len;++i){
        a[i][0]=0;
        a[0][i]=0;
        path[i][0]=0;
        path[0][i]=0;
    }

    vector<char> vec;
    vector<char> r_vec;
    vec.push_back('0');
    r_vec.push_back('0');
    for(int i=0;i<len-1;++i){
        vec.push_back(s[i]);
    }
    for(int i=len-2;i>=0;i--){
        r_vec.push_back(s[i]);
    }

    for(int i=1;i<len;++i){
        for(int j=1;j<len;++j){
            if(vec[i]==r_vec[j]){
                a[i][j]=a[i-1][j-1]+1;
                path[i][j]=1;  //up-left
            }else{
                if(a[i-1][j]>a[i][j-1]){
                    a[i][j]=a[i-1][j];
                    path[i][j]=2; //up
                }else{
                    a[i][j]=a[i][j-1];
                    path[i][j]=3;  //left
                }
            }
        }
    }
    cout<<"a:"<<endl;
    for(int i=0;i<len;++i){
        for(int j=0;j<len;++j){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"path:"<<endl;
    for(int i=0;i<len;++i){
        for(int j=0;j<len;++j){
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    print(vec,len-1,len-1);






return 0;
}

void print(vector<char>&v,int i,int j){
    if(i==0||j==0){
        return ;
    }

    if(path[i][j]==1){
        print(v,i-1,j-1);
        cout<<v[i];
    }else if(path[i][j]==2){
        print(v,i-1,j);
    }else{
        print(v,i,j-1);
    }
}




