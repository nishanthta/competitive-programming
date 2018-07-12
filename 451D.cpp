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
#define mp make_pair
#define si map<long long,long long>::iterator
#define rep(a,b,c) for(ll c = a;c < b;c++)
#define brep(a,b,c) for(ll c = a;c >= b;c--)
#define pb emplace_back;
#define all(v) v.begin(), v.end()
#define MAXN 501
using namespace std;
 
ll a[200005];
ll bit[1000005];
 
void upd(ll b[],ll n,ll idx,ll val){
	while(idx <= n){
		b[idx] += val;
		idx += idx&(-idx);
	}
}
ll sum(ll b[],ll idx){
	ll s = 0;
	while(idx > 0){
		s += b[idx];
		idx -= idx&(-idx);
	}
	return s;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m,k;
	cin >> n >> m >> k;
	rep(0,n,i) cin >> a[i];
	sort(a,a+n);
	set <ll> temp;
	ll r = 0;
	rep(0,n,i){
		temp.insert(a[i]);
		upd(bit,n,a[i],1);
		if(a[i] < m)continue;
		ll sum1 = sum(bit,a[i]);
		ll sum2 ;
		if(a[i] == m) sum2=0;
		else sum2 = sum(bit,a[i]-m);
		ll x = sum1 - sum2;
		while(x >= k){
			ll val = *temp.rbegin();
			temp.erase(temp.find(val));
			upd(bit,n,val,-1);
			x--;
			r++;
		}
	}
	cout << r;
}