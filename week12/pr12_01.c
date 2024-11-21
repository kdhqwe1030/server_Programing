#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>

int main() {
    int port;
    char *protocol="tcp";
    printf("Input port number: ");
    scanf("%d", &port);


    uint16_t net_port = htons(port);

    struct servent *service = getservbyport(net_port, protocol);

    if (service != NULL) {
        printf("Name=%s, Port=%d\n", service->s_name, ntohs(net_port));
    } else {
        printf("No service found for Port=%d, Protocol=%s\n", port, protocol);
    }

    return 0;
}

