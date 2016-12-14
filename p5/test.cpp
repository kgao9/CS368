#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

main()
{
    string test = "According to [Bjarne] Stroustrup: \"the name signifies the evolutionary";

    cout << test.substr(1,4) << endl;
}
