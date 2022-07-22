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

int table[maxN];
vector<int> adj[maxN];
bool valid[maxN];

int dfs(int curNode){
	if(table[curNode] != -1) return table[curNode];
	
	table[curNode] = 1;
	for(auto nxt : adj[curNode]){
		dfs(nxt);
		
		if(table[nxt]+1 > table[curNode]){
			table[curNode] = table[nxt]+1;
		}
	}
	
	return table[curNode];
}

void dfs2(int curNode){
	valid[curNode] = true;
	for(auto nxt : adj[curNode]){
		if(table[nxt] == table[curNode]-1){
			dfs2(nxt);
			break;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	vector<tuple<ll, int, int>> v;
	for(int x=0;x<m;x++){
		int a, b, c;
		cin >> a >> b >> c;
		
		v.push_back(make_tuple(b, 1, a-1));
		v.push_back(make_tuple(c+1, -1, a-1));
	}
	
	sort(v.begin(), v.end());
	
	int active[n];
		
	for(int x=0;x<n;x++){
		active[x] = 0;
	}
	
	set<int> st;
	for(auto t : v){
		int pos = get<0>(t), row = get<2>(t);
		bool add = (get<1>(t) == 1);
		
		if(add){			
			if(active[row] == 0){
				auto it = st.lower_bound(row);
				if(it != st.end()){
					adj[row].push_back(*it);
	//				cout << row << " " << *it << " connected1\n";
				}
				if(it != st.begin()){
					it--;
					adj[*it].push_back(row);
	//				cout << *it << " " << row << " connected2\n";	
				}
				st.insert(row);
			}
			active[row]++;
		} else {
			active[row]--;
			if(active[row] == 0) st.erase(row);
		}
	}
	
	for(int x=0;x<n;x++){
		table[x] = -1;
		valid[x] = false;
	}
	
	int ans = -1, head = -1;
	for(int x=0;x<n;x++){
		if(table[x] == -1){
			int tmp = dfs(x);
			
//			cout << x << " -> " << tmp << "\n";
			if(tmp > ans){
				ans = tmp;
				head = x;
			}
		}
	}
	
	dfs2(head);
	
	bool space = false;
	cout << n-ans << "\n";
	for(int x=0;x<n;x++){
		if(!valid[x]){
			if(space) cout << " ";
			cout << x+1;
			
			space = true;
		}
	}
	if(n-ans > 0) cout << "\n";
    return 0;
}

