#ifndef SCREEN_H
#define SCREEN_H

#include "webpage.h"
#include <fstream>

extern void clear();

class screen
{
    sitevec history;
    sitevec allsites;

    vector<edge> edges;

    string emptyString;

    vector<vector<siteInfo>> adjList;

    // sites webgraph(edge, edges.size());
public:
    screen();
    void readSites();
    void printAllSites();
    void startingScreen();
    void createWebGraph();
    void printEdgesvec();

    sitevec getAllSites();

    string getTillChar(string &, char);

    
};

#endif /*SCREEN_H*/