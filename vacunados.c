#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "vacunados.h"

eVacunado* newVacunado()
{
    eVacunado* v = (eVacunado*) malloc(sizeof(eVacunado));

    if(v != NULL)
    {
        v->id = 0;
        strcpy(v->pais, "");
        v->vac1dosis = 0;
        v->vac2dosis = 0;
        v->sinVacunar = 0;
    }

    return v;
}
eVacunado* newVacunadoString(char* id, char* pais, char*vac1, char* vac2, char* sinVac)
{
    eVacunado* v = newVacunado();

    if(v != NULL)
    {
        if(!(vacunadosSetId(v,atoi(id)) && vacunadosSetPais(v, pais) && vacunadosSetVac1(v, atoi(vac1)) && vacunadosSetVac2(v, atoi(vac2)) && vacunadosSetSinVac(v, atoi(sinVac))))
        {
            free(v);
            v = NULL;
        }
    }
    return v;
}

//Setters
int vacunadosSetId(eVacunado* this, int id)
{
    int retorno = 0;

    if(this != NULL && id >= 1)
    {
        this->id = id;
        retorno = 1;
    }
    return retorno;
}

int vacunadosSetPais(eVacunado* this, char* pais)
{
    int retorno = 0;
    char auxCad[100];

    if(this != NULL && pais != NULL && strlen(pais) < 100)
    {
        strcpy(auxCad, pais);
        auxCad[0] = toupper(auxCad[0]);
        strcpy(this->pais, auxCad);
        retorno = 1;
    }
    return retorno;
}

int vacunadosSetVac1(eVacunado* this, int vac1)
{
    int retorno = 0;

    if(this != NULL && vac1 >= 0)
    {
        this->vac1dosis = vac1;
        retorno = 1;
    }
    return retorno;
}

int vacunadosSetVac2(eVacunado* this, int vac2)
{
    int retorno = 0;

    if(this != NULL && vac2 >= 0)
    {
        this->vac2dosis = vac2;
        retorno = 1;
    }
    return retorno;
}

int vacunadosSetSinVac(eVacunado* this, int sinVac)
{
    int retorno = 0;

    if(this != NULL && sinVac >= 0)
    {
        this->sinVacunar = sinVac;
        retorno = 1;
    }
    return retorno;
}
//Getters
int vacunadosGetId(eVacunado* this, int* id)
{
    int retorno = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}
int vacunadosGetPais(eVacunado* this, char* pais)
{
    int retorno = 0;

    if(this != NULL && pais != NULL)
    {
        strcpy(pais, this->pais);
        retorno = 1;
    }
    return retorno;
}

int vacunadosGetVac1(eVacunado* this, int* vac1)
{
    int retorno = 0;

    if(this != NULL && vac1 != NULL)
    {
        *vac1 = this->vac1dosis;
        retorno = 1;
    }
    return retorno;
}

int vacunadosGetVac2(eVacunado* this, int* vac2)
{
    int retorno = 0;

    if(this != NULL && vac2 != NULL)
    {
        *vac2 = this->vac2dosis;
        retorno = 1;
    }
    return retorno;
}

int vacunadosGetSinVac(eVacunado* this, int* sinVac)
{
    int retorno = 0;

    if(this != NULL && sinVac != NULL)
    {
        *sinVac = this->sinVacunar;
        retorno = 1;
    }
    return retorno;
}
