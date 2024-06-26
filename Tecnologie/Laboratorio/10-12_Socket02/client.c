//
// client TCP 2
// invia un numero intero al server,
// il server restituisce il doppio
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
#include <stdlib.h>

// definizione della costante contenente il numero di porta del server
#define PORT 12345

// definizione della costante contenente indirizzo IP del server
#define SERVER_IP "127.0.0.1"

int main()
{
    int socketfd, dato;
    struct sockaddr_in server; //  record con gli indirizzi

    /* impostazione del socket */
    // utilizzo della funzione socket
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    // controllo che la socket sia stata creata
    if (socketfd == -1)
    {
        perror("chiamata alla system call socket fallita");
        exit(1);
    }

    /* impostazione di indirizzo IP e porta del server a cui connettersi */
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(SERVER_IP);
    server.sin_port = htons(PORT);

    /* connessione al server */
    // utilizzo della funzione connect
    // controllo che la connessione sia andata a buon fine
    if (connect(socketfd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        perror("connessione al server fallita");
        exit(2);
    }

    /* ------ inizio dialogo tra server e client -------- */
    // acquisizione dato da inviare
    printf("Inserisci un numero intero: ");
    scanf("%d", &dato);

    // invio del dato
    send(socketfd, &dato, sizeof(int), 0);

    // lettura del dato inviato dal server
    if (read(socketfd, &dato, sizeof(int)) == -1)
    {
        printf("read fallito");
        exit(3);
    }

    printf("Ricevuto un dato dal server: %d\n", dato);

    /* chiusura della connessione */
    close(socketfd);

    return 0;
}
