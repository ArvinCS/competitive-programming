#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us n;
	cin >> n;
	
	int cnt = 0, best = 0;
	while(n--){
		us a, b;
		cin >> a >> b;
		
		if(a == b){
			cnt++;
			if(cnt > best) best = cnt;
		} else {
			cnt = 0;
		}
	}
	
	if(best >= 3){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	
    return 0;
}

