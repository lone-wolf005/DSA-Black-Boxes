//Radhe Radhe
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int N = 10e6;
vector<bool>isprime(N,true);
void seive(){
isprime[0] = isprime[1] = false;
for(int i = 2; i < N ; i++){
    if(isprime[i]){
        for(int j = 2*i ; j < N ; j+=i){
            isprime[j]=false;
        }
    }
}
}
int main(){
seive();
return 0;
}