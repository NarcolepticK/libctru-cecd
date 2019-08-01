#include "3ds/services/cecdu.h"
#include <3ds/svc.h>
#include <3ds/srv.h>
#include <3ds/synchronization.h>
#include <3ds/ipc.h>

static Handle cecduHandle;
static int cecduRefCount;

Result cecduInit(void)
{
    Result ret;

    if (AtomicPostIncrement(&cecduRefCount)) return 0;

    ret = srvGetServiceHandle(&cecduHandle, "cecd:u");
    if (R_FAILED(ret)) AtomicDecrement(&cecduRefCount);

    return ret;
}

void cecduExit(void)
{
	if (AtomicDecrement(&cecduRefCount)) return;
	svcCloseHandle(cecduHandle);
}