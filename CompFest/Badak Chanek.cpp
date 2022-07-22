#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	us n, tmp;
	cin >> n;
	
	ui q, p[n];
	cin >> q;
	
	for(us x=0;x<n;x++) cin >> p[x];
	
	sort(p, p+n);
	
	while(q--){
		cin >> tmp;
		cout << p[tmp-1] << "\n";
	}
	
    return 0;
}

