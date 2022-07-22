#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	bool valid = false;
	char c[3] = {'o', 'x', 'x'};
	for(int i=0;i<3;i++){
		int turn = i;
		bool ok = true;
		for(int x=0;x<s.length();x++){
			if(s[x] == c[turn]){
				turn++;
				turn %= 3;
			} else {
				ok = false;
				break;
			}
		}
		valid |= ok;
	}
	
	if(valid){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
    return 0;
}

