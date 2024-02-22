#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

int menuPrincipal()
{
    int opcion;
    system("cls");
    printf("                ***MENU PRINCIPAL***\n\n");
    printf("1.CARGAR ARCHIVO\n"
           "2.IMPRIMIR LISTA\n"
           "3.ASIGNAR ESTADISTICAS\n"
           "4.FILTRAR POR PAISES EXITOSOS\n"
           "5.FILTRAR POR PAISES EN EL HORNO\n"
           "6.ORDENAR POR NIVEL DE VACUNACION\n"
           "7.MOSTRAR MAS CASTIGADO\n"
           "8.SALIR\n");

    utn_getNumeroInt(&opcion,"Ingrese una opcion: ", "Error\n", 1, 8, 4);

    return opcion;
}
