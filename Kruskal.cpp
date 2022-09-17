#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> m;
    int r=0;
public:
    int md(vector<int> v1,vector<int> v2){
        return abs(v1[0]-v2[0])+abs(v1[1]-v2[1]);
    }
    bool istree(vector<pair<int,int>> &v){
        int v1=v.back().first,v2=v.back().second;
        if(m[v1]==0 && m[v2]==0){
            r++;
            m[v1]=r;
            m[v2]=r;
            return true;
        }
        if(m[v1]==m[v2]){
            v.pop_back();
            return false;
        }
        if(m[v1]==0){
            m[v1]=m[v2];
        }
        if(m[v2]==0){
            m[v2]=m[v1];
        }
        if(m[v1]!=m[v2]){
            int val1=m[v1],val2=m[v2];
            replace(m.begin(),m.end(),val1,val2);
        }
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        m.resize(1e3+1,0);
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<points.size()-1;i++){
            for(int j=i+1;j<points.size();j++){
                v.push_back({md(points[i],points[j]),{i,j}});
            }
        }
        sort(v.begin(),v.end());
        int sum=0;
        vector<pair<int,int>> vs;
        for(auto i: v){
            vs.push_back(i.second);
            if(istree(vs)){
                sum+=i.first;
            }
        }
        return sum;
    }
};
int main(){
    Solution s;
    vector<vector<int>> v{{0,0},{5,2},{3,7}};
    cout<<s.minCostConnectPoints(v);
}