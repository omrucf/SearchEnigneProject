#include "screen.h"
#include "hash.h"
#include "search.h"

void clear();
string getTillChar(string &, char);

// vector<siteInfo> WebPages;

int main()
{
    cout << "everything's fine..\n\n";

    screen s;

    s.startingScreen();

    // s.createWebGraph();

    // s.printEdgesvec();

    // hashtable test;

    // Search s;

    // cout << endl;


    // string temp;

    // // // cout << "please search: ";
    // // // getline(cin >> ws, temp);

    // temp = "omar OR memes";

    // s.ORSearch(temp);


    return 0;
}

void clear()
{
    for(int i = 0; i < 100; i++)
        cout << endl;
}

string getTillChar(string &word, char c)
{
    string result = "";

    int i;

    for (i = 0; i < word.size() && word[i] != c; i++)
    {
        result += word[i];
    }
    if (i != word.size())
        word = word.substr(i + 1, word.size() - 1);
    else
    {
        result = word;
        word = "";
    }
    return result;
}