/* *********************************************************************** *
 *       Filename:  netcat_common.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 07 March 2013 11:37:24  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Gamit (09211014), <prakashgamit23@gmail.com>
 *   Organization:  Indian Institute of Technology, Roorkee
 *
 * ********************************************************************** */

#include "netcat_core.h"
#include "wrapper.h"
#include <strings.h>


/* @type - type of socket */
/* @return - socket descriptor */
extern int create_socket(int type);


/* @mode - is it client mode or listen mode
 * @port - port to use
 * @target - client mode = host to connect
 *           listen mode = interfce to use*/
/* @return - address struct */
extern struct sockaddr_in build_addr_struct(int mode, int port, char *target);
