#ifndef SCREEN_H
#define SCREEN_H

#include "webpage.h"
#include <fstream>

class screen
{
    sitevec history;
    sitevec allsites;

    vector<edge> edges;

    string emptyString;

    // sites webgraph(edge, edges.size());
public:
    screen();
    void readSites();
    void printAllSites();
    void startingScreen();
    void createWebGraph();

    sitevec getAllSites();

    string getTillChar(string &, char);
};

#endif /*SCREEN_H*/