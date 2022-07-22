#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> v;
	while(n > 0){
		v.push_back(n%10);
		n /= 10;
	}
	
	while(v.size() < 4){
		v.push_back(0);
	}
	
	for(int x=v.size()-1;x>=0;x--){
		cout << v[x];
	}
	cout << "\n";
    return 0;
}

