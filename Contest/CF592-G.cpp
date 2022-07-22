#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, k;
	cin >> n >> k;
	
	if(n*(n+1)/2 > k){
		cout << "-1\n";
		return 0;
	}
	
	ll cnt = n*(n+1)/2;
	
	bool done[n+1];
	fill(done, done+n+1, false);
	
	int p[n], cur = n;
	fill(p, p+n, -1);
	
	for(int x=0;x<n/2;x++){
		while(cnt+cur-x-1 > k){
			cur--;
		}
		if(cur <= x+1) break;
		
		cnt += cur-x-1;
		done[cur] = true;
		p[x] = cur--;
	}
	
	int pos = 1;
	for(int x=0;x<n;x++){
		if(p[x] != -1) continue;
		
		while(done[pos]) pos++;
		p[x] = pos++;
	}
	
	cout << cnt << "\n";
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << x+1;
	}
	cout << "\n";
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << p[x];
	}
	cout << "\n";
    return 0;
}

