#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <map>
#include <cstdio>
#include <bitset>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <set>
#include <tuple>
#include <unordered_map>
#define vi vector<long long>
#define vvi vector< vector<long long> >
#define ll long long	
#define mp make_pair
#define si map<long long,long long>::iterator
#define rep(a,b,c) for(ll c = a;c < b;c++)
#define brep(a,b,c) for(ll c = a;c >= b;c--)
#define pb push_back
using namespace std;


ll modular_pow(ll base, ll exponent, ll modulus){
    ll result = 1;
    while (exponent > 0){
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}


map<ll,vector<ll> > elem;

int main() {
	ll n,ans = 0; cin >> n;
    rep(0,n,j) {
        ll a; cin >> a;
        vector<pair<ll,ll> > v;
        for (int i = 2; i*i <= a; i++) {
            if(!(a%i)) {
                v.push_back(mp(i,0));
                while (!(a%i)) { v[v.size()-1].second++; a = a/i;}
            }
        }
        if (a > 1) v.push_back(mp(a,1));
        for (auto p : v) elem[p.first].push_back(p.second);
    }
    for (auto it: elem) {
        n = it.second.size();
        sort(it.second.begin(), it.second.end()); ans^= it.second[0];
        rep(0,n,i) ans ^= (it.second[i]-it.second[i-1]);
    }
    if (!ans) cout << "Arpa" << endl;
    else	cout << "Mojtaba" << endl;
}