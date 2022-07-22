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

	int n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	int mx = 0;
	for(int x=1;x<n;x++){
		if(s[x] < s[0]){
			mx = x-1;
			break;
		}
	}
	
	int best = 1;
	for(int x=1;x<n;x++){
		if(s[x] > s[x%best]){
			break;
		}
		
		if(s[x] == s[x%best]){
			continue;
		} else {
			best = x+1;
		}
	}
	
	for(int x=0;x<k;x++){
		cout << s[x%best];
	}
	cout << "\n";
    return 0;
}

