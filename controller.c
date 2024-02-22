#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "controller.h"
#include "vacunados.h"
#include "LinkedList.h"

int pedirPath(char* path)
{
    int retorno = 0;
    char auxPath[30];

    if(path != NULL)
    {
        system("cls");
        printf("         ***INGRESE PATH DEL ARCHIVO***\n\n");
        printf("Ingrese path(vacunas.csv): ");
        fflush(stdin);
        gets(auxPath);
        while(strlen(auxPath) <= 0 || strlen(auxPath) >= 20)
        {
            printf("Path demasiado largo/corto. Vuelva a ingresar path: ");
            fflush(stdin);
            gets(auxPath);
        }
        strcpy(path, auxPath);
        retorno = 1;
    }
    return retorno;
}

int parser_VacunadosFromText(FILE* pFile , LinkedList* pLista)
{
	int retorno = 0;
	char buffer[5][100];
	eVacunado* auxUser = NULL;

	if(pFile!=NULL && pLista!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
			auxUser = newVacunadoString(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

			if(auxUser != NULL)
			{
				ll_add(pLista, auxUser);
			}
		}
		retorno = 1;
	}
    return retorno;
}

/** \brief Carga los datos de los paises desde el archivo vacunas.csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int
 *
 */
int controller_cargarVacunadosDesdeTexto(char* path , LinkedList* pLista)
{
	int retorno=0;
	FILE* file = NULL;

	if(pLista!=NULL && path!=NULL)
	{
		file=fopen(path,"r");

		if(file!=NULL)
		{
			parser_VacunadosFromText(file, pLista);
			retorno=1;
		}
		fclose(file);
	}
    return retorno;
}


int controller_listarVacunado(eVacunado* unVacunado)
{
	int retorno = 0;
	int id;
	char pais[100];
	int vac1dosis;
	int vac2dosis;
	int sinVacunar;

	if(unVacunado!=NULL)
	{
		if(vacunadosGetId(unVacunado, &id) && vacunadosGetPais(unVacunado, pais) && vacunadosGetVac1(unVacunado, &vac1dosis) &&
		   vacunadosGetVac2(unVacunado, &vac2dosis) && vacunadosGetSinVac(unVacunado, &sinVacunar))
		{
			printf("| %-3d |  %-26s  |   %%%-5d |    %%%-5d   |    %%%-5d   |\n", id, pais, vac1dosis, vac2dosis, sinVacunar);
		}
	}


	return retorno;
}


int controller_listarVacunados(LinkedList* pLista)
{
	int retorno = 0;
	int largo = ll_len(pLista);

	if(pLista != NULL && largo > 0)
	{
		system("cls");
		printf( "=============================================================================\n"
				"|                            ***LISTA PAISES***                             |\n"
				"=============================================================================\n"
				"| ID  |            PAIS              | VAC1DOSIS|  VAC2DOSIS  | SINVACUNAR  |\n"
			    "-----------------------------------------------------------------------------\n");

		for(int i=0; i < largo; i++)
		{
			controller_listarVacunado((eVacunado*) ll_get(pLista, i));
		}
		printf( "=============================================================================\n");
		retorno=1;
	}
    return retorno;
}

int asignarUnaDosis(LinkedList* listaPaises)
{
	int retorno = 0;
	if(listaPaises!=NULL)
	{
		ll_map(listaPaises, asignarVacAleatorio);
		retorno = 1;
	}
	return retorno;
}

void* asignarVacAleatorio(void* elemento)
{
	int vac1Dosis;
	eVacunado* auxVacunado = NULL;

	if(elemento!=NULL)
	{
		auxVacunado = (eVacunado*)elemento;
		vac1Dosis= ((rand() % (60 - 1 + 1)));
		vacunadosSetVac1(auxVacunado, vac1Dosis);
	}

	return auxVacunado;
}

int asignarDosDosis(LinkedList* listaPaises)
{
	int retorno = 0;
	if(listaPaises!=NULL)
	{
		ll_map(listaPaises, asignarVac2Aleatorio);
		retorno = 1;
	}
	return retorno;
}

void* asignarVac2Aleatorio(void* elemento)
{
	int vac2Dosis;
	eVacunado* auxVacunado = NULL;

	if(elemento!=NULL)
	{
		auxVacunado = (eVacunado*)elemento;
		vac2Dosis= ((rand() % (40 - 1 + 1)));
		vacunadosSetVac2(auxVacunado, vac2Dosis);
	}

	return auxVacunado;
}

int asignarNoVacunados(LinkedList* listaPaises)
{
	int retorno = 0;
	if(listaPaises!=NULL)
	{
		ll_map(listaPaises, asignarNoVacAleatorio);
		retorno = 1;
	}
	return retorno;
}

void* asignarNoVacAleatorio(void* elemento)
{
	int noVacunados;
	eVacunado* auxVacunado = NULL;
	int dosis1;
	int dosis2;

	if(elemento!=NULL)
	{
		auxVacunado = (eVacunado*)elemento;
		vacunadosGetVac1(auxVacunado, &dosis1);
		vacunadosGetVac2(auxVacunado, &dosis2);
		noVacunados = 100 - (dosis1 + dosis2);
		vacunadosSetSinVac(auxVacunado, noVacunados);
	}

	return auxVacunado;
}

