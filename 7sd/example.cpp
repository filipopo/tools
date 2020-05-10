#include "7sd.h"

using namespace std;

int main() {
	ssd circut("anoda", "a b c d e f g p");
	circut.print_table();
	cout << "Za broj 5 treba da se posalje: " << "0x" << circut.convert(5) << endl;
	
	cout << endl;
	ssd A;
}
