#include <iostream>

using namespace std;

int main(){
    int br;
    cout << "Unesite broj jelki: ";
    cin >> br;
    int num;
    cout << "Unesite broj redova: ";
    cin >> num;
    for (int k=0;k<br;k++){
        for (int i=0;i<num;i++){
            for (int j=i;j<num-k;j++)
                cout << ' ';
            for (int j=0;j<i+1+k;j++)
                cout << "# ";
            cout << endl;
        }
    }

    for (int j=0;j<num-1;j++)
            cout << ' ';
        for (int j=0;j<num/3;j++)
            cout << "# ";
        cout << endl;
}
