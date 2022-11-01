#ifndef WEBPAGE_H
#define WEBPAGE_H

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

class sites
{
    vector<sitevec> adjList;

public:
    sites(vector<edge> const&, int);

    // void CreateGraph(vector<edge> &, int);
};

#endif /*WEBPAGE_H*/