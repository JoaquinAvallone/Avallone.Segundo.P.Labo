#ifndef VACUNADOS_H_INCLUDED
#define VACUNADOS_H_INCLUDED

typedef struct
{
    int id;
    char pais[100];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
}eVacunado;

#endif // VACUNADOS_H_INCLUDED

eVacunado* newVacunado();
eVacunado* newVacunadoString(char* id, char* pais, char*vac1, char* vac2, char* sinVac);

//Setters
int vacunadosSetId(eVacunado* this, int id);
int vacunadosSetPais(eVacunado* this, char* pais);
int vacunadosSetVac1(eVacunado* this, int vac1);
int vacunadosSetVac2(eVacunado* this, int vac2);
int vacunadosSetSinVac(eVacunado* this, int sinVac);
//Getters
int vacunadosGetId(eVacunado* this, int* id);
int vacunadosGetPais(eVacunado* this, char* pais);
int vacunadosGetVac1(eVacunado* this, int* vac1);
int vacunadosGetVac2(eVacunado* this, int* vac2);
int vacunadosGetSinVac(eVacunado* this, int* sinVac);
