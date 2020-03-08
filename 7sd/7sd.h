//7 segment display configurator header file
#include <iostream>

class ssd{
    bool table[10][8]={
        //anode values for 0-9
       //a b c d e f g dp
		{0,0,0,0,0,0,1,1},
        {1,0,0,1,1,1,1,1},
        {0,0,1,0,0,1,0,1},
        {0,0,0,0,1,1,0,1},
        {1,0,0,1,1,0,0,1},
        {0,1,0,0,1,0,0,1},
        {0,1,0,0,0,0,0,1},
        {0,0,0,1,1,1,1,1},
        {0,0,0,0,0,0,0,1},
        {0,0,0,0,1,0,0,1},
    };

	std::string mode, order="";
	short B[10]={0,0,0,0,0,0,0,0,0,0};

	void calculate();

	public:
		ssd(std::string, std::string);
		ssd();

		short convert(short num){ return B[num]; }

		void print_table();
};
