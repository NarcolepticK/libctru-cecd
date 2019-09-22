# libctru-cecd
CECD service code for libctru

## Setup
Requires existing devkitPro install.

Add **libctru-cecd/source/3ds/services/cec** to your makefile SOURCES, and **libctru-cecd/include/3ds/services/cec** and **libctru-cecd/include/** to your INCLUDES to compile. Then **#include "3ds/services/cecd.h"** to start using.

## Goal
This aims to fill in the missing service code, and enable [CECTool](https://github.com/NarcolepticK/CECTool) to function.

When it is more complete it should be added into libctru, but in the meantime this will do.

## Supported Functions
- **cecd:u**
  - Open
  - Read
  - ReadMessage
  - ReadMessageWithHMAC
  - Write
  - WriteMessage
  - WriteMessageWithHMAC
  - Delete
  - SetData
  - ReadData
  - Start
  - Stop
  - GetCecInfoBuffer
  - GetCecdState
  - GetCecInfoEventHandle
  - GetChangeStateEventHandle
  - OpenAndWrite
  - OpenAndRead
  - GetEventLog
  - GetEventLogStart

## Todo
- Implement
  - cecd:ndm
  - cecd:s/CecSys
  - CecControl
  - CecControlSys
  - MessageId
  - Message
  - MessageBox
  - And whatever else I may still find

## Usage
`cecdInit()` and `cecdExit()` must be called to initialize and finalize CecControl. They default to using the cecd:u service.

### Api calls available:
```
cecdInit(void);
cecdExit(void);

cecdOpen(programId, pathType, flag, size);

cecdRead(readSize, readBuf, readBufSize);
cecdReadMessage(programId, isOutBox, msgId, msgIdSize, readSize, readBuf, readBufSize);
cecdReadMessageWithHmac(programId, isOutBox, msgId, msgIdSize, readSize, readBuf, readBufSize, hmacKey);

cecdWrite(writeBuf, writeBufSize);
cecdWriteMessage(programId, isOutBox, msgId, msgIdSize, writeBuf, writeBufSize);
cecdWriteMessageWithHmac(programId, isOutBox, msgId, msgIdSize, writeBuf, writeBufSize, hmacKey);

cecdDelete(programId, pathType, isOutBox, msgId, msgIdSize);

cecdSetData(programId, dataBuf, dataBufSize, option);
cecdReadData(destBuf, destBufSize, option, paramBuf, paramBufSize);

cecdStart(command);
cecdStop(command);

cecdGetCecInfoBuffer(programId, buf, bufSize);
cecdGetCecdState(state);
cecdGetCecInfoEventHandle(eventHandle);
cecdGetChangeStateEventHandle(eventHandle);

cecdOpenAndWrite(writeBuf, writeBufSize, programId, pathType, fileFlag);
cecdOpenAndRead(readBuf, readBufSize, readSize, programId, pathType, fileFlag);

cecdGetEventLog(eventLogBuf, end, start, size);
cecdGetEventLogStart(start);
```
