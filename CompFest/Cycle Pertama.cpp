#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

ui parrent[100000];

ui getParrent(ui id){
	if(parrent[id] == id) return id;
	return parrent[id] = getParrent(parrent[id]);
}
void join(ui id1, ui id2){
	parrent[getParrent(id1)] = getParrent(id2);
}

bool check(ui id1, ui id2){
	return getParrent(id1) == getParrent(id2);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n, m;
	cin >> n >> m;
	
	for(ui x=0;x<n;x++) parrent[x] = x;
	for(ui x=0;x<m;x++){
		ui a, b;
		cin >> a >> b;
		
		if(check(a, b)){
			cout << x+1 << "\n";
			return 0;
		} else {
			join(a, b);
		}
	}
	cout << "-1\n";
    return 0;
}

