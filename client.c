//client.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<netdb.h>
#include<netinet/in.h>
#include<errno.h>
#include<assert.h>

#define MAXLINE 4096 /*max text line length*/
#define SERV_PORT 59001 /*port*/
#define BUFFER 65000 /*buffer*/

//function to get ip address for web address
int getIp(char* server, char* ip){
    //struct hostent *he;
    struct hostent *caddr;
	struct in_addr **addr_list;
    int i;//iterator	
	if ((caddr = gethostbyname(server)) == NULL){
		//get host info
		herror("gethostbyname");
		return 1;
	}
	addr_list = (struct in_addr **) caddr->h_addr_list;
	for(i = 0; addr_list[i] != NULL; i++){
		//Return the first one;
		strcpy(ip , inet_ntoa(*addr_list[i]));
		return 0;
	}
	return 1;
}
/*
I need to use this function send bytes to the server
*/
//function to send datagrams
void send_bytes(int sock, struct sockaddr_in * target, char * buffer, int bytes_to_send, int max_send_size, int * current_send_num) {
    int temp, mod_temp, loop, result,flags;
    if((max_send_size < 1) || (max_send_size > 65495)) max_send_size = 65495;
    if(bytes_to_send < 1){
        printf("Bad bytes_to_send value %d\n", bytes_to_send);
        exit(-1);
    }
    temp = bytes_to_send / max_send_size;     /* integer number of max_send_size buffers to send */
    mod_temp = bytes_to_send % max_send_size; /* residual bytes to send, if any */
    if(mod_temp > 0)
        temp++;      /* if non-zero, mod_temp holds the byte count of the last buffer to send */
    else
        mod_temp = max_send_size;  /* if zero, set to the largest size we can send */
    /* send loop */
    flags = 0;
    /* sends temp number of buffers, where the last one may be smaller than the rest */
    for(loop=1; loop <= temp; loop++) {
        *((int *) buffer) = *current_send_num; /* copy current_send_num into buffer */
        result = sendto(sock, buffer, (loop == temp) ? mod_temp : max_send_size, flags, target, sizeof(struct sockaddr_in));
        if(result < 0) {
            printf("send error %d\n", errno);
            return;
        };
        (*current_send_num)++; /* increment the datagram number */
    }
    return;
}

//main function
int main(int argc, char *argv[]){
    int sockfd, bytes, b, flags, i, j;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE], recvline[MAXLINE], IP[100]; 
    char *svr, saddr;
    //basic check of the arguments
    //additional checks can be inserted
    if (argc !=2) {
        perror("Usage: client <IP address of the server");
        exit(1);
    }
 
    //Create a socket for the client
    //If sockfd<0 there was an error in the creation of the socket
    if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Problem in creating the socket");
        exit(2);
    }
    bytes = 200;
    svr = argv[1];
    saddr = getIp(svr, IP);
    //Creation of the socket
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(&saddr);
    servaddr.sin_port = htons(SERV_PORT); //htons-convert to big-endian order

    /*
    DESCRIPTION OF ARGS FOR BIND/CONNECT
    sockfd – File descriptor of the socket 
    BUFFER – buffer containing the data to be sent 
    bytes – Size of buf application buffer 
    flags – Bitwise OR of flags to modify socket behavior 
    saddr – Structure containing the address of the destination (server)
    addrlen – Size of dest_addr structure  
    */

    //bind
    b = bind(sockfd, (struct sockaddr *) &saddr, sizeof(saddr));
    //Connection of the client to the socket
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
        perror("Error connecting to the server");
        exit(1);
    }

    while (fgets(sendline, MAXLINE, stdin) != NULL){
        bytes = strlen(BUFFER);
        flags = 0;
        j = 0;
        //call send_bytes function
        send_bytes(sockfd, (struct sockaddr *)&saddr, (char*)BUFFER, bytes, (char*)MAXLINE, j);
        //sendto(sockfd, (char *)BUFFER, bytes, flags,(struct sockaddr *)&saddr, sizeof(saddr));
        int addrlen = sizeof(saddr);
        int size = recvfrom(sockfd, BUFFER, bytes, flags, (struct sockaddr *)&saddr, &addrlen);
        
        /*time_t last time = time();
        long sent_counter = 0;
        //psuedo code
        //for (int i = 0; i < num_messages; i++){
            //sent = sendto();
            //rcvd = recvfrom();
            //sleep(interval);
        //}
        time_t now = time();
        sent_counter += bytes;
        sleep();

        if(now - last_time > 1){
            printf (...); // print the counter 
            counter = 0;
            last_time = now;
        }
        */
        if (recv(sockfd, recvline, MAXLINE,0) == 0){
            //error: server terminated prematurely
            perror("The server terminated prematurely");
            exit(-1);
        }
        printf("%s", "String received from the server: ");
        fputs(recvline, stdout);
    }
    close(sockfd);
    exit(0);
}
/*
// DECLARATIONS:
struct sockaddr_in me, target;
socklen_t len;
int port; // Get from commandline atoi
int socket;
char buffer[512];
char target_addr[32] = "136.50.5.87"; // This is the nuka ip address, you can hardcode it or get it from commandline using the dig +short command from programM$
*
*/