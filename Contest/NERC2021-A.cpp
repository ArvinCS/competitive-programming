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

const int maxN = 5e5 + 10;

pair<int, int> tree[maxN];

pair<int, int> query(int pos){
	pair<int, int> ans = {0,0};
	
	pos++;
	while(pos > 0){
		ans = max(ans, tree[pos]);
		
		pos -= pos&(-pos);	
	}
	return ans;
}

void update(int pos, pair<int, int> val){
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

	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		for(int x=0;x<=n+5;x++){
			tree[x] = {0, 0};
		}
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int nxt[n];
		stack<int> st;
		
		for(int x=n-1;x>=0;x--){
			while(!st.empty() && a[st.top()] < a[x]){
				st.pop();
			}
			
			if(st.empty()){
				nxt[x] = n;
			} else {
				nxt[x] = st.top();
			}
			
			st.push(x);
		}
		
		int ans = 0;
		for(int x=0;x<n;x++){
			pair<int, int> best = query(a[x]);
			
//			cout << best.first << " " << best.second << "\n";
			best.first++;
			
			if(best.first == 1 && x > 0){
				best.first++;
			}
			if(best.second < 0 && -best.second >= x){
				best.first--;
			}
			if(nxt[x] < n){
				best.first++;
				best.second = -nxt[x];
			} else {
				best.second = 0;
			}
 			
//			cout << x << " -> " << best.first << " " << best.second << "\n";
			ans = max(ans, best.first);
			update(a[x], best);
		}
		
		cout << ans << "\n";
	}

    return 0;
}

