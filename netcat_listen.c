/* *********************************************************************** *
 *
 *       Filename:  netcat_listen.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 07 March 2013 09:52:58  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Gamit (09211014), <prakashgamit23@gmail.com>
 *   Organization:  Indian Institute of Technology, Roorkee
 *
 * ********************************************************************* */

#include "netcat_listen.h"

int sockfd;


void start_server(){
    if(o.udp)
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    else
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == -1)
        die("socket");

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(o.port);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
        die("bind");

    if(listen(sockfd, 5) == -1)
        die("listen");

    /* start service */
    if(o.verbose)
        printf("started listening on port %d\n", o.port);
    do{
        service();
    }while(o.keepopen);
}


void service(){
    struct sockaddr_in cliaddr;
    int clifd, clilen = sizeof(cliaddr);
    /* accept a connection */
    if((clifd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen)) == -1)
        die("accept");

    /* print client address and port number when a new connection
       request is received */
    char str[INET_ADDRSTRLEN];
    unsigned short p;
    if(o.verbose){
        p = ntohs(cliaddr.sin_port);
        inet_ntop(AF_INET, &(cliaddr.sin_addr), str, INET_ADDRSTRLEN);
        printf("got new connection from (%s, %d)\n", str, p);
    }

    char sendline[MAX], recvline[MAX];
    fd_set rset;
    int maxfdp1;
    int bytes;

    FD_ZERO(&rset);
    while(1){
        FD_SET(fileno(stdin), &rset);
        FD_SET(clifd, &rset);

        maxfdp1 = (fileno(stdin) < clifd? clifd : fileno(stdin)) + 1;

        if(select(maxfdp1, &rset, NULL, NULL, NULL) == -1)
            die("select");

        if(FD_ISSET(clifd, &rset)){
            bzero(recvline, MAX);
            bytes = read(clifd, recvline, MAX);

            if(bytes == -1)
                die("read");
            else if(bytes == 0)
                break;

            fputs(recvline, stdout);
        }

        if(FD_ISSET(fileno(stdin), &rset)){
            bzero(sendline, MAX);
            bytes = read(fileno(stdin), sendline, MAX);

            if(bytes == -1)
                die("read");

            if(write(clifd, sendline, strlen(sendline)) == -1)
                die("write");
        }
    }/* while */
    
    /* close connection */
    close(clifd);
    if(o.verbose){
        printf("closed connection to (%s, %d)\n", str, p);
    }
}
