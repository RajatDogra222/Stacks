#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &st,int ele){
     
     if(st.empty()){
         st.push(ele);
         return;
     }

     int val=st.top();
     st.pop();
     insertAtBottom(st,ele);
     st.push(val);
}

void reverseStack(stack<int> &st){

    if(st.empty()){
        return;
    }

    int ele=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,ele);
}

int main(){
    stack<int> st;
    for(int i=6; i>=1; i--){
        st.push(i);
    }
    reverseStack(st);

    for(int i=6; i>=1; i--){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}