#include "3ds/services/cec/cecCec.h"
#include <3ds/svc.h>
#include <3ds/ipc.h>

namespace cec::detail {

Cec::Cec(void) {
    sessionHandle = 0;
    refCount = 0;
}

Result Cec::Open(u32 programId, CecDataPathType pathType, u32 flag, u32* size) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x1, 3, 2);
    cmdbuf[1] = programID;
    cmdbuf[2] = pathType;
    cmdbuf[3] = flag;
    cmdbuf[4] = IPC_Desc_CurProcessId(); // do placeholder
    cmdbuf[5] = 0; // placeholder

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;
    ret = (Result)cmdbuf[1];

    if (R_SUCCEEDED(ret)) {
        if (size) *size = cmdbuf[2];
    }
    return ret;
}

Result Cec::Read(u32* readSize, void* readBuf, u32 readBufSize) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x2, 1, 2);
    cmdbuf[1] = readBufSize;
    cmdbuf[2] = IPC_Desc_Buffer(readBufSize, IPC_BUFFER_W);
    cmdbuf[3] = (u32)readBuf;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;
    ret = (Result)cmdbuf[1];

    if (R_SUCCEEDED(ret)) {
        if (readSize) *readSize = cmdbuf[2];
    }
    return ret;
}

Result Cec::ReadMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x3, 4, 4);
    cmdbuf[1] = programID;
    cmdbuf[2] = isOutBox;
    cmdbuf[3] = msgIdSize;
    cmdbuf[4] = readBufSize;
    cmdbuf[5] = IPC_Desc_Buffer(msgIdSize, IPC_BUFFER_R);
    cmdbuf[6] = (u32)msgId;
    cmdbuf[7] = IPC_Desc_Buffer(readBufSize, IPC_BUFFER_W);
    cmdbuf[8] = (u32)readBuf;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;
    ret = (Result)cmdbuf[1];

    if (R_SUCCEEDED(ret)) {
        if (readSize) *readSize = cmdbuf[2];
    }
    return ret;
}

Result Cec::ReadMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize, const void* hmacKey) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x4, 4, 6);
    cmdbuf[1] = programID;
    cmdbuf[2] = isOutBox;
    cmdbuf[3] = msgIdSize;
    cmdbuf[4] = readBufSize;
    cmdbuf[5] = IPC_Desc_Buffer(msgIdSize, IPC_BUFFER_R);
    cmdbuf[6] = (u32)msgId;
    cmdbuf[7] = IPC_Desc_Buffer(0x20, IPC_BUFFER_R); // 32 byte key size
    cmdbuf[8] = (u32)hmacKey;
    cmdbuf[9] = IPC_Desc_Buffer(readBufSize, IPC_BUFFER_W);
    cmdbuf[10] = (u32)readBuf;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;
    ret = (Result)cmdbuf[1];

    if (R_SUCCEEDED(ret)) {
        if (readSize) *readSize = cmdbuf[2];
    }
    return ret;
}

Result Cec::Write(const void* writeBuf, u32 writeBufSize) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x5, 1, 2);
    cmdbuf[1] = writeBufSize;
    cmdbuf[2] = IPC_Desc_Buffer(writeBufSize, IPC_BUFFER_R);
    cmdbuf[3] = (u32)writeBuf;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;

    return (Result)cmdbuf[1];
}

Result Cec::WriteMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x6, 4, 4);
    cmdbuf[1] = programID;
    cmdbuf[2] = isOutBox;
    cmdbuf[3] = msgIdSize;
    cmdbuf[4] = writeBufSize;
    cmdbuf[5] = IPC_Desc_Buffer(writeBufSize, IPC_BUFFER_R);
    cmdbuf[6] = (u32)writeBuf;
    cmdbuf[7] = IPC_Desc_Buffer(msgIdSize, IPC_BUFFER_RW);
    cmdbuf[8] = (u32)msgId;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;

    return (Result)cmdbuf[1];
}

Result Cec::WriteMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize, const void* hmacKey) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x7, 4, 6);
    cmdbuf[1] = programID;
    cmdbuf[2] = isOutBox;
    cmdbuf[3] = msgIdSize;
    cmdbuf[4] = writeBufSize;
    cmdbuf[5] = IPC_Desc_Buffer(writeBufSize, IPC_BUFFER_R);
    cmdbuf[6] = (u32)writeBuf;
    cmdbuf[7] = IPC_Desc_Buffer(0x20, IPC_BUFFER_R); // 32 byte key size
    cmdbuf[8] = (u32)hmacKey;
    cmdbuf[9] = IPC_Desc_Buffer(msgIdSize, IPC_BUFFER_RW);
    cmdbuf[10] = (u32)msgId;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;

    return (Result)cmdbuf[1];
}

Result Cec::Delete(u32 programId, CecDataPathType pathType, bool isOutBox, const void* msgId, u32 msgIdSize) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x8, 4, 2);
    cmdbuf[1] = programID;
    cmdbuf[2] = pathType;
    cmdbuf[3] = isOutBox;
    cmdbuf[4] = msgIdSize;
    cmdbuf[5] = IPC_Desc_Buffer(msgIdSize, IPC_BUFFER_R);
    cmdbuf[6] = (u32)msgId;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;

    return (Result)cmdbuf[1];
}

