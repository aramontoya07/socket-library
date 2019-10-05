/*
 * socket.h
 *
 *  Created on: 3 oct. 2019
 *      Author: utnso
 */

#ifndef SOCKET_CLIENTE_H_
#define SOCKET_CLIENTE_H_

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>


typedef enum
{
	MENSAJE,
	PAQUETE
}op_code;

typedef struct
{
	int size;
	void* stream;
} t_buffer;

typedef struct
{
	op_code codigo_operacion;
	t_buffer* buffer;
} t_paquete;

void* serializar_paquete(t_paquete* paquete, int bytes);
int cconectar_a_servidor(char* ip, char* puerto);
void enviar_mensaje_al_servidor(char* mensaje, int socketfd);
//void crear_buffer(t_paquete* paquete);
//void agregar_a_paquete(t_paquete* paquete, void* valor, int tamanio);
//void enviar_paquete(t_paquete* paquete, int socketfd);
void eliminar_paquete(t_paquete* paquete);
void liberar_conexion(int socketfd);


#endif /* SOCKET_H_ */
