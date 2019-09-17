/**
 * @file cecCecApi.h
 * @brief Detail level cec namespace functions.
 */
#pragma once

#include <3ds/types.h>
#include <3ds/result.h>
#include "3ds/services/cec/cecApi.h"

Result cecdInit(void);
Result cecdExit(void);

Result cecdOpen(u32 programId, CecDataPathType pathType, u32 flag, u32* size);

Result cecdRead(u32* readSize, void* readBuf, u32 readBufSize);
Result cecdReadMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize);
Result cecdReadMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize, const void* hmacKey);

Result cecdWrite(const void* writeBuf, u32 writeBufSize);
Result cecdWriteMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize);
Result cecdWriteMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize, const void* hmacKey);

Result cecdDelete(u32 programId, CecDataPathType pathType, bool isOutBox, const void* msgId, u32 msgIdSize);

Result cecdSetData(u32 programId, const void* dataBuf, u32 dataBufSize, u32 option);
Result cecdReadData(void* destBuf, u32 destBufSize, u32 option, const void* paramBuf, u32 paramBufSize);

Result cecdStart(CecCommand command);
Result cecdStop(CecCommand command);

Result cecdGetCecInfoBuffer(u32 programId, void* buf, u32 bufSize);
Result cecdGetCecdState(u32* state);
Result cecdGetCecInfoEventHandle(Handle* eventHandle);
Result cecdGetChangeStateEventHandle(Handle* eventHandle);

Result cecdOpenAndWrite(const void* writeBuf, u32 writeBufSize, u32 programId, CecDataPathType pathType, u32 fileFlag);
Result cecdOpenAndRead(void * readBuf, u32 readBufSize, u32* readSize, u32 programId, CecDataPathType pathType, u32 fileFlag);

Result cecdGetEventLog(void* eventLogBuf, u32* end, u32 start, u32 size);
Result cecdGetEventLogStart(u32* start);
