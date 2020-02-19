//7 segment display configurator cpp file
#include <iostream>
#include <cstring>
#include "7sd.h"

ssd::ssd(std::string mode, std::string order){
	this->mode=mode;
	this->order=order;
	target=1;
	calculate();
}

ssd::ssd(){
	std::cout << "Zajednicka katoda ili anoda?" << std::endl;
	std::cin >> mode;
	std::cout << "Unesite redosled a b c d e f g p:" << std::endl;
	std::cin >> order[0] >> order[1] >> order[2] >> order[3] >> order[4] >> order[5] >> order[6] >> order[7];
	calculate();
	print_table();
}

void ssd::calculate(){
	bool table_b[10][8];
	for (short i = 0; i<10;i++){
		for (short j = 0; j<8;j++){
			bool b=0;
			if (mode == "anoda")
				switch (order[j]){
					case 'a':b = table[i][0];break;
					case 'b':b = table[i][1];break;
					case 'c':b = table[i][2];break;
					case 'd':b = table[i][3];break;
					case 'e':b = table[i][4];break;
					case 'f':b = table[i][5];break;
					case 'g':b = table[i][6];break;
					case 'p':b = table[i][7];break;
				}
			else
				switch (order[j]){
					case 'a':b = !table[i][0];break;
					case 'b':b = !table[i][1];break;
					case 'c':b = !table[i][2];break;
					case 'd':b = !table[i][3];break;
					case 'e':b = !table[i][4];break;
					case 'f':b = !table[i][5];break;
					case 'g':b = !table[i][6];break;
					case 'p':b = !table[i][7];break;
				}

		table_b[i][j]=b;
		if (b == 1)
			B[i] |= (1u << 7-j);
		}
	}

	memcpy(table, table_b, sizeof(table));
}

void ssd::print_table(){
	if (target)
		std::cout << order << std::endl;
	for(short i=0;i<10;i++){
		for (short j = 0; j<8;j++)
			std::cout << table[i][j] << ' ';
		std::string start="0x";
		if (B[i] <= 0xF)
			start+="0";
		std::cout << start << std::hex << B[i] << ' ' << i << std::endl;
	}
}

int main(){
	new ssd();
}
