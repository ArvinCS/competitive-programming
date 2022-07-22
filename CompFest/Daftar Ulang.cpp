#include <iostream>
#include <map>

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
	
	us n, q;
	cin >> n >> q;
	
	map<string, us> daftar;
	
	for(us x=1;x<=n;x++){
		string tmp;
		cin >> tmp;
		daftar[tmp] = x;
	}
	
	while(q--){
		string tmp;
		cin >> tmp;
		if(daftar.find(tmp) != daftar.end()){
			cout << daftar[tmp] << "\n";
		} else cout << "-1\n";
	}
    return 0;
}

