#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	int count[26] = { 0 }, turn = 0;
	for(int x=0;x<s.length();x++) count[s[x] - 'a']++;
	
	for(int x=0;x<26;x++){
		if(count[x] % 2 == 1) turn++;
	}
	
	if(turn != 0 && turn % 2 == 0) cout << "Second\n";
	else cout << "First\n";
    return 0;
}
