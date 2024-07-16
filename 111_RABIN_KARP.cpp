#include <iostream>
#include <string>
#include <utility>

using namespace std;
#define ll long long int

class Solution {
    const ll M1 = 1e9+7;
    const ll M2 = 1e9+33;
    const ll RADIX1 = 27;
    const ll RADIX2 = 29;

    pair<ll, ll> RabinHash(const string &s, ll m) {
        ll factor1 = 1;
        ll factor2 = 1;
        ll hashValue1 = 0;
        ll hashValue2 = 0;
        for (int i = m - 1; i >= 0; i--) {
            hashValue1 = (hashValue1 + (s[i] - 'a') * factor1) % M1;
            hashValue2 = (hashValue2 + (s[i] - 'a') * factor2) % M2;
            factor1 = (factor1 * RADIX1) % M1;
            factor2 = (factor2 * RADIX2) % M2;
        }
        return {hashValue1 % M1, hashValue2 % M2};
    }

    int rabinkarp(const string &a, const string &pattern) {
        ll m = pattern.size();

        if (a.size() < m) return -1;

        ll MAX_VALUE1 = 1;
        ll MAX_VALUE2 = 1;

        for (int i = 0; i < m; i++) {
            MAX_VALUE1 = (RADIX1 * MAX_VALUE1) % M1;
            MAX_VALUE2 = (RADIX2 * MAX_VALUE2) % M2;
        }

        pair<ll, ll> patternHashValue = RabinHash(pattern, m);
        pair<ll, ll> stringHashValue = {0, 0};

        for (int i = 0; i <= a.size() - m; i++) {
            if (i == 0) {
                stringHashValue = RabinHash(a, m);
            } else {
                stringHashValue.first =
                    (stringHashValue.first * RADIX1 % M1 -
                     (a[i - 1] - 'a') * MAX_VALUE1 % M1 +
                     (a[i + m - 1] - 'a') + M1) % M1;

                stringHashValue.second =
                    (stringHashValue.second * RADIX2 % M2 -
                     (a[i - 1] - 'a') * MAX_VALUE2 % M2 +
                     (a[i + m - 1] - 'a') + M2) % M2;
            }

            if (stringHashValue.first == patternHashValue.first &&
                stringHashValue.second == patternHashValue.second) {
                return i;
            }
        }
        return -1;
    }

public:
    int strStr(string haystack, string needle) {
        return rabinkarp(haystack, needle);
    }
};
