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

const int maxN = 2e5 + 5;

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
	
	sort(data, data+n);
	
	int cnt[maxN], prefix[maxN];
	fill(cnt, cnt+maxN, 0);
	fill(prefix, prefix+maxN, 0);
	
	for(int x=0;x<n;x++){
		cnt[data[x]]++;	
	}
	
	vector<int> v;
	for(int x=1;x<maxN;x++){
		if(cnt[x] <= 1){
			v.push_back(x);
		}
		prefix[x] = cnt[x] + prefix[x-1];
	}
	
	int best = 0, left = -1, right = -1;
	for(int x=1;x<maxN;x++){
		if(cnt[x] == 0) continue;
		
		auto it = lower_bound(v.begin(), v.end(), x+1);
		int limit = *it;
		if(cnt[limit] == 0) limit--;
		
		int sum = (prefix[limit] - prefix[x-1]);
//		cout << x << " -> " << sum << " " << limit << "\n";
		if(sum > best){
			best = sum;
			left = x;
			right = limit;
		}
	}
	
//	cout << best << " " << left << " " << right << "\n";
	int ans[best];
	int l = 0, r = best-1;
	for(int x=left;x<=right;x++){
		while(cnt[x] > 0){
			ans[l++] = x;
			cnt[x]--;
			if(cnt[x] > 0){
				ans[r--] = x;
				cnt[x]--;
			}
		}
	}
	
	cout << best << "\n";
	for(int x=0;x<best;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

