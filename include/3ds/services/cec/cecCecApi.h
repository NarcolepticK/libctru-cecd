/**
 * @file cecCecApi.h
 * @brief Detail level cec namespace functions.
 */
#pragma once

#include <3ds/result.h>
#include <3ds/types.h>
#include "3ds/services/cec/cecApi.h"

namespace cec::detail {

Result InitializeCecControl(void);
Result InitializeCecControlSys(void);
Result FinalizeCecControl(void);
Result FinalizeCecControlSys(void);

Result Open(u32 programId, CecDataPathType pathType, u32 flag, u32* size);

Result Read(u32* readSize, void* readBuf, u32 readBufSize);
Result ReadMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize);
Result ReadMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize, const void* hmacKey);

Result Write(const void* writeBuf, u32 writeBufSize);
Result WriteMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize);
Result WriteMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize, const void* hmacKey);

Result Delete(u32 programId, CecDataPathType pathType, bool isOutBox, const void* msgId, u32 msgIdSize);

Result SetData(u32 programId, const void* dataBuf, u32 dataBufSize, u32 option);
Result ReadData(void* destBuf, u32 destBufSize, u32 option, const void* paramBuf, u32 paramBufSize);

Result Start(CecCommand command);
Result Stop(CecCommand command);

Result GetCecInfoBuffer(u32 programId, void* buf, u32 bufSize);
Result GetCecdState(u32* state);
Result GetCecInfoEventHandle(Handle* eventHandle);
Result GetChangeStateEventHandle(Handle* eventHandle);

Result OpenAndWrite(const void* writeBuf, u32 writeBufSize, u32 programId, CecDataPathType pathType, u32 fileFlag);
Result OpenAndRead(void * readBuf, u32 readBufSize, u32* readSize, u32 programId, CecDataPathType pathType, u32 fileFlag);

Result GetEventLog(void* eventLogBuf, u32* end, u32 start, u32 size);
Result GetEventLogStart(u32* start);
} // namespace cec::detail