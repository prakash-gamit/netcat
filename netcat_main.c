/* *********************************************************************** *
 *
 *       Filename:  netcat_main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 06 March 2013 02:20:39  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Gamit (09211014), <prakashgamit23@gmail.com>
 *   Organization:  Indian Institute of Technology, Roorkee
 *
 * ********************************************************************* */

#include "netcat_core.h"


int main(int argc, char *argv[]){
    /* initialize options */
    init_options();

    /* parse command line args */
    int c;
    while((c = getopt(argc, argv, ":hve:p:lku")) != -1){
        switch(c){
            case 'h': help();
                      exit(EXIT_SUCCESS);

            case 'v': o.verbose = 1;
                      break;

            case 'e': o.execcommand = 1;
                      o.command = optarg;
                      break;

            case 'p': o.port = atoi(optarg);
                      break;

            case 'l': o.listen = 1;
                      break;

            case 'k': o.keepopen = 1;
                      break;

            case 'u': o.udp = 1;
                      break;

            case ':': fprintf(stderr, "-%c requires argument\n", optopt);
                      exit(EXIT_FAILURE);

            /* case ? */
            default: fprintf(stderr, "unknown option -%c\n", optopt);
                     exit(EXIT_FAILURE);

        }/* switch */
    }/* while */

    return 0;
}/* main() */
