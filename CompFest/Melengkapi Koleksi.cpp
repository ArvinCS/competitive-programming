#include <iostream>
#include <unordered_set>

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
	
	ui n, q;
	cin >> n >> q;
	
	unordered_set<ui> jilid;
	while(n--){
		ui tmp;
		cin >> tmp;
		jilid.insert(tmp);	
	}
	
	while(q--){
		ui tmp;
		cin >> tmp;
		if(jilid.count(tmp)){
			cout << "ada\n";
		} else {
			cout << "tidak ada\n";
		}
	}
    return 0;
}

