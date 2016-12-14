#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h> 

using namespace std;

int instancesInLine(string word, string line)
{
    //if the line is smaller than the word, we return 0
    if(line.length() < word.length())
    {
        return 0;
    }

    else
    {
        //line is bigger than word
        int startIndex = 0;
        int endIndex = word.length();
        int finds = 0;

        //continue until endIndex is at end of line
        while(endIndex != line.length())
        {
            string sub = line.substr(startIndex, word.length());

            //cout << sub << endl;

            if(strcmp(sub.c_str(), word.c_str()) == 0)
            {
                //cout << sub << endl;
                //cout << word << endl;
                //cout << strcmp(sub.c_str(), word.c_str()) << endl;
                finds++;
            }

            startIndex++;
            endIndex++;
        }

        //cout << finds << endl;
     
        return finds;
    }

}

main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cout << "Proper usage: findWord <word> <file>" << endl;
        cout << "where" << endl;
        cout << "    <word> is a sequence of non-whitespace characters" << endl;
        cout << "    <file> is the file in which to search for the word" << endl;
        cout << "example: findWord the test.txt" << endl;
    }

    else
    {
        string word = argv[1];
        string text = argv[2];

        ifstream inFile;
        inFile.open(text.c_str());

        if(inFile.fail())
        {
             cerr << "File " << '\'' << text << '\'' << " was not found" << endl;
             exit(1);
        }

        //tell user searching for word
        cout << "Searching for \'" << word << "\' in file \'" << text << "\'\n";

        string line;
        int numLines = 0;
        int numFinds = 0;

        while(!inFile.eof())
        {
            getline(inFile, line);

            //cout << line << endl;

            int numOccurences = instancesInLine(word, line);
            numFinds += numOccurences;

            if(numOccurences != 0)
            {
                  numLines++;
                  cout << numLines << " : " << line << endl;
            }

            else
            {
                numLines++;
                continue;
            }

        }

        cout << "# occurences of \'" << word << "\' = " << numFinds << endl;
        

        return 0;

    }
}
