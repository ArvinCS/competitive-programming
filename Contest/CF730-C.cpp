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

bool isSame(double a, double b){
	if(abs(a-b) < 1e-9){
		return true;
	} else {
		return false;
	}
}

double solve(double slip[], double v, double ans, int step, bool done){
	if(isSame(slip[2], 0) || done){
		return step*ans;
	}
	
	double oldSlip[3];
	for(int x=0;x<3;x++) oldSlip[x] = slip[x];
	
	double sum = 0.0;
	for(int x=0;x<3;x++){
		if(!isSame(slip[x], 0)){
			double distribute = min(slip[x], v);
			slip[x] = max(slip[x]-distribute, 0.0);
			
			int cnt = 0;
			for(int y=0;y<3;y++){
				if(x == y) continue;
				if(!isSame(slip[y], 0)) cnt++;
			}
			for(int y=0;y<3;y++){
				if(x == y) continue;
				if(!isSame(slip[y], 0)){
					slip[y] += distribute/cnt;
				}
			}
			
			sum += solve(slip, v, ans*oldSlip[x], step+1, (x == 2));
			
			for(int y=0;y<3;y++) slip[y] = oldSlip[y];
		}
	}
	
	return sum;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		double slip[3], v;
		cin >> slip[0] >> slip[1] >> slip[2] >> v;
		
		double ans = solve(slip, v, 1, 0, false);
		
		cout << fixed << setprecision(7) << ans << "\n";
	}

    return 0;
}

