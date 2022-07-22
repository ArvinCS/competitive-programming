#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		us n;
		cin >> n;
		
		us data[n];
		unordered_set<us> left, right;
		for(us x=0;x<n;x++){
			cin >> data[x];
			if(left.count(data[x])){
				right.insert(data[x]);
			} else {
				left.insert(data[x]);
			}
		}
		
		us first = 0, second = 0;
		for(;first<=100;first++){
			if(!left.count(first)) break;
		}
		for(;second<=100;second++){
			if(!right.count(second)) break;
		}
		
		cout << first + second << "\n";
	}
	
    return 0;
}

