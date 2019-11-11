#pragma once
#include "No.h"
template <class T>
class Lista
{
public:
	Lista();
	~Lista();
	int obtemTamanhoLista();
	bool listaVazia();//true = vazia; false = não vazia
	void insereFimLista(T * elemento);
	void insereInicioLista(T * elemento);
	int insereEm(int posicao, T * elemento); //1 - Sucesso; 0 - Erro
	T * removeUltimoNo();
	T * removePrimeiroNo();
	//T * removeElemento(T * elemento);
	void esvaziaLista();
	bool contemNaLista(const T* elemento, No<T> * param_lista = lista);
	T * obterUltimoElemento();
	T * obterPrimeiroElemento();
	T * obterElementoEm(int posicao);

private:
	void percorreLista(No<T> * lista);
protected:
	No<T> * lista, *lista_aux, *fim_lista;
	int tam;
};


template <class T>
Lista<T>::Lista()
{
	this->tam = 0;
	this->lista = nullptr;
	this->lista_aux = nullptr;
	this->fim_lista = nullptr;
}
template <class T>
Lista<T>::~Lista()
{
}
template <class T>
int Lista<T>::obtemTamanhoLista()
{
	return this->tam;
}
template <class T>
bool Lista<T>::listaVazia()
{
	if (this->lista == nullptr)
		return true;
	else
		return false;
}
template <class T>
void Lista<T>::percorreLista(No<T> * lista)
{
	if (lista != nullptr) {
		lista_aux = lista;
		percorreLista(lista->proximo);
	}
}
template <class T>
void Lista<T>::insereFimLista(T * elemento)
{
	No<T> * no = new No<T>;
	no->info = elemento;
	if (listaVazia()) { //se é vazia
		this->lista = no;//insere o primeiro elemento
		this->fim_lista = no;
		this->tam++;
	}
	else {
		this->fim_lista->proximo = no; //atribui novo nó
		no->anterior = this->fim_lista;
		this->fim_lista = no;
		this->tam++;
	}
}

template<class T>
void Lista<T>::insereInicioLista(T * elemento)
{
	No<T> * no = new No<T>;
	no->info = elemento;
	if (!listaVazia()) {
		lista->anterior = no;
		no->proximo = lista;
		no->anterior = nullptr;
		this->lista = no;
		tam++;
	}
	else {
		lista = no;
		fim_lista = no;
		tam++;
	}
}
template <class T>
int Lista<T>::insereEm(int posicao, T * elemento)
{

	//declarar o índice
	int i = 0;

	//inicializa o ponteiro para percorrer a lista
	this->lista_aux = this->lista;
	if (posicao <= (this->tam - 1)) {
		while (i <= posicao) {
			if (i == posicao) {//atualiza o nó
				if (listaVazia()) {
					insereFimLista(elemento);
				}
				else {
					if (posicao == 0) {
						insereInicioLista(elemento);
					}
					else {
						No<T> * no = new No<T>;
						no->info = elemento;
						no->proximo = this->lista_aux;
						no->anterior = this->lista_aux->anterior;
						this->lista_aux->anterior->proximo = no;
						this->lista_aux->anterior = no;
					}
				}
				this->tam++;
			}
			this->lista_aux = this->lista_aux->proximo;
			i++;
		}
		return 1;
	}
	else {
		return 0;
	}
}

template <class T>
void Lista<T>::esvaziaLista()
{
	if (this->lista != nullptr) {
		this->lista_aux = this->lista;
		while (this->lista_aux != nullptr) {
			//primeiro passo: atualizar lista_aux para o próximo nó
			this->lista_aux = this->lista->proximo;
			//segundo passo: deletar o nó
			delete this->lista;
			this->tam--;
			//terceiro passo: atualizar a lista para o próximo nó
			this->lista = this->lista_aux;
		}
	}
}

template<class T>
bool Lista<T>::contemNaLista(const T* elemento, No<T> * param_lista)
{
	//recebe o nó
	//percorre a lista até encontrar o nó
	//pra cada nó comparar a info que contém o tipo T, ou a informação desejada

	if (param_lista != nullptr) {
		//lista_aux = lista;
		if (param_lista->info == elemento)
			return true;
		else
			return contemNaLista(elemento, param_lista->proximo);
	}
	return false;

}

template<class T>
inline T * Lista<T>::obterUltimoElemento()
{
	return this->fim_lista->info;
}

template<class T>
inline T * Lista<T>::obterPrimeiroElemento()
{
	return this->lista->info;
}

template<class T>
inline T * Lista<T>::obterElementoEm(int posicao)
{
	if (posicao >= this->tam || posicao < 0)
		return nullptr;
	T * e = nullptr;
	//declarar o índice
	int i = 0;
	//inicializa o ponteiro para percorrer a lista
	this->lista_aux = this->lista;
	if (posicao <= (this->tam - 1)) {
		while (i <= posicao) {
			if (i == posicao) {//atualiza o nó
				e = this->lista_aux->info;
				return e;
			}
			this->lista_aux = this->lista_aux->proximo;
			i++;
		}

	}
	return e;
}

template <class T>
T *  Lista<T>::removeUltimoNo() {
	T * e = nullptr;
	if (!listaVazia()) {
		if (this->tam == 1)
		{
			e = this->lista->info;
			delete this->lista;
			this->lista = nullptr;
			this->fim_lista = nullptr;
		}
		else {
			this->lista_aux = this->fim_lista;
			this->fim_lista = this->fim_lista->anterior;
			this->fim_lista->proximo = nullptr;
			e = this->lista_aux->info;
			delete this->lista_aux;
		}
		this->tam--;
	}
	return e;
}

template<class T>
T * Lista<T>::removePrimeiroNo()
{
	T * e = nullptr;
	if (!listaVazia()) {
		if (this->tam == 1)
		{
			e = this->lista->info;
			delete this->lista;
			this->lista = nullptr;
			this->fim_lista = nullptr;
			this->tam--;
		}
		else {
			lista_aux = lista;
			lista = lista->proximo;
			e = lista_aux->info;
			delete lista_aux;
			this->tam--;
		}
	}
	return e;
}