#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll a, b;
	cin >> a >> b;
	
	vector<ll> v;
	
	b *= 10;
	b /= 2;
	
	while(b > 0){
		v.push_back(b%10);
		b /= 10;
	}
	
	reverse(v.begin(), v.end());
	
	for(int x=0;x<v.size();x++){
		cout << v[x];
	}
	
	v.clear();
	
	while(a > 0){
		v.push_back(a%10);
		a /= 10;
	}
	
	reverse(v.begin(), v.end());
	
	for(int x=0;x<v.size();x++){
		cout << v[x];
	}
	cout << "\n";
    return 0;
}

