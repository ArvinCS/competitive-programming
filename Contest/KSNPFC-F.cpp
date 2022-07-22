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

bool ask1(int x, int y){
	cout << "! 1 " << x << " " << y << endl;
	
	char c;
	cin >> c;
	
	if(c == 'Y') return true;
	else return false;
}

bool ask2(int x, int y){
	cout << "! 2 " << x << " " << y << endl;
	
	char c;
	cin >> c;
	
	if(c == 'Y') return true;
	else return false;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int pos = -1;
	for(int x=0;x<n;x++){
		if(ask2(0, x)){
			pos = x;
			break;
		}
	}
	
	int a[n], b[n];
	fill(a, a+n, -1);
	fill(b, b+n, -1);
	
	int res = ask1(0, pos);
	if(res&1){
		res = (res+n)/2;
	}
	a[0] = res; b[pos] = res;
	
	for(int x=0;x<n;x++){
		if(x == pos) continue;
		
		int ans = ask2(0, x);
		
		if((ans+n-a[0]) > n){
			ans = ans-a[0];
		} else {
			ans = (ans+n-a[0]);
		}
		
		b[x] = ans;
	}
	
	for(int x=1;x<n;x++){
		if(x == pos) continue;
		
		int ans = ask2(x, pos);
		
		if((ans+n-b[pos]) > n){
			ans = ans-b[pos];
		} else {
			ans = (ans+n-b[pos]);
		}
		
		a[x] = ans;
	}
	
	cout << "!";
	for(int x=0;x<n;x++){
		cout << " " << a[x];
	}
	for(int x=0;x<n;x++){
		cout << " " << b[x];
	}
	cout << endl;
    return 0;
}

