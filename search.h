#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <set>

#include "hash.h"
#include "screen.h"

using namespace std;



extern string getTillChar(string &, char);
extern vector<siteInfo> WebPages;

class Search
{
    vector<node *> table;
public:
    Search();

    void OneWordSearch(string);
    void ANDSearch(string);
    void ORSearch(string);


};

#endif /*SEARCH_H*/