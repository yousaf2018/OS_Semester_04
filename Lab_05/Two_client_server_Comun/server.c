#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 1
#define PORT 8080
#define SA struct sockaddr

// Driver function
int main()
{
    char buff[MAX];
    int sockfd, connfd_1,connfd_2, len;
    struct sockaddr_in servaddr, cli_1,cli_2;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..for client 1\n");
    len = sizeof(cli_1);

    // Accept the data packet from client and verification
    connfd_1 = accept(sockfd, (SA*)&cli_1, &len);
    if (connfd_1 < 0) {
        printf("server acccept failed...\n");
        exit(0);
    }
    else
        printf("server acccept the client...\n");

    // Function for chatting between client and server
    bzero(buff, MAX);
    read(connfd_1, buff, sizeof(buff));
    buff[0]=buff[0]-1;
    printf("I received char from client 1 %s:",buff);


///////////////////////////////////////////////////////////////
   printf("Server listening.. for client 2\n");
    len = sizeof(cli_2);

    // Accept the data packet from client and verification
    connfd_2 = accept(sockfd, (SA*)&cli_2, &len);
    if (connfd_2 < 0) {
        printf("server acccept failed...\n");
        exit(0);
    }
    else
        printf("server acccept the client...\n");
        write(connfd_2, buff, sizeof(buff));
    // Function for chatting between client and server


    // After chatting close the socke
    close(sockfd);
}
