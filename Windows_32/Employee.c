#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    return 0;
}


void employee_print(Employee* this)
{
    printf("%d - %s - %s - %d\n", this->id, this->name, this->lastName, this->isEmpty);
}


Employee* employee_new(void)
{

    Employee* returnAux;

    returnAux = (Employee*)malloc(sizeof(Employee));

    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{
    this->id = id;

    return 0;
}

int employee_getId(Employee* this)
{
    int id;
    id = this->id;

    return id;
}

int employee_setName(Employee* this, const char* name)
{
    strcpy(this->name, name);

    return 0;
}

char* employee_getName(Employee* this)
{
    char* retorno = NULL;
    strcpy(retorno, this->name);

    return retorno;
}

int employee_setLastName(Employee* this, const char* lastName)
{
    strcpy(this->lastName, lastName);

    return 0;
}

char* employee_getLastName(Employee* this)
{
    char* retorno = NULL;
    strcpy(retorno, this->lastName);

    return retorno;
}

int employee_setIsEmpty(Employee* this, int isEmpty)
{
    int retorno = -1;
    if(isEmpty == 0 || isEmpty == 1)
    {
        this->isEmpty = isEmpty;
        retorno = 0;
    }

    return retorno;
}

int employee_getIsEmpty(Employee* this)
{
    int isEmpty;
    isEmpty = this->isEmpty;

    return isEmpty;
}

int employee_nuevoId(ArrayList* arrayEmpleados)
{
    int i;
    int nuevoId = 0;
    Employee* unEmpleado = NULL;
    int primerElemento = 0;

    for(i = 0; i < al_len(arrayEmpleados); i++)
    {
        unEmpleado = (Employee*)al_get(arrayEmpleados, i);
        if(unEmpleado != NULL)
        {
            if(unEmpleado->id > nuevoId || primerElemento == 0)
            {
                primerElemento = 1;
                nuevoId = unEmpleado->id;
            }
        }
    }

    nuevoId++;

    return nuevoId;
}
