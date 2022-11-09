#ifndef U05_HASH_HASHMAP_HASHENTRY_H_
#define U05_HASH_HASHMAP_HASHENTRY_H_

template <class K, class T> 
class HashEntry {
  protected:
    K clave;
    T valor;

  public:

    HashEntry(K clave, T valor){
        this->clave = clave;
        this->valor = valor;
    }

    K getClave(){
        return clave;
    }

    void setClave(K clave){
        this->clave = clave;
    }

    T getValor(){
        return valor;
    }

    void setValor(T valor){
        this->valor = valor;
    }
};

#endif // U05_HASH_HASHMAP_HASHENTRY_H_
