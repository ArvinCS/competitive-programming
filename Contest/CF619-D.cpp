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

vector<pair<int, string>> ans;
int k;

void printAns(){
	if(k != 0){
		cout << "NO\n";
		return;
	}
	
	cout << "YES\n";
	
	vector<pair<int, string>> new_ans;
	for(auto p : ans){
		if(p.first == 0) continue;
		new_ans.push_back(p);
	}
	
	swap(new_ans, ans);
	
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first << " " << p.second << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m >> k;
	
	if(n == 1){
		ans.push_back({min(m-1, k), "R"});
		k -= min(m-1, k);
		
		ans.push_back({min(m-1, k), "L"});
		k -= min(m-1, k);
		
		printAns();
		return 0;
	}
	
	// First Move (Must)
	ans.push_back({min(n-2, k), "D"});
    k -= min(n-2, k);
    
	ans.push_back({min(m-1, k), "R"});
	k -= min(m-1, k);
	
	ans.push_back({min(1, k), "D"});
	k -= min(1, k);
	
	ans.push_back({min(m-1, k), "L"});
	k -= min(m-1, k);
	
	int rem = 0;
	if(k/3 < m-1){
		rem = k%3;
	}
	
	ans.push_back({min(k/3, m-1), "UDR"});
	k -= min(k/3, m-1)*3;
	
	if(rem > 0){
		if(rem == 1){
			ans.push_back({1, "U"});
			k--;
		} else {
			ans.push_back({1, "UD"});
			k -= 2;
		}
	}
		
	ans.push_back({min(1, k), "U"});
	k -= min(1, k);
	
	ans.push_back({min(m-1, k), "L"});
	k -= min(m-1, k);
	
	if(n > 2){
		ans.push_back({min(1, k), "U"});
		k -= min(1, k);
	}
	
	// Repetitive Move
	for(int x=n-3;x>=0;x--){
		if(k == 0) break;
		
		ans.push_back({min(m-1, k), "R"});
		k -= min(m-1, k);
		
		int rem = 0;
		
		if(k/3 < m-1){
			rem = k%3;
		}
		
		ans.push_back({min(m-1, k/3), "DUL"});
		k -= min(m-1, k/3)*3;
		
		if(rem > 0){
			if(rem == 1){
				ans.push_back({1, "D"});
				k--;
			} else {
				ans.push_back({1, "DU"});
				k -= 2;
			}
		}
		
		if(x > 0){
			ans.push_back({min(1, k), "U"});
			k -= min(1, k);
		}
	}
	
	printAns();
	return 0;
}

