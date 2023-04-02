#include<bits/stdc++.h>
using namespace std;
void reverseSent(string s){
     stack<string> st;
     for(int i=0; i<s.size(); i++){

         string word="";
        while(s[i]!=' ' && i<s.size()){
            word+=s[i];
            i++;
        }

        st.push(word);
     }

     while(!st.empty()){
         cout<<st.top()<<" ";
         st.pop();
     }
     cout<<endl;
}

int main(){
    string s="hey, how are you?";
    reverseSent(s);
    return 0;
}