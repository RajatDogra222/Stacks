#include<bits/stdc++.h>
using namespace std;

bool dublBrac(string s){
    
    stack<char> st;
    for(int i=0; i<s.size(); i++){

        if(s[i]!=')'){
            st.push(s[i]);
        }
        else{
            if(!st.empty() && st.top()=='(') return true;
            while(!st.empty() && st.top()!='(')
                st.pop();
            st.pop();
        }
    }

    return false;
}

int main(){
    string s="(a+b) + ((c+d))";
    bool isdub=dublBrac(s);
    if(isdub) cout<<"true";
    else cout<<"false";
    return 0;
}