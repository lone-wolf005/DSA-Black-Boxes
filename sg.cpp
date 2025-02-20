#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class SGTree {
public:
    vector<ll> seg;
    vector<ll> lazy;
    int n;

    SGTree(int n) {
        seg.resize(4 * n + 1, 0);
        lazy.resize(4 * n + 1, 0);
        this->n = n;
    }

    void build(int ind, int low, int high, vector<ll>& arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind, low, mid, arr);
        build(2 * ind + 1, mid + 1, high, arr);
        seg[ind] = seg[2 * ind] + seg[2 * ind + 1];
    }

    void propagate(int ind, int low, int high) {
        if (lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high) {
                lazy[2 * ind] += lazy[ind];  
                lazy[2 * ind + 1] += lazy[ind];  
            }
            lazy[ind] = 0;  // Reset after propagation
        }
    }

    void update(int ind, int low, int high, int l, int r, ll val) {
        propagate(ind, low, high);  // Apply any pending updates before proceeding

        if (high < l || low > r) return;  // No overlap case

        if (low >= l && high <= r) {  // Complete overlap case
            seg[ind] += (high - low + 1) * val;
            if (low != high) {  // Not a leaf node
                lazy[2 * ind] += val;  // Fix: Correct indexing
                lazy[2 * ind + 1] += val;  // Fix: Correct indexing
            }
            return;
        }

        int mid = (low + high) / 2;
        update(2 * ind, low, mid, l, r, val);
        update(2 * ind + 1, mid + 1, high, l, r, val);
        seg[ind] = seg[2 * ind] + seg[2 * ind + 1];  // Recalculate after update
    }

    ll query(int ind, int low, int high, int l, int r) {
        propagate(ind, low, high);  // Apply pending updates before proceeding

        if (high < l || low > r) return 0;  // No overlap case

        if (low >= l && high <= r) return seg[ind];  // Complete overlap case

        int mid = (low + high) / 2;
        ll left = query(2 * ind, low, mid, l, r);
        ll right = query(2 * ind + 1, mid + 1, high, l, r);
        return left + right;
    }
};

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SGTree sg(n);
    sg.build(1, 0, n - 1, arr);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {  // Range update
            int l, r;
            ll val;
            cin >> l >> r >> val;
            --l; --r;
            sg.update(1, 0, n - 1, l, r, val);
        } else if (type == 2) {  // Range query
            int l,r;
            cin >> l >>r;
            --l;--r;
            cout << sg.query(1, 0, n - 1, l, l) << endl;
        }
    }

    return 0;
}
