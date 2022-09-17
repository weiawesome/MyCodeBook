#include<bits/stdc++.h>
using namespace std;
int main(){
    //LCS
    string s1="ABCABCBA",s2="CBABCABCC";
    vector<vector<int>> v(s1.length()+1,vector<int> (s2.length()+1,0));
    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
            if(s1[i-1]==s2[j-1]){
                v[i][j]=v[i-1][j-1]+1;
            }
            else{
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
    }
    //LIS
    vector<int> v1{1,4,6,7,2,3,5,2,4,6,7,3,9};
    vector<int> sv;
    int high,low,mid;
    for(auto i:v1){
        if(sv.empty()){
            sv.push_back(i);
        }
        else{
            if(i>sv.back()){
                sv.push_back(i);
            }
            else{
                low=0;
                high=sv.size()-1;
                while(low<high){
                    mid=(low+high)/2;
                    if(sv[mid]==i){
                        break;
                    }
                    else if(sv[mid]>i){
                        high=mid;
                    }
                    else{
                        low=mid+1;
                    }
                }
                sv[(low+high)/2]=i;
            }
        }
    }
}