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

int calc(pair<int, int> a, pair<int, int> b){
	int diffX = a.first-b.first;
	int diffY = a.second-b.second;
	
	return diffX*diffX + diffY*diffY;

}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	
	for(int x=1;x<n;x++){ // as center point
		
	}
    return 0;
}

