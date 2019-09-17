/**
 * @file cecCecSys.h
 * @brief Detail level CecSys ipc functions.
 */
#pragma once

#include <3ds/types.h>
#include <3ds/result.h>
#include "3ds/services/cec/cecApi.h"

Result cecdsInit(void);
Result cecdsExit(void);

Result cecdsOpen(u32 programId, CecDataPathType pathType, u32 flag, u32* size);

Result cecdsRead(u32* readSize, void* readBuf, u32 readBufSize);
Result cecdsReadMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize);
Result cecdsReadMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize, const void* hmacKey);

Result cecdsWrite(const void* writeBuf, u32 writeBufSize);
Result cecdsWriteMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize);
Result cecdsWriteMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize, const void* hmacKey);

Result cecdsDelete(u32 programId, CecDataPathType pathType, bool isOutBox, const void* msgId, u32 msgIdSize);

Result cecdsSetData(u32 programId, const void* dataBuf, u32 dataBufSize, u32 option);
Result cecdsReadData(void* destBuf, u32 destBufSize, u32 option, const void* paramBuf, u32 paramBufSize);

Result cecdsStart(CecCommand command);
Result cecdsStop(CecCommand command);

Result cecdsGetCecInfoBuffer(u32 programId, void* buf, u32 bufSize);
Result cecdsGetCecdState(u32* state);
Result cecdsGetCecInfoEventHandle(Handle* eventHandle);
Result cecdsGetChangeStateEventHandle(Handle* eventHandle);

Result cecdsOpenAndWrite(const void* writeBuf, u32 writeBufSize, u32 programId, CecDataPathType pathType, u32 fileFlag);
Result cecdsOpenAndRead(void * readBuf, u32 readBufSize, u32* readSize, u32 programId, CecDataPathType pathType, u32 fileFlag);

Result cecdsGetEventLog(void* eventLogBuf, u32* end, u32 start, u32 size);
Result cecdsGetEventLogStart(u32* start);
