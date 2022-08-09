#include <enet/enet.h>
#include <iostream>
#include <string>
using namespace std;

string AskNames();
ENetAddress address;
ENetHost* server = nullptr;
ENetHost* client = nullptr;
string serverName = "Server";
string clientName = "Client";

void EraseConsoleLine();
int ServerLogic();
int ClientLogic();

bool CreateServer()
{
    address.host = ENET_HOST_ANY;
    address.port = 1234;
    server = enet_host_create(&address, 32, 2, 0, 0);
    return server != nullptr;
}

bool CreateClient() 
{
    client = enet_host_create(NULL, 1, 2, 0, 0);
    return client != nullptr;
}


int main(int argc, char** argv)
{
    if (enet_initialize() != 0)
    {
        cout << "An error occurred while initializing ENet.\n" << endl;
        return EXIT_FAILURE;
    }
    atexit(enet_deinitialize);

    int UserInput;
    
    cout << "1) Create a server" << endl;
    cout << "2) Create a client" << endl;
    cin >> UserInput;
    
    if (UserInput == 1)
    {
        serverName = AskNames();
        ServerLogic();
    }
    else if (UserInput == 2)
    {
        clientName = AskNames();
        ClientLogic();
    }
    else
    {
        cout << "Invalid Input" << endl;
    }

    if (client != nullptr)
    {
       enet_host_destroy(client);
    }

    if (server != nullptr)
    {
        enet_host_destroy(server);
    }

    return EXIT_SUCCESS;
}

string AskNames() 
{
    string currentName;
    cout << "Enter a name please." << endl;
    cin >> currentName;
    return currentName;
}

void EraseConsoleLine()
{
    std::cout << "\33[2K";// Delete current line
    // i=1 because we included the first line
    std::cout
        << "\33[1A" // Move cursor up one
        << "\33[2K"; // Delete the entire line
    std::cout << "\r"; // Resume the cursor at beginning of line
}


int ServerLogic()
{
    if (!CreateServer())
    {
        cout << "An error occurred while initializing ENet.\n" << endl;
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        ENetEvent event;
        /* Wait up to 1000 milliseconds for an event. */
        while (enet_host_service(server, &event, 6000) > 0)
        {
            switch (event.type)
            {
            case ENET_EVENT_TYPE_CONNECT:
                cout << serverName << ": A new client connected." << endl;
                cout << "Enter bye to exit." << endl;
                event.peer->data = (void*)("Client");
                {
                    ENetPacket* packet = enet_packet_create(
                        "Hello",
                        strlen("Hello") + 1,
                        ENET_PACKET_FLAG_RELIABLE);
                    enet_host_broadcast(server, 0, packet);
                    enet_host_flush(server);
                }
                
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                cout << clientName << ": " << (char*)event.packet->data << endl;
                {
                    string message = "Hello, how are you today?";

                    if (message == "bye" || message == "Bye")
                    {
                        return 0;
                    }
                    cout << serverName << ": " << message << endl;
                    getline(cin, message);

                    if (strlen(message.c_str()) > 0)
                    {
                        ENetPacket* packet = enet_packet_create(
                            message.c_str(),
                            strlen(message.c_str()) + 1,
                            ENET_PACKET_FLAG_RELIABLE);
                        enet_host_broadcast(server, 0, packet);
                        enet_host_flush(server);
                    }
                    EraseConsoleLine();
                }
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                cout << (char*)event.peer->data << " disconnected." << endl;
                event.peer->data = NULL;
            }
        }
    }
}

int ClientLogic()
{
    if (!CreateClient())
    {
        cout << "An error occurred while trying to create an ENet client host." << endl;
        exit(EXIT_FAILURE);
    }

    ENetAddress address;
    ENetEvent event;
    ENetPeer* peer;
    enet_address_set_host(&address, "127.0.0.1");
    address.port = 1234;
    peer = enet_host_connect(client, &address, 2, 0);
    if (peer == NULL)
    {
        fprintf(stderr,
            "No available peers for initiating an ENet connection.\n");
        exit(EXIT_FAILURE);
    }
    if (enet_host_service(client, &event, 5000) > 0 &&
        event.type == ENET_EVENT_TYPE_CONNECT)
    {
        cout << "Connection to 127.0.0.1:1234 succeeded." << endl;
        cout << "Enter bye to exit." << endl;
    }
    else
    {
        enet_peer_reset(peer);
        cout << "Connection to 127.0.0.1:1234 failed." << endl;
    }

    while (1)
    {
        ENetEvent event;
        while (enet_host_service(client, &event, 100000) > 0)
        {
            switch (event.type)
            {
            case ENET_EVENT_TYPE_RECEIVE:
                cout << serverName << ": " << (char*)event.packet->data << endl;
                {
                    string message = "I am well.";
                    
                    cout << clientName << ": " << message << endl;
                    getline(cin, message);
                    if (message == "bye" || message == "Bye")
                    {
                        return 0;
                    }
                    if (strlen(message.c_str()) > 0)
                    {
                        ENetPacket* packet = enet_packet_create(
                            message.c_str(),
                            strlen(message.c_str()) + 1,
                            ENET_PACKET_FLAG_RELIABLE);
                        enet_host_broadcast(client, 0, packet);
                        enet_host_flush(client);
                    }
                    EraseConsoleLine();
                    
                }
                
                enet_packet_destroy(event.packet);
                break;
            }
        }
    }
}