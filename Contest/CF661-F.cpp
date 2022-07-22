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

int table[6005][6005];
vector<int> v[6005];

int solve(int left, int right){
	if(left > right) return 0;
	if(table[left][right] != -1) return table[left][right];
	
	table[left][right] = 0;
	
	bool exist = false;
	for(auto curRight : v[left]){
		if(curRight == right){
			exist = true;
			break;
		}
	}
	
	table[left][right] = max(table[left][right], exist+solve(left+1, right));
	for(auto curRight : v[left]){
		if(curRight < right){
			table[left][right] = max(table[left][right], exist+solve(left, curRight)+solve(curRight+1, right));
		}
	}
	
	return table[left][right];
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
		
		map<int, int> mp;
		set<int> st;
		pair<int, int> s[n];
		for(int x=0;x<n;x++){
			cin >> s[x].first >> s[x].second;
			st.insert(s[x].first);
			st.insert(s[x].second);
		}
		
		for(int x=0;x<2*n;x++) v[x].clear();
		
		int i = 0;
		for(auto val : st){
			mp[val] = i++;
		}
		for(int x=0;x<n;x++){
			s[x].first = mp[s[x].first];
			s[x].second = mp[s[x].second];
			
			v[s[x].first].push_back(s[x].second);
		}
		
		fill(table[0], table[2*n], -1);
		
		cout << solve(0, 2*n-1) << "\n";
	}

    return 0;
}

