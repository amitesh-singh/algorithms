#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cerr << argv[0] << " <file> <copiedfile>\n";
        return -1; 
    }

    string file(argv[1]), cfile(argv[2]);

    ifstream fin(file);
    if (!fin)
    {
        cerr << "Error in reading " << file << endl;
        return -2;
    }
    ofstream fout(cfile);
    string s;

    while(getline(fin, s))
    {
        fout << s << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}