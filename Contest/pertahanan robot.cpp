#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string commands;
    int x = 0;
	int y = 0;
    cin >> commands;
    
    for(int a=0;a<commands.size();a++){
    	char alphabet = commands[a];
    	if(alphabet >= 'A' && alphabet <= 'Z'){
    	    if(alphabet == 'R'){
    	    	x++;
			} else if(alphabet == 'L'){
				x--;
			} else if(alphabet == 'U'){
				y++;
			} else if(alphabet == 'D'){
				y--;
			}
		}
	}
	
	cout << x << " " << y << "\n";
    return 0;
}
