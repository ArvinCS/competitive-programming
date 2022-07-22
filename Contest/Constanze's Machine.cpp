#include <iostream>

using namespace std;

long long modul = 1e9 + 7;
string s;

long long solve(){
	if(s.find('w') <= s.length() || s.find('m') <= s.length()){
		return 0;	
	}
	
	long long table[s.length()] = { 0 };
	table[0] = table[1] = 1;
	
	for(int x=2;x<=s.length();x++){
		if(s[x-1] == s[x-2] && (s[x-1] == 'u' || s[x-1] == 'n')){
			table[x] = table[x-1] + table[x-2] % modul;
		} else {
			table[x] = table[x-1];
		}
	}
	
	/*for(int x=1;x<s.length();x++){
		int best = table[x-1];
		if(s[x] == 'u' && x > 0 && s[x-1] == 'u'){
			best++;
		} else if(s[x] == 'n' && x > 0 && s[x-1] == 'n'){
			best++;
		}
		if((s[x-1] == 'n' || s[x-1] == 'u') && s[x] != s[x-1]){
		 	best *=;
			tmp = 1;
			count %= 1000000007;
		}
		table[x] = best;
	}
	if(s[s.length()-1] == 'n' || s[s.length()-1] == 'u') count *= (count + tmp);*/
	
	return table[s.length()] % modul; // ????
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> s;
	
	cout << solve() << "\n";

    return 0;
}
