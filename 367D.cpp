#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#define vi vector<int>
#define vvi vector< vector<int> >
#define mp make_pair
#define si set<pair<int,int> >::iterator
#define loop(i,n) for(int i = 0;i <= n;i++)
#define loop1(i,n) for(int i = 1;i < n;i++)
#define loop2(i,n) for(int i = 0;i < n;i++)
using namespace std;
long long dp[100005][2],c[100005];
string rev(string r){
    reverse(r.begin(),r.end());
    string tmp = r;
    return tmp;
}
int main(){
    int n; cin >> n;
    loop2(i,n) cin >> c[i];
    vector <string> s;
    loop2(i,n){
        string x; cin >> x;
        s.push_back(x);
        dp[i][0] = dp[i][1] = 1000000000;
    }
    dp[0][0] = 0;
    dp[0][1] = c[0];
    loop1(i,n){
        if(s[i - 1] < s[i]){
            dp[i][0] = min(dp[i - 1][0],dp[i][0]);
        }
        if(s[i - 1] < rev(s[i])){
            dp[i][1] = min(dp[i - 1][0] + c[i],dp[i][1]);
        }
        if(rev(s[i - 1]) < s[i]){
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if(rev(s[i - 1]) < rev(s[i])){
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
        }
    }
    if(dp[n - 1][0] == 1000000000 && dp[n - 1][1] == 1000000000) dp[n - 1][0] = -1;
    cout << min(dp[n - 1][0],dp[n - 1][1]) << endl;
}