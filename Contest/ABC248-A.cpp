#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int cnt[10];
	fill(cnt, cnt+10, 0);
	
	string s;
	cin >> s;
	
	for(int x=0;x<s.length();x++){
		cnt[(s[x] - '0')]++;
	}
	
	int ans = -1;
	for(int x=0;x<10;x++){
		if(!cnt[x]){
			ans = x;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

