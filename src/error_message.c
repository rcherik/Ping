#include "ping.h"
#include <linux/errqueue.h>

void	error_message(struct msghdr msg)
{
	struct cmsghdr *cmsg;                   /* Control related data */
	struct sock_extended_err *sock_err;     /* Struct describing the error */ 

	ft_putendl("in err");
    for (cmsg = CMSG_FIRSTHDR(&msg); cmsg; cmsg = CMSG_NXTHDR(&msg, cmsg)) 
    {
	printf("hue = %d\n", cmsg->cmsg_level);
        /* Ip level */
        if (cmsg->cmsg_level == SOL_IP)
        {
            /* We received an error */
            if (cmsg->cmsg_type == IP_RECVERR)
            {
                printf("We got IP_RECVERR message\n");
                sock_err = (struct sock_extended_err*)CMSG_DATA(cmsg); 
                if (sock_err)
                {
                    /* We are intrested in ICMP errors */
                    if (sock_err->ee_origin == SO_EE_ORIGIN_ICMP) 
                    {
                        /* Handle ICMP errors types */
                        switch (sock_err->ee_type) 
                        {
                            case ICMP_NET_UNREACH:
                                /* Hendle this error */
                                printf("Network Unreachable Error\n");
                                break;
                            case ICMP_HOST_UNREACH:
                                /* Hendle this error */
                                printf("Host Unreachable Error\n");
                                break;
                        }
                    }
                }
            }
        } 
    }
}
