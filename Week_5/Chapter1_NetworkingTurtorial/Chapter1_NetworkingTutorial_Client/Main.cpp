#include <enet/enet.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    if (enet_initialize() != 0)
    {
        fprintf(stderr, "An error occurred while initializing ENet.\n");

        cout << "An error occurred while initializing ENet.\n" << endl;
        return EXIT_FAILURE;
    }
    atexit(enet_deinitialize);

    ENetHost* client;
    client = enet_host_create(NULL /* create a client host */,
        1 /* only allow 1 outgoing connection */,
        2 /* allow up 2 channels to be used, 0 and 1 */,
        0 /* assume any amount of incoming bandwidth */,
        0 /* assume any amount of outgoing bandwidth */);

    if (client == NULL)
    {
        fprintf(stderr,
            "An error occurred while trying to create an ENet client host.\n");
        exit(EXIT_FAILURE);
    }

    enet_host_destroy(client);

    return EXIT_SUCCESS;
}