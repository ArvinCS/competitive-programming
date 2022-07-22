#include <iostream>

using namespace std;

int k, a, b;
string s;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> k >> a >> b >> s;
		
	if(b*k < s.length() || a*k > s.length()){
		cout << "No solution\n";
	} else {
		int part[k], n = s.length();
		for(int x=0;x<k;x++) part[x] = a;
		n -= a*k;
		
		for(int x=0;x<k;x++){
			if(b-a >= n){
				part[x] += n;
				break;
			} else {
				part[x] += b-a;
				n -= (b-a);
			}
		}
		
		int cnt = 0;
		for(int x=0;x<k;x++){
			cout << s.substr(cnt, part[x]) << "\n";
			cnt += part[x];
		}
	}
    
	return 0;
}
