#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string a, b, c;
	cin >> a >> b >> c;
	
	int cnt[26];
	fill(cnt, cnt+26, 0);
	
	auto check = [&](string s) -> void {
		int cnt2[26];
		fill(cnt2, cnt2+26, 0);
		for(int x=0;x<s.length();x++){
			cnt[(s[x] - 'A')]++;
		}
		
		for(int x=0;x<26;x++){
			cnt[x] = max(cnt[x], cnt2[x]);
		}
	};
	
	check(a);
	check(b);
	check(c);
	
	vector<char> v;
	for(int x=0;x<26;x++){
		for(int y=0;y<cnt[x];y++){
			v.push_back(('A' + x));
		}
	}
	
	cout << (v.size()+1)/2 << "\n";
	for(int x=0;x<v.size()/2;x++){
		cout << v[x] << v[(x+v.size()/2)%v.size()] << "\n";
	}
    return 0;
}

