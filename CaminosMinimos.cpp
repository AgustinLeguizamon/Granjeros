/*
 * CaminosMinimos.cpp
 *
 *  Created on: Jun 24, 2018
 *      Author: agustin
 */


#include "CaminosMinimos.h"
//#include "HIIIIIP"


Lista<Arribo*>* CaminosMinimos::caminosMinimos(/*ojo que no es una lista, reemplazar por heap*/
		Lista<Arribo*>* heap, Lista<Viaje*>* listaDeAdyacencia){


	//busca en la lista de adyacencia, la lista de arribos de almacen
	Lista<Arribo*>* arribosAlmacen = buscarEnListaDeAdyacenciaPorNombre(listaDeAdyacencia, "ALMACEN");

	while (!heap->estaVacia()){

		/****METODO DEL HEAP****////
		Arribo* almacenAProvincia = heap->quitarRaiz();


		//busca en la lista de adyacencia, la lista de arribos de la provincia que fue removida
		Lista<Arribo*>* arribosProvincia = buscarEnListaDeAdyacencia(listaDeAdyacencia, almacenAProvincia);

		//recorre la lista de arribos de la provincia removida
		arribosProvincia->iniciarCursor();

		while(arribosProvincia->avanzarCursor()){

			/*obtiene el arribo actual de la lista de arribos*/
			Arribo* provinciaAProvincia = arribosProvincia->obtenerCursor();

			/*busca la distancia desde almacen hasta la provincia actual
			en la lista de arribos de Almacen*/
			Arribo* candidatoAlmacenAProvincia = buscarEnListaDeArribos(arribosAlmacen, provinciaAProvincia);

			if (elCosteDeLaSumaEsMenorAlCosteDirecto(almacenAProvincia,provinciaAProvincia, candidatoAlmacenAProvincia)){

				unsigned int* nuevoCosto = almacenAProvincia->obtenerCosto() + provinciaAProvincia->obtenerCosto();

				/****METODO DE LA CLASE ARRIBO ******/
				candidatoAlmacenAProvincia->modificarCosto(*nuevoCosto);

				/****METODO DEL HEAP******/
				heap->promover(candidatoAlmacenAProvincia);
				/**puede ser que la provincia ya no este en el heap, en este caso
				 * no pasa nada
				 */
			}

		}
	}

	Lista<Arribo*>* CopiaListaDeArribosDesdeAlmacen = copiarListaDeArribos(arribosAlmacen);

	return arribosAlmacen;

}



bool CaminosMinimos::elCosteDeLaSumaEsMenorAlCosteDirecto(Arribo* almacenAProvincia,
		Arribo*provinciaAProvincia, Arribo* candidatoAlmacenAProvincia){

	int sumaAlmacenAProvinciayProvinciaAProvincia = almacenAProvincia->obtenerCosto() + provinciaAProvincia->obtenerCosto();

	int costeCandidatoAlmacenAProvincia = candidatoAlmacenAProvincia->obtenerCosto();

	return (sumaAlmacenAProvinciayProvinciaAProvincia < costeCandidatoAlmacenAProvincia);

}



Lista<Arribo*>* CaminosMinimos::buscarEnListaDeAdyacencia(Lista<Viaje*>*
		listaDeAdyacencia, Arribo* unArribo){

	bool encontro=false;

	Lista<Arribo*>* arribos=NULL;

	listaDeAdyacencia->iniciarCursor();

	while(listaDeAdyacencia->avanzarCursor() && !encontro){

		Viaje* unViaje = listaDeAdyacencia->obtenerCursor();

		if(unViaje->obtenerSalidaDelViaje() == unArribo->obtenerArribo()){

			arribos = unViaje->obtenerArribos();
			encontro = true;

		}

	}

	return arribos;
}



Lista<Arribo*>* CaminosMinimos::buscarEnListaDeAdyacenciaPorNombre(Lista<Viaje*>* listaDeAdyacencia,
		std::string nombreProvincia){

	bool encontro=false;

	Lista<Arribo*>* arribos=NULL;

	listaDeAdyacencia->iniciarCursor();

	while(listaDeAdyacencia->avanzarCursor() && !encontro){

		Viaje* unViaje = listaDeAdyacencia->obtenerCursor();

		if(unViaje->obtenerSalidaDelViaje() == nombreProvincia){

			arribos = unViaje->obtenerArribos();
			encontro = true;

		}

	}

	return arribos;

}



Arribo* CaminosMinimos::buscarEnListaDeArribos(Lista<Arribo*>* listaDeArribos,
		Arribo* unArribo){

	bool encontro=false;


	Arribo* arribo=NULL;

	listaDeArribos->iniciarCursor();

	while(listaDeArribos->avanzarCursor() && !encontro){

		if(listaDeArribos->obtenerCursor()->obtenerArribo() == unArribo->obtenerArribo()){

			arribo = listaDeArribos->obtenerCursor();
			encontro = true;

		}

	}

	return arribo;

}


Lista<Arribo*>* CaminosMinimos::copiarListaDeArribos(Lista<Arribo*>* listaDeArribos){

	Lista<Arribo*>* copiaListaAlmacen = new Lista<Arribo*>;

	copiaListaAlmacen->agregar(*listaDeArribos);

	return copiaListaAlmacen;

}

/*NOTA:son tres metodos de busqueda
 * la primera busca una lista de arribos en la lista de adyacencia
 * la segunda busca una lista de arribos en la lista de adyacencia por nombre string
 * la tercera busca un arribo en una lista de arribos*/
