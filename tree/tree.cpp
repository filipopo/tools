// Gonna try to be the most advanced text tree generator lmao
#include <iostream>

using namespace std;

int main() {
    int br;
    cout << "Unesite broj jelki: ";
    cin >> br;
    int num;
    cout << "Unesite broj redova: ";
    cin >> num;

    int x;
    for (int k = 0;k < br;k++) {
        for (int i = 0;i < num;i++) {
            for (int j = i;j < num - k + br - 2;j++)
                cout << ' ';
            for (x = 0;x <= i + k;x++)
                cout << "# ";
            cout << endl;
        }
    }

    for (int k = 0;k < (num + br - 1) / 2;k++) {
        for (int i = 0;i < (num + br) / 2;i++)
            cout << ' ';
         for (int y = 0;y < x / 2;y++)
            cout << "# ";
        cout << endl;
    }
}
