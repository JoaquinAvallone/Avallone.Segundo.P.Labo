#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "vacunados.h"
#include "menu.h"
#include "validaciones.h"
#include "LinkedList.h"
#include "controller.h"

int main()
{
    char respuesta = 's';
    char path[20];
    int flagVacunas = 0;
    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* listaPaisesExitosos = ll_newLinkedList();
    LinkedList* listaPaisesAlHorno = ll_newLinkedList();
    LinkedList* auxListaPaises = ll_newLinkedList();

    do{
        switch(menuPrincipal())
        {
        case 1:
            pedirPath(path);
            if(strcmp(path, "vacunas.csv") == 0)
            {
                if(controller_cargarVacunadosDesdeTexto(path, listaPaises))
                {
                    printf("El archivo se cargo con exito.\n");
                }
                else
                {
                    printf("Hubo un problema al cargar el archivo.\n");
                }
            }
            else
            {
                printf("El path ingresado es invalido. Recomendacion de path: vacunas.csv\n");
            }
            system("pause");
            break;
        case 2:
            if(ll_isEmpty(listaPaises))
            {
                printf("No hay paises para mostrar.\n");
            }
            else
            {
                controller_listarVacunados(listaPaises);
            }
            system("pause");
            break;
        case 3:
            if(ll_isEmpty(listaPaises))
            {
                printf("No hay paises en la lista. Ingrese al punto 1.\n");
            }
            else
            {
                if(asignarUnaDosis(listaPaises) && asignarDosDosis(listaPaises) && asignarNoVacunados(listaPaises))
                {
                    flagVacunas = 1;
                    controller_listarVacunados(listaPaises);
                }
                else
                {
                    printf("Hubo un problema al cargar las vacunas.\n");
                }
            }
            system("pause");
            break;
        case 4:
            if(ll_isEmpty(listaPaises))
            {
                printf("No hay paises en la lista. Ingrese al punto 1.\n");
            }
            else
            {
                if(!flagVacunas)
                {
                    printf("La lista no tiene asignada las vacunas. Ingrese al punto 3.\n");
                }
                else
                {

                    listaPaisesExitosos = ll_filter(listaPaises, filtrarExitosos);
                    controller_listarVacunados(listaPaisesExitosos);
                    printf("           Paises con mas del 30%% de la segunda dosis aplicada.\n\n");
                    controller_guardarVacunadosTexto("paisesExitosos.csv", listaPaisesExitosos);
                }
            }
            system("pause");
            break;
        case 5:
            if(ll_isEmpty(listaPaises))
            {
                printf("No hay paises en la lista. Ingrese al punto 1.\n");
            }
            else
            {
                if(!flagVacunas)
                {
                    printf("La lista no tiene asignada las vacunas. Ingrese al punto 3.\n");
                }
                else
                {

                    listaPaisesAlHorno = ll_filter(listaPaises, filtrarAlHorno);
                    controller_listarVacunados(listaPaisesAlHorno);
                    printf("          Paises con mayor porcentaje de no vacunados que de vacunados.\n\n");
                    controller_guardarVacunadosTexto("paisesAlHorno.csv", listaPaisesAlHorno);
                }
            }
            system("pause");
            break;
        case 6:
            if(ll_isEmpty(listaPaises))
            {
                printf("No hay paises en la lista. Ingrese al punto 1.\n");
            }
            else
            {
                if(!flagVacunas)
                {
                    printf("La lista no tiene asignada las vacunas. Ingrese al punto 3.\n");
                }
                else
                {
                    auxListaPaises = ll_clone(listaPaises);
                    ll_sort(auxListaPaises, ordenarVacunados, 1);
                    controller_listarVacunados(auxListaPaises);
                }
            }
            system("pause");
            break;
        case 7:
            if(ll_isEmpty(listaPaises))
            {
                printf("No hay paises en la lista. Ingrese al punto 1.\n");
            }
            else
            {
                if(!flagVacunas)
                {
                    printf("La lista no tiene asignada las vacunas. Ingrese al punto 3.\n");
                }
                else
                {
                    listaPaisesAlHorno = ll_filter(listaPaises, filtrarAlHorno);
                    masCastigados(listaPaisesAlHorno);
                }
            }
            system("pause");
            break;
        case 8:
            confirmaSalida(&respuesta,'n', 's');
            break;
        default:
            printf("La opcion elegida no existe.\n");
            system("pause");
            break;
        }
        system("cls");
    }while(respuesta == 's');



    return 0;
}
