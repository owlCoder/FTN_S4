/*
Napraviti program koji kreira jednu nit i u okviru niti ispisuje proizvoljnu rečenicu.
*/

#include <iostream>
#include <thread>

using namespace std;

void f() {
    cout << "Helou, it's me!" << endl;
}

int main()
{
    thread t(f);
    t.join();

    return 0;
}
