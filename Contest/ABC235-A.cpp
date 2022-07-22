#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int a, b, c;
	string s;
	cin >> s;
	
	a = (s[0] - '0'); b = (s[1] - '0'); c = (s[2] - '0');
	
	cout << (a*100+b*10+c) + (b*100+c*10+a) + (c*100+a*10+b) << "\n";
	
    return 0;
}

