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

int ask(int a, int b, int c){
	cout << a << " " << b << " " << c << endl;
	
	int ans;
	cin >> ans;	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t, n, q;
	cin >> t >> n >> q;
	
	while(t--){
		int start = 1;
		for(int x=1;x<=n;x++){
			int a = -1, b = -1;
			int cur = 1;
			
			bool valid = true;
			while(cur <= n){
				if(cur == x) cur++;
				a = cur;
				if(a+1 == x) b = a+2;
				else b = a+1;
				
				if(b > n){
					b = a-1;
					if(b == x) b--;
				}
				
				int ans = ask(x, a, b);
				if(ans == x){
					valid = false;
					break;
				}
				if(b < a) break;
				cur++;
			}
			if(valid){
				start = x;
				break;
			}
		}
		
		set<int> st;
		st.insert(start);
		int a = 1, b = 2;
		if(a == start){
			a++;
			b++;
		} else if(b == start){
			b++;
		}
		
		int tmp = ask(left, a, b);
		int left = -1, right = -1;
		
		if(a == tmp){
			left = tmp; 
			right = b;
		} else {
			left = tmp;
			right = a;
		}
		st.insert(a);
		st.insert(b);
		
		int next[n], prev[n];
		fill(next, next+n, -1);
		fill(prev, prev+n, -1);
		
		next[0] = 1;
		prev[1] = 0;
		next[1] = 2;
		prev[2] = 1;
		
		for(int x=1;x<=n;x++){
			if(st.count(x)) continue;
			
		}
		
		int ans[n+1];
		fill(ans, ans+n+1, -1);
		
		ans[0] = left;
		for(int x=1;x<=n;x++){
			int pos = n-cnt[x];
			ans[pos-1] = x;
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << endl;
		
		int ok;
		cin >> ok;
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

