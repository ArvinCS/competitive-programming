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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		int cnt[26];
		fill(cnt, cnt+26, 0);
		for(int x=0;x<s.length();x++){
			cnt[s[x] - 'a']++;
		}
		
		int m;
		cin >> m;
		
		short ans[m];
		
		pair<int, int> data[m];
		for(int x=0;x<m;x++){
			cin >> data[x].first;
			data[x].second = x;
		}
		
		sort(data, data+m);
		
		for(int big=25;big>=0;big--){
			if(cnt[big] == 0) continue;
			fill(ans, ans+m, -1);
			
			int left = m;
			for(int x=0;x<m;x++){
				if(data[x].first != 0) break;
				ans[data[x].second] = big;
				left--;
			}
			
			if(m-left > cnt[big]) continue;
			
			for(int c=big-1;c>=0;c--){
				if(cnt[c] == 0) continue;
				
				vector<int> v;
				for(int x=0;x<m;x++){
					if(ans[data[x].second] != -1) continue;
					
					int tmp = 0;
					for(int y=0;y<m;y++){
						if(ans[y] != -1 && c < ans[y]){
							tmp += abs(y-data[x].second);
						}
					}
					
//					cout << x << " : " << tmp << "\n";
					if(tmp == data[x].first){
						v.push_back(data[x].second);
					}
				}
				
//				char ctmp = 'a'+c;
//				cout << ctmp << " " << cntC << " " << cnt[c] << " " << v.size() << "\n";
				if(v.size() <= cnt[c]){
					for(int x=0;x<v.size();x++){
						ans[v[x]] = c;
						left--;
					}
				}
			}
			
//			cout << "end " << left << "\n";
			if(left == 0){
				for(int x=0;x<m;x++){
					char c = ('a'+ans[x]);
					cout << c;
				}
				cout << "\n";
				break;
			}
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

