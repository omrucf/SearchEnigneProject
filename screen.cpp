#include "screen.h"

screen::screen()
{
    emptyString = "   ";
    emptyString[0] = '"';
    emptyString[1] = ' ';
    emptyString[2] = '"';
}

void screen::readSites()
{
    ifstream in;

    in.open("sites.txt");

    siteInfo sites;

    while (!in.eof())
    {
        in >> sites.loc >> sites.url;
        getline(in, sites.KeyWords);

        allsites.push_back(sites);
    }

    in.close();
}

void screen::printAllSites()
{
    readSites();

    for (int i = 0; i < allsites.size(); i++)
    {
        std::cout << "site: " << allsites.at(i).loc << endl
                  << "url: " << allsites.at(i).url << endl
                  << "keywords: " << allsites.at(i).KeyWords << endl
                  << endl;
    }
}

void screen::startingScreen()
{
    string keywords;

    char choice;

    std::cout << "Welcome!" << endl;

    do
    {
        std::cout << "\nPlease choose from the following:" << endl
                  << "1. New Search" << endl
                  << "2. Exit" << endl;

        cin >> choice;

        clear();

        if (choice != '1' && choice != '2' && choice != '0')
            std::cout << "*INVALID INPUT*\n";
        else if (choice == '1')
        {
            std::cout << "\nSearch: ";

            getline(cin >> ws, keywords);

            // cin >> keywords;

            std::cout << "\nsearch type: ";
            if (keywords.find(emptyString) != string::npos
             ||
              (keywords.find("AND") != string::npos))
            {
                std::cout << "AND\n";
            }
            else if (keywords.find("OR") != string::npos)
            {
                std::cout << "OR\n";
            }
            else if (keywords[0] == '"' && keywords[keywords.size() - 1] == '"')
            {
                std::cout << "quotations\n";
            }
            else
            {
                std::cout << "OR\n";
            }
            choice = '0';
        }

    } while (choice != '2');

    std::cout << "\nThank You for chosing our search engin!\nGoodBye!\n";
}

sitevec screen::getAllSites()
{
    return allsites;
}

void screen::createWebGraph()
{
    ifstream in;

    in.open("webgraph.csv");

    string mainURL, secondaryURL;

    string input;

    int count = 0;

    edge temp;

    while (!in.eof())
    {
        getline(in >> ws, input);

        mainURL = getTillChar(input, ',');

        temp.src.url = mainURL;

        while (!input.empty())
        {
            secondaryURL = getTillChar(input, ',');
            temp.dst.url = secondaryURL;

            edges.push_back(temp);
        }
    }
}

string screen::getTillChar(string &word, char c)
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

void screen::printEdgesvec()
{
    for (auto i = edges.begin(); i != edges.end(); i++)
    {
        cout << "source: " << i->src.url << endl
             << "destination: " << i->dst.url << endl << endl;
    }
}