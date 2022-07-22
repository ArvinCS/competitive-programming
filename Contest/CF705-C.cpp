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

bool valid(int cnt[], string s){
	bool safe = false;
	for(int x=0;x<s.length();x++){
		if(safe){
			int pos = 0;
			while(pos < 26 && cnt[pos] <= 0){
				pos++;
			}
			if(pos == 26){
				return false;
			}
			
			cnt[pos]--;
			continue;	
		}
		
		int i = (s[x] - 'a');
		if(cnt[i] > 0){
			cnt[i]--;
			continue;
		}
		
		int pos = i;
		while(pos < 26 && cnt[pos] <= 0){
			pos++;
		}
		if(pos == 26){
			return false;
		}
		cnt[pos]--;
		safe = true;
	}
	return true;
}

string construct(int cnt[26], string s){
	string ans;
	bool safe = false;
	for(int x=0;x<s.length();x++){
		if(safe){
			int pos = 0;
			while(pos < 26 && cnt[pos] <= 0){
				pos++;
			}
			
			ans.push_back(('a' + pos));
			cnt[pos]--;
			continue;	
		}
		
		int i = (s[x] - 'a');
		if(cnt[i] > 0){
			ans.push_back(('a' + i));
			cnt[i]--;
			continue;
		}
		
		int pos = i;
		while(pos < 26 && cnt[pos] <= 0){
			pos++;
		}
		ans.push_back(('a' + pos));
		cnt[pos]--;
		safe = true;
	}
	return ans;
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
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		if(n%k != 0){
			cout << "-1\n";
			continue;
		}
		if(k == 1){
			cout << s << "\n";
			continue;
		}
		
		int cnt[26];
		fill(cnt, cnt+26, 0);
		
		for(int x=0;x<n;x++){
			cnt[(s[x] - 'a')]++;
		}
		
		bool ok = true;
		for(int x=0;x<26;x++){
			if(cnt[x]%k != 0){
				ok = false;
				break;
			}
		}
		
		if(ok){
			cout << s << "\n";
			continue;
		}
		
		bool found = false;
		for(int x=n-1;x>=0;x--){
			cnt[(s[x] - 'a')]--;
			
			int need = 0;
			for(int y=0;y<26;y++){
				need += (k-cnt[y]%k)%k;
			}
			
			for(int y=(s[x]-'a')+1;y<26;y++){
				cnt[y]++;
				
				int need = 0;
				for(int y=0;y<26;y++){
					need += (k-cnt[y]%k)%k;
				}
				
				if(x+need < n){
					for(int i=0;i<x;i++){
						cout << s[i];
					}
					cout << char('a' + y);
					
					string ans;
					for(int i=0;i<26;i++){
						int need = (k-cnt[i]%k)%k;
						for(int j=0;j<need;j++){
							ans.push_back(('a' + i));
						}
					}
					for(int i=ans.size()+x+1;i<n;i++){
						ans.push_back('a');
					}
					
					sort(ans.begin(), ans.end());
					found = true;
					
					cout << ans << "\n";
					break;
	 			}
	 			cnt[y]--;
	 		}
 			
 			if(found) break;
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

