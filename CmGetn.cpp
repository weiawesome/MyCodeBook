#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> v(100,vector<int> (100,1));
    for(int i=1;i<v.size();i++){
        for(int j=1;j<i;j++){
            v[i][j]=v[i-1][j-1]+v[i-1][j];
        }
    }
}