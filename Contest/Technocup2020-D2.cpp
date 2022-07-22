#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

bool customSort(const pair<int, int> &a, const pair<int, int> &b){
	if(a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int data[n];
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		p[x].first = data[x];
		p[x].second = x;
	}
	
	int m;
	cin >> m;
	
	tuple<int, int, int> query[m];
	int ans[m];
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		query[x] = make_tuple(a, b, x);
	}
	
	sort(query, query+m);
	sort(p, p+n, customSort);
	
	int q = 0;
	ordered_set st;
	for(int k=1;k<=n;k++){
		st.insert(p[k-1].second);
		
		while(q < m && get<0>(query[q]) == k){
			ans[get<2>(query[q])] = data[*st.find_by_order(get<1>(query[q])-1)];
			q++;
		}
		if(q >= m) break;
	}
	
	for(int x=0;x<m;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

