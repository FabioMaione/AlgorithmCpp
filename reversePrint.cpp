#include <list>
#include <string>
#include <iostream>
using namespace std;

int main(){
    bool firstIt = true;
    string parola;
    list<string> elencoParole;
    cin >> parola;

    while (parola != "<END>"){
        elencoParole.push_front(parola);
        cin >> parola;
    }

    for (list<string>::iterator it = elencoParole.begin(); it != elencoParole.end(); it++){
        if (firstIt == true){
            cout << *it;
            firstIt = false;
        }
        else
            cout << endl
                 << *it;
    }
    return 0;
}