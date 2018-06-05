#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

#define MASACARA_ARCHIVO_EMPLEADOS "%[^,],%[^,],%[^,],%[^\n]\n"
#define CANTIDAD_CAMPOS_ARCHIVO_EMPLEADOS 4
#define TIENE_ENCABEZADO_ARCHIVO_EMPLEADOS 1

int parserEmployee(FILE* pFile, ArrayList* pArrayListEmployee)
{
    int retorno = -1;
    int cantidadFilasLeidas = 0;
    int cantidadDatosLeidos;
    Employee* unEmpleado;
    char charId[10];
    char charIsEmpty[10];
    int agregoEmpleado;
    char cabecera[80];
    char nombre[TAM_NOMBRE];
    char apellido[TAM_APELLIDO];
    int guardoDato;

    if(pFile != NULL)
    {
        retorno = -2;
        if(TIENE_ENCABEZADO_ARCHIVO_EMPLEADOS == 1)
        {
            //descarto la lectura del encabezado
            fgets(cabecera, 80, pFile);
        }

        while(!feof(pFile))
        {
            retorno = 0;
            unEmpleado = employee_new();
            if(unEmpleado != NULL)
            {
                cantidadDatosLeidos = fscanf(pFile, MASACARA_ARCHIVO_EMPLEADOS, charId, nombre, apellido, charIsEmpty);
                if(cantidadDatosLeidos == CANTIDAD_CAMPOS_ARCHIVO_EMPLEADOS)
                {
                    guardoDato = employee_setId(unEmpleado, charIdToId(charId));
                    if(guardoDato < 0)
                    {
                        break;
                    }

                    guardoDato = employee_setName(unEmpleado, nombre);
                    if(guardoDato < 0)
                    {
                        break;
                    }

                    guardoDato = employee_setLastName(unEmpleado, apellido);
                    if(guardoDato < 0)
                    {
                        break;
                    }

                    guardoDato = employee_setIsEmpty(unEmpleado, charIsEmptyToIsEmpty(charIsEmpty));
                    if(guardoDato < 0)
                    {
                        break;
                    }

                    agregoEmpleado = al_add(pArrayListEmployee, unEmpleado);
                    if(agregoEmpleado < 0) //Hubo error
                    {
                        break;
                    }

                    cantidadFilasLeidas++;
                }
                else //Fin de archivo u otro error
                {
                    break;
                }
            }
            else //Sin memoria
            {
                break;
            }
        }
    }

    return retorno;
}

int charIdToId(char* charId)
{
    int id;
    id = atoi(charId);

    return id;
}

int charIsEmptyToIsEmpty(char* charIsEmpty)
{
    int isEmpty;

    if(stricmp(charIsEmpty, "true") == 0)
    {
        isEmpty = 1;
    }
    else
    {
        isEmpty = 0;
    }

    return isEmpty;
}
