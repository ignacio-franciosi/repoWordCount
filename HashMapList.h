#ifndef U05_HASH_HASHMAP_HASHMAPLIST_H_
#define U05_HASH_HASHMAP_HASHMAPLIST_H_

#include "HashEntry.h"
#include "lista.h"

using namespace std;

//Tabla hash con manejo de colisiones usando listas enlazadas
template<class K, class T>
class HashMapList {
private:
    Lista<HashEntry<K, T>> **tabla;

    unsigned int tamanio;

    static unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

public:
    explicit HashMapList(unsigned int k);

    HashMapList(unsigned int k, unsigned int (*hashFuncP)(K clave));

    void getList(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    ~HashMapList();

    bool esVacio();


};

/**
 * Constructor
 * @tparam K Key
 * @tparam T Dato
 * @param k tamaño
 */
template<class K, class T>
HashMapList<K, T>::HashMapList(unsigned int k) {
    tamanio = k;
    tabla = new Lista<HashEntry<K, T>> *[tamanio];
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = NULL;
    }
    hashFuncP = hashFunc;
}

/**
 * Constructor
 * @tparam K
 * @tparam T
 * @param k
 * @param fp function Pointer
 */
template<class K, class T>
HashMapList<K, T>::HashMapList(unsigned int k, unsigned int (*fp)(K)) {
    tamanio = k;
    tabla = new Lista<HashEntry<K, T>> *[tamanio];
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = NULL;
    }
    hashFuncP = fp;
}

/**
 * Destructor
 * @tparam K key
 * @tparam T valoe
 */
template<class K, class T>
HashMapList<K, T>::~HashMapList() {
    for (int i = 0; i < tamanio; i++) {
        if (tabla[i] != NULL) {
            delete tabla[i];
        }
    }
}

/**
 * Ingresa un dato en el Hash
 * @tparam K Key
 * @tparam T Dato
 * @param clave
 * @param valor
 */
template<class K, class T>
void HashMapList<K, T>::put(K clave, T valor) {
    unsigned int pos = hashFuncP(clave) % tamanio;

    if (tabla[pos] == NULL) {
        tabla[pos] = new Lista<HashEntry<K, T>>();
    }

    tabla[pos]->insertarUltimo(HashEntry<K, T>(clave, valor));
}

/**
 * Elimina una entrada del Hash
 * @tparam K Key
 * @tparam T Dato
 * @param clave
 */
template<class K, class T>
void HashMapList<K, T>::remove(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio;

    if (tabla[pos] == NULL) {
        throw 404;
    }

    T dato; // = get(clave);

    tabla[pos]->remove({clave, dato});

    if (tabla[pos]->esVacio()) {
        delete tabla[pos];
        tabla[pos] = NULL;
    }
}

/**
 * Se fija si la posicion determinada está vacía
 * @tparam K key
 * @tparam T Dato
 * @return
 */
template<class K, class T>
bool HashMapList<K, T>::esVacio() {
    for (int i = 0; i < tamanio; i++) {
        if (tabla[i] != NULL) {
            return false;
        }
    }
    return true;
}

/**
 * Devuelve la clave del un determinado Hash
 * @tparam K key
 * @tparam T Dato
 * @param clave
 * @return
 */
template<class K, class T>
unsigned int HashMapList<K, T>::hashFunc(K clave) {
    return (unsigned int) clave;
}

/**
 * Devuelve la lista según la clave que recibe
 * @tparam K Key
 * @tparam T Dato
 * @param clave
 */
template<class K, class T>
void HashMapList<K, T>::getList(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio;
    int sumaValor=0;
    if (tabla[pos] == NULL) {
        throw 404;
    }

    Nodo<HashEntry<K, T>> *aux = tabla[pos]->getInicio();

    while (aux != NULL) {
         sumaValor += aux->getDato().getValor();
        aux = aux->getSiguiente();
    }

    cout<<"Cantidad de Colisiones: "<<sumaValor<<endl;
}

#endif // U05_HASH_HASHMAP_HASHMAPLIST_H_