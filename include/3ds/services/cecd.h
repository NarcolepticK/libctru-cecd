/**
 * @file cecd.h
 * @brief CECD service.
 */
#pragma once

#include <3ds/types.h>
#include <3ds/result.h>
#include <3ds/services/fs.h>

#include "3ds/services/cec/cecApi.h"
#include "3ds/services/cec/cecCec.h"
#include "3ds/services/cec/cecCecApi.h"
#include "3ds/services/cec/cecCecSys.h"

Result cecdInit(void);
void cecdExit(void);

inline Result cecdsInit(void) {
    return cec::detail::InitializeCecControlSys();
}

inline void cecdsExit(void) {
    return cec::detail::FinalizeCecControlSys();
}

inline Result cecduInit(void) {
    return cec::detail::InitializeCecControl();
}

inline void cecduExit(void) {
    return cec::detail::FinalizeCecControl();
}

inline Result cecdOpen(u32 programId, CecDataPathType pathType, u32 flag, u32* size) {
    return cec::detail::Open(programId, pathType, flag, size);
}

inline Result cecdRead(u32* readSize, void* readBuf, u32 readBufSize) {
    return cec::detail::Read(readSize, readBuf, readBufSize);
}

inline Result cecdReadMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize) {
    return cec::detail::ReadMessage(programId, isOutBox, msgId, msgIdSize, readSize, readBuf, readBufSize);
}

inline Result cecdReadMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize, const void* hmacKey) {
    return cec::detail::ReadMessageWithHmac(programId, isOutBox, msgId, msgIdSize, readSize, readBuf, readBufSize, hmacKey);
}

inline Result cecdWrite(const void* writeBuf, u32 writeBufSize) {
    return cec::detail::Write(writeBuf, writeBufSize);
}

inline Result cecdWriteMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize) {
    return cec::detail::WriteMessage(programId, isOutBox, msgId, msgIdSize, writeBuf, writeBufSize);
}

inline Result cecdWriteMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize, const void* hmacKey) {
    return cec::detail::WriteMessageWithHmac(programId, isOutBox, msgId, msgIdSize, writeBuf, writeBufSize, hmacKey);
}

inline Result cecdDelete(u32 programId, CecDataPathType path, bool isOutBox, const void* msgId, u32 msgIdSize) {
    return cec::detail::Delete(programId, path, isOutBox, msgId, msgIdSize);
}

inline Result cecdSetData(u32 programId, const void* dataBuf, u32 dataBufSize, u32 option) {
    return cec::detail::SetData(programId, dataBuf, dataBufSize, option);
}

inline Result cecdReadData(void* destBuf, u32 destBufSize, u32 option, const void* paramBuf, u32 paramBufSize) {
    return cec::detail::ReadData(destBuf, destBufSize, option, paramBuf, paramBufSize);
}

inline Result cecdStart(CecCommand command) {
    return cec::detail::Start(command);
}

inline Result cecdStop(CecCommand command) {
    return cec::detail::Stop(command);
}

inline Result cecdGetCecInfoBuffer(u32 programId, void* buf, u32 bufSize) {
    return cec::detail::GetCecInfoBuffer(programId, buf, bufSize);
}

inline Result cecdGetCecdState(u32* state) {
    return cec::detail::GetCecdState(state);
}

inline Result cecdGetCecInfoEventHandle(Handle* eventHandle) {
    return cec::detail::GetCecInfoEventHandle(eventHandle);
}

inline Result cecdGetChangeStateEventHandle(Handle* eventHandle) {
    return cec::detail::GetChangeStateEventHandle(eventHandle);
}

inline Result cecdOpenAndWrite(const void* writeBuf, u32 writeBufSize, u32 programId, CecDataPathType pathType, u32 fileFlag) {
    return cec::detail::OpenAndWrite(writeBuf, writeBufSize, programId, pathType, fileFlag);
}

inline Result cecdOpenAndRead(void * readBuf, u32 readBufSize, u32* readSize, u32 programId, CecDataPathType pathType, u32 fileFlag) {
    return cec::detail::OpenAndRead(readBuf, readBufSize, readSize, programId, pathType, fileFlag);
}

inline Result cecdGetEventLog(void* eventLogBuf, u32* end, u32 start, u32 size) {
    return cec::detail::GetEventLog(eventLogBuf, end, start, size);
}

inline Result cecdGetEventLogStart(u32* start) {
    return cec::detail::GetEventLogStart(start);
}