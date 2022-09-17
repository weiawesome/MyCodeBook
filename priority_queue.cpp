#include <bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(int a,int b){
        return a>b;
    }
};
int main() {
    vector<int> v{5,2,4,3,1};
    priority_queue<int, vector<int>, cmp> q(v.begin(),v.end());
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();

    }
}