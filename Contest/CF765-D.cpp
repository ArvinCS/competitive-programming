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

vector<int> ans;
vector<int> v[30];
int a[maxN], k;
int mx = 0, bound = -1;

void solve(int i, vector<int> &w){
	if(w.empty()) return;
	if(i < bound || (i == bound && __builtin_popcount(k) != 1)){
		if(w.size() > 0){
			ans.push_back(w.front());
		}
		return;
	}
	
	int bit = (1 << i);
	vector<int> zero, one;
	for(auto idx : w){
		if(a[idx]&bit){
			one.push_back(idx);
		} else {
			zero.push_back(idx);
		}
	}
	
	solve(i-1, zero);
	solve(i-1, one);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n >> k;
	
	for(int i=29;i>=0;i--){
		int bit = (1 << i);
		
		if(k&bit){
			bound = i;
			break;
		}
	}	
	
	if(k == 0){
		cout << n << "\n";
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << x+1;
		}
		cout << "\n";
		return 0;
	}
	
	for(int x=0;x<n;x++){
		cin >> a[x];
		
		bool found = false;
		for(int y=29;y>bound;y--){
			int bit = (1 << y);
			
			if(a[x]&bit){
				found = true;
				v[y].push_back(x);
				break;
			}
		}
		
		if(!found){
			v[bound].push_back(x);
		}
	}
	
	map<int, int> mp;
	int mx = 0, cur = 0;
	for(int i=bound;i>=0;i--){
		mx <<= 1;
		cur = mx|1;
		
		mp.clear();
		
		for(int x=0;x<n;x++){
			if(a[x] < (1 << (bound+1))) mp[a[x]>>i] = x;
		}
		
		for(auto p : mp){
			if(mp.find(p.first^cur) != mp.end()){
				mx = cur;
				ans.clear();
				ans.push_back(p.second);
				ans.push_back(mp[p.first^cur]);
				break;
			}
		}
	}
	
	if(mx < k){
		ans.clear();
	}
	
	for(int i=29;i>bound;i--){
		solve(i-1, v[i]);
	}
	
	if(ans.size() <= 1){
		cout << "-1\n";
		return 0;
	}
	
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	
	cout << ans.size() << "\n";
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x]+1;
	}
	cout << "\n";
    return 0;
}

