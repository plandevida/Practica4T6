/**
  @file Pila.h

  Implementaci�n del TAD Pila utilizando un
  array est�tico.

  Estructura de Datos y Algoritmos
  Facultad de Inform�tica
  Universidad Complutense de Madrid

 (c) Antonio S�nchez Ruiz-Granados, 2013
*/
#ifndef __PILAE_H
#define __PILAE_H

#include "Excepciones.h"

/**
 Implementaci�n del TAD Pila utilizando un array est�tico.

 Las operaciones son:

 - PilaVacia: -> Pila. Generadora implementada en el
   constructor sin par�metros.
 - apila: Pila, Elem -> Pila. Generadora parcial.
 - desapila: Pila - -> Pila. Modificadora parcial.
 - cima: Pila - -> Elem. Observadora parcial.
 - esVacia: Pila -> Bool. Observadora.
 - numElems: Pila -> Entero. Observadora.

 @author Antonio S�nchez Ruiz-Granados
 */
template <class T>
class PilaE {
public:
	/** N�mero m�ximo de elementos. */
	static const int TAM_MAX = 100;

	/** Constructor; operaci�n PilaVacia */
	PilaE() : _numElems(0) {	}

	/** Destructor. */
	~PilaE() { }

	/**
	 Apila un elemento. Operaci�n generadora parcial.

	 @param elem Elemento a apilar.
	 error: apila(p) cuando numElems(p) == TAM_MAX
	*/
	void apila(const T &elem) {
		if (_numElems == TAM_MAX)
			throw EPilaLlena();
		
		_v[_numElems] = elem;
		_numElems++;
	}
	
	/**
	 Desapila un elemento. Operaci�n modificadora parcial,
	 que falla si la pila est� vac�a.

	 desapila(Apila(elem, p)) = p
	 error: desapila(PilaVacia)
	*/
	void desapila() {
		if (esVacia())
			throw EPilaVacia();
		_numElems--;
	}

	/**
	 Devuelve el elemento en la cima de la pila. Operaci�n
	 observadora parcial, que falla si la pila est� vac�a.

	 cima(Apila(elem, p) = elem
	 error: cima(PilaVacia)

	 @return Elemento en la cima de la pila.
	 */
	const T &cima() const {
		if (esVacia())
			throw EPilaVacia();
		return _v[_numElems-1];
	}

	/**
	 Devuelve true si la pila no tiene ning�n elemento.

	 esVacia(PilaVacia) = true
	 esVacia(Apila(elem, p)) = false

	 @return true si la pila no tiene ning�n elemento.
	 */
	bool esVacia() const {
		return _numElems == 0;
	}

	/**
	 Devuelve el n�mero de elementos que hay en la
	 pila.
	 numElems(PilaVacia) = 0
	 numElems(Apila(elem, p)) = 1 + numElems(p)

	 @return N�mero de elementos.
	 */
	int numElems() const {
		return _numElems;
	}

	// //
	// M�TODOS DE "FONTANER�A" DE C++ QUE HACEN VERS�TIL
	// A LA CLASE
	// //

	/** Constructor copia */
	PilaE(const PilaE<T> &other) {
		copia(other);
	}

	/** Operador de asignaci�n */
	PilaE<T> &operator=(const PilaE<T> &other) {
		if (this != &other) 
			copia(other);
		
		return *this;
	}

	/** Operador de comparaci�n. */
	bool operator==(const PilaE<T> &rhs) const {
		if (_numElems != rhs._numElems)
			return false;
		
		for (unsigned int i = 0; i < _numElems; ++i)
			if (_v[i] != rhs._v[i])
				return false;
		
		return true;
	}

	bool operator!=(const PilaE<T> &rhs) const {
		return !(*this == rhs);
	}

protected:

	void copia(const PilaE<T> &other) {
		_numElems = other._numElems;
		for (unsigned int i = 0; i < _numElems; ++i)
			_v[i] = other._v[i];
	}

private:

	/** Array de elementos. */
	T _v[TAM_MAX];

	/** N�mero de elementos almacenados en la pila. */
	unsigned int _numElems;
};

#endif // __PILAE_H
