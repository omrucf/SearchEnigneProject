#ifndef RESULTSSCREEN_H
#define RESULTSSCREEN_H

#include <iostream>

using namespace std;

class resultsScreen
{
protected:
    int numOfSites;
    string *keywords;
    string *websites;

public:
    resultsScreen(string[], string[]);
};

#endif /*RESULTSSCREEN_H*/