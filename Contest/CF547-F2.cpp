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

bool customSort(vector<pair<int, int>> v1, vector<pair<int, int>> v2){
	return v1.size() < v2.size();
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
	for(int x=0;x<n;x++){
		cin >> data[x];
	}

	int prefix[n];
	prefix[0] = data[0];
	for(int x=1;x<n;x++) prefix[x] = data[x] + prefix[x-1];
	
	map<int, vector<pair<int, int>>> mp;
	map<int, int> last;
	for(int right=0;right<n;right++){
		for(int left=0;left<=right;left++){
			int sum = prefix[right] - (left > 0 ? prefix[left-1] : 0);
			
			if(last.find(sum) == last.end() || last[sum] < left){
				last[sum] = right;
				mp[sum].push_back({left, right});
			}
 		}
	}
	
	vector<pair<int, int>> ans;
	for(auto m : mp){
		if(ans.size() < m.second.size()){
			ans = m.second;
		}
	}
	
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first+1 << " " << p.second+1 << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

