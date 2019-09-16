#include "3ds/services/cec/cecCecSys.h"
#include <3ds/svc.h>
#include <3ds/ipc.h>

namespace cec::detail {

CecSys::CecSys(void) {
    sessionHandle = 0;
    refCount = 0;
}

Result Open(u32 programId, CecDataPathType pathType, u32 flag, u32* size) {
    return 0;
}

Result Read(u32* readSize, void* readBuf, u32 readBufSize) {
    return 0;
}

Result ReadMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize) {
    return 0;
}

Result ReadMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize, const void* hmacKey) {
    return 0;
}

Result Write(const void* writeBuf, u32 writeBufSize) {
    return 0;
}

Result WriteMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize) {
    return 0;
}

Result WriteMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize, const void* hmacKey) {
    return 0;
}

Result Delete(u32 programId, CecDataPathType pathType, bool isOutBox, const void* msgId, u32 msgIdSize) {
    return 0;
}

Result SetData(u32 programId, const void* dataBuf, u32 dataBufSize, u32 option) {
    return 0;
}

Result ReadData(void* destBuf, u32 destBufSize, u32 option, const void* paramBuf, u32 paramBufSize) {
    return 0;
}

Result Start(CecCommand command) {
    return 0;
}

Result Stop(CecCommand command) {
    return 0;
}

Result GetCecInfoBuffer(u32 programId, void* buf, u32 bufSize) {
    return 0;
}

Result GetCecdState(u32* state) {
    return 0;
}

Result GetCecInfoEventHandle(Handle* eventHandle) {
    return 0;
}

Result GetChangeStateEventHandle(Handle* eventHandle) {
    return 0;
}

Result OpenAndWrite(const void* writeBuf, u32 writeBufSize, u32 programId, CecDataPathType pathType, u32 fileFlag) {
    return 0;
}

Result OpenAndRead(void * readBuf, u32 readBufSize, u32* readSize, u32 programId, CecDataPathType pathType, u32 fileFlag) {
    return 0;
}

Result GetEventLog(void* eventLogBuf, u32* end, u32 start, u32 size) {
    return 0;
}

Result GetEventLogStart(u32* start) {
    return 0;
}
} // namespace cec::detail