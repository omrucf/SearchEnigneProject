#include "screen.h"

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

void screen::readHistory()
{
    ifstream in;

    in.open("history.txt");

    siteInfo sites;

    while (!in.eof())
    {
        in >> sites.loc >> sites.url;
        getline(in, sites.KeyWords);
        history.push_back(sites);
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

        if (choice != '1' && choice != '2' && choice != '0')
            std::cout << "*INVALID INPUT*\n";
        else if (choice == '1')
        {
            std::cout << "Search: ";

            getline(cin >> ws, keywords);

            // cin >> keywords;

            std::cout << "\nsearch type: ";
            if (keywords[0] == '"' && keywords[keywords.size() - 1] == '"')
            {
                std::cout << "quotations\n";
            }
            else if (keywords.find("AND") != string::npos)
            {
                std::cout << "AND\n";
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