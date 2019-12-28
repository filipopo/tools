#include <iostream>

using namespace std;

int main(){
    int br;
    cout << "Unesite broj blokova u jelci: ";
    cin >> br;
    int num;
    cout << "Unesite broj redova bloka jelke: ";
    cin >> num;
    for (int j=0;j<num;j++)
        cout << ' ';
    cout << '#' << endl;
    for (int k=0;k<br;k++){
        for (int i=1;i<num;i++){
            for (int j=i;j<num;j++)
                cout << ' ';
            for (int j=0;j<i+1+k;j++)
                cout << "# ";
            cout << endl;
        }
        for (int j=k;j<num;j++)
            cout << ' ';
        for (int j=0;j<k+1;j++)
            cout << "# ";
        cout << endl;
    }
}
