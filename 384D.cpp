#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#define vi vector<long long>
#define vvi vector< vector<long long> >
#define ll long long	
#define mp make_pair
#define si map<long long,long long>::iterator
#define rep(a,b,c) for(ll c = a;c <= b;c++)
using namespace std;

ll a[200005],b[200005] = {},m = -1000000005;

ll f = 1,pf = 0;

bool marked[200005] = {};

vector<vector<ll> > v;

void dfs(ll u,ll pv){
	marked[u] = 1;
	if(u == 1 && v[u].size() == 1){
		dfs(v[u][0],u);
		b[u] = b[u] + b[v[u][0]];
	}
	if((v[u].size() == 2) && u != f){
		b[u] = a[u];
		return;
	}
	else if(v[u].size() == 2 && u == f){
		if(v[u][0] == pf){
			dfs(v[u][1],u);
			b[u] = a[u] + b[v[u][1]];
		}
		else{
			dfs(v[u][0],u);
			b[u] = a[u] + b[v[u][0]];
		}
	}
	b[u] = a[u];
	rep(0,v[u].size() - 1,i){
		if(v[u][i] != pv && !marked[v[u][i]]){
			dfs(v[u][i],u);
			b[u] += b[v[u][i]];
		}
	}
}

void calc(ll u,ll pv){
	if(v[u].size() == 1){
		m = max(m,b[u]);
		return;
	}
	m = max(m,b[u]);
	rep(0,v[u].size() - 1,i){
		if(v[u][i] != pv){
			calc(v[u][i],u);			
		}
	}
}



int main(){
	ll n; cin >> n;
	if(n == 1){
		ll tmp; cin >> tmp;
		cout << "Impossible";
		return 0;
	}
	rep(1,n,i){
		cin >> a[i];
		vector<ll> t;
		v.push_back(t);
	}
	vector<ll> t;
	v.push_back(t);
	v.push_back(t);
	rep(1,n - 1,i){
		ll x,y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<ll> val;
	bool poss = 0;
	if(v[1].size() == 1){
		while(v[f].size() <= 2){
			if(f == 1 && v[f].size() == 1){
				pf = f;
				f = v[f][0];
			}
			else if(v[f].size() == 1){
				poss = 1;
				break;
			}
			else{
				if(v[f][0] == pf){
					pf = f;
					f = v[f][1];
				}
				else{
					pf = f;
					f = v[f][0];
				}
			}
		}
	}
	dfs(1,0);
	if(poss || v[1].size() == 0){
		cout << "Impossible";
		return 0;
	}
	rep(0,v[f].size() - 1,i){
		m = -1000000005;
		if(v[f][i] != pf){
			calc(v[f][i],f);
			val.push_back(m);
		}
	}
	sort(val.begin(),val.end());
	ll tmp = val.size(); 
	(tmp > 1) ? cout <<  val[tmp - 1] + val[tmp - 2] : cout << "Impossible";
}