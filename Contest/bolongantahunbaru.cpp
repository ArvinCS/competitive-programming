#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, currentIndex = 0;
    int listOne[3] = {4,6,9};
    bool leading = true;
    
    cin >> n;
    
    if(n == 0){
    	cout << "1\n";
	} else if(n == 1){
    	cout << "0\n";
	} else if(n == 2){
		cout << "8\n";
	} else {
	    while(n > 0){
    		if(n % 2 == 0){
    			cout << "8";
				n -= 2;	
			} else {
				if(leading){
		    		cout << "4"; 
					n--;
					leading = false;
				} else {
					cout << "0"; 
					n--;
				}
			}
		}
		cout << "\n";
	}
}
