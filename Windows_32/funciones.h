#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif // FUNCIONES_H_INCLUDED

/** \brief Imprime Texto del menu
 *
 * \param opciones char*
 * \return void
 *
 */
void menu(char *opciones);

/** \brief Muestra cartel de Error con su respectivo codigo de Error.
 *
 * \param mensaje int
 * \param Error int
 * \return void
 *
 */
void sms_error(int mensaje,int Error);
int get_int(char *sms);
