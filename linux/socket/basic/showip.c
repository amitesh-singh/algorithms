// show ip addresses for a host given as command line argument

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
/*
struct addrinfo
{
  int ai_flags;			 // Input flags. 
  int ai_family;		// Protocol family for socket.  
  int ai_socktype;		// Socket type.  
  int ai_protocol;		// Protocol for socket.  
  socklen_t ai_addrlen;		// Length of socket address. 
  struct sockaddr *ai_addr;	// Socket address for socket. 
  char *ai_canonname;		// Canonical name for service location.
  struct addrinfo *ai_next;	// Pointer to next in list. 
};
*/

int main(int argc, char **argv)
{
  struct addrinfo hints, *res, *p;

  int status;
  //ipv4 address
  char ipstr[INET6_ADDRSTRLEN];

  if (argc != 2)
  {
    fprintf(stderr, "usage: %s hostname\n", argv[0]);
    return 1;
  }

 memset(&hints, 0, sizeof(hints));

 hints.ai_family = AF_UNSPEC; //AF_INT or AF_INET6 to force
 hints.ai_socktype = SOCK_STREAM;

 status = getaddrinfo(argv[1], NULL, &hints, &res);
 if (status != 0)
 {
   fprintf(stderr, "getaddrinfo: %s", gai_strerror(status));
   return 2;
 }

 printf("IP Address for %s\n\n", argv[1]);

 for (p = res; p != NULL; p = p->ai_next)
 {
   void *addr;
  
   //ipv4
   if (p->ai_family == AF_INET)
   {
     struct sockaddr_in *ipv4 = p->ai_addr;
     addr = &(ipv4->sin_addr);
   }
   else if (p->ai_family == AF_INET6)
   {
     struct sockaddr_in6 *ipv6 = p->ai_addr;
     addr = &(ipv6->sin6_addr);
   }

   //convert ip to string and print it.

   inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
   printf("ip: %s", ipstr);
 }

  freeaddrinfo(res); //free linked list

  return 0;
}