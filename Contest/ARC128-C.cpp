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

const double eps = 1e-7;

bool isSame(double a, double b){
	if(abs(a-b) < eps){
		return true;
	} else {
		return false;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, p;
	cin >> n >> m >> p;
	
	double s = p;
	int a[n], mx = 0;
	for(int x=0;x<n;x++){
		cin >> a[x];
		mx = max(mx, a[x]);
	}
	
	int prefix[n];
	for(int x=0;x<n;x++){
		prefix[x] = max(a[x], x > 0 ? prefix[x-1] : 0);
	}
	
	int suffix[n+1];
	suffix[n] = 0;
	for(int x=n-1;x>=0;x--){
		suffix[x] = a[x] + (x+1 < n ? suffix[x+1] : 0);
	}
	
	double sum = 0;
	double ans[n];
	fill(ans, ans+n, 0);
	
	for(int x=0;x<n;x++){
		ans[x] = (s*1.0/n);
		sum += ans[x]*a[x];
	}
	
	cout << fixed << setprecision(7) << sum << "\n";
	
	for(int x=0;x<n;x++){
		double best = 0, mn = m, sv = 0;
		int pos = -1;
		for(int y=n-1;y>x;y--){
			mn = min(mn, m-ans[y]);
			
			double tmp = sum - (min(ans[x]/(n-y), mn)*(n-y)*a[x]) + (min(ans[x]/(n-y), mn)*suffix[y]);
			
			if(best < tmp){
				best = tmp;
				pos = y;
				sv = min(ans[x]/(n-y), mn);
			}
		}
		
		if(best > sum && pos != -1){
			sum = best;
			for(int y=pos;y<n;y++){
				ans[y] += sv;
			}
			ans[x] -= sv*(n-pos);
		}
	}
	
	cout << fixed << setprecision(7) << sum << "\n";
    return 0;
}

