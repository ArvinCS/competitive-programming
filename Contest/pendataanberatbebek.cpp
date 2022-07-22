#include <iostream>

using namespace std;

struct Batas{
	int from, end;
};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	int bebek[n];
	for(int x=0;x<n;x++){
		cin >> bebek[x];
	}	
	int q;
	cin >> q;
	Batas list[q];
	
	for(int x=0;x<q;x++){
		int f,u;
		cin >> f >> u;
		int s=0,e=n-1;
		int l = 0;
		while(l <= e){
			int mid = (l+e)/2;
			if(bebek[mid] > f){
				e = mid-1;
			} else {
				l = mid +1;
				s = l;
			}
		}
		l = 0;
		e = n-1;
		while(l <= e){
			int mid = (l+e)/2;
			if(bebek[mid] <= u){
				l = mid + 1;
			} else {
				e = mid - 1;
			}
		}
		
		cout << (e-s+1) << "\n";
	}
	
    return 0;
}
