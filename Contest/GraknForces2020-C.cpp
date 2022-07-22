#include <bits/stdc++.h>

using namespace std;

#define ll long long

const double eps = 1e-6;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, l;
		cin >> n >> l;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		double left = 0, right = l;
		for(int x=0;x<100;x++){
			double mid = (left+right)*0.5;
			
			int cnt = 1, lst = 0;
			double time = 0, time2 = 0;
			for(int x=0;x<n;x++){
				if(a[x] <= mid){
					time += (a[x]-(x > 0 ? a[x-1] : 0))*1.0/cnt;
					cnt++;
					lst = a[x];
				}
			}
			time += (mid-lst)*1.0/cnt;
			
			cnt = 1; lst = l;
			for(int x=n-1;x>=0;x--){
				if(a[x] >= mid){
					time2 += ((x+1 < n ? a[x+1] : l)-a[x])*1.0/cnt;
					cnt++;
					lst = a[x];
				}
			}
			time2 += (lst-mid)*1.0/cnt;
			
			if(x == 99){
				cout << fixed << setprecision(8) << time << "\n";
			} else {
				if(time > time2){
					right = mid-eps;
				} else {
					left = mid+eps;
				}
			}
		}
	}
	
    return 0;
}

