#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <iostream>
#include <vector>

using namespace std;

struct siteInfo
{
    string url;
    vector<string> KeyWords;
};

struct edge
{
    siteInfo src, dst;
};

class sites
{
    vector<vector<siteInfo>> adjList;

    sites(vector<edge> const &, siteInfo);
};

#endif /*WEBPAGE_H*/