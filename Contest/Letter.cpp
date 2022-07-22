#include <iostream>

using namespace std;

string s;

int solve(){
	int table[s.length()+1][2] = { 0 }; // table[i][0] == UPPERCASE , table[i][1] == LOWERCASE
		
	if(s[0] >= 'A' && s[0] <= 'Z') table[0][1] = 1;
	else table[0][0] = 1;
	bool lowercase = false;
	//cout << table[0][0] << " " << table[0][1] << "\n";
	// S 0 1e9
	// a 1 1e9h
	for(int x=1;x<s.length();x++){
		if(s[x] >= 'A' && s[x] <= 'Z'){
			table[x][0] = table[x-1][0];
			table[x][1] = min(table[x-1][0], table[x-1][1]) + 1;// = table[x-1];
		} else if(s[x] >= 'a' && s[x] <= 'z'){
			table[x][0] = table[x-1][0] + 1;
			table[x][1] = min(table[x-1][0], table[x-1][1]);
		}
		//cout << table[x][0] << " " << table[x][1] << "\n";
	}
	
	return min(table[s.length()-1][0], table[s.length()-1][1]);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> s;
	
	cout << solve() << "\n";
	
    return 0;
}
