#include <bits/stdc++.h>
using namespace std;
vector<bool> prime_table;
void build_prime_table(int size){
    int multi;
    prime_table.assign(size+1,true);
    prime_table[0]= false;
    prime_table[1]=false;
    for(int i=0;i<=size;i++){
        if(prime_table[i]){
            multi=2;
            while(i*multi<=size){
                prime_table[i*multi]=false;
                multi++;
            }
        }
    }
}
int main(){
    build_prime_table(50);
}