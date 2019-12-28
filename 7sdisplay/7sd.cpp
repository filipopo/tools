//7 segment display configurator
#include <iostream>

using namespace std;

int main(){
    bool tabela[10][8]={
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
    cout << "Zajednicka katoda ili anoda?" << endl;
    string mode;
    cin >> mode;
    string order;
    cout << "Unesite redosled a b c d e f g p:" << endl;
    cin >> order[0] >> order[1] >> order[2] >> order[3] >> order[4] >> order[5] >> order[6] >> order[7];

    for (short i = 0; i<10;i++){
        short B=0;
        for (short j = 0; j<8;j++){
            bool b=0;
            if (mode == "anoda")
                switch (order[j]){
                    case 'a':b = tabela[i][0];break;
                    case 'b':b = tabela[i][1];break;
                    case 'c':b = tabela[i][2];break;
                    case 'd':b = tabela[i][3];break;
                    case 'e':b = tabela[i][4];break;
                    case 'f':b = tabela[i][5];break;
                    case 'g':b = tabela[i][6];break;
                    case 'p':b = tabela[i][7];break;
                }
            else
                switch (order[j]){
                    case 'a':b = !tabela[i][0];break;
                    case 'b':b = !tabela[i][1];break;
                    case 'c':b = !tabela[i][2];break;
                    case 'd':b = !tabela[i][3];break;
                    case 'e':b = !tabela[i][4];break;
                    case 'f':b = !tabela[i][5];break;
                    case 'g':b = !tabela[i][6];break;
                    case 'p':b = !tabela[i][7];break;
                }
            cout << b << ' ';
            if (b == 1)
                B |= (1u << 7-j);
        }
        cout << "0x" << hex << B << ' ' << i << endl;
    }
}
