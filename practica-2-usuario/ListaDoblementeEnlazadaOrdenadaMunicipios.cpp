/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author  Miguel Ángel Ramírez Ruiz
	\date  
	\version 1.0
*/

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "NodoMunicipioInterfaz.hpp"
#include "Municipio.hpp"

// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE ListaDoblementeEnlazadaOrdenadaMunicipios

bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::find(ed::Municipio const & item)
{
	bool retval;
	if (this->isEmpty() == true)
	{
		return false;
	}
	gotoHead();

	while(getCurrent()->getNext() != NULL || isLastItem() == true)
	{
		if (item == getCurrentItem())
		{
			retval = true;
			#ifndef NDEBUG
				// Se comprueba la postcondición
				assert(this->getCurrentItem() == item);
			#endif //NDEBUG
			return retval;
		}

		if (item < getCurrentItem())
		{
			retval = false;
			#ifndef NDEBUG
				// Se comprueba la postcondición
				assert(item < this->getCurrentItem());
			#endif //NDEBUG
			return retval;
		}

		if (isLastItem() == true)
		{
			break;
		}

		gotoNext();
	}

	#ifndef NDEBUG
		// Se comprueba la postcondición
		assert(this->isLastItem() == true);
	#endif //NDEBUG
	return false;
}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::insert(ed::Municipio item)
{
	#ifndef NDEBUG
		// Se comprueba la precondición
		assert(this->find(item) == false);
	#endif //NDEBUG

	int oldnItems = nItems();
	ed::NodoDoblementeEnlazadoMunicipio* newnodo = new ed::NodoDoblementeEnlazadoMunicipio(item, NULL, NULL);

	if (this->isEmpty() == true)
	{
		setHead(newnodo);
	}
	else
	{
		find(item);

		if (isFirstItem() == true && item < getCurrentItem())
		{
			newnodo->setNext(getCurrent());
			getCurrent()->setPrevious(newnodo);
			setHead(newnodo);
		}
		else if(isLastItem() == true && getCurrentItem() < item)
		{
			newnodo->setPrevious(getCurrent());
			getCurrent()->setNext(newnodo);
		}
		else
		{
			newnodo->setPrevious(getCurrent()->getPrevious());
			getCurrent()->setPrevious(newnodo);
			newnodo->setNext(getCurrent());
			newnodo->getPrevious()->setNext(newnodo);
		}
	}
	setCurrent(newnodo);
	#ifndef NDEBUG
		// Se comprueba la postcondición
		assert(getCurrentItem() == item and nItems() == oldnItems + 1);
	#endif //NDEBUG
}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::remove(){
	#ifndef NDEBUG
		// Se comprueba la precondición
		assert(this->isEmpty() == false);
	#endif //NDEBUG
	ed::NodoDoblementeEnlazadoMunicipio* oldprevious = NULL;
	ed::NodoDoblementeEnlazadoMunicipio* oldnext = NULL;
	ed::NodoDoblementeEnlazadoMunicipio* nodo = getCurrent();


	if (nItems() == 1)
	{
		delete(nodo);
		_head = NULL;
		_current = NULL;
	}
	else if (this->isLastItem() == true)
	{
		oldprevious = this->getCurrent()->getPrevious();
		this->getCurrent()->getPrevious()->setNext(NULL);
		delete(nodo);
		this->setCurrent(oldprevious);
		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->isEmpty() == true or (oldprevious->getItem() == this->getCurrentItem() and this->isLastItem() == true));
		#endif //NDEBUG
	}
	else if(this->isFirstItem() == true)
	{
		oldnext = this->getCurrent()->getNext();
		this->getCurrent()->getNext()->setPrevious(NULL);
		delete(nodo);
		this->setCurrent(oldnext);
		this->setHead(oldnext);
		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->isEmpty() == true or (oldnext->getItem() == this->getCurrentItem() and this->isFirstItem() == true));
		#endif //NDEBUG
	}
	else{
		oldprevious = this->getCurrent()->getPrevious();
		oldnext = this->getCurrent()->getNext();
		this->setCurrent(oldnext);
		oldprevious->setNext(getCurrent());
		getCurrent()->setPrevious(oldprevious);
		delete(nodo);
		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(oldprevious->getItem() == this->getPreviousItem() and oldnext->getItem() == this->getCurrentItem());
		#endif //NDEBUG
	}
}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::removeAll(){
	while(this->nItems() > 0)
	{
		this->remove();
	}
	#ifndef NDEBUG
		// Se comprueba la postcondición
		assert(this->isEmpty() == true);
	#endif //NDEBUG
}