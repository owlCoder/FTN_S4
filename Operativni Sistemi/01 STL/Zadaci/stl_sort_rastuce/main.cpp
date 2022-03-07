/*
Uneti 5 celih brojeva sa standardnog ulaza.
Korišćenjem STL algoritma sortirati brojeve u rastućem redosledu.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<int>brojevi(5);

    for(int i = 0; i < 5; i++)
        cin >> brojevi[i];

    sort(brojevi.begin(), brojevi.end());

    cout << endl << "SORTIRANO RASTUCE: \n";
    for(int i = 0; i < 5; i++)
        cout << brojevi[i] << " ";

    return 0;
}
