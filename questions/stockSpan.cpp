#include<bits/stdc++.h>
using namespace std;
vector<int> stockSpan(int a[],int n){
    stack<int> st;
    st.push(0);
    vector<int> v;
    v.push_back(1);

    for(int i=1; i<n; i++){
        while(!st.empty() && a[i]>=a[st.top()]){
            st.pop();
        }
        if(st.empty()) v.push_back(i+1);
        else v.push_back(i-st.top());

        st.push(i);
    }

    return v;
}

int main(){
    int a[]={2,5,9,3,1,12,6,8,7};
    vector<int> ans=stockSpan(a,9);
    for(auto val:ans){
        cout<<val<<" ";
    }
    return 0;
}