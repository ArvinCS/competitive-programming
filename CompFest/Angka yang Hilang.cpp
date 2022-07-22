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
	
	int n, k, tmp;
	cin >> n >> k;
	
	unordered_set<int> kertas;
	
	while(k--){
		cin >> tmp;
		kertas.insert(tmp);
	}
	
	bool first = true;
	for(int x=1;x<=n;x++){
		if(!kertas.count(x)){
			if(!first){
				cout << " ";
			}
			cout << x;
			first = false;
		}
	}
	cout << "\n";
    return 0;
}

