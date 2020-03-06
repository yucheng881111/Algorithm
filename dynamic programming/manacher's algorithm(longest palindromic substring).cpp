#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
string longestPalindrome(string s);
int main(){
    string str;
    cin>>str;
    cout<<longestPalindrome(str)<<endl;

return 0;
}

string longestPalindrome(string s) {
    vector<char> vec;
    vec.push_back('#');
    for(int i=0;i<s.size();++i){
        vec.push_back(s[i]);
        vec.push_back('#');
    }

    int len=s.size()*2+2;
    int r[len];

    for(int i=0;i<len;++i){
        int j=1;
        for(;j<=i;++j){
            if(i+j<len){
                if(vec[i-j]!=vec[i+j]){
                    break;
                }
            }else{
                break;
            }
        }
        r[i]=j-1;
    }
    int m=0;
    int k=0;
    for(int i=0;i<len;++i){
        if(r[i]>m){
            m=r[i];
            k=i;
        }
    }
    string ans="";
    for(int i=k-m;i<=k+m;++i){
        if(vec[i]!='#'){
            ans+=vec[i];
        }
    }

    return ans;

}
