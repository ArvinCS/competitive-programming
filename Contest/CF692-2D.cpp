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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	string s, t;
	ll a, b;
	cin >> s;
	cin >> a >> b;
	
	t = s;
	int n = s.length();
	
	int suffix[n+1];
	suffix[n] = 0;
	
	for(int x=n-1;x>=0;x--){
		if(s[x] == '?') t[x] = '0';
		
		suffix[x] = suffix[x+1];
		if(t[x] == '1'){
			suffix[x]++;
		}
	}
	
	ll ans = inf_ll, cur = 0, one = 0, zero = 0;
	for(int x=0;x<n;x++){
		if(t[x] == '0'){
			cur += one*b;
			zero++;
		} else if(t[x] == '1'){
			cur += zero*a;
			one++;
		}
	}
	
	ans = min(ans, cur);
	
	zero = 0; one = 0;
	for(int x=0;x<n;x++){
		int rightZero = n-(x+1)-suffix[x+1], rightOne = suffix[x+1];
		
		if(s[x] == '0'){
			zero++;
		} else if(s[x] == '1'){
			one++;
		} else if(s[x] == '?'){
			cur -= one*b + rightOne*a;
			cur += zero*a + rightZero*b;
			
			one++;
		}
		ans = min(ans, cur);
	}
	
	for(int x=n-1;x>=0;x--){
		if(s[x] == '?') t[x] = '1';
		
		suffix[x] = suffix[x+1];
		if(t[x] == '1'){
			suffix[x]++;
		}
	}
	
	cur = 0; one = 0; zero = 0;
	for(int x=0;x<n;x++){
		if(t[x] == '0'){
			cur += one*b;
			zero++;
		} else if(t[x] == '1'){
			cur += zero*a;
			one++;
		}
	}
	
	ans = min(ans, cur);
	
	zero = 0; one = 0;
	for(int x=0;x<n;x++){
		int rightZero = n-(x+1)-suffix[x+1], rightOne = suffix[x+1];
		
		if(s[x] == '0'){
			zero++;
		} else if(s[x] == '1'){
			one++;
		} else if(s[x] == '?'){
			cur += one*b + rightOne*a;
			cur -= zero*a + rightZero*b;
			
			zero++;
		}
		ans = min(ans, cur);
	}
	
	cout << ans << "\n";
    return 0;
}

