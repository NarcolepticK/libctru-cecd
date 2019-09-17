#include <3ds/ipc.h>
#include "3ds/services/cec/cecCecSys.h"
#include <3ds/srv.h>
#include <3ds/svc.h>
#include <3ds/synchronization.h>

Handle cecdsSessionHandle;
int cecdsRefCount;

Result cecdsInit(void) {
    Result ret;

    if (AtomicPostIncrement(&cecdsRefCount)) return 0;

    ret = srvGetServiceHandle(&cecdsSessionHandle, "cecd:s");
    if(R_FAILED(ret)) AtomicDecrement(&cecdsRefCount);

    return ret;
}

Result cecdsExit(void) {
    if (AtomicDecrement(&cecdsRefCount)) return 0;
    return svcCloseHandle(cecdsSessionHandle);
}

Result cecdsOpen(u32 programId, CecDataPathType pathType, u32 flag, u32* size) {
    return 0;
}

Result cecdsRead(u32* readSize, void* readBuf, u32 readBufSize) {
    return 0;
}

Result cecdsReadMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize) {
    return 0;
}

Result cecdsReadMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize, const void* hmacKey) {
    return 0;
}

Result cecdsWrite(const void* writeBuf, u32 writeBufSize) {
    return 0;
}

Result cecdsWriteMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize) {
    return 0;
}

Result cecdsWriteMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize, const void* hmacKey) {
    return 0;
}

Result cecdsDelete(u32 programId, CecDataPathType pathType, bool isOutBox, const void* msgId, u32 msgIdSize) {
    return 0;
}

Result cecdsSetData(u32 programId, const void* dataBuf, u32 dataBufSize, u32 option) {
    return 0;
}

Result cecdsReadData(void* destBuf, u32 destBufSize, u32 option, const void* paramBuf, u32 paramBufSize) {
    return 0;
}

Result cecdsStart(CecCommand command) {
    return 0;
}

Result cecdsStop(CecCommand command) {
    return 0;
}

Result cecdsGetCecInfoBuffer(u32 programId, void* buf, u32 bufSize) {
    return 0;
}

Result cecdsGetCecdState(u32* state) {
    return 0;
}

Result cecdsGetCecInfoEventHandle(Handle* eventHandle) {
    return 0;
}

Result cecdsGetChangeStateEventHandle(Handle* eventHandle) {
    return 0;
}

Result cecdsOpenAndWrite(const void* writeBuf, u32 writeBufSize, u32 programId, CecDataPathType pathType, u32 fileFlag) {
    return 0;
}

Result cecdsOpenAndRead(void * readBuf, u32 readBufSize, u32* readSize, u32 programId, CecDataPathType pathType, u32 fileFlag) {
    return 0;
}

Result cecdsGetEventLog(void* eventLogBuf, u32* end, u32 start, u32 size) {
    return 0;
}

Result cecdsGetEventLogStart(u32* start) {
    return 0;
}
