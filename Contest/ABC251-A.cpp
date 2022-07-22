#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	int cnt = 0;
	while(cnt < 6){
		cout << s;
		cnt += s.length();
	}
	cout << "\n";
	
    return 0;
}

