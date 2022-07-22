#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	int a, b;
	cin >> a >> b;
	
	swap(s[a-1], s[b-1]);
	
	cout << s << "\n";
	
    return 0;
}

