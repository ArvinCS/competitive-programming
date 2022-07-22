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

const int maxN = 1e5 + 5;
vector<int> v[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		v[data[x]].push_back(x);
	}
	
	vector<int> a, b;
	a.push_back(data[0]);
	for(int x=1;x<n;x++){
		bool useA = (a.back() != data[x]), useB = (b.size() == 0 || b.back() != data[x]);
		
		if(b.size() > 0 && useA && useB){
			auto itA = lower_bound(v[a.back()].begin(), v[a.back()].end(), x+1);
			auto itB = lower_bound(v[b.back()].begin(), v[b.back()].end(), x+1);
			
			int nextA = *itA, nextB = *itB;
			if(itA == v[a.back()].end()) nextA = inf_int;
			if(itB == v[b.back()].end()) nextB = inf_int;
			if(nextA < nextB){
				a.push_back(data[x]);
			} else {
				b.push_back(data[x]);
			}
		} else if(useA){
			a.push_back(data[x]);
		} else if(useB){
			b.push_back(data[x]);
		}
	}
	cout << a.size() + b.size() << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

