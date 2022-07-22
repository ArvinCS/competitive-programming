#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	vector<char> v;
	for(int x=0;x<n;x++){
		v.push_back(s[x]);
	}
	
	sort(v.begin(), v.end());
	
	int cnt[26];
	fill(cnt, cnt+26, 0);
	
	int idx = 0, posL = 0;
	vector<int> l, r;
	for(int x=n-1;x>posL;x--){
		while(cnt[(v[idx] - 'a')] > 0){
			cnt[(v[idx] - 'a')]--;
			idx++;
		}
		while(posL < x){
			while(cnt[(v[idx] - 'a')] > 0){
				cnt[(v[idx] - 'a')]--;
				idx++;
			}
			
			if(s[posL] == v[idx]){
				idx++;
				posL++;
				continue;
			} else {
				break;
			}
		}
		while(cnt[(v[idx] - 'a')] > 0){
			cnt[(v[idx] - 'a')]--;
			idx++;
		}
			
		if(posL >= x) break;
		if(s[x] == v[idx]){
			idx++;
			cnt[(s[posL] - 'a')]++;
			l.push_back(posL++);
			r.push_back(x);
		} else {
			cnt[(s[x] - 'a')]++;
		}
	}
	
	for(int x=0;x<r.size();x++){
		swap(s[l[x]], s[r[x]]);
	}
	
	cout << s << "\n";
    return 0;
}

