#include "search.h"

Search::Search()
{
    // hashtable test;

    // table = test.getTable();
}

// void Search::OneWordSearch(string word)
// {
//     for (int i = 0; i < word.length(); i++)
//         word[i] = toupper(word[i]);

//     int key = 0;
//     for (int i = 0; i < word.length(); i++)
//         key += (word[i] * (i + 1));

//     bool flag = false;

//     cout << "results for: " << word << " are:\n";
//     for (int i = 0; i < table.size(); i++)
//     {
//         if (table[i]->key == key)
//         {
//             flag = true;
//             node *a = table[i];

//             while (a != NULL)
//             {
//                 cout << a->value.url << endl;
//                 a = a->next;
//             }
//         }
//     }
//     if (!flag)
//         cout << "sorry, no results were found!!\n";
// }

vector<string> Search::ANDSearch(string input)
{
    string results(""), urls;
    vector<string> URLs;
    vector<string> KWs;
    vector<string> res;

    while (!input.empty())
    {
        string temp;
        
        do
            temp = getTillChar(input, ' ');
        while(temp == "AND");

        if (temp[0] == '"' && temp[temp.size() - 1] == '"')
            temp = temp.substr(1, temp.size() - 2);

        if(temp[0] == ' ')
            temp = temp.substr(1, temp.size() - 1);

            transform(temp.begin(),temp.end(),temp.begin(),::toupper);

            KWs.push_back(temp);
    }

    ifstream in;

    in.open("keywords.csv");

    while (!in.eof())
    {
        bool Flag(true);

        string keys;

        getline(in >> ws, keys);

        string URL = getTillChar(keys, ',');

        transform(keys.begin(),keys.end(),keys.begin(),::toupper);

        for (int i = 0; i < KWs.size(); i++)
        {
            if(keys.find(KWs[i]) == string::npos)
                Flag = false;
        }

        if(Flag)
            if(results.find(URL) == string::npos)
                results += URL + " ";
    }

    in.close();

    if (results.empty())
        cout << "no results found!!\n";
    else
        while (!results.empty())
            res.push_back(getTillChar(results, ' '));
    
    return res;
}

// void Search::ORSearch(string input)
// {
//     string results("");

//     while (!input.empty())
//     {
//         string temp = getTillChar(input, ' ');

//         if (temp[0] == '"' && temp[temp.size() - 1] == '"')
//             temp = temp.substr(1, temp.size() - 2);

//         for (int i = 0; i < temp.length(); i++)
//             temp[i] = toupper(temp[i]);

//         int key = 0;
//         for (int i = 0; i < temp.length(); i++)
//             key += (temp[i] * (i + 1));

//         for (int i = 0; i < table.size(); i++)
//         {
//             if (table[i]->key == key)
//             {
//                 node *a = table[i];

//                 while (a != NULL)
//                 {
//                     if (results.find(a->value.url) == string::npos)
//                         results += a->value.url + " ";
//                     a = a->next;
//                 }
//             }
//         }
//     }
//     if (results.empty())
//         cout << "no results found!!\n";
//     else
//         while (!results.empty())
//             cout << getTillChar(results, ' ') << endl;
// }


vector<string> Search::ORSearch(string input)
{
    string results(""), urls;
    vector<string> URLs;
    vector<string> KWs;
    vector<string> res;

    while (!input.empty())
    {
        string temp;
        
        do
            temp = getTillChar(input, ' ');
        while(temp == "OR");

        if (temp[0] == '"'&& temp[temp.size() - 1] == '"')
            temp = temp.substr(1, temp.size() - 2);
        if(temp[0] == ' ')
            temp = temp.substr(1, temp.size() - 1);

            transform(temp.begin(),temp.end(),temp.begin(),::toupper);

            KWs.push_back(temp);
    }

    ifstream in;

    in.open("keywords.csv");

    while (!in.eof())
    {
        bool Flag(false);

        string keys;

        getline(in >> ws, keys);

        string URL = getTillChar(keys, ',');

        transform(keys.begin(),keys.end(),keys.begin(),::toupper);

        for (int i = 0; i < KWs.size(); i++)
        {
            if(keys.find(KWs[i]) != string::npos)
                Flag = true;
        }

        if(Flag)
            if(results.find(URL) == string::npos)
                results += URL + " ";
    }

    in.close();

    if (results.empty())
        cout << "no results found!!\n";
    else
        while (!results.empty())
            res.push_back(getTillChar(results, ' '));

    return res;
}