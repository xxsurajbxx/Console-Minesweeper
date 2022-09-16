#include <iostream>
#include <map>
#include <ctime>

using namespace std;

char display_array[10][26] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

char background_array[10][26] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

int char_to_int(char x) {
    map<char, int> char_to_int = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}};
    return char_to_int[x];
}

char int_to_char(int x) {
    map<int, char> int_to_char = {{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}};
    return int_to_char[x];
}

void print(char arr[10][26]) {
    cout << "  A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z" << endl;
    for(int y=0; y<10; y++) {
        cout << y << '|';
        for(int x=0; x<26; x++) {
            cout << arr[y][x] << ' ';
        }
        cout << endl;
    }
}

bool checkForWin() {
    for(int y=0; y<10; y++) {
        for(int x=0; x<26; x++) {
            if(background_array[y][x] == '*') {
                if(display_array[y][x] != 'F') {
                    return false;
                }
            }
            else {
                if(display_array[y][x] == '#') {
                    return false;
                }
            }
        }
    }
    return true;
}

void buildMap() {
    int counter;
    for(int y=0; y<10; y++) {
        for(int x=0; x<26; x++) {
            if(background_array[y][x] != '*') {
                counter = 0;
                if((x==0 && (y==0 || y==9)) || (x==25 && (y==0 || y==9))) { 
                    if(x==0 && y==0) {
                        if(background_array[y][x+1] == '*') {
                            counter++;
                        }
                        if(background_array[y+1][x] == '*') {
                            counter++;
                        }
                        if(background_array[y+1][x+1] == '*') {
                            counter++;
                        }
                    }
                    if(x==25 && y==0) {
                        if(background_array[y][x-1] == '*') {
                            counter++;
                        }
                        if(background_array[y+1][x] == '*') {
                            counter++;
                        }
                        if(background_array[y+1][x-1] == '*') {
                            counter++;
                        }
                    }
                    if(x==0 && y==9) {
                        if(background_array[y][x+1] == '*') {
                            counter++;
                        }
                        if(background_array[y-1][x] == '*') {
                            counter++;
                        }
                        if(background_array[y-1][x+1] == '*') {
                            counter++;
                        }
                    }
                    if(x==25 && y==9) {
                        if(background_array[y][x-1] == '*') {
                            counter++;
                        }
                        if(background_array[y-1][x] == '*') {
                            counter++;
                        }
                        if(background_array[y-1][x-1] == '*') {
                            counter++;
                        }
                    }
                }
                else {
                    if((x==0 && (y!=0 && y!=9)) || (x==25 &&(y!=0 && y!=9)) || (y==0 && (x!=0 && x!=25)) || (y==9 && (x!=0 && x!=25))) {
                        if(y==0 && (x!=0 && x!=25)) {
                            if(background_array[y][x-1] == '*') {
                                counter++;
                            }
                            if(background_array[y][x+1] == '*') {
                                counter++;
                            }
                            if(background_array[y+1][x] == '*') {
                                counter++;
                            }
                            if(background_array[y+1][x+1] == '*') {
                                counter++;
                            }
                            if(background_array[y+1][x-1] == '*') {
                                counter++;
                            }
                        }
                        if(y==9 && (x!=0 && x!=25)) {
                            if(background_array[y][x+1] == '*') {
                                counter++;
                            }
                            if(background_array[y][x-1] == '*') {
                                counter++;
                            }
                            if(background_array[y-1][x] == '*') {
                                counter++;
                            }
                            if(background_array[y-1][x+1] == '*') {
                                counter++;
                            }
                            if(background_array[y-1][x-1] == '*') {
                                counter++;
                            }
                        }
                        if(x==0 && (y!=0 && y!=9)) {
                            if(background_array[y+1][x] == '*') {
                                counter++;
                            }
                            if(background_array[y-1][x] == '*') {
                                counter++;
                            }
                            if(background_array[y][x+1] == '*') {
                                counter++;
                            }
                            if(background_array[y-1][x+1] == '*') {
                                counter++;
                            }
                            if(background_array[y+1][x+1] == '*') {
                                counter++;
                            }
                        }
                        if(x==25 && (y!=0 && y!=9)) {
                            if(background_array[y-1][x] == '*') {
                                counter++;
                            }
                            if(background_array[y+1][x] == '*') {
                                counter++;
                            }
                            if(background_array[y][x-1] == '*') {
                                counter++;
                            }
                            if(background_array[y+1][x-1] == '*') {
                                counter++;
                            }
                            if(background_array[y-1][x-1] == '*') {
                                counter++;
                            }
                        }
                    }
                    else {
                        if(background_array[y+1][x] == '*') {
                            counter++;
                        }
                        if(background_array[y-1][x] == '*') {
                            counter++;
                        }
                        if(background_array[y][x+1] == '*') {
                            counter++;
                        }
                        if(background_array[y][x-1] == '*') {
                            counter++;
                        }
                        if(background_array[y+1][x+1] == '*') {
                            counter++;
                        }
                        if(background_array[y+1][x-1] == '*') {
                            counter++;
                        }
                        if(background_array[y-1][x+1] == '*') {
                            counter++;
                        }
                        if(background_array[y-1][x-1] == '*') {
                            counter++;
                        }
                    }
                }
                background_array[y][x] = int_to_char(counter);
            }
        }
    }
}

