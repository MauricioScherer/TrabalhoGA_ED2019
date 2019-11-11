#pragma once
#include "Lista.h"
template<class T>
class Pilha : public Lista<T>
{
public:
	Pilha() {};
	~Pilha() {};
	void empilhar(T * elemento);
	T * desempilhar();
	T * topo();
	void esvaziaPilha();
	int obtemTamanhoPilha();
};
template<class T>
void Pilha<T>::empilhar(T * elemento) {
	Lista<T>::insereFimLista(elemento);
}

template<class T>
T * Pilha<T>::desempilhar() {
	return Lista<T>::removeUltimoNo();
}

template<class T>
T * Pilha<T>::topo() {
	return Lista<T>::obterUltimoElemento();
}

template<class T>
inline void Pilha<T>::esvaziaPilha()
{
	Lista<T>::esvaziaLista();
}

template<class T>
inline int Pilha<T>::obtemTamanhoPilha()
{
	return Lista<T>::obtemTamanhoLista();
}

