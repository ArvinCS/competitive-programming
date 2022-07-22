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
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		string rev_s = s;
		reverse(rev_s.begin(), rev_s.end());
		
		if(k == 0 || s == rev_s){
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}
	
    return 0;
}