void openZero(int x, int y) {
    display_array[y][x] = ' ';
    background_array[y][x] = ' ';
    if((x==0 && y==0)||(x==25 && y==0)||(x==0 && y==9)||(x==25 && y==9)) {
        if(x==0 && y==0) {
            if(display_array[y][x+1]!='F') {
                display_array[y][x+1] = background_array[y][x+1];
                if(display_array[y][x+1] == '0') {
                    openZero(x+1, y);
                }
            }
            if(display_array[y+1][x] != 'F') {
                display_array[y+1][x] = background_array[y+1][x];
                if(display_array[y+1][x] == '0') {
                    openZero(x, y+1);
                }
            }
            if(display_array[y+1][x+1] != 'F') {
                display_array[y+1][x+1] = background_array[y+1][x+1];
                if(display_array[y+1][x+1] == '0') {
                    openZero(x+1, y+1);
                }
            }
            return;
        }
        if(x==0 && y==9) {
            if(display_array[y-1][x] != 'F') {
                display_array[y-1][x] = background_array[y-1][x];
                if(display_array[y-1][x] == '0') {
                    openZero(x, y-1);
                }
            }
            if(display_array[y][x+1] != 'F') {
                display_array[y][x+1] = background_array[y][x+1];
                if(display_array[y][x+1] == '0') {
                    openZero(x+1, y);
                }
            }
            if(display_array[y-1][x+1] != 'F') {
                display_array[y-1][x+1] = background_array[y][x+1];
                if(display_array[y-1][x+1] == '0') {
                    openZero(x+1, y-1);
                }
            }
            return;
        }
        if(x==25 && y==0) {
            if(display_array[y][x-1] != 'F') {
                display_array[y][x-1] = background_array[y][x-1];
                if(display_array[y][x-1] == '0') {
                    openZero(x-1, y);
                }
            }
            if(display_array[y+1][x] != 'F') {
                display_array[y+1][x] = background_array[y+1][x];
                if(display_array[y+1][x] == '0') {
                    openZero(x, y+1);
                }
            }
            if(display_array[y+1][x-1] != 'F') {
                display_array[y+1][x-1] = background_array[y+1][x-1];
                if(display_array[y+1][x-1] == '0') {
                    openZero(x-1, y+1);
                }
            }
            return;
        }
        if(x==25 && y==9) {
            if(display_array[y-1][x] != 'F') {
                display_array[y-1][x] = background_array[y-1][x];
                if(display_array[y-1][x] == '0') {
                    openZero(x, y-1);
                }
            }
            if(display_array[y][x-1] != 'F') {
                display_array[y][x-1] = background_array[y][x-1];
                if(display_array[y][x-1] == '0') {
                    openZero(x-1, y);
                }
            }
            if(display_array[y-1][x-1] != 'F') {
                display_array[y-1][x-1] = background_array[y-1][x-1];
                if(display_array[y-1][x-1] == '0') {
                    openZero(x-1, y-1);
                }
            }
            return;
        }
    }
    else {
        if((x==0 && (y!=0 && y!=9))||(x==25 && (y!=0 && y!=9))||(y==0 && (x!=0 && x!=25))||(y==9 && (x!=0 && x!=25))) {
            if(x==0 && (y!=0 && y!=9)) {
                if(display_array[y-1][x] != 'F') {
                    display_array[y-1][x] = background_array[y-1][x];
                    if(display_array[y-1][x] == '0') {
                        openZero(x, y-1);
                    }
                }
                if(display_array[y-1][x+1] != 'F') {
                    display_array[y-1][x+1] = background_array[y-1][x+1];
                    if(display_array[y-1][x+1] == '0') {
                        openZero(x+1, y-1);
                    }
                }
                if(display_array[y][x+1] != 'F') {
                    display_array[y][x+1] = background_array[y][x+1];
                    if(display_array[y][x+1] == '0') {
                        openZero(x+1, y);
                    }
                }
                if(display_array[y+1][x+1] != 'F') {
                    display_array[y+1][x+1] = background_array[y+1][x+1];
                    if(display_array[y+1][x+1] == '0') {
                        openZero(x+1, y+1);
                    }
                }
                if(display_array[y+1][x] != 'F') {
                    display_array[y+1][x] = background_array[y+1][x];
                    if(display_array[y+1][x] == '0') {
                        openZero(x, y+1);
                    }
                }
                return;
            }
            if(x==25 && (y!=0 && y!=9)) {
                if(display_array[y-1][x] != 'F') {
                    display_array[y-1][x] = background_array[y-1][x];
                    if(display_array[y-1][x] == '0') {
                        openZero(x, y-1);
                    }
                }
                if(display_array[y-1][x-1] != 'F') {
                    display_array[y-1][x-1] = background_array[y-1][x-1];
                    if(display_array[y-1][x-1] == '0') {
                        openZero(x-1, y-1);
                    }
                }
                if(display_array[y][x-1] != 'F') {
                    display_array[y][x-1] = background_array[y][x-1];
                    if(display_array[y][x-1] == '0') {
                        openZero(x-1, y);
                    }
                }
                if(display_array[y+1][x-1] != 'F') {
                    display_array[y+1][x-1] = background_array[y+1][x-1];
                    if(display_array[y+1][x-1] == '0') {
                        openZero(x-1, y+1);
                    }
                }
                if(display_array[y+1][x] != 'F') {
                    display_array[y+1][x] = background_array[y+1][x];
                    if(display_array[y+1][x] == '0') {
                        openZero(x, y+1);
                    }
                }
                return;
            }
            if(y==0 && (x!=0 && x!=25)) {
                if(display_array[y][x+1] != 'F') {
                    display_array[y][x+1] = background_array[y][x+1];
                    if(display_array[y][x+1] == '0') {
                        openZero(x+1, y);
                    }
                }
                if(display_array[y][x-1] != 'F') {
                    display_array[y][x-1] = background_array[y][x-1];
                    if(display_array[y][x-1] == '0') {
                        openZero(x-1, y);
                    }
                }
                if(display_array[y+1][x] != 'F') {
                    display_array[y+1][x] = background_array[y+1][x];
                    if(display_array[y+1][x] == '0') {
                        openZero(x, y+1);
                    }
                }
                if(display_array[y+1][x-1] != 'F') {
                    display_array[y+1][x-1] = background_array[y+1][x-1];
                    if(display_array[y+1][x-1] == '0') {
                        openZero(x-1, y+1);
                    }
                }
                if(display_array[y+1][x+1] != 'F') {
                    display_array[y+1][x+1] = background_array[y+1][x+1];
                    if(display_array[y+1][x+1] == '0') {
                        openZero(x+1, y+1);
                    }
                }
                return;
            }
            if(y==9 && (x!=0 && x!=25)) {
                if(display_array[y-1][x] != 'F') {
                    display_array[y-1][x] = background_array[y-1][x];
                    if(display_array[y-1][x] == '0') {
                        openZero(x, y-1);
                    }
                }
                if(display_array[y][x+1] != 'F') {
                    display_array[y][x+1] = background_array[y][x+1];
                    if(display_array[y][x+1] == '0') {
                        openZero(x+1, y);
                    }
                }
                if(display_array[y][x-1] != 'F') {
                    display_array[y][x-1] = background_array[y][x-1];
                    if(display_array[y][x-1] == '0') {
                        openZero(x-1, y);
                    }
                }
                if(display_array[y-1][x-1] != 'F') {
                    display_array[y-1][x-1] = background_array[y-1][x-1];
                    if(display_array[y-1][x-1] == '0') {
                        openZero(x-1, y-1);
                    }
                }
                if(display_array[y-1][x+1] != 'F') {
                    display_array[y-1][x+1] = background_array[y-1][x+1];
                    if(display_array[y-1][x+1] == '0') {
                        openZero(x+1, y-1);
                    }
                }
                return;
            }
        }
        else {
            if(display_array[y-1][x] != 'F') {
                display_array[y-1][x] = background_array[y-1][x];
                if(display_array[y-1][x] == '0') {
                    openZero(x, y-1);
                }
            }
            if(display_array[y-1][x-1] != 'F') {
                display_array[y-1][x-1] = background_array[y-1][x-1];
                if(display_array[y-1][x-1] == '0') {
                    openZero(x-1, y-1);
                }
            }
            if(display_array[y-1][x+1] != 'F') {
                display_array[y-1][x+1] = background_array[y-1][x+1];
                if(display_array[y-1][x+1] == '0') {
                    openZero(x+1, y-1);
                }
            }
            if(display_array[y][x+1] != 'F') {
                display_array[y][x+1] = background_array[y][x+1];
                if(display_array[y][x+1] == '0') {
                    openZero(x+1, y);
                }
            }
            if(display_array[y][x-1] != 'F') {
                display_array[y][x-1] = background_array[y][x-1];
                if(display_array[y][x-1] == '0') {
                    openZero(x-1, y);
                }
            }
            if(display_array[y+1][x] != 'F') {
                display_array[y+1][x] = background_array[y+1][x];
                if(display_array[y+1][x] == '0') {
                    openZero(x, y+1);
                }
            }
            if(display_array[y+1][x-1] != 'F') {
                display_array[y+1][x-1] = background_array[y+1][x-1];
                if(display_array[y+1][x-1] == '0') {
                    openZero(x-1, y+1);
                }
            }
            if(display_array[y+1][x+1] != 'F') {
                display_array[y+1][x+1] = background_array[y+1][x+1];
                if(display_array[y+1][x+1] == '0') {
                    openZero(x+1, y+1);
                }
            }
            return;
        }
    }
}

