#include <iostream>
#include <fstream>

using namespace std;

class redpill {
    ofstream myfile;
    short num = 0,nbase;
    void loopy(string pass, short pos) {
        for (short i = pos; i < pass.length() * (nbase - 1); i++) {
            if (pos < pass.length() * (nbase - 1)) {
               pos++;
               loopy(pass, pos);
            }

            //for (int j = 0;j < nbase;j++){
            cout << "OILALA " << (char)(int)pass[i] << " HARAMBE" << endl;
            //}
        }
        cout << pass << endl;
        myfile << pass << endl;
        num++;
    }

    public:
        redpill(short nbase, short nums){
            this->nbase = nbase;
            myfile.open("comb.txt");
            string s = "0";
            for(;nums > 1;nums--)
                s += '0';
            loopy(s, 0);
            myfile.close();
            cout << num << " Combinations" << endl;
        }
};

int main() {
    cout << "Input number base:" << endl;
    short nbase;
    cin >> nbase;
    cout << "Numbers: ";
    short nums;
    cin >> nums;
    redpill A(nbase, nums);
}
