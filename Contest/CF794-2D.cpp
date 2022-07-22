#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		string s;
		cin >> s;
		
		int n = s.length();
		bool exist[n];
		fill(exist, exist+n, true);
		
		int cntA = 0, cntB = 0;
		int lst = 0;
		for(int x=0;x<n;x++){
			if(s[x] == s[lst] && (x+1 == n || s[x+1] == s[lst])){
				exist[x] = false;
				if(s[x] == 'A'){
					cntA++;
				} else {
					cntB++;
				}
			} else {
				lst = x;
			}
		}
		
		if(cntA > a || cntB > b){
			cout << "NO\n";
			continue;
		}
		
		a -= cntA; b -= cntB;
		
		vector<string> v;
		string tmp;
		for(int x=0;x<n;x++){
			if(exist[x]){
				if(tmp.empty() || tmp.back() != s[x]){
					tmp.push_back(s[x]);
				} else {
					v.push_back(tmp);
					tmp.clear();
					tmp.push_back(s[x]);
				}
			} else {
				if(!tmp.empty()) v.push_back(tmp);
				tmp.clear();
			}
		}
		if(!tmp.empty()) v.push_back(tmp);
		tmp.clear();
		
		int cntAB = 0, cntBA = 0;
		vector<pair<char, int>> w;
		for(auto s : v){
			if(s.length()&1){
				w.push_back({s[0], s.length()});
			} else {
				if(s[0] == 'A'){
					cntAB += (s.length())/2;
				} else {
					cntBA += (s.length())/2;
				}
			}
		}
		
		cout << a << " " << b << "\n";
		if(cntAB > c+min(a,b)){
			cout << "NO1\n";
			continue;
		}
		
		cout << cntAB << " -\n";
		int mn = min(cntAB, c);
		c -= mn;
		cntAB -= mn;
		
		a -= cntAB;
		b -= cntAB;
		
		if(cntBA > d+min(a,b)){
			cout << cntBA << " " << d << " " << a << " " << b << " " << "NO\n";
			continue;
		}
		
		mn = min(cntBA, d);
		d -= mn;
		cntBA -= mn;
		
		a -= cntBA;
		b -= cntBA;
		
		int sum = 0;
		for(auto p : w){
			if(p.first == 'A'){
				a--;
			} else {
				b--;
			}
			sum += p.second-1;
		}
		
		if(a < 0 || b < 0){
			cout << "NO\n";
			continue;
		}
		
		if((sum)/2 > c+d){
			cout << "NO\n";
			continue;
		}
		
		cout << "YES\n";
		// ABA -> AB + A or A + BA
		// BAB -> BA + B or B + AB
		// AB - BA
		// BA - AB
	}
	
    return 0;
}

