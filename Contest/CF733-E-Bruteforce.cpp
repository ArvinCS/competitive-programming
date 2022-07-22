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

int limit = 0;

int prefix_function(string s) {
    int n = (int)s.length(), ans = 0;
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
        ans = max(ans, pi[i]);
    }
    return ans;
}

int mx = inf_int;
string ans;

void solve(int cnt[26], string s){
	bool done = true;
	for(int x=0;x<26;x++){
		if(cnt[x] > 0){
			done = false;
			break;
		}
	}
	
	if(done){
		int tmp = prefix_function(s);
		if(tmp < mx){
			mx = tmp;
			ans = s;
		} else if(tmp == mx){
			ans = min(ans, s);
		}
		return;
	}
	
	for(int x=0;x<=limit;x++){
		if(cnt[x] > 0){
			char c = ('a' + x);
			s += c;
			cnt[x]--;
			solve(cnt, s);
			cnt[x]++;
			s.pop_back();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	string s;
	cin >> s;
	
	int cnt[26];
	fill(cnt, cnt+26, 0);
	
	for(int x=0;x<s.length();x++){
		cnt[(s[x] - 'a')]++;
		limit = max(limit, (s[x] - 'a'));
	}
	
	solve(cnt, "");
	
	cout << mx << " -> " << ans << "\n";
    return 0;
}

