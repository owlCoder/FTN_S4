/*
Napraviti program koji kreira jednu nit kojoj se prosleđuju dva cela broja a i b.
U okviru niti sabrati brojeve i ispisati na ekran njihov zbir.
*/

#include <iostream>
#include <thread>

using namespace std;

void f(int a, int b) {
    cout << a + b << endl;
}

int main(void)
{
    thread(f, 3, 4).join();

    return 0;
}
