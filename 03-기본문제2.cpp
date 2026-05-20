#include <iostream>
using namespace std;

void GetItem(int** inventory, int x, int y);
void UseItem(int** inventory, int x, int y);
void PrintItems(int** inventory, int n, int m);

int main() {

    int n, m;
    cin >> n >> m;

    int** inventory = new int* [n];

    for (int i = 0; i < n; i++) {
        inventory[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            inventory[i][j] = 0;
        }
    }

    char command;

    while (true) {
        cin >> command;

        if (command == 'p') {
            PrintItems(inventory, n, m);
            break;
        }

        int x, y;
        cin >> x >> y;

        if (command == 'g') {
            GetItem(inventory, x, y);
        }

        else if (command == 'u') {
            UseItem(inventory, x, y);
        }

    }
    
    for (int i = 0; i < n; i++) {
        delete[] inventory[i];
    }

    delete[] inventory;

}



void GetItem(int** inventory, int x, int y) {
    inventory[x][y]++;
}

void UseItem(int** inventory, int x, int y) {
    if (inventory[x][y] > 0)
        inventory[x][y]--;
}

void PrintItems(int** inventory, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << inventory[i][j];

            if (j < m - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// 2번 팀 원 수정
