#include <iostream>

using namespace std;

int findRepresent(int x, int par[]){
	if(par[x] == x){
		return x;
	}
	return findRepresent(par[x], par);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	int parrent[n+1];
	for(int x=1;x<=n;x++) parrent[x] = x;
	
	for(int x=0;x<q;x++){
		short a;
		int b, c;
		cin >> a >> b >> c;
		if(a == 1){
			parrent[findRepresent(b, parrent)] = findRepresent(c, parrent);
		} else if(a == 2){
			if(findRepresent(b, parrent) == findRepresent(c, parrent)){
				cout << "Y\n";
			} else {
				cout << "T\n";
			}
		}
	}
    return 0;
}
