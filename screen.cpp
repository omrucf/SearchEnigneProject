#include "screen.h"

screen::screen()
{
    emptyString = "   ";
    emptyString[0] = '"';
    emptyString[1] = ' ';
    emptyString[2] = '"';
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

            std::cout << "\nsearch type: ";
            if (keywords.find(emptyString) != string::npos ||
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
        temp.src.loc = count++;

        adjList.resize(count);

        adjList[count - 1].push_back(temp.src);

        while (!input.empty())
        {
            secondaryURL = getTillChar(input, ',');
            temp.dst.url = secondaryURL;

            edges.push_back(temp);
        }
    }

    adjList.resize(edges.size());

    for (auto &edge : edges)
    {
        adjList[edge.src.loc].push_back(edge.dst);
    }
}

void screen::printEdgesvec()
{
    cout << "\ngraph:\n";

    for (int i = 0; i < edges.size(); i++)
    {
        if (!adjList[i].empty())
        {
            for (siteInfo v : adjList[i])
            {
                cout << v.url << " --> ";
            }
            cout << "NULL" << endl;
        }
    }
}