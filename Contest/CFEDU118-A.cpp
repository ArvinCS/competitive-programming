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

	int t;
	cin >> t;
	
	while(t--){
		int n1, p1, n2, p2;
		cin >> n1 >> p1 >> n2 >> p2;
		
		int len1 = p1, len2 = p2;
		int cur = n1;
		vector<int> v1, v2;
		while(cur >= 10){
			len1++;
			v1.push_back(cur%10);
			cur /= 10;
		}
		v1.push_back(cur);
		
		cur = n2;
		while(cur >= 10){
			len2++;
			v2.push_back(cur%10);
			cur /= 10;
		}
		v2.push_back(cur);
		
		if(len1 > len2){
			cout << ">\n";
		} else if(len1 < len2){
			cout << "<\n";
		} else {
			reverse(v1.begin(), v1.end());
			reverse(v2.begin(), v2.end());
			
			while(v1.back() == 0) v1.pop_back();
			while(v2.back() == 0) v2.pop_back();
			
			int state = 0;
			for(int x=0;x<min(v1.size(), v2.size());x++){
				if(v1[x] == v2[x]) continue;
				if(v1[x] > v2[x]){
					state = 1;
				} else {
					state = -1;
				}
				break;
			}
			
			if(state == 0){
				if(v1.size() > v2.size()){
					state = 1;
				} else if(v1.size() < v2.size()){
					state = -1;
				}
			}
			
			if(state == 1){
				cout << ">\n";
			} else if(state == 0){
				cout << "=\n";
			} else {
				cout << "<\n";
			}
		}
	}

    return 0;
}

