#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

ll pw[32];

ll riciclo(int n, int m, vector<int> t, vector<int> p) {
	pw[0] = 1;
	for(int x=1;x<32;x++){
		pw[x] = 2ll*pw[x-1];
	}
	
	ll sum = 0;
	for(int x=0;x<n;x++){
		sum += t[x];
	}
	
	ll ans = 0;
	for(int y=0;y<m;y++){
		ll mn = 0;
		for(int x=0;x<n;x++){
			if(t[x] >= pw[y]) mn += t[x]/pw[y];
		}
		
		mn = min(mn, min(p[y]*1ll, sum/pw[y]));
		ans += mn;
		sum -= mn*pw[y];
	}
	
	return ans;
}
