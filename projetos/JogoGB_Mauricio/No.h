#pragma once
template <class T>
class No
{
public:
	No();
	~No();

	T* info; //informa��es do que ser� armazenado
	No<T> *proximo;
	No<T> *antrior;
};

template <class T>
No<T>::No()
{
	this->proximo = nullptr;
	this->anterior = nullptr;
}

template <class T>
No<T>::~No()
{
}

