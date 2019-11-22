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
//        ESGC_EVENT_HANDLE hEventConnect = NULL;
//        error = ESGCRegisterEvent(hServer, ESGC_EVENT_SERVER_CLIENT_CONNECTED, &hEventConnect);
//        if(ESGC_ERR_SUCCESS != error)
//            cout << "ESGCRegisterEvent Failed! Error:" << error << endl;

        error = ESGCServerStart(hServer);
        if(ESGC_ERR_SUCCESS != error)
            cout << "ESGCServerStart Failed! Error:" << error << endl;

//        char buffer[2048] ={0};
//        size_t bufferSize = sizeof(buffer);
//        while(true)
//        {
//            error = ESGCEventGetData(hEventConnect, buffer, &bufferSize, 1000);
//            if(ESGC_ERR_ABORT == error)
//            {
//                cout << "ESGCEventGetData ESGC_ERR_ABORT!" << endl;
//                break;
//            }
//            else if(ESGC_ERR_SUCCESS == error)
//            {
//                std::string clientID;
//                clientID.append((char*)buffer, bufferSize);

//                cout << "ESGCEventGetData ESGC_ERR_SUCCESS!" << endl;
//                cout << "ClientID: " << clientID.c_str() << endl;
//                break;
//            }
//            else if(ESGC_ERR_TIMEOUT == error)
//                cout << "ESGCEventGetData Timeout!" << endl;
//        }

    }

//    Sleep(4000);
//    ESGCClose();
    system("pause");
    return 0;
}
