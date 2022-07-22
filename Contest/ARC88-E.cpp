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

const int maxN = 2e5 + 50;

ll tree[maxN];

ll query(int pos){
	pos = maxN-pos-5;
	
	ll ans = 0;
	while(pos > 0){
		ans += tree[pos];
		
		pos -= pos & (-pos);
	}
	return ans;
}

void update(int pos, ll val){
	pos = maxN-pos-5;
	
	while(pos < maxN){
		tree[pos] += val;
		
		pos += pos & (-pos);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	string s;
	cin >> s;
	
	fill(tree, tree+maxN, 0ll);
	
	deque<int> cnt[26];
	for(int x=0;x<s.length();x++){
		cnt[(s[x] - 'a')].push_back(x);
	}
	
	int odd = 0;
	for(int x=0;x<26;x++){
		if(cnt[x].size()&1) odd++;
	}
	
	if(odd > 1){
		cout << "-1\n";
		return 0;
	}
	
	bool picked[s.length()];
	fill(picked, picked+s.length(), false);
	
	int a[s.length()];
	ll ans = 0, pos = 0;
	for(int x=0;x<s.length();x++){
		if(picked[x]) continue;
		
		int idx = (s[x] - 'a');
		if(cnt[idx].size() == 1){
			continue;
		}
		
		a[pos] = cnt[idx].front();
		a[s.length()-pos-1] = cnt[idx].back();
		pos++;
		
		picked[cnt[idx].front()] = true;
		picked[cnt[idx].back()] = true;
		cnt[idx].pop_front(); cnt[idx].pop_back();
	}
	for(int x=0;x<26;x++){
		if(cnt[x].size() == 1){
			a[pos] = cnt[x].front();
			cnt[x].pop_back();
		}
	}
	
	for(int x=0;x<s.length();x++){
		ans += query(a[x]+1);
		
		update(a[x], 1);
	}
	
	cout << ans << "\n";
    return 0;
}

