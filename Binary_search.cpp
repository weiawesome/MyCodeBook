#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v{2,3,4,6,7,9};
    int target=7;
    int low=0,high=v.size()-1,mid;
    //find target
    while(low<=mid){
        mid=(low+high)/2;
        if(v[mid]==target){
            break;
        }
        else if(v[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
}