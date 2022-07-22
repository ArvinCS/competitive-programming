#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	char s[3], t[3];
	for(int x=0;x<3;x++) cin >> s[x];
	for(int x=0;x<3;x++) cin >> t[x];
	
	int cnt = 0;
	for(int x=0;x<3;x++){
		if(s[x] != t[x]) cnt++;
	}
	
	if(cnt == 3 || cnt == 0) cout << "Yes\n";
	else cout << "No\n";
    return 0;
}

