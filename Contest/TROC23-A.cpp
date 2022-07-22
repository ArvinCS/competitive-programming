#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int cnt = 0;
	for(int x=1;x*x<=n;x++){
		if(n%x == 0){
			cnt++;
			if(n/x != x) cnt++;
		}
	}
	
	if(cnt == 5){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
    return 0;
}

