#include "socket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>


int creer_serveur(int port){

	int socket_serveur ;
	socket_serveur = socket (AF_INET,SOCK_STREAM, 0);
	if ( socket_serveur == -1)
	{
		perror ( "socket_serveur" );
		/* traitement de l ’ erreur */
		return -1;
	}
	/* Utilisation de la socket serveur */
	struct sockaddr_in saddr ;
	saddr.sin_family = AF_INET ; /* Socket ipv4 */
	saddr.sin_port = htons (port); /* Port d ’ écoute */
	saddr.sin_addr.s_addr = INADDR_ANY ; /* écoute sur toutes les interfaces */
	if (bind (socket_serveur,(struct sockaddr*)&saddr ,sizeof(saddr)) == -1)
	{
		perror ( " bind socket_serveur " );
		/* traitement de l ’ erreur */
		return -1;
	}
	if (listen (socket_serveur,10) == -1)
	{
		perror ("listen socket_serveur");
		/* traitement d ’ erreur */
		return -1;
	}
	int socket_client ;
	socket_client = accept (socket_serveur,NULL,NULL);
	if (socket_client == -1)
	{
		perror ("accept");
		/* traitement d ’ erreur */
		return -1;
	}
	/* On peut maintenant dialoguer avec le client */
	const char * message_bienvenue = "Bienvenue sur le serveur de Ludovic et Clément ! " ;
	printf("%s",message_bienvenue);
	write ( socket_client , message_bienvenue , strlen(message_bienvenue));

	return 0;
}
