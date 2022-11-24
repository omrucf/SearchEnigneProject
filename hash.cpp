#include "hash.h"

int hashtable::hash(string key)
{
    int sum = 0;
    for(int i = 0; i < key.length(); i++)
        sum += (key[i] * i);

    temp.push_back(sum);
    return sum;
}


hashtable::hashtable()
{
    KeyWords = KW();

    table.resize(KeyWords.size());

    for (int i = 0; i < table.size(); i++)
        table[i] = NULL;
    NOE = 0;
}
void hashtable::insert(string SID,siteInfo name)
{
    int pos = hash(SID);
    node* input = new node;
    input->key = SID;
    input->value = name;
    if(table[pos] == NULL)
    {
        table[pos] = input;
        input->next = NULL;
        NOE++;
    }
    else
    {
        node* a = table[pos];
        while(a->next != NULL && a->key != SID)
        {
            a = a->next;
        }
        if(a->key!=SID)
        {
        a->next = input;
        input->next = NULL;
            NOE++;
        }
        else
        {
            cout << "ID EXISTS!!" << endl;
        }
    }
    
}

vector<string> hashtable::KW()
{
    string input;
    string temp;

    vector<string> keywords;

    ifstream in;

    in.open("keywords.csv");

    while (!in.eof())
    {
        getline(in >> ws, input);

        temp = getTillChar(input, ','); // to disregard URLs

        while(!input.empty())
        {
            temp = getTillChar(input, ',');

            if(!contains(keywords, temp))
                keywords.push_back(temp), cout << temp << endl;
        }
    }

    return keywords;
}


bool hashtable::contains(vector<string> v, string s)
{
    for(auto i = v.begin(); i != v.end(); i++)
        if (*i == s)
            return true;

    return false;
}

int hashtable::getHash(string test)
{
    return hash(test);
}