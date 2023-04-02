#include<bits/stdc++.h>
using namespace std;

vector<int> greaterele(int a[],int n){

    stack<int> st;
    st.push(n-1);
    vector<int> v(n);
    v[n-1]=n;

    for(int i=n-2; i>=0; i--){
        while(!st.empty() && a[i]>=a[st.top()]) st.pop();

        if(st.empty()) v[i]=n;
        else v[i]=st.top();

        st.push(i);
    }

    return v;
}

vector<int> slidingWindow(int a[],int n,int k){
    deque<int> dq;
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(!dq.empty() && dq.front()==i-k)  dq.pop_front();
        
        while(!dq.empty() && a[i] >= a[dq.back()]) dq.pop_back();
        
        dq.push_back(i);
        if(i>=k-1)
            ans.push_back(a[dq.front()]);
    }

    return ans;
}


int main(){
    int a[]={2,9,3,8,1,7,12,6,14,4,32,0,7,19,8,12,6};
    int n=sizeof(a)/sizeof(a[0]);

    // vector<int> nge=greaterele(a,n);

    // for(auto val: nge){
    //     cout<<a[val]<<" ";
    // }
    // cout<<endl<<endl;
    
    // int j=0;
    // for(int i=0; i<n-4+1; i++){
    //     if(j<i) j=i;

    //     while(nge[j] < i+4) j=nge[j];

    //     cout<<a[j]<<" ";
        
    // }

    vector<int> ans=slidingWindow(a,n,4);
    cout<<endl;
    for(auto val:ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}