int filtrarExitosos(void* unVacunado)
{

	int retorno=0;
	eVacunado* auxVacunado;
	int segundaDosis;

	if(unVacunado!=NULL)
	{
		auxVacunado=(eVacunado*)unVacunado;
		vacunadosGetVac2(auxVacunado,&segundaDosis);

		if(segundaDosis > 30)
		{
			retorno=1;
		}
	}
return retorno;
}

int filtrarAlHorno(void* unVacunado)
{

	int retorno=0;
	eVacunado* auxVacunado = NULL;
	int noVacunado;
	int unaDosis;
	int dosDosis;
	int vacunados;

	if(unVacunado!=NULL)
	{
		auxVacunado=(eVacunado*)unVacunado;
		vacunadosGetSinVac(auxVacunado,&noVacunado);
		vacunadosGetVac1(auxVacunado, &unaDosis);
		vacunadosGetVac2(auxVacunado, &dosDosis);

        vacunados = unaDosis + dosDosis;
		if(noVacunado > vacunados)
		{
			retorno=1;
		}
	}
return retorno;
}


int controller_guardarVacunadosTexto(char* path , LinkedList* listaPaises)
{
	int retorno = 0;
	eVacunado* auxVacunado = NULL;
	int id;
	char pais[100];
	int vac1;
	int vac2;
	int sinVacunar;
	int tam;
	FILE* f=fopen(path,"w");

	tam=ll_len(listaPaises);

	if(path!=NULL && listaPaises!=NULL && f!=NULL)
	{
		fprintf(f,"id,pais,vac1dosis,vac2dosis,sinVacunar\n");

		for(int i=0;i<tam;i++)
		{
			auxVacunado=(eVacunado*)ll_get(listaPaises, i);
			vacunadosGetId(auxVacunado, &id);
			vacunadosGetPais(auxVacunado, pais);
			vacunadosGetVac1(auxVacunado, &vac1);
			vacunadosGetVac2(auxVacunado, &vac2);
			vacunadosGetSinVac(auxVacunado, &sinVacunar);
			fprintf(f,"%d,%s,%d,%d,%d\n",id,pais,vac1,vac2,sinVacunar);
			retorno = 1;
		}
	}
	fclose(f);

    return retorno;
}

int ordenarVacunados(void* paisI, void* paisJ)
{
    int returnAux=0;
    eVacunado* vacunadoIndiceI;
    eVacunado* vacunadoIndicej;
    int auxVacunadoI;
    int auxVacunadoJ;

    if(paisI != NULL && paisJ != NULL)
    {
    	vacunadoIndiceI = (eVacunado*)paisI;
    	vacunadoIndicej = (eVacunado*)paisJ;

    	vacunadosGetVac1(vacunadoIndiceI,&auxVacunadoI);
    	vacunadosGetVac1(vacunadoIndicej,&auxVacunadoJ);

        if(auxVacunadoI < auxVacunadoJ)
        {
            returnAux=1;
        }

    }
    return returnAux;
}

int ordenarNoVacunados(void* paisI, void* paisJ)
{

	int returnAux=0;
    eVacunado* noVacunadoIndiceI;
    eVacunado* noNacunadoIndicej;
    int auxNoVacunadoI;
    int auxNoVacunadoJ;

    if(paisI != NULL && paisJ != NULL)
    {
    	noVacunadoIndiceI = (eVacunado*)paisI;
    	noNacunadoIndicej = (eVacunado*)paisJ;

    	vacunadosGetSinVac(noVacunadoIndiceI,&auxNoVacunadoI);
    	vacunadosGetSinVac(noNacunadoIndicej,&auxNoVacunadoJ);

        if(auxNoVacunadoI < auxNoVacunadoJ)
        {
            returnAux=1;
        }

    }
    return returnAux;
}

int masCastigados(LinkedList* masCastigados)
{
	int retorno = 0;
	int tam;
	eVacunado* aux = NULL;
	int mayor;
	LinkedList* listaOrdenada = ll_newLinkedList();

	if(masCastigados != NULL && listaOrdenada != NULL)
	{
		system("cls");
		listaOrdenada = ll_clone(masCastigados);
		ll_sort(listaOrdenada, ordenarNoVacunados, 1);
		tam = ll_len(listaOrdenada);
		printf( "=============================================================================\n"
				"|                          ***PAIS MAS CASTIGADO***                         |\n"
				"=============================================================================\n"
				"| ID  |            PAIS              | VAC1DOSIS|  VAC2DOSIS  | SINVACUNAR  |\n"
				"-----------------------------------------------------------------------------\n");
        aux = (eVacunado*) ll_get(listaOrdenada, 0);
        vacunadosGetSinVac(aux, &mayor);
		for(int i=0; i<tam; i++)
		{
		    aux = (eVacunado*) ll_get(listaOrdenada, i);
		    if(aux->sinVacunar == mayor)
            {
                controller_listarVacunado(aux);
            }
		}
		printf("=============================================================================\n");
		retorno = 1;
	}

	return retorno;
}
