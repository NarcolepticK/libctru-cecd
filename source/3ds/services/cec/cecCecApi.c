#include "3ds/services/cec/cecCec.h"
#include "3ds/services/cec/cecCecApi.h"
#include "3ds/services/cec/cecCecSys.h"

extern Handle cecdsSessionHandle;
extern int cecdsRefCount;

extern Handle cecduSessionHandle;
extern int cecduRefCount;

Result cecdInit(void) {
    return cecduInit();
}

Result cecdExit(void) {
    return cecduExit();
}

Result cecdOpen(u32 programId, CecDataPathType pathType, u32 flag, u32* size) {
    if (cecdsSessionHandle != 0) {
        return cecdsOpen(programId, pathType, flag, size);
    }

    if (cecduSessionHandle != 0) {
        return cecduOpen(programId, pathType, flag, size);
    }

    return 0xE0810BF8;
}

Result cecdRead(u32* readSize, void* readBuf, u32 readBufSize) {
    if (cecdsSessionHandle != 0) {
        return cecdsRead(readSize, readBuf, readBufSize);
    }

    if (cecduSessionHandle != 0) {
        return cecduRead(readSize, readBuf, readBufSize);
    }

    return 0xE0810BF8;
}

Result cecdReadMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize) {
    if (cecdsSessionHandle != 0) {
        return cecdsReadMessage(programId, isOutBox, msgId, msgIdSize, readSize, readBuf, readBufSize);
    }

    if (cecduSessionHandle != 0) {
        return cecduReadMessage(programId, isOutBox, msgId, msgIdSize, readSize, readBuf, readBufSize);
    }

    return 0xE0810BF8;
}

Result cecdReadMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize, const void* hmacKey) {
    if (cecdsSessionHandle != 0) {
        return cecdsReadMessageWithHmac(programId, isOutBox, msgId, msgIdSize, readSize, readBuf, readBufSize, hmacKey);
    }

    if (cecduSessionHandle != 0) {
        return cecduReadMessageWithHmac(programId, isOutBox, msgId, msgIdSize, readSize, readBuf, readBufSize, hmacKey);
    }

    return 0xE0810BF8;
}

Result cecdWrite(const void* writeBuf, u32 writeBufSize) {
    if (cecdsSessionHandle != 0) {
        return cecdsWrite(writeBuf, writeBufSize);
    }

    if (cecduSessionHandle != 0) {
        return cecduWrite(writeBuf, writeBufSize);
    }

    return 0xE0810BF8;
}

Result cecdWriteMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize) {
    if (cecdsSessionHandle != 0) {
        return cecdsWriteMessage(programId, isOutBox, msgId, msgIdSize, writeBuf, writeBufSize);
    }

    if (cecduSessionHandle != 0) {
        return cecduWriteMessage(programId, isOutBox, msgId, msgIdSize, writeBuf, writeBufSize);
    }

    return 0xE0810BF8;
}

Result cecdWriteMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize, const void* hmacKey) {
    if (cecdsSessionHandle != 0) {
        return cecdsWriteMessageWithHmac(programId, isOutBox, msgId, msgIdSize, writeBuf, writeBufSize, hmacKey);
    }

    if (cecduSessionHandle != 0) {
        return cecduWriteMessageWithHmac(programId, isOutBox, msgId, msgIdSize, writeBuf, writeBufSize, hmacKey);
    }

    return 0xE0810BF8;
}

Result cecdDelete(u32 programId, CecDataPathType pathType, bool isOutBox, const void* msgId, u32 msgIdSize) {
    if (cecdsSessionHandle != 0) {
        return cecdsDelete(programId, pathType, isOutBox, msgId, msgIdSize);
    }

    if (cecduSessionHandle != 0) {
        return cecduDelete(programId, pathType, isOutBox, msgId, msgIdSize);
    }

    return 0xE0810BF8;
}

Result cecdSetData(u32 programId, const void* dataBuf, u32 dataBufSize, u32 option) {
    if (cecdsSessionHandle != 0) {
        return cecdsSetData(programId, dataBuf, dataBufSize, option);
    }

    if (cecduSessionHandle != 0) {
        return cecduSetData(programId, dataBuf, dataBufSize, option);
    }

    return 0xE0810BF8;
}