Result Cec::SetData(u32 programId, const void* dataBuf, u32 dataBufSize, u32 option) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x9, 3, 2);
    cmdbuf[1] = programID;
    cmdbuf[2] = dataBufSize;
    cmdbuf[3] = option;
    cmdbuf[4] = IPC_Desc_Buffer(dataBufSize, IPC_BUFFER_R);
    cmdbuf[5] = (u32)dataBuf;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;

    return (Result)cmdbuf[1];
}

Result Cec::ReadData(void* destBuf, u32 destBufSize, u32 option, const void* paramBuf, u32 paramBufSize) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0xA, 3, 4);
    cmdbuf[1] = destBufSize;
    cmdbuf[2] = option;
    cmdbuf[3] = paramBufSize;
    cmdbuf[4] = IPC_Desc_Buffer(paramBufSize, IPC_BUFFER_R);
    cmdbuf[5] = (u32)paramBuf;
    cmdbuf[6] = IPC_Desc_Buffer(destBufSize, IPC_BUFFER_W);
    cmdbuf[7] = (u32)destBuf;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;

    return (Result)cmdbuf[1];
}

Result Cec::Start(CecCommand command) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0xB, 1, 0);
    cmdbuf[1] = command;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;

    return (Result)cmdbuf[1];
}

Result Cec::Stop(CecCommand command) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0xC, 1, 0);
    cmdbuf[1] = command;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;

    return (Result)cmdbuf[1];
}

Result Cec::GetCecInfoBuffer(u32 programId, void* buf, u32 bufSize) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0xD, 2, 2);
    cmdbuf[1] = programId;
    cmdbuf[2] = bufSize;
    cmdbuf[3] = IPC_Desc_Buffer(bufSize, IPC_BUFFER_W);
    cmdbuf[4] = (u32)buf;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;

    return (Result)cmdbuf[1];
}

Result Cec::GetCecdState(u32* state) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0xE, 0, 0);

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;
    ret = (Result)cmdbuf[1];

    if (R_SUCCEEDED(ret)) {
        if (state) *state = cmdbuf[2];
    }
    return ret;
}

Result Cec::GetCecInfoEventHandle(Handle* eventHandle) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0xF, 0, 0);

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;
    ret = (Result)cmdbuf[1];

    if (R_SUCCEEDED(ret)) {
        if (eventHandle) *eventHandle = cmdbuf[3];
    }
    return ret;
}

Result Cec::GetChangeStateEventHandle(Handle* eventHandle) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x10, 0, 0);

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;
    ret = (Result)cmdbuf[1];

    if (R_SUCCEEDED(ret))
    {
        if (eventHandle) *eventHandle = cmdbuf[3];
    }
    return ret;
}

Result Cec::OpenAndWrite(const void* writeBuf, u32 writeBufSize, u32 programId, CecDataPathType pathType, u32 fileFlag) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x11, 4, 4);
    cmdbuf[1] = writeBufSize;
    cmdbuf[2] = programID;
    cmdbuf[3] = pathType;
    cmdbuf[4] = fileFlag;
    cmdbuf[5] = IPC_Desc_CurProcessId(); // do placeholder
    cmdbuf[6] = 0; // placeholder
    cmdbuf[7] = IPC_Desc_Buffer(writeBufSize, IPC_BUFFER_R);
    cmdbuf[8] = (u32)writeBuf;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;

    return (Result)cmdbuf[1];
}

Result Cec::OpenAndRead(void * readBuf, u32 readBufSize, u32* readSize, u32 programId, CecDataPathType pathType, u32 fileFlag) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x12, 4, 4);
    cmdbuf[1] = readBufSize;
    cmdbuf[2] = programID;
    cmdbuf[3] = pathType;
    cmdbuf[4] = fileFlag;
    cmdbuf[5] = IPC_Desc_CurProcessId(); // do placeholder
    cmdbuf[6] = 0; // placeholder
    cmdbuf[7] = IPC_Desc_Buffer(readBufSize, IPC_BUFFER_W);
    cmdbuf[8] = (u32)readBuf;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;
    ret = (Result)cmdbuf[1];

    if (R_SUCCEEDED(ret)) {
        if (readSize) *readSize = cmdbuf[2];
    }
    return ret;
}

Result Cec::GetEventLog(void* eventLogBuf, u32* end, u32 start, u32 eventLogBufSize) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x1E, 2, 2);
    cmdbuf[1] = start;
    cmdbuf[2] = eventLogBufSize;
    cmdbuf[3] = IPC_Desc_Buffer(eventLogBufSize, IPC_BUFFER_RW);
    cmdbuf[4] = (u32)eventLogBuf;

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;
    ret = (Result)cmdbuf[1];

    if (R_SUCCEEDED(ret)) {
        if (end) *end = cmdbuf[2];
    }
    return ret;
}

Result Cec::GetEventLogStart(u32* start) {
    Result ret;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x1F, 0, 0);

    if (R_FAILED(ret = svcSendSyncRequest(sessionHandle))) return ret;
    ret = (Result)cmdbuf[1];

    if (R_SUCCEEDED(ret)) {
        if (start) *start = cmdbuf[2];
    }
    return ret;
}
} // namespace cec::detail