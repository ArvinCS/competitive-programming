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

int n, k;

bool customSort(pair<int, int> a, pair<int, int> b){
	if((a.second-a.first) == (b.second-b.first)){
		if(a.second > k){
			return true;
		} else if(b.second > k){
			return false;
		}
		return a.first < b.first;
	}
	return (a.second-a.first) > (b.second-b.first);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	for(us i=1;i<=t;i++){
		cout << "Case #" << i << ": ";
		cin >> n >> k;
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		sort(data, data+n);
		
		vector<pair<int, int>> v;
		int start = 1;
		for(int x=0;x<n;x++){ // [l, r)
			int end = data[x];
			if(start > end) continue;
			
			if(end-start > 0) v.push_back({start, end});
			start = end+1;
		}
		v.push_back({start, k+1});
		
		sort(v.begin(), v.end(), customSort);
				
		vector<int> ans;
		for(int x=0;x<v.size();x++){
			int length = v[x].second-v[x].first;
			
			int cnt = 0;
			if(length <= 0) continue;
			if(v[x].second > k || v[x].first == 1){
				cnt += v[x].second-v[x].first;
			} else {
				cnt += (length+1)/2;
			}
			ans.push_back(cnt);
		}
		ans.push_back(0);
		ans.push_back(0);
		sort(ans.rbegin(), ans.rend());
		
		if(v.size() > 0 && (ans[0]+ans[1]) < (v[0].second-v[0].first)){
			cout << fixed << setprecision(7) << ((v[0].second-v[0].first)*1.0/k) << "\n";
			continue;
		}
		
		cout << fixed << setprecision(7) << ((ans[0]+ans[1])*1.0/k) << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

