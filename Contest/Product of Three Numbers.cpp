#include <iostream>
#include <vector>

using namespace std;

vector<int> cariFaktor(long long &n){
	vector<int> faktor;
	
	for(int x=2;x*x<n;x++){
		if(n % x != 0) continue;
		faktor.push_back(x);
		n /= x;
		if(faktor.size() >= 2) break;
	}
	
	return faktor;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	// 32
	// 16 8 4 2
	while(t--){
		long long n;
		cin >> n;
		
		vector<int> faktor = cariFaktor(n);
				
		if(faktor.size() >= 2 && n > 2){
			cout << "YES\n";
			cout << faktor[0] << " " << faktor[1] << " " << n << "\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}
