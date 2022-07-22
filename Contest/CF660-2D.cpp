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

const int maxN = 3e5;

ll table[maxN];
vector<int> adj[maxN];
ll a[maxN];
int b[maxN], sz[maxN];
int n;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	set<int> st;
	for(int x=0;x<n;x++){
		st.insert(x);
		sz[x] = 0;
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
		if(b[x] > 0){
			b[x]--;
			sz[b[x]]++;
			
			if(sz[b[x]] == 1) st.erase(b[x]);
		}
	}
	
	ll sum = 0;
	vector<int> ans[2];
	while(!st.empty()){
		int curNode = *st.begin();
		st.erase(st.begin());
		
		sum += a[curNode];
		if(a[curNode] >= 0){
			if(b[curNode] >= 0){
				a[b[curNode]] += a[curNode];
			}
			ans[0].push_back(curNode);
		} else {
			ans[1].push_back(curNode);
		}
		
		if(b[curNode] >= 0){
			sz[b[curNode]]--;
			if(sz[b[curNode]] == 0){
				st.insert(b[curNode]);
			}
		}
	}
	
	cout << sum << "\n";
	for(auto v : ans[0]) cout << v+1 << " ";
	reverse(ans[1].begin(), ans[1].end());
	for(auto v : ans[1]) cout << v+1 << " ";
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

