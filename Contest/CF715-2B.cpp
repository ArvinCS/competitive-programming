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

int cnt[maxN];

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
		
		string s;
		cin >> s;
		
		bool valid = true;
		int a = 0, b = 0;
		
		for(int x=0;x<s.length();x++){
			cnt[x] = (x > 0 ? cnt[x-1] : 0);
			if(s[x] == 'T'){
				a++;
				cnt[x]++;
			} else {
				b++;
				cnt[x]--;
			}
			
			if(cnt[x] < 0){
				valid = false;
				break;
			}
		}
		
		for(int x=0;x<s.length();x++){
			if(cnt[x] > a/2){
				valid = false;
				break;
			}
		}
		
		if(a != b*2 || (a&1)){
			valid = false;
		}
		if(a/2 < cnt[s.length()-1]){
			valid = false;
		}
		
		if(valid) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

