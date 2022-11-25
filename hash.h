#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <list>
#include <algorithm>

#include "screen.h"

using namespace std;

extern string getTillChar(string &, char);

struct node
{
    int key;
    siteInfo value;
    node *next;

public:
    bool operator<(const node *&a)
    {
        return key < a->key;
    }
    bool operator>(const node *&a)
    {
        return key > a->key;
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

    vector<string> KW();

    vector<string> getKeyWords();

    vector<node *> getTable();
};

#endif /*HASH_H*/