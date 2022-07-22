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

const int maxN = 5e5 + 5;

int n;
pair<int, int> tree[2*maxN];

pair<int, int> query(int left, int right){
	pair<int, int> ans = {inf_int, inf_int};
	
	for(left += n, right += n; left < right; left >>= 1, right >>= 1){
		if(left&1) ans = min(ans, tree[left++]);
		if(right&1) ans = min(ans, tree[--right]);
	}
	return ans;
}

void update(int pos, int val){
	pos += n;
	
	tree[pos] = {val, pos-n};
	for(int x=pos;x>1;x>>=1){
		tree[x>>1] = min(tree[x], tree[x^1]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;
	
	fill(tree, tree+2*maxN, make_pair(inf_int, inf_int));
	
	vector<int> pos[n];
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		a[x]--;		
		pos[a[x]].push_back(x);
	}
	
	int ans = inf_int;
	for(int x=0;x<n;x++){
		int val = a[x];
		
		int left = x, right = pos[val].back(), cnt = pos[val].size();
		int length = right-left+1;
		bool full = (pos[val].front() == x);
		
		pair<int, int> best = query(0, x);
		best = min(best, {n, -1});
		
		int removed = lower_bound(pos[val].begin(), pos[val].end(), best.second)-pos[val].begin();
		int remain = cnt-removed;
		
		int sum = best.first-remain;
		
		// if the element we keep is not full, then we cant pick/keep the remain (right) element anymore
		if(full){
			update(right, sum);
		}
		ans = min(ans, sum);
		
//		cout << x << " " << val << " -> " << ans << " " << sum << " " << best.first << " " << best.second << " " << removed << "\n";
	}
	
	cout << ans << "\n";
    return 0;
}

