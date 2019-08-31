# libctru-cecd
CECD service code for libctru

Requires existing devkitPro install

This aims to fill in the missing service code, and enable [CECTool](https://github.com/NarcolepticK/CECTool) to function.

When it is more complete it should be added into libctru, but in the meantime this will do.

### CECD:u Functions
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
- GetCecdState
- GetCecInfoEventHandle
- GetChangeStateEventHandle
- OpenAndWrite
- OpenAndRead

### Partially Supported
- GetCecInfoBuffer
- GetEventLog
- GetEventLogStart
