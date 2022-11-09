using namespace std;
#include "HashMap.h"
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <math.h>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm>


class Texto{
private:
    string texto;
    int TamanioTexto;

public:

    Texto();
    Texto (string, int);
    string getTexto();
    void setTexto(string);
    int getTamanioTexto();
    void setTamanioTexto(int);
    void contarLetrasPalabrasEspacios(string,HashMap<string,int>);
    void ordenAlfabetico(HashMap<string,int>, int);
    


    
    void bubbleAlfabetico (string);
    

};

unsigned int miHashFunc(string clave);
void quicksort(HashEntry<string, int> *cadena, int limite_izq, int limite_der);