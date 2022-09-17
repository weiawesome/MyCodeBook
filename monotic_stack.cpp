#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v{1,6,3,4,7,2,5};
    vector<int> record(v.size(),-1),st;
    //find next greater one
    for(int i=0;i<v.size();i++){
        if(st.empty()){
            st.push_back(i);
        }
        else{
            while(!st.empty() && v[st.back()]<v[i]){
                record[st.back()]=i;
                st.pop_back();
            }
            st.push_back(i);
        }
    }
}