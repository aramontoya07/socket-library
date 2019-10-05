/*
 * servidor.h
 *
 *  Created on: 4 oct. 2019
 *      Author: utnso
 */

#ifndef SRC_SERVIDOR_H_
#define SRC_SERVIDOR_H_

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
#include<commons/log.h>
#include<commons/collections/list.h>
#include<string.h>

typedef enum
{
	MENSAJE,
	PAQUETE
}op_code;

t_log* logger;

int iniciar_servidor(char* puerto);
int aceptar_cliente(int socket_servidor);
int dame_tu_protocolo_cliente(int socket_cliente);
void* deserializar_datos_del_cliente(int* size, int socket_cliente);
void recibir_mensaje_del_cliente(int socket_cliente);
t_list* recibir_paquete(int socket_cliente);


#endif /* SRC_SERVIDOR_H_ */
