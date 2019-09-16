/**
 * @file cecCec.h
 * @brief Detail level Cec ipc functions.
 */
#pragma once

#include <3ds/result.h>
#include <3ds/types.h>
#include "3ds/services/cec/cecApi.h"

namespace cec::detail {

class Cec {
public:
    Cec();

    static Result Open(u32 programId, CecDataPathType pathType, u32 flag, u32* size);

    static Result Read(u32* readSize, void* readBuf, u32 readBufSize);
    static Result ReadMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize);
    static Result ReadMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize, const void* hmacKey);

    static Result Write(const void* writeBuf, u32 writeBufSize);
    static Result WriteMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize);
    static Result WriteMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize, const void* hmacKey);

    static Result Delete(u32 programId, CecDataPathType pathType, bool isOutBox, const void* msgId, u32 msgIdSize);

    static Result SetData(u32 programId, const void* dataBuf, u32 dataBufSize, u32 option);
    static Result ReadData(void* destBuf, u32 destBufSize, u32 option, const void* paramBuf, u32 paramBufSize);

    static Result Start(CecCommand command);
    static Result Stop(CecCommand command);

    static Result GetCecInfoBuffer(u32 programId, void* buf, u32 bufSize);
    static Result GetCecdState(u32* state);
    static Result GetCecInfoEventHandle(Handle* eventHandle);
    static Result GetChangeStateEventHandle(Handle* eventHandle);

    static Result OpenAndWrite(const void* writeBuf, u32 writeBufSize, u32 programId, CecDataPathType pathType, u32 fileFlag);
    static Result OpenAndRead(void * readBuf, u32 readBufSize, u32* readSize, u32 programId, CecDataPathType pathType, u32 fileFlag);

    static Result GetEventLog(void* eventLogBuf, u32* end, u32 start, u32 eventLogBufSize);
    static Result GetEventLogStart(u32* start);

public:
    static Handle sessionHandle;
    static int refCount;
} // class Cec
} // namespace cec::detail