Result cecdReadData(void* destBuf, u32 destBufSize, u32 option, const void* paramBuf, u32 paramBufSize) {
    if (cecdsSessionHandle != 0) {
        return cecdsReadData(destBuf, destBufSize, option, paramBuf, paramBufSize);
    }

    if (cecduSessionHandle != 0) {
        return cecduReadData(destBuf, destBufSize, option, paramBuf, paramBufSize);
    }

    return 0xE0810BF8;
}

Result cecdStart(CecCommand command) {
    if (cecdsSessionHandle != 0) {
        return cecdsStart(command);
    }

    if (cecduSessionHandle != 0) {
        return cecduStart(command);
    }

    return 0xE0810BF8;
}

Result cecdStop(CecCommand command) {
    if (cecdsSessionHandle != 0) {
        return cecdsStop(command);
    }

    if (cecduSessionHandle != 0) {
        return cecduStop(command);
    }

    return 0xE0810BF8;
}

Result cecdGetCecInfoBuffer(u32 programId, void* buf, u32 bufSize) {
    if (cecdsSessionHandle != 0) {
        return cecdsGetCecInfoBuffer(programId, buf, bufSize);
    }

    if (cecduSessionHandle != 0) {
        return cecduGetCecInfoBuffer(programId, buf, bufSize);
    }

    return 0xE0810BF8;
}

Result cecdGetCecdState(u32* state) {
    if (cecdsSessionHandle != 0) {
        return cecdsGetCecdState(state);
    }

    if (cecduSessionHandle != 0) {
        return cecduGetCecdState(state);
    }

    return 0xE0810BF8;
}

Result cecdGetCecInfoEventHandle(Handle* eventHandle) {
    if (cecdsSessionHandle != 0) {
        return cecdsGetCecInfoEventHandle(eventHandle);
    }

    if (cecduSessionHandle != 0) {
        return cecduGetCecInfoEventHandle(eventHandle);
    }

    return 0xE0810BF8;
}

Result cecdGetChangeStateEventHandle(Handle* eventHandle) {
    if (cecdsSessionHandle != 0) {
        return cecdsGetChangeStateEventHandle(eventHandle);
    }

    if (cecduSessionHandle != 0) {
        return cecduGetChangeStateEventHandle(eventHandle);
    }

    return 0xE0810BF8;
}

Result cecdOpenAndWrite(const void* writeBuf, u32 writeBufSize, u32 programId, CecDataPathType pathType, u32 fileFlag) {
    if (cecdsSessionHandle != 0) {
        return cecdsOpenAndWrite(writeBuf, writeBufSize, programId, pathType, fileFlag);
    }

    if (cecduSessionHandle != 0) {
        return cecduOpenAndWrite(writeBuf, writeBufSize, programId, pathType, fileFlag);
    }

    return 0xE0810BF8;
}

Result cecdOpenAndRead(void* readBuf, u32 readBufSize, u32* readSize, u32 programId, CecDataPathType pathType, u32 fileFlag) {
    if (cecdsSessionHandle != 0) {
        return cecdsOpenAndRead(readBuf, readBufSize, readSize, programId, pathType, fileFlag);
    }

    if (cecduSessionHandle != 0) {
        return cecduOpenAndRead(readBuf, readBufSize, readSize, programId, pathType, fileFlag);
    }

    return 0xE0810BF8;
}

Result cecdGetEventLog(void* eventLogBuf, u32* end, u32 start, u32 size) {
    if (cecdsSessionHandle != 0) {
        return cecdsGetEventLog(eventLogBuf, end, start, size);
    }

    if (cecduSessionHandle != 0) {
        return cecduGetEventLog(eventLogBuf, end, start, size);
    }

    return 0xE0810BF8;
}

Result cecdGetEventLogStart(u32* start) {
    if (cecdsSessionHandle != 0) {
        return cecdsGetEventLogStart(start);
    }

    if (cecduSessionHandle != 0) {
        return cecduGetEventLogStart(start);
    }

    return 0xE0810BF8;
}
