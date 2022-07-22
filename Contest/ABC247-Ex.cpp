#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll k;
	cin >> n >> k;
	
	int c[n];
	for(int x=0;x<n;x++){
		cin >> c[x];
		c[x]--;
	}
	
	int cnt[n];
	fill(cnt, cnt+n, 0);
	
	for(int x=0;x<n;x++){
		cnt[c[x]]++;
	}
	
	
    return 0;
}

