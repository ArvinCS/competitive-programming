#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<int, int> data[n];
	for(int x=0;x<n;x++){
		cin >> data[x].first;
		data[x].second = x+1;
	}
	
	sort(data, data+n);
	
	int left = 0;
	stack<int> s;
	for(int x=0;x<n*2;x++){
		char tmp;
		cin >> tmp;
		
		if(x > 0) cout << " ";
		if(tmp == '0'){ // introvert
			s.push(left);
			cout << data[left++].second;
		} else { // extrovert
			cout << data[s.top()].second;
			s.pop();
		}
	}
	cout << "\n";
    return 0;
}

