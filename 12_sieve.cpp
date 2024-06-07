//Radhe Radhe
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int N = 10e6;
vector<bool>isprime(N,true);
void sieve() {
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (isprime[i]) {
            for (int j = i * i; j < N; j += i) {
                isprime[j] = false;
            }
        }
    }
}
int main(){
sieve();
return 0;
}
