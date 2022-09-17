#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> p1,pair<int,int> p2){
    return p1.second<p2.second;
}
int main(){
    vector<pair<int,int>> v{{0,5},{1,3},{2,7}};
    sort(v.begin(),v.end(),cmp);
}