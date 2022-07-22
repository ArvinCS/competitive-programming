#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	string s[n];
	for(int x=0;x<n;x++){
		cin >> s[x];
	}	
	
	int ans = 0;
	for(int state=1;state<(1 << n);state++){
		int cnt[26];
		fill(cnt, cnt+26, 0);
		
		for(int y=0;y<n;y++){
			if(state&(1 << y)){
				for(int z=0;z<s[y].length();z++){
					cnt[(s[y][z] - 'a')]++;
				}
			}
		}
		
		int val = 0;
		for(int y=0;y<26;y++){
			if(cnt[y] == k){
				val++;
			}
		}
		
		ans = max(ans, val);
	}
	
	cout << ans << "\n";
    return 0;
}

