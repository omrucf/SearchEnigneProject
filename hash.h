#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#include "webpage.h"

using namespace std;

extern string getTillChar(string &, char);

struct node
{
    string key;
    siteInfo value;
    node* next;
};

class hashtable
{
private:
    int NOE;
    vector<node *> table;
    vector<string> KeyWords;
    int hash(string);
public:
    hashtable();

    void insert(string, siteInfo);

    int getHash(string);

    bool contains(vector<string>, string);

    vector<string> KW();

};

#endif /*HASH_H*/