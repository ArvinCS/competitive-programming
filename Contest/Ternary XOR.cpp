#include <iostream>

using namespace std;

int n;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> n >> s;
		
		string largest(n, '0');
		string smallest(n, '0');
		
		for(int x=0;x<s.length();x++){
			if(s[x] == '2'){
				smallest[x] = largest[x] = '1';
			} else if(s[x] == '1'){
				largest[x] = '1';
				for(int y=x+1;y<s.length();y++){
					smallest[y] = s[y];
				}
				break;
			}
		}
		cout << largest << "\n";
		cout << smallest << "\n";
	}
	
    return 0;
}
