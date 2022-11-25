#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct siteInfo
{
    string url;
    string KeyWords;
    int loc, clicks;
};

struct edge
{
    siteInfo src, dst;
    int loc;
};

typedef vector<siteInfo> sitevec;

extern void clear();
extern string getTillChar(string &, char);

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

    void startingScreen();
    void createWebGraph();
    void printEdgesvec();

    sitevec getAllSites();


    
};

#endif /*SCREEN_H*/