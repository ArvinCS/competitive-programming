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

int n;

int ask(int a[]){
	cout << "?";
	for(int x=0;x<n;x++){
		cout << " " << a[x];
	}
	cout << endl;
	
	int k;
	cin >> k;
	
	return k;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n;
	
	int a[n];
	fill(a, a+n, n);
	
	int p[n];
	fill(p, p+n, -1);
	
	for(int x=1;x<=n;x++){
		a[n-1] = x;
		
		int ans = ask(a);
		if(ans != 0){
			p[n-1] = n+1-x;
			break;
		}
	}
	if(p[n-1] == -1){
		p[n-1] = 1;
	}
	
	for(int x=2;x<=p[n-1];x++){
		fill(a, a+n, x);
		a[n-1] = 1;
		
		int ans = ask(a);
		p[ans-1] = p[n-1]+1-x;
	}
	
	for(int x=2;x<=(n-p[n-1]+1);x++){
		fill(a, a+n, 1);
		a[n-1] = x;
		
		int ans = ask(a);
		p[ans-1] = p[n-1]+x-1;
	}
	
	cout << "!";
	for(int x=0;x<n;x++){
		cout << " " << p[x];
	}
	cout << endl;
    return 0;
}

