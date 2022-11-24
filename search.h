#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <unordered_map>

#include "webpage.h"

using namespace std;

unordered_map<string, siteInfo> WordInSite;

class search
{
    vector<list<siteInfo>> keywords;
};

#endif /*SEARCH_H*/