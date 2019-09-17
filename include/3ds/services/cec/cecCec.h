/**
 * @file cecCec.h
 * @brief Detail level Cec ipc functions.
 */
#pragma once

#include <3ds/types.h>
#include <3ds/result.h>
#include "3ds/services/cec/cecApi.h"

Result cecduInit(void);
Result cecduExit(void);

Result cecduOpen(u32 programId, CecDataPathType pathType, u32 flag, u32* size);

Result cecduRead(u32* readSize, void* readBuf, u32 readBufSize);
Result cecduReadMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize);
Result cecduReadMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize, const void* hmacKey);

Result cecduWrite(const void* writeBuf, u32 writeBufSize);
Result cecduWriteMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize);
Result cecduWriteMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize, const void* hmacKey);

Result cecduDelete(u32 programId, CecDataPathType pathType, bool isOutBox, const void* msgId, u32 msgIdSize);

Result cecduSetData(u32 programId, const void* dataBuf, u32 dataBufSize, u32 option);
Result cecduReadData(void* destBuf, u32 destBufSize, u32 option, const void* paramBuf, u32 paramBufSize);

Result cecduStart(CecCommand command);
Result cecduStop(CecCommand command);

Result cecduGetCecInfoBuffer(u32 programId, void* buf, u32 bufSize);
Result cecduGetCecdState(u32* state);
Result cecduGetCecInfoEventHandle(Handle* eventHandle);
Result cecduGetChangeStateEventHandle(Handle* eventHandle);

Result cecduOpenAndWrite(const void* writeBuf, u32 writeBufSize, u32 programId, CecDataPathType pathType, u32 fileFlag);
Result cecduOpenAndRead(void * readBuf, u32 readBufSize, u32* readSize, u32 programId, CecDataPathType pathType, u32 fileFlag);

Result cecduGetEventLog(void* eventLogBuf, u32* end, u32 start, u32 eventLogBufSize);
Result cecduGetEventLogStart(u32* start);
