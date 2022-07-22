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
	
	us t;
	cin >> t;
	
	while(t--){
		short n;
		cin >> n;
		
		string s;
		cin >> s;
		
		queue<short> pos;
		for(short x=0;x<n;x++){
			if(s[x] == 'u'){
				pos.push(x);
			} else if(s[x] == 'b' && pos.size() > 0){
				swap(s[pos.front()],s[x]);
				pos.pop();
				pos.push(x);
			}
		}
		
		for(short x=0;x<n;x++){
			cout << s[x];
		}
		cout << "\n";
	}
	
    return 0;
}

