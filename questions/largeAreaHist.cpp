#include<bits/stdc++.h>
using namespace std;

vector<int> smallEleFromRight(int a[],int n){
    stack<int> st;
    st.push(n-1);
    vector<int> v(n);
    v[n-1]=n;
    for(int i=n-2; i>=0; i--){
        while(!st.empty() && a[i]<=a[st.top()]) st.pop();

        if(st.empty()) v[i]=n;
        else v[i]=st.top();

        st.push(i);
    }
    
    return v;
}

vector<int> smallEleFromLeft(int a[],int n){
    stack<int> st;
    st.push(0);
    vector<int> v;
    v.push_back(-1);

    for(int i=1; i<n; i++){
        while(!st.empty() && a[i]<=a[st.top()]) st.pop();

        if(st.empty()) v.push_back(-1);
        else v.push_back(st.top());

        st.push(i);
    }

    return v;
}
int main(){
    int a[]={6,2,5,4,5,1,6};

    vector<int> rs=smallEleFromRight(a,7);
    vector<int> ls=smallEleFromLeft(a,7);

    int max=0;

    for(int i=0; i<7; i++){
        int width=rs[i]-ls[i]-1;
        int area=a[i]*width;
        if(area>max) max=area;
    }

    cout<<max<<endl;
    return 0;
}