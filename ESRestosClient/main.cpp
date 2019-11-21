#include <iostream>

using namespace std;

#include "es_gennp_common.h"
#include "es_gennp.h"
using namespace ESGenNP;

int main(int argc, char *argv[])
{
    //cout << "Hello World!" << endl;
    ESGCInit();

    ESGC_CLIENT_HANDLE hClient = NULL;
    ESGC_ERROR error = ESGCClientCreate(&hClient);
    if(ESGC_ERR_SUCCESS != error)
        cout << "ESGCClientCreate failed!" << endl;
    else
    {
        error = ESGCClientConnect(hClient, "127.0.0.1", 4711);
        if(ESGC_ERR_SUCCESS != error)
            cout << "ESGCClientConnect failed!" << endl;
        else
            cout << "Client Connected!" << endl;
    }

    ESGCClose();
    system("pause");
    return 0;
}
