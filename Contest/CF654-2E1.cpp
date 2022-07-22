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

const int maxN = 1e5 + 5;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, p;
	cin >> n >> p;
	
	map<int, int> mp;
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		mp[data[x]]++;
	}
	
	sort(data, data+n);
	
	vector<int> ans;
	
	for(ll start=data[0];start<=data[n-1];start++){
		bool valid = true;
		ll cur = start;
		ll picked = 0, sum = 0;
		for(auto it=mp.begin();it!=mp.end();it++){
			auto m = *it;
			if(m.first > cur){
				ll need = m.first-cur;
				if(sum-picked < need){
					valid = false;
					break;
				}
				if(sum-picked >= p && (sum-picked)-need+1 <= p){
					valid = false;
					break;
				}
				picked += need;
				cur += need;
			}
			sum += m.second;
			
			if(m.first < cur){
				continue;
			}
			
			bool hasNext = (next(it) != mp.end());
			
			if(hasNext){
				auto nxt = *next(it);
				if(sum-picked >= p && sum-(picked+(nxt.first-cur)) <= p){
					valid = false;
					break;
				}
				if(sum < picked+(nxt.first-cur)){
					valid = false;
					break;
				}
				
				picked += nxt.first-cur;
				cur = nxt.first;
			} else {
				if(sum-picked >= p){
					valid = false;
					break;
				}
				cur++;
				picked++;
			}
		}
		
		if(valid){
			ans.push_back(start);
		}
	}
	
	cout << ans.size() << "\n";
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar
