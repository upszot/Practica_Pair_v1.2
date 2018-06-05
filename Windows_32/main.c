#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

#define NOMBRE_ARCHIVO_EMPLEADOS "data.csv"

#define PAGINADO 20


//int agregarEmpleado(ArrayList*);

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    ArrayList* arrayEmpleados = al_newArrayList();
    int Error;
    char seguir = 's';
    int opcion;
    int listaEmpleados;

    if(arrayEmpleados != NULL)
    {
        do
        {
            system("cls");
            menu("1. Parse del archivo data.csv\n"
                 "2. Listar Empleados\n"
                 "3. Ordenar por nombre\n"
                 "4. Agregar un elemento\n"
                 "5. Elimina un elemento\n"
                 "6. Listar Empleados (Desde/Hasta)\n\n"
                 );


            scanf("%d", &opcion);

            switch(opcion)
            {
                case 1:
                    Error = cargarDesdeArchivo(NOMBRE_ARCHIVO_EMPLEADOS, arrayEmpleados);
                    break;
                case 2:
                    listaEmpleados = listarEmpleados(arrayEmpleados,PAGINADO);
                    if(listaEmpleados < 1)
                    {
                        printf("No hay Empleados cargados\n");
                    }
                    break;
                case 3:
                    al_sort(arrayEmpleados, employee_compare, 1);
                    listarEmpleados(arrayEmpleados,PAGINADO);
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 0:
                    seguir = 'n';
                    Error=0;
                    break;
                default:
                    Error=-1;
                    opcion=-2;
            }//FIN switch(opcion)
            if(Error!=0)
            {
                sms_error(opcion,Error);
                Error=0;
            }

        }while(seguir == 's');

    }
    else
    {
        printf("ERROR. No se puede crear la lista de Empleados en memoria\n");
        Error=-1;
    } //FIN if(arrayEmpleados != NULL)

    return Error;
}

