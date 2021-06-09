#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <fstream>

using namespace std;

void saveGame(char& y, int& x) {
    ofstream save;
    save.open("game_save.txt", ios::binary);
    save.put(y);
    save.write((char*)&x, sizeof(x));
    save.close();
}

int grupa(int, int);
int podgrupa(int, char);

int main()
{

    int x, Y;
    char y, igrac = 'X';
    char polje[9][9];
    int straneSvijeta[9][9];
    int izbor;
    //==================================================================================================================================================
    while (1)
    {
        system("cls");
        cout << endl << endl << "|===========DOBRODOSLI U STRATESKI KRIZIC-KRUZIC==========|" << endl << endl;
        cout << "--> 1. POKRENI IGRU" << endl;
        cout << "--> 2. SPREMI IGRU" << endl;
        cout << "--> 3. UCITAJ IGRU" << endl;
        cout << "--> 4. IZLAZ IZ IGRE" << endl;
        cout << "--> ODABIR: ";
        cin >> izbor;
        if (izbor == 1)
        {
            //NACRT PLOCE
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    polje[i][j] = j + 49;
                }
            }
            int j = 0;
            int h;
            for (int y = 0; y < 9; y++)
            {
                while (j < 9)
                {
                    if (y == 0 || y == 3 || y == 6)
                    {
                        h = 1;
                    }
                    else if (y == 1 || y == 4 || y == 7)
                    {
                        h = 4;
                    }
                    else if (y == 2 || y == 5 || y == 8)
                    {
                        h = 7;
                    }
                    for (int i = 0; i < 3; i++)
                    {
                        straneSvijeta[y][j] = h;
                        h++;
                        j++;
                    }
                }
                j = 0;
            }
            int y1, x1;
            int gr, pgr = 0;

            for (int potez = 0; potez < 80; potez++)
            {
                system("@cls||clear");
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                    {
                        char temp = 'a' + i;
                        if (polje[i][j] == 'X' || polje[i][j] == 'O')
                        {
                            temp = ' ';
                        }
                        if (j == 2 || j == 5)
                        {
                            cout << temp << polje[i][j] << "   |   ";
                            //printf(" %c%c |", temp, polje[i][j]);
                        }
                        else
                        {
                            cout << " " << temp << polje[i][j] << "  ";
                            //printf(" %c%c ", temp, polje[i][j]);
                        }
                    }
                    cout << endl << endl;
                    if (i == 2 || i == 5)
                    {
                        cout << "------------------------------------------------------------" << endl << endl;
                        //printf("--------------------------------------\n\n");
                    }
                    cout << endl;
                }

                while (1)
                {
                    cout << "Igrac " << igrac << " unos mjesta:" << endl;
                    //printf("Igrac %c unos mjesta:\n", igrac);
                    cin >> y >> x;
                    if (y == 's' && x == 1) {
                        saveGame(y, x);
                        break;
                    }
                    y1 = y - 97;
                    x1 = x - 1;
                    gr = grupa(x, y);

                    if ((polje[(int)y - 97][x - 1] != 'X' && polje[(int)y - 97][x - 1] != 'O') && (pgr == gr || pgr == 0))
                    {
                        polje[(int)y - 97][x - 1] = igrac;
                        pgr = podgrupa(x, y);
                        break;
                    }
                    else
                    {
                        cout << "Igrac " << igrac << " ponovno unosi mjesto." << endl;
                        //printf("Igrac %c ponovno unosi mjesto.\n", igrac);
                    }
                }


                if (igrac == 'O')
                {
                    igrac = 'X';
                }
                else
                {
                    igrac = 'O';
                }
            }
        }
        else if (izbor == 2)
        {

        }
        else if (izbor == 3)
        {
            cout << "DOVIDJENJA!";
            break;
        }
        else
        {
            cout << "-->KRIVI UNOS!" << endl;
        }
    }
    //==================================================================================================================================================
    return 0;
}


int grupa(int x, int y)
{
    if (y - 96 <= 3 && x <= 3)
    {
        return 1;
    }
    else if (y - 96 <= 3 && x >= 4 && x <= 6)
    {
        return 2;
    }
    else if (y - 96 <= 3 && x >= 7 && x <= 9)
    {
        return 3;
    }
    else if (y - 96 <= 6 && y - 96 >= 2 && x <= 3)
    {
        return 4;
    }
    else if (y - 96 <= 6 && y - 96 >= 2 && x <= 6 && x >= 4)
    {
        return 5;
    }
    else if (y - 96 <= 6 && y - 96 > 3 && x <= 9 && x >= 7)
    {
        return 6;
    }
    else if (y - 96 <= 9 && y - 96 >= 7 && x >= 1 && x <= 3)
    {
        return 7;
    }
    else if (y - 96 <= 9 && y - 96 >= 7 && x <= 6 && x >= 4)
    {
        return 8;
    }
    else
    {
        return 9;
    }
}

int podgrupa(int x, char y)
{
    if ((y == 'a' || y == 'd' || y == 'g') && x % 3 == 1)
    {
        return 1;
    }
    else if ((y == 'a' || y == 'd' || y == 'g') && x % 3 == 2)
    {
        return 2;
    }
    else if ((y == 'a' || y == 'd' || y == 'g') && x % 3 == 0)
    {
        return 3;
    }
    else if ((y == 'b' || y == 'e' || y == 'h') && x % 3 == 1)
    {
        return 4;
    }
    else if ((y == 'b' || y == 'e' || y == 'h') && x % 3 == 2)
    {
        return 5;
    }
    else if ((y == 'b' || y == 'e' || y == 'h') && x % 3 == 0)
    {
        return 6;
    }
    else if ((y == 'c' || y == 'f' || y == 'i') && x % 3 == 1)
    {
        return 7;
    }
    else if ((y == 'c' || y == 'f' || y == 'i') && x % 3 == 2)
    {
        return 8;
    }
    else
    {
        return 9;
    }
}
