#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;

string operator+(string num1,string num2){
    int s=max(num1.size(),num2.size());
    int sm=min(num1.size(),num2.size());
    string ans;
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    bool in=false;
    for(int i=0;i<s;++i){
        if(i<sm){
            int n=(num1[i]-'0')+(num2[i]-'0');
            if(in){
                n++;
            }
            if(n>=10){
                in=true;
                n-=10;
            }else{
                in=false;
            }
            ans+=to_string(n);
        }else{
            if(s==num1.size()){
                int n=num1[i]-'0';
                if(in){
                    n++;
                }
                if(n>=10){
                    in=true;
                    n-=10;
                }else{
                    in=false;
                }
                ans+=to_string(n);
            }else{
                int n=num2[i]-'0';
                if(in){
                    n++;
                }
                if(n>=10){
                    in=true;
                    n-=10;
                }else{
                    in=false;
                }
                ans+=to_string(n);
            }

        }


    }
    if(in){
        ans+="1";
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
/*(s*10^n)*/
string prod10(string s,int n){
    for(int i=0;i<n;++i){
        s+="0";
    }
    string temp=s;
    return temp;
}
/*(s/10^n)*/
string divide(string s,int n){
    string temp;
    if(s.size()<=n){
        temp="0";
    }else{
        for(int i=0;i<s.size()-n;++i){
            temp+=s[i];
        }
    }
    return temp;
}
/*(s%10^n)*/
string rem(string s,int n){
    string temp;
    if(s.size()<=n){
        temp=s;
    }else{
        for(int i=s.size()-1;n>0;--n,--i){
            temp+=s[i];
        }
        reverse(temp.begin(),temp.end());
    }
    return temp;
}
string prod(string num1,string num2);
int main(){
    string num1,num2;
    cin>>num1>>num2;
    cout<<prod(num1,num2)<<endl;

return 0;
}

string prod(string num1,string num2){
    string x,y,z,w;
    int n,m;
    n=max(num1.size(),num2.size());
    if(num1=="0"||num2=="0"){
        return "0";
    }else if(n<=4){
        int temp1,temp2;
        stringstream ss1,ss2;
        ss1<<num1;
        ss2<<num2;
        ss1>>temp1;
        ss2>>temp2;
        int temp3=temp1*temp2;
        string ans=to_string(temp3);
        return ans;
    }else{
        m=n/2;
        x=divide(num1,m);
        y=rem(num1,m);
        w=divide(num2,m);
        z=rem(num2,m);
        return prod10(prod(x,w),2*m)+prod10((prod(w,y)+prod(x,z)),m)+prod(y,z);
    }
}






