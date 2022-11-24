#include "hash.h"

int hashtable::hash(string key)
{
    int sum = 0;
    for (int i = 0; i < key.length(); i++)
        sum += (key[i] * i);

    return sum;
}

hashtable::hashtable()
{
    KeyWords = KW();

    table.resize(KeyWords.size());

    for (int i = 0; i < table.size(); i++)
    {
        node *temp = new node;
        temp->key = hash(KeyWords[i]);
        temp->next = NULL;
        table[i] = temp;
    }

    for (auto i = KeyWords.begin(); i != KeyWords.end(); i++)
    {
        string input;
        string temp;
        string url;

        ifstream in;

        in.open("keywords.csv");

        while (!in.eof())
        {
            getline(in >> ws, input);

            url = getTillChar(input, ','); // to disregard URLs

            if (input.find(*i) != string::npos)
                insert(*i, url);
        }
    }
        
        std::sort(table.begin(), table.end());

    for (int i = 0; i < table.size(); i++)
    {
        cout << "key: " << table[i]->key << ":\t";
        node *a = table[i]->next;

        while (a->next != NULL)
        {
            cout << a->value.url << " -> ";
            a = a->next;
        }
        cout << a->value.url;
        cout << endl;
    }
}
void hashtable::insert(string keyword, string website)
{
    node *input = new node;

    input->key = hash(keyword);
    input->value.url = website;

    int i = pos(input->key);

    if (i == -1)
    {
        cout << "keyword DNE\n";
    }
    else
    {
        node *a = table[i];

        while (a->next != NULL && a->value.url != input->value.url)
        {
            a = a->next;
        }

        if (a->value.url != input->value.url)
        {
            a->next = input;
            input->next = NULL;
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

        while (!input.empty())
        {
            temp = getTillChar(input, ',');

            if (!contains(keywords, temp))
                keywords.push_back(temp), cout << temp << endl;
        }
    }

    return keywords;
}

bool hashtable::contains(vector<string> v, string s)
{
    for (auto i = v.begin(); i != v.end(); i++)
        if (*i == s)
            return true;

    return false;
}

int hashtable::pos(int k)
{
    for (int i = 0; i < table.size(); i++)
        if (table[i]->key == k)
            return i;

    return -1;
}

int hashtable::getHash(string test)
{
    return hash(test);
}

vector<string> hashtable::getKeyWords()
{
    return KeyWords;
}


// bool hashtable::operator<(const node &a, const node &b)
// {
//     return a.key < b.key;
// }