#ifndef ANDSEARCHSCREEN_H
#define ANDSEARCHSCREEN_H

#include <iostream>

#include "ReultsScreen.h"

extern void clear();

using namespace std;

class ANDSearch: public resultsScreen
{
public:
    ANDSearch(string[], string[]);
};

#endif /*ANDSEARCHSCREEN_H*/