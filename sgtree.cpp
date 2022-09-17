#include <bits/stdc++.h>
using namespace std;
vector<int> sgt;
int needsize(int size){
    if(size==1){
        return 1;
    }
    else if(size==2){
        return 3;
    }
    else{
        return 1+needsize(size/2)+needsize(size-size/2);
    }
}
void sgtree(vector<int> v,int h,int e,int target){
    if(h==e){
        sgt[target]=v[h];
        return ;
    }
    sgtree(v,h,(h+e)/2,target*2);
    sgtree(v,(h+e)/2+1,e,target*2+1);
    sgt[target]=sgt[target*2]+sgt[target*2+1];
}
void query(int r,int l,int target,int tr,int tl,int &result){
    if(r>=tr && l<=tl){
        result+=sgt[target];
        return ;
    }
    if(r==l || r>l){
        return;
    }
    else{
        query((r+l)/2+1,l,target*2+1,tr,tl,result);
        query(r,(r+l)/2,target*2,tr,tl,result);
    }
}
int main(){
    vector<int> v{1,2,3,4,5};
    sgt.resize(2*v.size()-1,0);
    sgtree(v,0,v.size()-1,1);
    int result=0,left=3,right=7;
    query(0,v.size()-1,1,left,right,result);
    cout<<result;
}