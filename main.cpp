#include "screen.h"

void clear();

int main()
{
    cout << "everything's fine..\n\n";

    screen s;

    s.startingScreen();

    // s.createWebGraph();

    // s.printEdgesvec();

    return 0;
}

void clear()
{
    for(int i = 0; i < 100; i++)
        cout << endl;
}