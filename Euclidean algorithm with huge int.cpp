#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string Min(string a,string b){
    if(a.size()>b.size()){
         return b;
    }else if(a.size()<b.size()){
        return a;
    }else{
        if(a>b){
            return b;
        }else if(a<b){
            return a;
        }else{
            return "0";
        }
    }
}

string Minus(string a,string b){ //b-a
    vector<int> v1;
    vector<int> v2;
    for(int i=a.size()-1;i>=0;i--){
        v1.push_back(a[i]-'0');
    }
    for(int i=b.size()-1;i>=0;i--){
        v2.push_back(b[i]-'0');
    }

    bool borrow=false;
    vector<int> temp;
    string ans="";
    if(a.size()!=b.size()){
        for(int i=0;i<b.size()-a.size();++i){
            v1.push_back(0);
        }
    }
    for(int i=0;i<b.size();++i){
        if(borrow){
            v2[i]--;
        }
        if(v2[i]>=v1[i]){
            borrow=false;
            temp.push_back(v2[i]-v1[i]);
        }else{
            borrow=true;
            temp.push_back(10-v1[i]+v2[i]);
        }
    }

    bool first_zero=true;
    for(int i=temp.size()-1;i>=0;i--){
        if(temp[i]!=0){
            first_zero=false;
        }
        if(!first_zero){
            ans+=to_string(temp[i]);
        }
    }
    if(ans==""){
        ans="0";
    }
    return ans;
}


//Only effective when two integers are both huge
//輾轉相減法
string GCD(string s1,string s2){
    if(Min(s1,s2)=="0"){
        return s1;
    }else if(Min(s1,s2)==s1){
        string tmp=Minus(s1,s2);
        return GCD(tmp,s1);
    }else{
        string tmp=Minus(s2,s1);
        return GCD(tmp,s2);
    }

}

string mul(string a,int b);
string mod(string a,string b);
string GCD_by_mod(string s1,string s2);
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<GCD_by_mod(s1,s2)<<endl;
    //cout<<GCD(s1,s2)<<endl;





return 0;
}

string mul(string a,int b){ //a*(one digit int)
    string ans="";
    int in=0;
    for(int i=a.size()-1;i>=0;i--){
        int temp=(a[i]-'0')*b+in;
        ans+=to_string(temp%10);
        in=temp/10;
    }

    if(in!=0){
        ans+=to_string(in);
    }
    string str="";
    for(int i=ans.size()-1;i>=0;i--){
        str+=ans[i];
    }

    return str;
}

string mod(string a,string b){ //a mod b
    string temp="";
    for(int i=0;i<a.size();++i){
        if(temp=="0"){
            temp="";
        }
        temp+=a[i];
        if(Min(temp,b)==b){
            for(int j=1;j<=9;++j){
                if(Min(mul(b,j),temp)==temp){
                    temp=Minus(mul(b,j-1),temp);
                    break;
                }else if(Min(mul(b,j),temp)=="0"){
                    temp="";
                    break;
                }
            }
        }
    }
    if(temp==""){
        temp="0";
    }
    return temp;
}

//輾轉相除法
string GCD_by_mod(string s1,string s2){
    if(s1=="0"){
        return s2;
    }
    if(s2=="0"){
        return s1;
    }

    if(Min(s1,s2)=="0"){
        return s1;
    }else if(Min(s1,s2)==s1){
        string tmp=mod(s2,s1);
        return GCD_by_mod(tmp,s1);
    }else{
        string tmp=mod(s1,s2);
        return GCD_by_mod(tmp,s2);
    }

}








