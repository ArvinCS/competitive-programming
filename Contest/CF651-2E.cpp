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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	string s, t;
	cin >> s >> t;
	
	int a[n];
	int one = 0, zero = 0;
	for(int x=0;x<n;x++){
		a[x] = (s[x] - '0');
		
		if(s[x] == '0'){
			zero++;
		} else {
			one++;
		}
		if(t[x] == '0'){
			zero--;
		} else {
			one--;
		}
	}
	
	if(zero != 0 || one != 0){
		cout << "-1\n";
		return 0;
	}
	
	vector<int> v;
	for(int x=0;x<n;x++){
		if(s[x] != t[x]){
			v.push_back(x);
		}
	}
	
	if(v.size() == 0){
		cout << "0\n";
		return 0;
	}
	
	queue<int> q[2]; // need 0 or 1
	q[a[v[0]]^1].push(1);
	
	for(int x=1;x<v.size();x++){
		int idx = v[x];
		if(q[a[idx]].size() == 0){
			q[a[idx]^1].push(1);
			continue;
		}
		
		q[a[idx]^1].push(q[a[idx]].front()+1);
		q[a[idx]].pop();
	}
	
	int ans = 0;
	while(!q[0].empty()){
		q[0].pop();
		ans++;
	}
	while(!q[1].empty()){
		q[1].pop();
		ans++;
	}
	
	cout << ans << "\n";
    return 0;
}

