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

int tree[maxN];

int query(int pos){
	pos++;
	
	int ans = 0;
	while(pos > 0){
		ans = max(ans, tree[pos]);
		
		pos -= pos&(-pos);
	}
	return ans;
}

void update(int pos, int val){
	pos++;
	
	while(pos < maxN){
		tree[pos] = max(tree[pos], val);
		
		pos += pos&(-pos);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;
	
	map<int, int> mp;
	set<int> st;
	int a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		b[x] = a[x];
		
		a[x] -= x;
		st.insert(a[x]);
	}
	
	int cnt = 0;
	for(auto val : st){
		mp[val] = cnt++;
	}
	
	for(int x=0;x<n;x++){
		a[x] = mp[a[x]];
	}
	
	int lock[k];
	for(int x=0;x<k;x++){
		cin >> lock[x];
		
		lock[x]--;
	}
	
	for(int x=0;x+1<k;x++){
		int length = lock[x+1]-lock[x]+1;
		int range = b[lock[x+1]]-b[lock[x]]+1;
		
		if(range < length){
			cout << "-1\n";
			return 0;
		}
	}
	
	for(int x=0;x<n;x++) b[x] -= x;
	
	fill(tree, tree+maxN, 0);
	
	int pos = 0;
	for(int x=0;x<k;x++){
		int cur = lock[x];
		int mn = (x-1 >= 0 ? b[lock[x-1]] : -inf_int);
		
		while(pos < cur){
			if(b[pos] >= mn && b[pos] <= b[cur]){
				int best = query(a[pos]);
				
				update(a[pos], best+1);
			}
			
			pos++;
		}
		
		update(a[cur], query(a[cur])+1);
		pos++;
	}
	
	while(pos < n){
		if(k == 0 || b[pos] >= b[lock[k-1]]){
			int best = query(a[pos]);
				
			update(a[pos], best+1);	
		}
				
		pos++;
	}
	
	cout << n-query(n+3) << "\n";
    return 0;
}

