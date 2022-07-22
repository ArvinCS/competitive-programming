#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		int one = 0, zero = 0;
		for(int x=0;x<n;x++){
			if(s[x] == '1') one++;
			else zero++;
		}
		
		if(one % 2 == 1 || one == 0){
			cout << "NO\n";
			continue;
		}
		
		set<int> st[n];
		for(int x=0;x+1<n;x++){
			st[x].insert(x+1);
			st[x+1].insert(x);
		}
		
		
	}
	
    return 0;
}

