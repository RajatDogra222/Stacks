#include<bits/stdc++.h>
using namespace std;
int prec(char ch){
    if(ch=='^'){
        return 3;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string intopost(string s){
    stack<char> st;
    string res;

    for(int i=0; i<s.size(); i++){

        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='z')){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            bool alreadypush=false;
            while(!st.empty() && prec(st.top())>=prec(s[i])){
                // if(s[i]=='^' && st.top()=='^'){
                //     st.push(s[i]);
                //     alreadypush=true;
                //     break;
                // }
                // else{
                  res+=st.top();
                  st.pop();
                // }
            }
            // if(!alreadypush){
               st.push(s[i]);
            // }
        }
    }

    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}
int main(){
    string s;
    s="K+L-M*N+O^P*W/U/V*T+Q";
    // s="a^b^c";
    // s="(a-b/c)*(a/k-l)";
    // s="A*(B+C)/D";
    cout<<intopost(s);
    return 0;
}