#include <iostream>

using namespace std;

int kolom,baris;
int data[20][8];

void cek(){
	int batas = kolom-1;
	bool runtuh = false;
	for(int y=kolom-1;y>=0;y--){
		int hitam = 0;
		for(int x=0;x<baris;x++){
			if(data[y][x] == 1){
				hitam++;
				if(hitam == baris){
					for(int z=0;z<baris;z++){
						data[y][z] = 0;
					}	
					batas =  y;
					runtuh = true;
				}
			} else {
				break;
			}
		}
	}
	if(runtuh){
		if(batas != kolom-1){
			for(int y2=batas;y2<kolom;y2++){
				for(int x2=0;x2<baris;x2++){
					if(data[y2][x2] == 1){
						int checkpoint = y2;
						for(int z=y2-1;z>=0;z--){
							if(data[z][x2] == 0){
								checkpoint = z;
							} else {
								break;
							}
						}
						data[y2][x2] = 0;
						data[checkpoint][x2] = 1;
					}
				}
			}
		}
		cek();
	}
}

int main(){
	cin >> kolom >> baris;

	for(int y=kolom-1;y>=0;y--){
		string command;
		cin >> command;
		for(int x=0;x<baris;x++){
			data[y][x] = command[x] - '0';
		}
	}
	
	cek();

	for(int y=kolom-1;y>=0;y--){
		for(int x=0;x<baris;x++){
			cout  << data[y][x];
		}
		cout << "\n";
	}
	return 0;
}
