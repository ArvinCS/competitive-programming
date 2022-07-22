#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

void solve(){
	us n;
	cin >> n;
	
	int cnt[26];
	fill(begin(cnt), end(cnt), 0);
	
	for(int x=0;x<n;x++){
		string tmp;
		cin >> tmp;
		for(int x=0;x<tmp.length();x++){
			cnt[tmp[x] - 'a']++;
		}	
	}
	
	for(int x=0;x<26;x++){
		if(cnt[x] % n != 0){
			cout << "NO\n";
			return;
		}
	}
	
	cout << "YES\n";
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		solve();
	}
	
    return 0;
}

