//Radhe Radhe
// love lines:  

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define debug(x) cout << "Debug " #x << ": " << x << endl;
#define pb push_back
#define present cout << "PRESENT" << endl;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define printlist(x) for(auto it : x) cout<<it<<" ";cout<<endl;
const ll M = 1000000007;
ll Factorial[500000+10];
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// X.find_by_order(k)  return the kth smallest element (zero based)
// X.order_of_key(k)  return the count of element strictly less than K
ll add(ll x, ll y)  { return (x%M + y%M)%M; }
ll sub(ll x, ll y)  { return (x%M - y%M + M)%M; }
ll mul(ll x, ll y)  { return (x%M * y%M)%M; }

void print(vector<ll> v1) {
    for (auto x : v1) { cout << x << " "; }
    cout << endl;
}

ll binexp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = ((res%M)*(a%M)%M);
        a = ((a%M)*(a%M)%M);
        b >>= 1LL;
    }
    return res % M;
}

void make_factorial() {
    Factorial[0] = 1;
    for (int i = 1; i < 500010; i++)
        Factorial[i] = (Factorial[i-1] * i) % M;
}

ll Mod_Inv(ll a) {
    return binexp(a % M, M-2);
}

int nCr(ll n, ll r) {
    return (((Factorial[n] * Mod_Inv(Factorial[r])) % M) * Mod_Inv(Factorial[n-r])) % M;
}

void love(bool flag) {
    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}

void Radhe() {
        // I don't care about Rating, I like Experience
        
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
    Radhe();
    }
    return 0;
}
