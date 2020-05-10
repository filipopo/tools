//7 segment display configurator cpp file
#include "7sd.h"
#include <cstring>

//Instance with predefined options
ssd::ssd(std::string mode, std::string order) {
	this->mode = mode;

	size_t last = 0;
	size_t next = 0;
	//Splits the string based on a space being the delimiter, for readability
	while ((next = order.find(' ', last)) != std::string::npos) {
		this->order += order.substr(last, next - last);
		last = next + 1;
	}
	this->order += order.substr(last);
	
	calculate();
}

//Default instance which asks you for the options
ssd::ssd() {
	std::cout << "Zajednicka katoda ili anoda? ";
	std::cin >> mode;
	std::cout << "Unesite redosled: ";
	std::cin >> order[0] >> order[1] >> order[2] >> order[3] >> order[4] >> order[5] >> order[6] >> order[7];

	calculate();
	print_table();
}

//For the input options creates a table and pre-defines conversion values
//This is done with so that the program doesn't need to do a for loop 8 times on every convert(i) operation
void ssd::calculate() {
	//Creates a temporary matrix because we don't know the order and need the original one
	bool table_b[10][8];
	for (short i = 0; i < 10;i++) {
		for (short j = 0; j < 8;j++) {
			bool b = 0;
			switch (order[j]) {
				case 'a':b = table[i][0];break;
				case 'b':b = table[i][1];break;
				case 'c':b = table[i][2];break;
				case 'd':b = table[i][3];break;
				case 'e':b = table[i][4];break;
				case 'f':b = table[i][5];break;
				case 'g':b = table[i][6];break;
				case 'p':b = table[i][7];break;
			}

			//Cathode values are just inverted anode values
			if (mode[0] == 'k')
				b = !b;

			table_b[i][j] = b;
			if (b == 1)
				B[i] |= (1u << 7-j); //Sets the bit on the 7-j position of the B[i] element to 1
		}
	}

	//Copies over our temporary matrix into the real one
	memcpy(table, table_b, sizeof(table));
}

//Prints out the order and then prints the table + conversion values for each number
void ssd::print_table(){
	for(short i = 0;i < 8;i++)
		std::cout << order[i] << ' ';
	std::cout << std::endl;
	
	for(short i = 0;i < 10;i++){
		for (short j = 0; j < 8;j++)
			std::cout << table[i][j] << ' ';

		std::string start = "0x";
		if (B[i] <= 0xF)
			start += '0';
		std::cout << start << std::hex << B[i] << ' ' << i << std::endl;
	}
}
