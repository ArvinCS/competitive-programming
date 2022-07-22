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

int n;

void normalize(vector<pair<char, int>> &v){
	int prefix[n], suffix[n], mn = inf_int;
	for(int x=0;x<n;x++){
		prefix[x] = (v[x].first == '(' ? 1 : -1) + (x > 0 ? prefix[x-1] : 0);
		mn = min(mn, prefix[x]);
	}
	for(int x=n-1;x>=0;x--){
		suffix[x] = (v[x].first == '(' ? 1 : -1) + (x < n-1 ? suffix[x+1] : 0);
	}
	
	int pos = 0;
	for(int x=0;x<n-1;x++){
		if(prefix[x] == mn && v[x+1].first == '(' && prefix[x] == -suffix[x+1]){
			pos = x+1;
			break;
		}
	}
	
	for(int x=0;x<pos;x++) v.push_back(v[x]);
	for(int x=0;x<n;x++){
		v[x] = v[pos+x];
	}
	while(v.size() > n) v.pop_back();
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n;
	
	vector<pair<char, int>> v;
	for(int x=0;x<n;x++){
		char c;
		cin >> c;
		
		v.push_back({c, x});
	}
	
	normalize(v);
	
	int last[n+1][2];
	fill(last[0], last[n+1], -1);
	
	int cnt = 0, cnt2 = 0, mn = inf_int;
	for(int x=0;x<n;x++){
		if(v[x].first == '('){
			cnt++;
		} else {
			cnt--;
		}
		mn = min(mn, cnt);
		if(cnt == -1) cnt2++;
	}
	
	int mx = 0, l = 0, r = 0;
	if(cnt2 == 1){
		cnt = 0;
		for(int x=0;x<n-1;x++){
			if(v[x].first == '('){
				cnt++;
			} else {
				cnt--;
			}
			
			if(cnt == -1){
				mx = 0;
				l = x;
				r = x+1;
				swap(v[x], v[x+1]);
				break;
			}
		}
	}
	
	if(cnt == 0){
		cnt = 0;
		for(int x=0;x<n;x++){
			if(v[x].first == '(') cnt++;
			else cnt--;
			
			if(cnt == 0) mx++;
		}
		
		int prefix[n], suffix[n+1];
		prefix[0] = suffix[n] = cnt = 0;
		for(int x=0;x<n;x++){
			if(v[x].first == '('){
				cnt++;
			} else {
				cnt--;
			}
			
			if(x > 0) prefix[x] = prefix[x-1]; 
			if(cnt == 0){
				prefix[x]++;
			}
		}
		for(int x=n-1;x>=0;x--){
			if(v[x].first == '('){
				cnt++;
			} else {
				cnt--;
			}
			
			suffix[x] = suffix[x+1];
			if(cnt == 0){
				suffix[x]++;
			}
		}
		
		cnt = 0;
		int pos = 0;
		map<int, int> mp[2];
		for(int x=0;x<n;x++){
			if(v[x].first == '('){
				cnt++;
				
				if(cnt >= 0){
					last[cnt][0] = x;
					if(cnt <= 1){
						mp[cnt].clear();
					}
				}
			} else {
				cnt--;
				if(cnt >= 0){
					last[cnt][1] = x;
					mp[0][cnt]++;
					mp[1][cnt]++;
					
					if(cnt <= 1 && last[cnt+1][0] >= pos){
						if(mx < mp[cnt][cnt+1]+1+(cnt == 1 ? 1+prefix[last[cnt+1][0]]+suffix[x+1] : 0)){
							mx = mp[cnt][cnt+1]+1+(cnt == 1 ? 1+prefix[last[cnt+1][0]]+suffix[x+1] : 0);
							l = last[cnt+1][0];
							r = last[cnt][1];
						}
					}
				} else {
					pos = x+1;
					mp[0].clear();
					mp[1].clear();
				}
			}
		}
		
		swap(v[l], v[r]);
	}
	
	l = v[l].second; r = v[r].second;
	normalize(v);
	
	int ans = 0;
	cnt = 0;
	for(int x=0;x<n;x++){
		if(v[x].first == '('){
			cnt++;
		} else {
			cnt--;
		}
		
		if(cnt < 0){
			ans = 0;
			break;
		}
		if(cnt == 0){
			ans++;
		}
	}
	
	cout << ans << "\n";
	cout << l+1 << " " << r+1 << "\n";
    return 0;
}

