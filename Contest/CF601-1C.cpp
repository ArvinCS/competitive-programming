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

ll ask1(int i, int j, int k){
	cout << "1 " << i << " " << j << " " << k << endl;
	
	ll ans;
	cin >> ans;
	
	return ans;
}

bool ask2(int i, int j, int k){
	cout << "2 " << i << " " << j << " " << k << endl;
	
	int ans;
	cin >> ans;
	
	return (ans == -1);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int nxt = 2;
	for(int x=3;x<=n;x++){
		if(ask2(1, nxt, x)){
			nxt = x;
		}
	}
	
	// The area is always concave down as the more far the point (the more far the point, the bigger the area is).
	// But we don't know it placed on the left or right side.
	// So we divide the side by 2 points between point 1 and the biggest area point.
	// Just query which side the undecided point is, it will guaranteed to be at the most left/rightmost empty place, because
	// the area is sorted.
	
	vector<pair<ll, int>> v;
	for(int x=2;x<=n;x++){
		if(x != nxt){
			ll area = ask1(1, nxt, x);
			v.push_back({area, x});
		}
	}
	
	sort(v.begin(), v.end());
	
	vector<int> l, r;
	r.push_back(1);
	r.push_back(nxt);
	
	for(int x=0;x<v.size()-1;x++){
		pair<ll, int> p = v[x];
		
		if(ask2(1, v.back().second, p.second)){
			r.push_back(p.second);
		} else {
			l.push_back(p.second);
		}
	}
	
	r.push_back(v.back().second);
	for(int x=l.size()-1;x>=0;x--) r.push_back(l[x]);
	
	cout << "0";
	for(int x=0;x<r.size();x++){
		cout << " " << r[x];
	}
	cout << endl;
    return 0;
}

