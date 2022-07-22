#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int countChar(char c, string s){
	int ans = 0;
	for(int x=0;x<s.length();x++){
		if(s[x] == c) ans++;
	}
	return ans;
}

int solve(string s, char c){
	if(s.length() == 1) return s[0] != c;
	
	int halfSize = s.length()/2;
	string firstHalf = s.substr(0, halfSize), secondHalf = s.substr(halfSize, halfSize);
	
	int cnt1 = solve(firstHalf, c+1), cnt2 = solve(secondHalf, c+1);
	
	for(int x=halfSize;x<s.length();x++) cnt1 += s[x] != c;
	for(int x=0;x<halfSize;x++) cnt2 += s[x] != c;
	
	return min(cnt1, cnt2);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	int tmp;
	while(t--){
		cin >> tmp;
		
		string s;
		cin >> s;
		
		if(s.length() > 1){
			cout << solve(s, 'a') << "\n";
		} else {
			cout << (s[0] != 'a') << "\n";
		}
	}
	
    return 0;
}
