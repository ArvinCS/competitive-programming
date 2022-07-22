#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	int n = s.length();
	ll prefix[2*n], cnt[2*n];
	fill(prefix, prefix+2*n, 0);
	fill(cnt, cnt+2*n, 0);
	
	for(int x=0;x<n;x++){
		prefix[n+x] = (s[x] - '0');
		if(x > 0) prefix[n+x] += prefix[n+x-1];
	}
	
	vector<int> ans;
	for(int x=2*n-1;x>=0;x--){
		ll val = prefix[x] + cnt[x];
		ans.push_back(val%10);
		val /= 10;
		
		int pos = x-1;
		while(val > 0){
			cnt[pos] += val%10;
			
			val /= 10;
			pos--;
		}
	}
	
	reverse(ans.begin(), ans.end());
	
	bool valid = false;
	for(int x=0;x<ans.size();x++){
		if(ans[x] == 0){
			if(valid) cout << ans[x];
		} else {
			cout << ans[x];
			valid = true;
		}
	}
	cout << "\n";
    return 0;
}

