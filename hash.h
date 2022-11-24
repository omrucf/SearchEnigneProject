#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <list>
#include <algorithm>

#include "webpage.h"

using namespace std;

extern string getTillChar(string &, char);

struct node
{
    int key;
    siteInfo value;
    node *next;

    bool operator<(const node &rhs) const
    {
        return key < rhs.key;
    }
};

class hashtable
{
private:
    vector<node *> table;
    vector<string> KeyWords;
    int hash(string);

public:
    hashtable();

    void insert(string, string);

    int getHash(string);
    int partition(vector<node *>, int, int);
    int pos(int);

    bool contains(vector<string>, string);
    // bool operator<(const node &, const node &);

    // hashtable operator<(const node &a, const node &b)
    // {
    //     return a.key < b.key;
    // }

    vector<string> KW();

    vector<string> getKeyWords();
};

#endif /*HASH_H*/