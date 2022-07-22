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

	int n;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}

	int cnt[n+5];
	fill(cnt, cnt+n+5, 0);
	
	int ans = 0;
	for(int x=0;x<n;x++){
		if(cnt[data[x]] == 0) ans++;
		cnt[data[x]]++;
	}
	
	int mn = 0, mx = ans;
	for(int x=n;x>=1;x--){
		if(cnt[x] > 0){
			if(cnt[x+1] == 0){
//				cout << "-> " << x << "\n";
				cnt[x+1]++;
				cnt[x]--;
				mx++;
				if(cnt[x] == 0) mx--;
			}
		}
	}
	for(int x=1;x<=n;x++){
		if(cnt[x] > 0){
			if(cnt[x-1] == 0){
//				cout << "<- " << x << "\n";
				cnt[x-1]++;
				cnt[x]--;
				mx++;
				if(cnt[x] == 0) mx--;
			}
		}
	}
		
	fill(cnt, cnt+n+5, 0);
	for(int x=0;x<n;x++){
		cnt[data[x]]++;
	}
	
	int cur = 1;
	while(cur <= n){
		if(cnt[cur] > 0){
			mn++;
			cur += 2;
		}
		cur++;
	}
	
	cout << mn << " " << mx << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

