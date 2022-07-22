#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
		
	int t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		bool possible = true;
		for(int x=0;x<s.length();x++){
			if(s[x] >= 'A' && s[x] <= 'Z'){
				s[x] += 32; // mengubah kapital jadi huruf kecil
			} else if(!(s[x] >= 'a' && s[x] <= 'z') && !(s[x] >= '0' && s[x] <= '9')){
				possible = false;
			}
		}
		
		if(possible){
			reverse(s.begin(), s.end());
			cout << s << "\n";	
		} else {
			cout << "Ini hasil yang salah patrick" << "\n";
		}
	}
	return 0;
}
