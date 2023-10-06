//
// server TCP 1
// riceve un numero intero e lo visualizza
//
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/times.h>
#include <stdlib.h> // Added for exit()

// costante contenente il numero di porta del server
#define PORT 12345

int main()
{
    int qlen = 6;
    int socketfd, new_socket, dato;
    unsigned int client_len;
    struct sockaddr_in servizio, cliente; //  record con gli indirizzi
    /* impostazione del socket */
    // utilizzo della funzione socket
    socketfd = socket(AF_INET, SOCK_STREAM, 0); // Changed IPPROTO_TCP to 0
    // controllo che la socket sia stata creata
    if (socketfd == -1)
    {
        perror("chiamata alla system call socket fallita");
        exit(1); // Exit the program in case of an error
    }

    // indicando INADDR_ANY viene collegato il socket all'indirizzo locale IP
    // dell'interaccia di rete che verr‡ utilizzata per inoltrare il datagram IP
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(PORT);

    /* leghiamo l'indirizzo al socket */
    // funzione bind
    // controllo che la funzione bind sia andata a buon fine
    if (bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio)) == -1)
    {
        perror("chiamata alla system call bind fallita");
        exit(2);
    }

    // poniamo il server in ascolto delle richieste dei client con listen
    if (listen(socketfd, qlen) < 0)
    {
        perror("listen() failed.\n");
        close(socketfd);
        exit(3);
    }

    /* gestione delle connessioni dei client */
    while (1)
    {
        client_len = sizeof(cliente);

        // sia accetta la connessione con la funzione accept
        // controllo dell'accettazione
        new_socket = accept(socketfd, (struct sockaddr *)&cliente, &client_len);
        if (new_socket == -1)
        {
            perror("accept() failed.\n");
            continue; // Continue the loop if accept fails
        }

        /* ----- inizio dialogo tra server e client ------ */
        // ricezione del dato con recv
        recv(new_socket, &dato, sizeof(int), 0);

        // stampa a video del dato ricevuto
        printf("Ricevuto un dato: %d\n", dato);

        /* chiusura della connessione */
        close(new_socket);
    }

    close(socketfd);
    return 0;
}
