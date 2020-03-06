#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;
int Min(int a,int b,int c){
    return min(a,min(b,c));
}
/*This program is only for the edit distance
when the cost of insert=delete=replace(=1).*/
int main(){
    string temp1=" ";
    string temp2=" ";
    string input1="voidcinnboolmycomparecircleacircleb";
    string input2="voidinputFunctionboolcirclecomparecircleacircleb";
    string str1=temp1+input1;
    string str2=temp2+input2;
    int m=str1.size();
    int n=str2.size();
    int edit_distance[m][n];
    for(int i=0;i<m;++i){
        edit_distance[i][0]=i;
    }
    for(int j=0;j<n;++j){
        edit_distance[0][j]=j;
    }

    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            if(str1[i]==str2[j]){
                edit_distance[i][j]=edit_distance[i-1][j-1]; /*Not change*/
            }else{
                edit_distance[i][j]=Min(edit_distance[i-1][j],edit_distance[i][j-1],edit_distance[i-1][j-1])+1;
                /*if(edit_distance[i][j]-1==edit_distance[i-1][j]){
                    count_delete++;
                }else if(edit_distance[i][j]-1==edit_distance[i][j-1]){
                    count_insert++;
                }else{
                    count_replace++;
                }*/
            }
        }
    }

    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cout<<setw(2)<<edit_distance[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"edit distance: "<<edit_distance[m-1][n-1]<<endl;
    /*ans=16*/

return 0;
}

/*
test1:
INTENTION
EXECUTION
ans=5

test2:
AbabanBear
rAreBanana
ans=7
*/
