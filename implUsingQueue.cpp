#include<bits/stdc++.h>
using namespace std;

class stacks{
    queue<int> q1;
    queue<int> q2;

    public:
    // void push(int val){
    //     q2.push(val);
    //     if(!q1.empty()){
    //         while(!q1.empty()){
    //             q2.push(q1.front());
    //             q1.pop();
    //         }
    //     }
    //     while(!q2.empty()){
    //        q1.push(q2.front());
    //        q2.pop();
    //     }
    // }
    
    void push(int val){
        q1.push(val);
        for(int i=0; i<q1.size()-1; i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    void pop(){
        if(q1.empty()){
            cout<<"no element is present in stack"<<endl;
            return;
        }
        q1.pop();
    }
     
    int Top(){
         if(q1.empty()){
            cout<<"no element is present in stack"<<endl;
            return -1;
        }
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};

int main(){
    stacks st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    cout<<st.empty()<<endl;
    return 0;
}