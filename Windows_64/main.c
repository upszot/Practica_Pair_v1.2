#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

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
    int i;
    ArrayList* empleados;
    empleados = al_newArrayList();
    Employee* e;
    Employee* aux;
    e = (Employee*)malloc(sizeof(Employee));
    e->id = 1;
    strcpy(e->name, "Juan");
    al_add(empleados, e);

    Employee* e2;
    e2 = (Employee*)malloc(sizeof(Employee));
    e2->id = 2;
    strcpy(e2->name, "Luis");
    al_add(empleados, e2);

    printf("Hay %d elementos\n", al_len(empleados));

    for(i = 0; i < al_len(empleados); i++)
    {
        aux = (Employee*)al_get(empleados, i);
        printf("%d - %s\n", aux->id, aux->name);
    }


    return 0;
}
