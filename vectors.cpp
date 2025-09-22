// COMSC-210 | Lab 13 | Diksha Tara Natesan
// IDE used: Vim (Terminal)

#include <iostream>
#include <string>
#include <fstream>
#include <numeric>    // for accumulate()
#include <algorithm>  // for min_element, max_element
using namespace std;


//main() creates two STD::arrays and uses functions to output the first array and find lowest, highest, and total populations
//arguments: none
//return 0 when program is finished running
int main() {
    ifstream fin1("data.csv");

    array<string,50> arr;
    int count = 0;

    if (fin1.good( )) {
        string line;
        //output file header
        //getline(fin1, line);
        cout << line << endl;

        while (getline(fin1, line) && count < arr.size()) {
            arr[count] = line;
            count += 1;
        }
        fin1.close( ); // close the file
    }
    else
       cout << "File not found.\n";

    /* //output the file contents
    for (int i = 0; i<count; i++) {
        cout << arr.at(i) << endl;
    }
    */

    ifstream fin2("pop.txt");

    array<int,50> pop;
    int count1 = 0;

    if (fin2.good( )) {
        string line;
        //header

        while (getline(fin2, line) && count1 < pop.size()) {
            pop[count1] = stoi(line);
            count1 += 1;
        }
        fin2.close( ); // close the file
    }
    else
       cout << "File not found.\n";

    // find max & min & sum
    cout << "Highest State Population: " << *max_element(pop.begin(), pop.end()) << endl;
    cout << "Lowest State Population: " << *min_element(pop.begin(), pop.end()) << endl;
    cout << "Total USA Population: " << accumulate(pop.begin(), pop.end(), 0) << endl;

    return 0;
}
