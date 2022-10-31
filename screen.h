#ifndef SCREEN_H
#define SCREEN_H

#include "webpage.h"
#include <fstream>

class screen
{
    sitevec history;
    sitevec allsites;

public:
    void readSites();
    void readHistory();
    void prinHistory();
    void printAllSites();
    void startingScreen();

    sitevec getAllSites();
};

#endif /*SCREEN_H*/