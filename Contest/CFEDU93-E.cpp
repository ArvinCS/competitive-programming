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

ll tree[2*maxN], sum[2*maxN];
int sz = 0;

void update(int pos, int val){
	pos += sz;
	
	tree[pos] = val;
	for(int x=pos;x>1;x>>=1){
		tree[x>>1] = tree[x]+tree[x^1];
	}
}

ll query(int left, int right){
	ll ans = 0;
	
	for(left += sz, right += sz; left < right; left >>= 1, right >>= 1){
		if(left&1) ans += tree[left++];
		if(right&1) ans += tree[--right];
	}
	return ans;
}

void updateSum(int pos, int val){
	pos += sz;
	
	sum[pos] = val;
	for(int x=pos;x>1;x>>=1){
		sum[x>>1] = sum[x]+sum[x^1];
	}
}

ll querySum(int left, int right){
	ll ans = 0;
	
	for(left += sz, right += sz; left < right; left >>= 1, right >>= 1){
		if(left&1) ans += sum[left++];
		if(right&1) ans += sum[--right];
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	pair<int, ll> p[n];
	set<ll> st;
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		
		st.insert(abs(p[x].second));
	}
	
	map<ll, int> mp;
	for(auto val : st){
		mp[val] = sz++;
	}
	
	fill(tree, tree+2*maxN, 0);
	fill(sum, sum+2*maxN, 0);
	
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	int cnt = 0;
	for(int x=0;x<n;x++){
		if(p[x].first == 0){
			if(p[x].second > 0){
				update(mp[abs(p[x].second)], 1);
				updateSum(mp[abs(p[x].second)], p[x].second);
			} else {
				update(mp[abs(p[x].second)], 0);
				updateSum(mp[abs(p[x].second)], 0);
			}
		} else {
			pq.push(abs(p[x].second));
			if(p[x].second > 0){
				cnt++;
				update(mp[abs(p[x].second)], 1);
				updateSum(mp[abs(p[x].second)], p[x].second);
			} else {
				cnt--;
				update(mp[abs(p[x].second)], 0);
				updateSum(mp[abs(p[x].second)], 0);
			}
		}
		
		while(!pq.empty() && query(mp[pq.top()], mp[pq.top()]+1) == 0){
			pq.pop();
		}
		
		if(cnt == query(0, sz)){
			cout << querySum(0, sz)*2 - (pq.empty() ? 0 : pq.top()) << "\n";
			continue;
		}
		
		int left = 0, right = sz;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			bool extra = (!pq.empty() && mid <= mp[pq.top()]);
			if(query(mid, sz) < cnt+extra){
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		bool extra = (!pq.empty() && left-1 <= mp[pq.top()]);
		ll ans = querySum(left-1, sz)*2 + querySum(0, left-1);
		
		if(extra){
			ans -= pq.top();
		}
		
		cout << ans << "\n";
	}
    return 0;
}

