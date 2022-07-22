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

int getLeftBit(ll x){
	for(int i=28;i>=0;i--){
		if(x&(1ll << i)){
			return i;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	set<int> st;
	vector<int> v;
	
	int n;
	cin >> n;
	
	vector<int> w;
	for(int x=1;x<=n;x++){
		if(st.count(x)) continue;
		
		for(int y=x+1;;y++){
			if(st.count(y)) continue;
			if(st.count(x^y)) continue;
			
			st.insert(x);
			st.insert(y);
			st.insert(x^y);
			
			int left = getLeftBit(x);
			ll a = x-(1ll << left);
			ll b = y-(1ll << (left+1));
			ll c = (x^y)-((1ll << left) + (1ll << (left+1)));
			
			cout << x << " = " << a << " " << b << " " << c << " (" << (a+b+c) << ")\n";
//			if(x*2 == y && x*3 == x^y){
//				cout << x << " " << y << " " << (x^y) << "\n";
//				w.push_back(x);
//			}
			
			break;
		}	
	}
	
	for(auto val : v){
		cout << val << " ";
	}
	cout << "\n";
	
	for(auto val : w){
		cout << val << " ";
	}
	cout << "\n";
    return 0;
}

