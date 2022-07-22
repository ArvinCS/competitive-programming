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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us n, m, k;
	cin >> n >> m >> k;
	
	us tmp1, tmp2;
	for(us x=0;x<k;x++){
		cin >> tmp1 >> tmp2;
	}
	
	for(us x=0;x<k;x++){
		cin >> tmp1 >> tmp2;
	}
	
	cout << (n-1) + (m-1) + (n*m) << "\n";
	for(int x=0;x<n-1;x++){
		cout << "U";
//		steps.push_back('U');
	}
	for(int y=0;y<m-1;y++){
		cout << "L";
//		steps.push_back('L');
	}
	
	bool right = true;
	for(int y=0;y<n;y++){
		for(int x=0;x<m-1;x++){
			cout << (right ? "R" : "L");
//			steps.push_back(right ? 'R' : 'L');
		}
		cout << "D";
//		steps.push_back('D');
		right = !right;
	}
	
	cout << "\n";
//	cout << steps.size() << "\n";
//	for(int i=0;i<steps.size();i++){
//		cout << steps[i];
//	}
//	cout << "\n";
	
    return 0;
}

