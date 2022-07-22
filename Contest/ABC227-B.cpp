#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int s[n];
	for(int x=0;x<n;x++){
		cin >> s[x];
	}
	
	int ans = n;
	for(int x=0;x<n;x++){
		bool found = false;
		for(int a=1;a<=s[x];a++){
			for(int b=1;b<=s[x];b++){
				if(4*a*b + 3*a + 3*b == s[x]){
					ans--;
					found = true;
					break;		
				}
			}
			if(found) break;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

