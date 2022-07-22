#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, d, e;
	cin >> n >> d >> e;
	
	int ans = n;
	for(int x=0;x*e<=n;x+=5){
		ans = min(ans, (n-(x*e)) % d);	
	}
	
	cout << ans << "\n";
    return 0;
}

