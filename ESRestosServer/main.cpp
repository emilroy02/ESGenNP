#include <iostream>

using namespace std;

#include "es_gennp_common.h"
#include "es_gennp.h"
using namespace ESGenNP;



int main(int argc, char *argv[])
{
    ESGC_SERVER_HANDLE hServer = NULL;
    //cout << "Hello World!" << endl;
    ESGCInit();
    ESGC_ERROR error = ESGCServerCreate(&hServer);
    if(ESGC_ERR_SUCCESS != error)
        cout << "ESGCServerCreate Failed! Error:" << error << endl;
    else
    {
        error = ESGCServerStart(hServer);
        if(ESGC_ERR_SUCCESS != error)
            cout << "ESGCServerStart Failed! Error:" << error << endl;
    }
    ESGCClose();
    system("pause");
    return 0;
}
