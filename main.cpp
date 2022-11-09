#include "HashMapList.h"
#include "funciones.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>


int main() {

HashMap<string,int> hashmap (100000,&miHashFunc);
Texto texto;

texto.contarLetrasPalabrasEspacios("archivoPrueba.txt",hashmap);


}

    