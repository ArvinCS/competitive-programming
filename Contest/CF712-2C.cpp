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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		if(s[0] == '0' || s[n-1] == '0'){
			cout << "NO\n";
			continue;	
		}
		
		bool possible = true;
		char ansA[n], ansB[n];
		for(int x=0;x<n;x++){
			ansA[x] = ansB[x] = '.';
		}
		
		ansA[0] = ansB[0] = '(';
		ansA[n-1] = ansB[n-1] = ')';
		
		char c = '(';
		int a = 0, b = 0;
		for(int x=1;x<n-1;x++){
			int digit = (s[x] - '0');
			if(!digit){
				ansA[x] = c;
				if(c == '('){
					ansB[x] = c = ')';
				} else {
					ansB[x] = c = '(';
				}
			}
		}
		int need1 = (n/2)-1, need2 = (n/2)-1;
		for(int x=1;x<n-1;x++){
			if(ansA[x] == '('){
				need1--;
			}
			if(ansB[x] == '('){
				need2--;
			}
		}
		
		for(int x=0;x<n;x++){
			if(ansA[x] == '.'){
				if(need1 <= 0 || need2 <= 0){
					ansA[x] = ansB[x] = ')';
				} else {
					ansA[x] = ansB[x] = '(';
					need1--;
					need2--;
				}
			}
		}
		
		int cnt1 = 0, cnt2 = 0;
		for(int x=0;x<n;x++){
			if(ansA[x] == '('){
				cnt1++;
			} else {
				cnt1--;
			}
			if(ansB[x] == '('){
				cnt2++;
			} else {
				cnt2--;
			}
			
			if(cnt1 < 0 || cnt2 < 0){
				possible = false;
				break;
			}
		}
		if(cnt1 != 0 || cnt2 != 0) possible = false;
		
		if(possible){
			cout << "YES\n";
			for(int x=0;x<n;x++) cout << ansA[x];
			cout << "\n";
			for(int x=0;x<n;x++) cout << ansB[x];
			cout << "\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

