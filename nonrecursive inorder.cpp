#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

class node{
public:
    int val=0;
    node(int temp){
        val=temp;
    }
    node* left=NULL;
    node* right=NULL;
};

void inorder(node* root){
    node* current=root;
    if(current!=NULL){
        inorder(current->left);
        cout<<current->val<<" ";
        inorder(current->right);
    }
}
void nonrecursive_inorder(node* root){
    stack<node*> s;
    node* current=root;
    while(1){
        while(current!=NULL){
            s.push(current);
            current=current->left;
        }
        if(s.empty()){
            break;
        }
        cout<<s.top()->val<<" ";
        current=s.top()->right;
        s.pop();
    }
}

int main(){
    int n;
    cout<<"How many node: ";
    cin>>n;
    int k;
    vector<int> vec;
    for(int i=0;i<n;++i){
        cin>>k;
        vec.push_back(k);
    }
    node* root=new node(vec[0]);
    for(int i=1;i<n;++i){
        node* temp=root;
        node* y;
        while(temp!=NULL){
            y=temp;
            if(vec[i]>temp->val){
                temp=temp->right;
            }else{
                temp=temp->left;
            }
        }
        node* new_node=new node(vec[i]);
        if(vec[i]>y->val){
            y->right=new_node;
        }else{
            y->left=new_node;
        }
    }
    cout<<"inorder:"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"nonrecursive_inorder:"<<endl;
    nonrecursive_inorder(root);

return 0;
}
