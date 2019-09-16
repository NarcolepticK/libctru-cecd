#include <3ds/srv.h>
#include <3ds/svc.h>
#include <3ds/synchronization.h>
#include "3ds/services/cec/cecCec.h"
#include "3ds/services/cec/cecCecApi.h"
#include "3ds/services/cec/cecCecSys.h"

namespace cec::detail {

Result InitializeCecControl(void) {
    Result ret;

    if (AtomicPostIncrement(&cec::detail::Cec::refCount)) return 0;

    ret = srvGetServiceHandle(&cec::detail::Cec::sessionHandle, "cecd:u");
    if(R_FAILED(ret)) AtomicDecrement(&cec::detail::Cec::refCount);

    return ret;
}

Result InitializeCecControlSys(void) {
    Result ret;

    if (AtomicPostIncrement(&cec::detail::CecSys::refCount)) return 0;

    ret = srvGetServiceHandle(&cec::detail::CecSys::sessionHandle, "cecd:s");
    if(R_FAILED(ret)) AtomicDecrement(&cec::detail::CecSys::refCount);

    return ret;
}

Result FinalizeCecControl(void) {
    if (AtomicDecrement(&cec::detail::Cec::refCount)) return;
    svcCloseHandle(cec::detail::Cec::sessionHandle);
}

Result FinalizeCecControlSys(void) {
    if (AtomicDecrement(&cec::detail::CecSys::refCount)) return;
    svcCloseHandle(cec::detail::CecSys::sessionHandle);
}

Result Open(u32 programId, CecDataPathType pathType, u32 flag, u32* size) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::Open(programId, pathType, flag, size);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::Open(programId, pathType, flag, size);
    }

    return 0xE0810BF8;
}

Result Read(u32* readSize, void* readBuf, u32 readBufSize) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::Read(readSize, readBuf, readBufSize);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::Read(readSize, readBuf, readBufSize);
    }

    return 0xE0810BF8;
}

Result ReadMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::ReadMessage(programId, isOutBox, msgId, msgIdSize, readSize, readBuf, readBufSize);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::ReadMessage(programId, isOutBox, msgId, msgIdSize, readSize, readBuf, readBufSize);
    }

    return 0xE0810BF8;
}

Result ReadMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, u32* readSize, void* readBuf, u32 readBufSize, const void* hmacKey) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::ReadMessageWithHmac(programId, isOutBox, msgId, msgIdSize, readSize, readBuf, readBufSize, hmacKey);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::ReadMessageWithHmac(programId, isOutBox, msgId, msgIdSize, readSize, readBuf, readBufSize, hmacKey);
    }

    return 0xE0810BF8;
}

Result Write(const void* writeBuf, u32 writeBufSize) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::Write(writeBuf, writeBufSize);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::Write(writeBuf, writeBufSize);
    }

    return 0xE0810BF8;
}

Result WriteMessage(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::WriteMessage(programId, isOutBox, msgId, msgIdSize, writeBuf, writeBufSize);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::WriteMessage(programId, isOutBox, msgId, msgIdSize, writeBuf, writeBufSize);
    }

    return 0xE0810BF8;
}

Result WriteMessageWithHmac(u32 programId, bool isOutBox, const void* msgId, u32 msgIdSize, const void* writeBuf, u32 writeBufSize, const void* hmacKey) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::WriteMessageWitHmac(programId, isOutBox, msgId, msgIdSize, writeBuf, writeBufSize, hmacKey);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::WriteMessageWithHmac(programId, isOutBox, msgId, msgIdSize, writeBuf, writeBufSize, hmacKey);
    }

    return 0xE0810BF8;
}

Result Delete(u32 programId, CecDataPathType pathType, bool isOutBox, const void* msgId, u32 msgIdSize) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::Delete(programId, pathType, isOutBox, msgId, msgIdSize);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::Delete(programId, pathType, isOutBox, msgId, msgIdSize);
    }

    return 0xE0810BF8;
}

Result SetData(u32 programId, const void* dataBuf, u32 dataBufSize, u32 option) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::SetData(programId, dataBuf, dataBufSize, option);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::SetData(programId, dataBuf, dataBufSize, option);
    }

    return 0xE0810BF8;
}

Result ReadData(void* destBuf, u32 destBufSize, u32 option, const void* paramBuf, u32 paramBufSize) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::ReadData(destBuf, destBufSize, option, paramBuf, paramBufSize);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::ReadData(destBuf, destBufSize, option, paramBuf, paramBufSize);
    }

    return 0xE0810BF8;
}

Result Start(CecCommand command) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::Start(command);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::Start(command);
    }

    return 0xE0810BF8;
}

Result Stop(CecCommand command) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::Stop(command);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::Stop(command);
    }

    return 0xE0810BF8;
}

Result GetCecInfoBuffer(u32 programId, void* buf, u32 bufSize) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::GetCecInfoBuffer(programId, buf, bufSize);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::GetCecInfoBuffer(programId, buf, bufSize);
    }

    return 0xE0810BF8;
}

Result GetCecdState(u32* state) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::GetCecdState(state);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::GetCecdState(state);
    }

    return 0xE0810BF8;
}

Result GetCecInfoEventHandle(Handle* eventHandle) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::GetCecInfoEventHandle(eventHandle);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::GetCecInfoEventHandle(eventHandle);
    }

    return 0xE0810BF8;
}

Result GetChangeStateEventHandle(Handle* eventHandle) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::GetChangeStateEventHandle(eventHandle);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::GetChangeStateEventHandle(eventHandle);
    }

    return 0xE0810BF8;
}

Result OpenAndWrite(const void* writeBuf, u32 writeBufSize, u32 programId, CecDataPathType pathType, u32 fileFlag) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::OpenAndWrite(writeBuf, writeBufSize, programId, pathType, fileFlag);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::OpenAndWrite(writeBuf, writeBufSize, programId, pathType, fileFlag);
    }

    return 0xE0810BF8;
}

Result OpenAndRead(void* readBuf, u32 readBufSize, u32* readSize, u32 programId, CecDataPathType pathType, u32 fileFlag) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::OpenAndRead(readBuf, readBufSize, readSize, programId, pathType, fileFlag);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::OpenAndRead(readBuf, readBufSize, readSize, programId, pathType, fileFlag);
    }

    return 0xE0810BF8;
}

Result GetEventLog(void* eventLogBuf, u32* end, u32 start, u32 size) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::GetEventLog(eventLogBuf, end, start, size);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::GetEventLog(eventLogBuf, end, start, size);
    }

    return 0xE0810BF8;
}

Result GetEventLogStart(u32* start) {
    if (cec::detail::CecSys::sessionHandle != 0) {
        return cec::detail::CecSys::GetEventLogStart(start);
    }

    if (cec::detail::Cec::sessionHandle != 0) {
        return cec::detail::Cec::GetEventLogStart(start);
    }

    return 0xE0810BF8;
}
} // namespace cec::detail