#include <bits/stdc++.h>

using namespace std;

#define ll long long

int askAnd(int i, int j){
	cout << "AND " << i+1 << " " << j+1 << endl;
	
	int res;
	cin >> res;
	
	return res;
}

int askOr(int i, int j){
	cout << "OR " << i+1 << " " << j+1 << endl;
	
	int res;
	cin >> res;
	
	return res;
}

int askXor(int i, int j){
	cout << "XOR " << i+1 << " " << j+1 << endl;
	
	int res;
	cin >> res;
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=1;x<n;x++){
		a[x] = askXor(x-1, x);
	}
	
	int p1 = -1, p2 = -1;
	map<int, int> mp;
	int cur = 0;
	for(int x=1;x<n;x++){
		mp[cur] = x-1;
		cur ^= a[x];
		
		if(mp.find(cur) != mp.end()){
			p1 = mp[cur];
			p2 = x;
			break;
		}
	}
	
	// there is no duplicate
	if(p1 == -1){
		mp.clear();
		cur = 0;
		
		vector<pair<int, int>> v;
		int cur = 0;
		for(int x=1;x<n;x++){
			mp[cur] = x-1;
			cur ^= a[x];
			
			if(mp.find(cur^(n-1)) != mp.end()){
				p1 = mp[cur^(n-1)];
				p2 = x;
				break;
			}
		}
		
		auto ask = [&](int l, int r) -> int {
			if(l > r) swap(l, r);
			
			int ans = 0;
			for(int x=l+1;x<=r;x++){
				ans ^= a[x];
			}
			
			return ans;	
		};
		
		int ans[n];
		fill(ans, ans+n, 0);
		
		int p3 = -1;
		for(int x=0;x<n;x++){
			if(p1 == x || p2 == x) continue;
			
			int res = ask(p1, x);
			int res2 = askAnd(p1, x);
			int res3 = askAnd(p2, x);
			
			for(int y=0;y<log2(n);y++){
				int bit = (1 << y);
				
				if((res&bit) && (res3&bit)){
					ans[x] |= bit;
				} else if(!(res&bit) && (res2&bit)){
					ans[x] |= bit;
				}
			}
			
			for(int y=x;y>=1;y--){
				ans[y-1] = a[y]^ans[y];
			}
			for(int y=x+1;y<n;y++){
				ans[y] = a[y]^ans[y-1];
			}
			
			cout << "!";
			for(int x=0;x<n;x++){
				cout << " " << ans[x];
			}
			cout << endl;
			break;
		}
	} else { // there is duplicate
		int ans[n];
		
		ans[p1] = ans[p2] = askOr(p1, p2);
		for(int x=p1;x>=1;x--){
			ans[x-1] = a[x]^ans[x];
		}
		for(int x=p1+1;x<n;x++){
			ans[x] = a[x]^ans[x-1];
		}
		
		cout << "!";
		for(int x=0;x<n;x++){
			cout << " " << ans[x];
		}
		cout << endl;
	}
    return 0;
}

