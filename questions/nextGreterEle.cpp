#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterEle(int a[],int n){
    stack<int> st;
    vector<int> v(n,-1);
    st.push(0);
    for(int i=1; i<n; i++){
        while(!st.empty() && a[i]>=a[st.top()]){
             v[st.top()]=a[i];
             st.pop();
        }
        st.push(i);
    }
    // while(!st.empty()){
    //     v[st.top()]=-1;
    //     st.pop();
    // }
    return v;
}

// vector<int> nextGreaterEle(int a[],int n){
//     stack<int> st;
//     vector<int> v;
//     for(int i=n-1; i>=0; i--){

//         while(!st.empty() && a[i]>=st.top()) st.pop();

//         if(st.empty()) v.push_back(-1);
//         else v.push_back(st.top());

//         st.push(a[i]);
        
//     }
//     return v;
// }

int main(){
    int a[]={2,5,9,3,1,12,6,8,7};

    vector<int> ans=nextGreaterEle(a,9);

    // reverse(ans.begin(),ans.end());
    for(auto val:ans){
        cout<<val<<" ";
    }
    return 0;
}