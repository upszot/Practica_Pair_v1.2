#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"


int cargarDesdeArchivo(const char* nombreArchivo, ArrayList* arrayEmpleados)
{
    FILE* archivoEmpleados;
    int retorno = -1;
    int parseoArchivo;
    int cerroArchivo;

    archivoEmpleados = fopen(nombreArchivo, "r");
    if(archivoEmpleados != NULL)
    {
        parseoArchivo = parserEmployee(archivoEmpleados, arrayEmpleados);
        cerroArchivo = fclose(archivoEmpleados);

        if(parseoArchivo == 0 && cerroArchivo == 0)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int listarEmpleados(ArrayList* arrayEmpleados,int paginado)
{
    int i;
    int cont=0;
    int retorno = -1;
    Employee* unEmpleado = NULL;

    for(i = 0; i < al_len(arrayEmpleados); i++)
    {
        unEmpleado = (Employee*)al_get(arrayEmpleados, i);
        if(unEmpleado != NULL)
        {
            employee_print(unEmpleado);
            retorno = 0;
        }
        if(cont!=0 && cont %paginado==0)
        {
            system("pause");
            system("cls");
        }
        cont++;
    }
    if(cont!=0)
    {
        system("pause");
    }
    return retorno;
}

int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    Employee *tmp_emp1;
    Employee *tmp_emp2;
    tmp_emp1=(Employee * ) pEmployeeA;
    tmp_emp2=(Employee * ) pEmployeeB;
    return strcmp(tmp_emp1->name,tmp_emp2->name);
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
