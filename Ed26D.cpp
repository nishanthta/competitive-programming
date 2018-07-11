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
#define vi vector<long long>
#define vvi vector< vector<long long> >
#define ll long long	
#define mp make_pair
#define si map<long long,long long>::iterator
#define rep(a,b,c) for(ll c = a;c < b;c++)
#define brep(a,b,c) for(ll c = a;c >= b;c--)
using namespace std;

const ll MOD = 1e9 + 7,N = 100005;

bool comp1(tuple<int, int, int, int> a, tuple<int, int, int, int> b){
	if (get<0>(a) == get<0>(b)){
		return get<2>(a) > get<2>(b);
	}
	return get<0>(a) > get<0>(b);
}

bool comp2(tuple<int, int, int, int> a, tuple<int, int, int, int> b){
	if (get<1>(a) == get<1>(b)){
		return get<2>(a) > get<2>(b);
	}
	return get<1>(a) > get<1>(b);
}

int main(){
	int n, k;
	cin >> n >> k;
	ll a[n];
	vector<tuple<int, int, int, int>> v2, v5;
	rep(0, n, i){
		cin >> a[i];
		int x = 0, y = 0;
		while (a[i]%2 == 0){
			++x;
			a[i] /= 2;
		}
		while (a[i]%5 == 0){
			++y;
			a[i] /= 5;
		}
		int order = min(x, y);
		v2.push_back(make_tuple(x, y, order, i));
		v5.push_back(make_tuple(x, y, order, i));
	}
	sort(v2.begin(), v2.end(), comp1);
	sort(v5.begin(), v5.end(), comp2);
	bool mark[n] = {false};
	ll p1 = 0, p2 = 0, ans1 = 0, ans2 = 0, used = 0, twos = 0, fives = 0;
	while (used < k && p1 < n && p2 < n){

			//cout << used << ' ' << twos << ' ' << fives << ' ' << p1 << ' ' << p2 << '\n';
		if (twos <= fives){
			if (mark[get<3>(v2[p1])] == true)
			{
				++p1;
				continue;
			}
			twos += get<0>(v2[p1]);
			fives += get<1>(v2[p1]);
			mark[get<3>(v2[p1])] = true;
			++used;
			++p1;
		}
		else{
		if (mark[get<3>(v5[p2])] == true)
			{
				++p2;
				continue;
			}
			++used;			
			mark[get<3>(v5[p2])] = true;
			twos += get<0>(v5[p2]);
			fives += get<1>(v5[p2]);
			++p2;
		}
	}
	while (used < k && p1 < n){
		
		if (mark[get<3>(v2[p1])] == true)
			{
				++p1;
				continue;
			}
		//cout << twos << ' ' << fives << ' ' << p1 << ' ' << p2 << '\n';
			++used;
		twos += get<0>(v2[p1]);
			fives += get<1>(v2[p1]);
			++p1;
	}
	while (used < k && p2 < n){

		if (mark[get<3>(v5[p2])] == true)
			{
				++p2;
				continue;
			}
			//cout << twos << ' ' << fives << ' ' << p1 << ' ' << p2 << '\n';
			++used;
		twos += get<0>(v5[p2]);
			fives += get<1>(v5[p2]);
			++p2;
	}
	ans1 = min(twos, fives);
	p1 = 0, p2 = 0, twos = 0, fives = 0, used = 0;
	rep(0, n, i){
		mark[i] = false;
	}
	while (used < k && p1 < n && p2 < n){

			//cout << used << ' ' << twos << ' ' << fives << ' ' << p1 << ' ' << p2 << '\n';
		if (twos < fives){
			if (mark[get<3>(v2[p1])] == true)
			{
				++p1;
				continue;
			}
			twos += get<0>(v2[p1]);
			fives += get<1>(v2[p1]);
			mark[get<3>(v2[p1])] = true;
			++used;
			++p1;
		}
		else{
		if (mark[get<3>(v5[p2])] == true)
			{
				++p2;
				continue;
			}
			++used;			
			mark[get<3>(v5[p2])] = true;
			twos += get<0>(v5[p2]);
			fives += get<1>(v5[p2]);
			++p2;
		}
	}
	while (used < k && p1 < n){
		
		if (mark[get<3>(v2[p1])] == true)
			{
				++p1;
				continue;
			}
		//cout << twos << ' ' << fives << ' ' << p1 << ' ' << p2 << '\n';
			++used;
		twos += get<0>(v2[p1]);
			fives += get<1>(v2[p1]);
			++p1;
	}
	while (used < k && p2 < n){

		if (mark[get<3>(v5[p2])] == true)
			{
				++p2;
				continue;
			}
			//cout << twos << ' ' << fives << ' ' << p1 << ' ' << p2 << '\n';
			++used;
		twos += get<0>(v5[p2]);
			fives += get<1>(v5[p2]);
			++p2;
	}
	ans2 = min(twos, fives);
	cout << max(ans1, ans2) << '\n';
}