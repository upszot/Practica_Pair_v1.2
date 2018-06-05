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


int main()
{
    ArrayList* arrayEmpleados = al_newArrayList();
    int Error=-1;
    int opcion=-1; //Opcion -1 => Inicializar array
    char seguir = 's';

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
                    Error = listarEmpleados(arrayEmpleados,PAGINADO);
                    break;
                case 3:
                    al_sort(arrayEmpleados, employee_compare, 1);
                    Error=listarEmpleados(arrayEmpleados,PAGINADO);
                    break;
                case 4:



                    break;
                case 5:
                    Error=listarEmpleados(arrayEmpleados,PAGINADO);
                    int ID=get_int("\n Ingrese ID a borrar: ");
                    int index= get_index( arrayEmpleados,  ID);
                    Error=al_remove(arrayEmpleados, index);

                    break;
                case 6:

                    break;
                case 0:
                    seguir = 'n';
                    Error=0;
                    break;
                default:
                    Error=-2;
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
        sms_error(opcion,Error);
    } //FIN if(arrayEmpleados != NULL)

    return Error;
}

