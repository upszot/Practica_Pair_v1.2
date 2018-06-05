
void menu(char *opciones)
{
    system("cls");
    printf("%s \n",opciones);
    printf("\n0.  Salir \n");
    printf("\n\tIngrese Opcion: ");
}

void sms_error(int mensaje,int Error)
{
    system("cls");
    printf("\n\n");
    switch(mensaje)
    {
        case -1:
            printf("ERROR-COD: %d -- No se puede crear la lista de Empleados en memoria",Error);
            break;
        case 1:
            printf("ERROR-COD: %d -- Parse del archivo data.csv",Error);
            break;
        case 2:
            printf("ERROR-COD: %d -- Listar Empleados",Error);
            break;
        case 3:
            printf("ERROR-COD: %d -- Ordenar por nombre",Error);
            break;
        case 4:
            printf("ERROR-COD: %d -- Agregar un elemento",Error);
            break;
        case 5:
            printf("ERROR-COD: %d -- Elimina un elemento",Error);
            break;
        case 6:
            printf("ERROR-COD: %d -- Listar Empleados (Desde/Hasta)",Error);
            break;
        case -2:
            printf("ERROR-COD: %d -- Opcion de menu Invalida",Error);
            break;
        default:
            printf("Se produjo un Error Inesperado...");
            break;
    }
    printf("\n\n");
    system("pause");
}

int get_int(char *sms)
{
    int Numero;
    do
    {
        fflush(stdin);
        printf("%s ",sms);
        scanf("%d",&Numero);
        fflush(stdin);
    }while(Numero <= 0);
    return Numero;
}
