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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	vector<char> v;
	v.push_back('G');
	for(int x=0;x<100;x++){
		if(x%2 == 0) v.push_back('R');
		else v.push_back('G');
	}
	
	cout << v.size() << "\n";
	for(auto c : v){
		cout << c;
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

