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

    vector<string> output;

    char choice;
    char choicee;

    int i;

    std::cout << "Welcome!" << endl;

    do
    {
        if (choice != '1' && choice != '2')
        {
            std::cout << "\nPlease choose from the following:" << endl
                      << "1. New Search" << endl
                      << "2. Exit" << endl;

            cin >> choice;
        }

        clear();

        if (choice != '1' && choice != '2' && choice != '0')
            std::cout << "*INVALID INPUT*\n";
        else if (choice == '1')
        {
            std::cout << "\nSearch: ";

            getline(cin >> ws, keywords);

            if (keywords.find(emptyString) != string::npos ||
                (keywords.find("AND") != string::npos))
            {
                output = s.ANDSearch(keywords);
            }
            else if (keywords.find("OR") != string::npos)
            {
                output = s.ORSearch(keywords);
            }
            else if (keywords[0] == '"' && keywords[keywords.size() - 1] == '"')
            {
                output = s.ORSearch(keywords);
            }
            else
            {
                output = s.ORSearch(keywords);
            }

            do
            {
                choicee = 0;

                cout << "select any website you want by typing its number: " << endl;

                for (int j = 0; j < output.size(); j++)
                    cout << j + 1 << ". " << output[j] << endl;

                cout << "or type:\n(" << output.size() + 1 << ") New search\n(" << output.size() + 2 << ") Exit" << endl;

                cin >> i;

                if (i > 0 && i <= output.size())
                {
                    choicee = '0';
                    clear();
                    cout << "You are now viewing " << output[i - 1] << " !\n\n";

                    cout << "Would you like to :\n1. Back to search results\n2. New search\n3. Exit\n\n";

                    cin >> choicee;

                    if(choicee != 1)
                        choice = choicee - 1;

                    clear();
                }
                else if (i == output.size() + 1)
                    choice = '1';
                else if (i == output.size() + 2)
                    choice = '2';
                else
                    cout << "invlaid input!\nplease try again later!\n";
            } while (choicee == '1');
        }

    } while (choice != '2');

    clear();

    std::cout << "\nThank You for using our search engin!\nGoodBye!\n";
}

// sitevec screen::getAllSites()
// {
//     return allsites;
// }

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

    in.close();

    adjList.resize(edges.size());

    for (auto &edge : edges)
    {
        adjList[edge.src.loc].push_back(edge.dst);
    }
}

// void screen::printEdgesvec()
// {
//     cout << "\ngraph:\n";

//     for (int i = 0; i < edges.size(); i++)
//     {
//         if (!adjList[i].empty())
//         {
//             for (siteInfo v : adjList[i])
//             {
//                 cout << v.url << " --> ";
//             }
//             cout << "NULL" << endl;
//         }
//     }
// }