int main() {
    map<char, int> coords = {{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}, {'i', 8}, {'j', 9}, {'k', 10}, {'l', 11},
        {'m', 12}, {'n', 13}, {'o', 14}, {'p', 15}, {'q', 16}, {'r', 17}, {'s', 18}, {'t', 19}, {'u', 20}, {'v', 21}, {'w', 22}, {'x', 23}, {'y', 24}, {'z', 25}};
    srand(time(0));
    for(int x=0; x<30; x++) {
        background_array[rand() % 10][rand() % 26] = '*';
    }
    buildMap();
    string input;
    int x, y;
    bool loss = false;
    char action;
    while(!loss) {
        print(display_array);
        cin >> input;
        input.at(0) = tolower(input.at(0));
        input.at(1) = tolower(input.at(1));
        if((input.at(0)=='o'||input.at(0)=='f') && isalpha(input.at(1))) {
            action = input.at(0);
            x = coords[input.at(1)];
            y = char_to_int(input.at(2));
            if(action == 'f') {
                if(display_array[y][x] == 'F') {
                    display_array[y][x] = '#';
                }
                else {
                    display_array[y][x] = 'F';
                }
            }
            if(action == 'o' && display_array[y][x] != 'F') {
                display_array[y][x] = background_array[y][x];
                if(display_array[y][x] == '0') {
                    openZero(x, y);
                }
                if(display_array[y][x] == '*') {
                    loss = true;
                }
            }
        }
        if(checkForWin()) {
            system("cls");
            cout << "You Won" << endl << "Feels Good" << endl;
            system("pause");
            return 0;
        }
        system("cls");
    }
    cout << "You Lost" << endl << "Feels Bad" << endl;
    system("pause");
    return 0;
}