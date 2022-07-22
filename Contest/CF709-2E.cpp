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

const int maxN = 3e5 + 5;
const int lgN = log2(maxN)+1;

int n;
pair<int, int> a[maxN];
pair<ll, int> tree[2*maxN]; // for rmq opt sum

void update(int pos, ll val){
	pos += n;
	
	tree[pos] = max(tree[pos], {val, pos-n});
	for(int x=pos;x>1;x>>=1){
		tree[x>>1] = max(tree[x], tree[x^1]);
	}
}

pair<ll, int> query(int left, int right){
	pair<ll, int> val = {-inf_ll, -1};
	
	for(left += n, right += n; left < right; left >>= 1, right >>= 1){
		if(left&1) val = max(val, tree[left++]);
		if(right&1) val = max(val, tree[--right]);
	}
	return val;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;
	
	fill(tree, tree+2*maxN, make_pair(-inf_ll, -1));
	
	int pos[n];
	for(int x=0;x<n;x++){
		cin >> a[x].first;
		a[x].first--;
		pos[a[x].first] = x;
	}
	for(int x=0;x<n;x++){
		cin >> a[x].second;
	}
	
	stack<int> st;
	int left[n], right[n];
	for(int x=0;x<n;x++){
		while(!st.empty() && st.top() > a[x].first){
			st.pop();
		}
		
		if(st.empty()){
			left[x] = 0;
		} else {
			left[x] = pos[st.top()]+1;
		}
		
		st.push(a[x].first);
	}
	
	while(!st.empty()) st.pop();
	for(int x=n-1;x>=0;x--){
		while(!st.empty() && st.top() > a[x].first){
			st.pop();
		}
		
		if(st.empty()){
			right[x] = n-1;
		} else {
			right[x] = pos[st.top()]-1;
		}
		
		st.push(a[x].first);
	}
	
	ll ans = -inf_ll;
	int mn = inf_int;
	
	for(int x=0;x<n;x++){
		ll best = query(left[x], n).first+a[x].second;
		
		if(mn > a[x].first){
			best = max(best, a[x].second*1ll);
		}
//		cout << x << " -> " << query(left[x], n).first << " " << best << "\n";
		if(right[x] >= n-1){
			ans = max(ans, best);
		}
		
		mn = min(mn, a[x].first);
		update(right[x], best);
	}
	
	cout << ans << "\n";
    return 0;
}

