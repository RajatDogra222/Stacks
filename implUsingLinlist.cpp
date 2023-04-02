#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class stacks{
    public:
    node* top;

    stacks(){
        top=NULL;
    }

    void push(int val){
        node* n=new node(val);
        n->next=top;
        top=n;
    }

    int Top(){
        if(top==NULL){
            cout<<"no element is present in stack"<<endl;
            return -1;
        }
        return top->data;
    }

    void pop(){
        
        if(top==NULL){
            cout<<"No element is present"<<endl;
            return;
        }
        node* todelete=top;
        top=top->next;
        delete todelete;
    }

    bool empty(){
         return top==NULL;
    }

};

int main(){
    stacks st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    cout<<st.empty()<<endl;

    return 0;
}