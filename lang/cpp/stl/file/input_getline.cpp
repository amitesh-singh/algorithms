#include <iostream>

using namespace std;

int main()
{
    char name[10];
    string age;
    cout << "To end the input, use $\n";
    cout << "Enter your name: ";
    //$ is the delimeter
    //Amitesh$Singh -> Amitesh 
    cin.getline(name, 10, '$');
    
    cout << "name entered is: " << name << endl;

    //using global getline()
    cout << "Enter your age, # to delimeter it: ";
    getline(cin, age, '#');

    cout << "Age entered is: " << age << endl;

    return 0;
}