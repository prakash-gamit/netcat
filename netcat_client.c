/* *********************************************************************** *
 *
 *       Filename:  netcat_client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 07 March 2013 03:03:24  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Gamit (09211014), <prakashgamit23@gmail.com>
 *   Organization:  Indian Institute of Technology, Roorkee
 *
 * ********************************************************************* */

#include "netcat_client.h"


int sockfd;


void start_client(){
    sockfd = create_socket(o.udp);

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(o.port);
    Inet_pton(AF_INET, o.target, &servaddr.sin_addr);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    char sendline[MAX], recvline[MAX];
    
    fd_set rset;
    int maxfdp1;

    FD_ZERO(&rset);
    while(1){
        FD_SET(fileno(stdin), &rset);
        FD_SET(sockfd, &rset);

        maxfdp1 = (fileno(stdin) < sockfd ? sockfd : fileno(stdin)) + 1;

        select(maxfdp1, &rset, NULL, NULL, NULL);

        if(FD_ISSET(sockfd, &rset)){
            read(sockfd, recvline, MAX);

            fputs(recvline, stdout);
        }

        if(FD_ISSET(fileno(stdin), &rset)){
            if(fgets(sendline, MAX, stdin) == NULL)
                break;/* all done */

            write(sockfd, sendline, strlen(sendline));
        }
    }/* while */

    close(sockfd);
}/* start_client() */
