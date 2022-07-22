#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
//	priority_queue<pair<ui, string>, vector<pair<ui, string>>, greater<pair<ui,string>>> pq;
	int n, m;
	cin >> n >> m;
	
	string s;
	cin >> s;
	
	ll prefix[n];
	for(int x=0;x<n;x++){
		prefix[x] = (s[x] - 'A');
		if(x > 0) prefix[x] += prefix[x-1];
	}
	
	for(int x=0;x<m;x++){
		char tmp = ('A' + (prefix[n-(m-x)]-(x > 0 ? prefix[x-1] : 0))/(n-m+1));
		cout << tmp;
	}
	cout << "\n";
    return 0;
}

