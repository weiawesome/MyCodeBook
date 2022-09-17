//find path
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> q{k},distance(n+1,INT_MAX);
        distance[k]=0;
        vector<vector<pair<int,int>>> m(n+1,vector<pair<int,int>>(0));
        for(auto i:times){
            m[i[0]].push_back({i[1],i[2]});
        }
        int front;
        while(!q.empty()){
            front=q.front();
            for(auto i:m[front]){
                if(distance[front]+i.second<distance[i.first]){
                    distance[i.first]=distance[front]+i.second;
                    q.push_back(i.first);
                }
            }
            q.erase(q.begin());
        }
        int result=0;
        for(int i=1;i<distance.size();i++){
            result=max(result,distance[i]);
        }
        return result==INT_MAX ? -1:result;
    }
};
int main(){
    //Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
    //Output: 2
    Solution s;
    vector<vector<int>> times{{2,1,1},{2,3,1},{3,4,1}};
    int n=4,k=2;
    cout<<s.networkDelayTime(times,n,k);
}