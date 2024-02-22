#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = NULL;

	this = (LinkedList*) malloc(sizeof(LinkedList));// pedimemos memoria en dinamica
	// Que es un linkedlist? Lista enlazada.
	// linkedlist es una estructura
	if(this!=NULL)
	{
		this->size=0;// aca limpio los campos, me indica la cantidad de elementos que hay en el linkedlist
		this->pFirstNode=NULL;
	}

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this) // len es un geter del campo size
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=this->size;//me returnea el size
	}

    return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodo=NULL;

	if(this!=NULL && nodeIndex>=0 && nodeIndex < ll_len(this))// devuelve la direccion de memoria de un nodo
	{
		pNodo=this->pFirstNode;//apuntando al primer vagon

		while(nodeIndex>0)
		{
			pNodo=pNodo->pNextNode;// apunta al vagon que sigue
			nodeIndex--;// esto es para que a medida que avanzamos de vagon a vagon," descontamos" un vagon hasta
			// que lleguemos al que buscamos
		}

	}

    return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)//queda asi
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement) // recibe linkedlist,indice, y elemento "carga de nodo"
{
	int returnAux=-1;
	Node* newNode=NULL;
	//Node* nodoAnterior=NULL;
	if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
	{
		//crar nuevo nodo
		newNode=(Node*)malloc(sizeof(Node)); // construyo nuevo nodo/vagon

		if(newNode!=NULL)
		{

			newNode->pElement=pElement;//cargo el nuevo vagon con lo q quiero

			newNode->pNextNode=getNode(this, nodeIndex);// esto lo que hace es que mi nuevo nodo/vagon apunte al
			//vagon que esta en la posicion que quiero colocar el nuevo. Si yo quiero agregar un nodo en la posicion 3
			//necesito que mi nuevo nodo apunte a ese mismo nodo
			if(nodeIndex==0)
			{
				this->pFirstNode=newNode;
			}
			else
			{

				(getNode(this, nodeIndex - 1))->pNextNode=newNode;
			}
			this->size++;
			returnAux=0;
		}


	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)//NO SE TOCA
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)//Esta funcion la uso para poder agregar un elemento, se agrega al final
{
	int returnAux=-1;


	if(this!=NULL)
	{

		if(!addNode(this, ll_len(this), pElement))
		{
			returnAux=0;
		}
	}

    return returnAux;
}

