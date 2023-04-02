#include <bits/stdc++.h>
using namespace std;
#define n 100

class stacks{
    
    int *a;
    int top;
    int mn;
    public:
       stacks(){
           a=new int[n];
           top=-1;
           mn=INT_MAX;
       }

       void push(int val){
           if(top==n-1){
               cout<<"Stack Overflow"<<endl;
               return;
           }

          if(top==-1){
              top++;
              a[top]=val;
              mn=val;
              return;
          }
          
          if(val>=mn){
              top++;
              a[top]=val;
              return;
          }

          if(val<mn){
             top++;
             a[top]=val+(val-mn);
             mn=val;
          }
          
       }
       
       void pop(){
           if(top==-1){
               cout<<"no elements to be popped"<<endl;
               return;
           }
           if(a[top]>=mn)top--;
           else{
               mn=2*mn-a[top];
               top--;
           }
       }

       int Top(){
           if(top==-1){
               cout<<"no element is present in the stack"<<endl;
               return -1;
           }
           if(a[top]>=mn) return a[top];
           else return mn;
       }
       
       int min(){
           if(top==-1){
               cout<<"Empty Stack"<<endl;
               return -1;
           }
           return mn;
       }

       bool empty(){
           return top==-1;
       }
};

int main(){
    stacks st;
    st.push(10);
    st.push(6);
    st.push(8);
    st.push(2);
    cout<<st.Top()<<endl;
    cout<<st.min()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    cout<<st.min()<<endl;
    cout<<st.empty()<<endl;
    return 0;
}