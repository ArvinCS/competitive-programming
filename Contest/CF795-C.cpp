#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

struct Fenwick {
	int tree[maxN];
	
	void reset(){
		
	}
};
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
			
		for(int x=n-1;x>=max(0, n-k-1);x--){
			if(s[x] == '1'){
				swap(s[x], s[n-1]);
				k -= n-1-x;				
				break;
			}
		}
		for(int x=0;x<=min(k, n-2);x++){
			if(s[x] == '1'){
				swap(s[x], s[0]);
				k -= x;
				break;
			}
		}
		
		int ans = 0;
		for(int x=0;x+1<n;x++){
			ans += (s[x] - '0') * 10 + (s[x+1] - '0');
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}
