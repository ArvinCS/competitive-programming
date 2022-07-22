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
	
	int n;
	cin >> n;
	
	int p;
	cin >> p;
	
	int cnt = 0;
	for(int x=0;x<n;x++){
		int val;
		cin >> val;
		
		if(val < p){
			cnt++;
		}
	}
	
	cout << cnt << "\n";
    return 0;
}