/** \brief Retorna el elemento en el indice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void* returnAux=NULL;
	Node* pNode = getNode(this, index);

	if(pNode!=NULL)
	{
		returnAux=pNode->pElement;
	}


    return returnAux;
}


/** \brief Inserta un elemento en la lista en el indice especificado pisando al elemento que estaba en ese indice
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)//Piso el elemento en X posicion, con el elemento recibido por parametro
{
	int returnAux=-1;
	Node* pNode = getNode(this, index);

	if(pNode!=NULL)
	{
		pNode->pElement = pElement;
		returnAux=0;
	}


	return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)//  remueve un nodo/vagon, primero conectando los vagones de atras y delante
{
	int returnAux=-1;
	Node* auxNode=NULL;
	Node* prevNode;

	if(this!=NULL && index>=0 && index<ll_len(this))
	{
		auxNode= getNode(this, index);

		if(index==0)
		{
			this->pFirstNode = auxNode->pNextNode;
		}
		else
		{
			prevNode=getNode(this, index - 1);
			prevNode->pNextNode = auxNode->pNextNode;
		}
		free(auxNode);
		this->size--;
		returnAux=0;
	}

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)// elimina los elementos de la lista. Como? Va elmininando todos los que estan en la posicion 0, uno por uno
{
	int returnAux=-1;


	if(this!=NULL)
	{
		while(!ll_isEmpty(this))
		{
			ll_remove(this, 0);
		}
		returnAux=0;
	}

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)// usa ll clear, para eliminar todo lo de la lista. Y despues hace un free de la lista
{
	int returnAux=-1;
	if(this!=NULL)
	{
		ll_clear(this);
		free(this);
		returnAux=0;
	}
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int returnAux=-1;
	int size=ll_len(this);


	for(int i=0; i<size ;i++)
	{
		if(ll_get(this, i) == pElement)
		{
			returnAux=i;
			break;
		}
	}

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	int returnAux=-1;
	int size=ll_len(this);

	if(this!=NULL)
	{
		if(size==0)
		{
			returnAux=1;
		}
		else
		{
			if(size>0)
			{
				returnAux=0;
			}
		}
	}

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{

    return addNode(this, index, pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index) // me popea uno de la fila
{

	void* returnAux=ll_get(this, index);
	ll_remove(this, index);


    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int returnAux=-1;
	int index;

	if(this!=NULL)
	{
		index=ll_indexOf(this, pElement);
		returnAux=0;

		if(index>=0)
		{
			returnAux=1;
		}
	}

	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux=-1;
	int size;
	void* pElement=NULL;

	if(this!=NULL && this2!=NULL)
	{
		size=ll_len(this2);
		returnAux=1;
		for(int i=0; i<size; i++)
		{
			pElement=ll_get(this2, i);

			if(!ll_contains(this, pElement))
			{
				returnAux=0;
				break;
			}
		}
	}
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	LinkedList* cloneArray=NULL;
	void* pElement=NULL;


	if(this!=NULL && from>=0 && from <to && to<=ll_len(this))
	{
		cloneArray=ll_newLinkedList();
		if(cloneArray!=NULL)
		{
			for(int i=from;i<to;i++)
			{
				pElement=ll_get(this, i);
				ll_add(cloneArray, pElement);
			}
		}
	}
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    return ll_subList(this, 0, ll_len(this));
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	//hacer burbuje comunu y corriente y en el if el criterio pregunta pfunc donde de guarda puntero a funcion. v
    int returnAux=-1;
    int size;
    void* elementoi=NULL;
    void* elementoj=NULL;
    void* aux=NULL;

    if(this!=NULL && pFunc!=NULL && order>=0 && order<=1)
    {
    	size=ll_len(this);

    	for(int i=0; i<size-1; i++)
    	{
    		for(int j=i+1; j<size; j++)
    		{
    			elementoi=ll_get(this, i);
    			elementoj=ll_get(this, j);

    			if((pFunc(elementoi, elementoj)>0 && order==1) || (pFunc(elementoi, elementoj)<0 && order==0))
    			{
    				aux=elementoi;
    				ll_set(this, i, elementoj);
    				ll_set(this, j, aux);
    			}
    		}
    	}
    	returnAux=0;
    }

	return returnAux;

}


/// @brief Devuelve un nuevo linkedlist nuevo con los elementos que pasan la funcion filtro
///
/// @param this
/// @param pfunc
/// @return linkedList
LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void* ))
{
	LinkedList* listaAuxiliar=NULL;
	int tam;
	void* aux=NULL;

	if(this!=NULL && pFunc!=NULL)
	{
		listaAuxiliar=ll_newLinkedList();

		if(listaAuxiliar!=NULL)
		{
			tam=ll_len(this);

			for(int i=0; i<tam; i++)
			{
				aux=ll_get(this,i);
				if(pFunc(aux))
				{
					if(ll_add(listaAuxiliar, aux))
					{
						ll_deleteLinkedList(listaAuxiliar);
						listaAuxiliar=NULL;
						break;
					}
				}
			}
		}
	}
	return listaAuxiliar;
}

/// @brief Devuelve un nuevo linkedlist con elementos que pasen la funcion
///
/// @param this
/// @param pFunc
/// @return
LinkedList* ll_map (LinkedList* this, void*(*pFunc) (void*))
{
	LinkedList* listaMap = NULL;
	int tam;
	void* aux=NULL;
	if(this!=NULL && pFunc!=NULL)
	{
		listaMap=ll_newLinkedList();
		if(listaMap!=NULL)
		{
			tam=ll_len(this);
			for(int i=0;i<tam;i++)
			{
				aux=ll_get(this, i);
				if(aux!=NULL)
				{
					pFunc(aux);
					ll_add(listaMap, aux);
				}
			}
		}
	}
	return listaMap;
}
