#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxK = 128;

void mul(double a[], double b[]){
	double ans[maxK];
	fill(ans, ans+maxK, 0.0);
	
	for(int x=0;x<maxK;x++){
		for(int y=0;y<maxK;y++){
			assert((x^y) < maxK);
			ans[x^y] += (a[x] * b[y]);
		}
	}
	
	for(int x=0;x<maxK;x++){
		a[x] = ans[x];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	double a[maxK];
	fill(a, a+maxK, 0.0);
	
	for(int x=0;x<=k;x++){
		cin >> a[x];
	}
	
	double ans[maxK];
	fill(ans, ans+maxK, 0.0);
	
	ans[0] = 1.0;
	
	while(n > 0){
		if(n&1) mul(ans, a);
		
		n >>= 1;
		mul(a, a);
	}
	
	cout << fixed << setprecision(10) << 1-ans[0] << "\n";
    return 0;
}

