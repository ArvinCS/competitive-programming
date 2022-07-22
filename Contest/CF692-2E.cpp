#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	ll n, m;
	cin >> n >> m;
	
	string s;
	cin >> s;
	
	ll sum = (1 << (s.back() - 'a')) - (1 << (s[n-2] - 'a'));
	int cnt[26];
	fill(cnt, cnt+26, 0);
	
	for(int x=0;x<n-2;x++){
		cnt[(s[x] - 'a')]++;
		sum += (1ll << (s[x] - 'a'));
	}
	
	for(int x=25;x>=0;x--){
		while(cnt[x] > 0 && (sum - 2*(1ll << x)) >= m){
			cnt[x]--;
			sum -= 2*(1ll << x);
		}
	}
	
	if(sum == m){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
    return 0;
}

