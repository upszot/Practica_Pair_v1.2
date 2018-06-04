#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

#define NOMBRE_ARCHIVO_EMPLEADOS "data.csv"

int cargarDesdeArchivo(const char*, ArrayList*);
int listarEmpleados(ArrayList*);
int agregarEmpleado(ArrayList*);

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
    int parseoEmpleados;
    char seguir = 's';
    int opcion;
    int listaEmpleados;

    if(arrayEmpleados != NULL)
    {
        while(seguir == 's')
        {
            system("cls");

            printf("1. Parse del archivo data.csv\n");
            printf("2. Listar Empleados\n");
            printf("3. Ordenar por nombre\n");
            printf("4. Agregar un elemento\n");
            printf("5. Elimina un elemento\n");
            printf("6. Listar Empleados (Desde/Hasta)\n\n");
            printf("7. Salir\n");

            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                parseoEmpleados = cargarDesdeArchivo(NOMBRE_ARCHIVO_EMPLEADOS, arrayEmpleados);
                if(parseoEmpleados == 1)
                {
                    printf("Parse del archivo OK\n");
                }
                else
                {
                    printf("ERROR en Parse\n");
                }
                break;

            case 2:
                listaEmpleados = listarEmpleados(arrayEmpleados);
                if(listaEmpleados < 1)
                {
                    printf("No hay Empleados cargados\n");
                }
                break;

            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                seguir = 'n';
                break;

            default:
                printf("Opcion incorrecta, opciones validas desde 1 hasta 7\n");
            }

            if(seguir == 's')
            {
                system("pause");
            }
        }

    }
    else
    {
        printf("ERROR. No se puede crear la lista de Empleados en memoria\n");
    }

    return 0;
}

int cargarDesdeArchivo(const char* nombreArchivo, ArrayList* arrayEmpleados)
{
    FILE* archivoEmpleados;
    int retorno = 0;
    int parseoArchivo;
    int cerroArchivo;

    archivoEmpleados = fopen(nombreArchivo, "r");
    if(archivoEmpleados != NULL)
    {
        parseoArchivo = parserEmployee(archivoEmpleados, arrayEmpleados);
        cerroArchivo = fclose(archivoEmpleados);

        if(parseoArchivo == 1 && cerroArchivo == 0)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int listarEmpleados(ArrayList* arrayEmpleados)
{
    int i;
    int retorno = 0;
    Employee* unEmpleado = NULL;

    for(i = 0; i < al_len(arrayEmpleados); i++)
    {
        unEmpleado = (Employee*)al_get(arrayEmpleados, i);
        if(unEmpleado != NULL)
        {
            employee_print(unEmpleado);
            retorno = 1;
        }
    }

    return retorno;
}
