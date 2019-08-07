/**
 * @file cecd.h
 * @brief CECD service.
 */
#pragma once

#include <3ds/types.h>
#include <3ds/result.h>
#include <3ds/services/fs.h>

/// Enum value that corresponds with a specific file or directory
typedef enum {
    CEC_PATH_MBOX_LIST = 1,    /// data:/CEC/MBoxList____
    CEC_PATH_MBOX_INFO = 2,    /// data:/CEC/<id>/MBoxInfo____
    CEC_PATH_INBOX_INFO = 3,   /// data:/CEC/<id>/InBox___/BoxInfo_____
    CEC_PATH_OUTBOX_INFO = 4,  /// data:/CEC/<id>/OutBox__/BoxInfo_____
    CEC_PATH_OUTBOX_INDEX = 5, /// data:/CEC/<id>/OutBox__/OBIndex_____
    CEC_PATH_INBOX_MSG = 6,    /// data:/CEC/<id>/InBox___/_<message_id>
    CEC_PATH_OUTBOX_MSG = 7,   /// data:/CEC/<id>/OutBox__/_<message_id>
    CEC_PATH_ROOT_DIR = 10,    /// data:/CEC
    CEC_PATH_MBOX_DIR = 11,    /// data:/CEC/<id>
    CEC_PATH_INBOX_DIR = 12,   /// data:/CEC/<id>/InBox___
    CEC_PATH_OUTBOX_DIR = 13,  /// data:/CEC/<id>/OutBox__
    CEC_MBOX_DATA = 100,       /// data:/CEC/<id>/MBoxData.0<i-100>
    CEC_MBOX_ICON = 101,       /// data:/CEC/<id>/MBoxData.001
    CEC_MBOX_TITLE = 110,      /// data:/CEC/<id>/MBoxData.010
    CEC_MBOX_PROGRAM_ID = 150  /// data:/CEC/<id>/MBoxData.050
} CecDataPathType;

/// Commands used with Start and Stop
typedef enum {
    CEC_COMMAND_NONE = 0,
    CEC_COMMAND_START = 1,
    CEC_COMMAND_RESET_START = 2,
    CEC_COMMAND_READYSCAN = 3,
    CEC_COMMAND_READYSCANWAIT = 4,
    CEC_COMMAND_STARTSCAN = 5,
    CEC_COMMAND_RESCAN = 6,
    CEC_COMMAND_NDM_RESUME = 7,
    CEC_COMMAND_NDM_SUSPEND = 8,
    CEC_COMMAND_NDM_SUSPEND_IMMEDIATE = 9,
    CEC_COMMAND_STOPWAIT = 10,
    CEC_COMMAND_STOP = 11,
    CEC_COMMAND_STOP_FORCE = 12,
    CEC_COMMAND_STOP_FORCE_WAIT = 13,
    CEC_COMMAND_RESET_FILTER = 14,
    CEC_COMMAND_DAEMON_STOP = 15,
    CEC_COMMAND_DAEMON_START = 16,
    CEC_COMMAND_EXIT = 17,
    CEC_COMMAND_OVER_BOSS = 18,
    CEC_COMMAND_OVER_BOSS_FORCE = 19,
    CEC_COMMAND_OVER_BOSS_FORCE_WAIT = 20,
    CEC_COMMAND_END = 21
} CecCommand;

typedef enum {
    CEC_READ = BIT(1),
    CEC_WRITE = BIT(2),
    CEC_CREATE = BIT(3),
    CEC_CHECK = BIT(4)
} CecOpenFlag;

typedef enum {
    CEC_STATE_NONE = 0,
    CEC_STATE_INIT = 1,
    CEC_STATE_WIRELESS_PARAM_SETUP = 2,
    CEC_STATE_WIRELESS_READY = 3,
    CEC_STATE_WIRELESS_START_CONFIG = 4,
    CEC_STATE_SCAN = 5,
    CEC_STATE_SCANNING = 6,
    CEC_STATE_CONNECT = 7,
    CEC_STATE_CONNECTING = 8,
    CEC_STATE_CONNECTED = 9,
    CEC_STATE_CONNECT_TCP = 10,
    CEC_STATE_CONNECTING_TCP = 11,
    CEC_STATE_CONNECTED_TCP = 12,
    CEC_STATE_NEGOTIATION = 13,
    CEC_STATE_SEND_RECV_START = 14,
    CEC_STATE_SEND_RECV_INIT = 15,
    CEC_STATE_SEND_READY = 16,
    CEC_STATE_RECEIVE_READY = 17,
    CEC_STATE_RECEIVE = 18,
    CEC_STATE_CONNECTION_FINISH_TCP = 19,
    CEC_STATE_CONNECTION_FINISH = 20,
    CEC_STATE_SEND_POST = 21,
    CEC_STATE_RECEIVE_POST = 22,
    CEC_STATE_FINISHING = 23,
    CEC_STATE_FINISH = 24,
    CEC_STATE_OVER_BOSS = 25,
    CEC_STATE_IDLE = 26
} CecState;

typedef struct {
    u8 data[8];
} CecMessageId;

typedef struct {
    u16 magic; // 0x6262 'bb'
    u16 padding;
    u32 fileSize;
    u32 maxBoxSize;
    u32 boxSize;
    u32 maxNumMessages;
    u32 numMessages;
    u32 maxBatchSize;
    u32 maxMessageSize;
} CecBoxInfoHeader;

typedef struct
{
    u16 magic; // 0x6868 'hh'
    u16 padding;
    u32 version;
    u32 numBoxes;
    u8 boxNames[24][16]; // 12 used, but space for 24
} CecMBoxListHeader;


typedef struct {
    u16 magic; // 0x6767 'gg'
    u16 padding;
    u32 numMessages;
} CecOBIndexHeader;

typedef struct {
    u32 year;
    u8 month;
    u8 day;
    u8 weekDay;
    u8 hour;
    u8 minute;
    u8 second;
    u16 millisecond;
} CecTimestamp;

typedef struct {
    u16 magic; // 0x6363 'cc'
    u16 padding1;
    u32 programId;
    u32 privateId;
    u8 flag;
    u8 flag2;
    u16 padding2;
    u8 hmacKey[32];
    u32 padding3;
    CecTimestamp lastAccessed;
    u32 padding4;
    CecTimestamp lastReceived;
    u32 padding5;
    CecTimestamp unknownTime;
} CecMBoxInfoHeader;

typedef struct {
    u16 magic; // 0x6060 ``
    u16 padding;
    u32 messageSize;
    u32 totalHeaderSize;
    u32 bodySize;
    u32 titleId;
    u32 titleId2;
    u32 batchId;
    u32 unknown_1;
    u8 messageId[8];
    u32 messageVersion;
    u8 messageId2[8];
    u8 flags;
    u8 sendMethod;
    u8 unopened;
    u8 newFlag;
    u64 senderId;
    u64 senderId2;
    CecTimestamp sent;
    CecTimestamp received;
    CecTimestamp created;
    u8 sendCount;
    u8 forwardCount;
    u16 userData;
} CecMessageHeader;

/// Initializes CECD
Result cecdInit(void);

/// Exits CECD
void cecdExit(void);

/**
 * CECD::Open service function
 *  Inputs:
 *      0 : Header Code[0x000100C2]
 *      1 : NCCH Program ID
 *      2 : Path type
 *      3 : File open flag
 *      4 : Descriptor for process ID
 *      5 : Placeholder for process ID
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *      2 : File size
 **/
Result CECDU_Open(u32 programID, CecDataPathType path, u32 flag, u32* size);

/**
 * CECD::Read service function
 *  Inputs:
 *      0 : Header Code[0x00020042]
 *      1 : Buffer size (unused)
 *      2 : Descriptor for mapping a write-only buffer in the target process
 *      3 : Buffer address
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *      2 : Read size
 *      3 : Descriptor for mapping a write-only buffer in the target process
 *      4 : Buffer address
 **/
Result CECDU_Read(u32 bufferSize, void* buffer, u32* readSize);

/**
 * CECD::ReadMessage service function
 *  Inputs:
 *      0 : Header Code[0x00030104]
 *      1 : NCCH Program ID
 *      2 : bool is_outbox
 *      3 : Message ID size (unused, always 8)
 *      4 : Buffer size (unused)
 *      5 : Descriptor for mapping a read-only buffer in the target process
 *      6 : Message ID address
 *      7 : Descriptor for mapping a write-only buffer in the target process
 *      8 : Buffer address
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *      2 : Read size
 *      3 : Descriptor for mapping a read-only buffer in the target process
 *      4 : Message ID address
 *      5 : Descriptor for mapping a write-only buffer in the target process
 *      6 : Buffer address
 **/
Result CECDU_ReadMessage(u32 programID, bool outBox, u32 idSize, u32 bufferSize, const void* messageID, void* buffer, u32* readSize);

/**
 * CECD::ReadMessageWithHMAC service function
 *  Inputs:
 *      0 : Header Code[0x00040106]
 *      1 : NCCH Program ID
 *      2 : bool is_outbox
 *      3 : Message ID size(unused, always 8)
 *      4 : Buffer size(unused)
 *      5 : Descriptor for mapping a read-only buffer in the target process
 *      6 : Message ID address
 *      7 : Descriptor for mapping a read-only buffer in the target process
 *      8 : HMAC key address
 *      9 : Descriptor for mapping a write-only buffer in the target process
 *     10 : Buffer address
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *      2 : Read size
 *      3 : Descriptor for mapping a read-only buffer in the target process
 *      4 : Message ID address
 *      5 : Descriptor for mapping a read-only buffer in the target process
 *      6 : HMAC key address
 *      7 : Descriptor for mapping a write-only buffer in the target process
 *      8 : Buffer address
 **/
Result CECDU_ReadMessageWithHMAC(u32 programID, bool outBox, u32 idSize, u32 bufferSize, const void* messageID, const void* hmacKey, void* buffer, u32* readSize);

/**
 * CECD::Write service function
 *  Inputs:
 *      0 : Header Code[0x00050042]
 *      1 : Buffer size(unused)
 *      2 : Descriptor for mapping a read-only buffer in the target process
 *      3 : Buffer address
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *      2 : Descriptor for mapping a read-only buffer in the target process
 *      3 : Buffer address
 **/
Result CECDU_Write(u32 bufferSize, const void* buffer);

/**
 * CECD::WriteMessage service function
 *  Inputs:
 *      0 : Header Code[0x00060104]
 *      1 : NCCH Program ID
 *      2 : bool is_outbox
 *      3 : Message ID size(unused, always 8)
 *      4 : Buffer size(unused)
 *      5 : Descriptor for mapping a read-only buffer in the target process
 *      6 : Buffer address
 *      7 : Descriptor for mapping a read/write buffer in the target process
 *      8 : Message ID address
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *      2 : Descriptor for mapping a read-only buffer in the target process
 *      3 : Buffer address
 *      4 : Descriptor for mapping a read/write buffer in the target process
 *      5 : Message ID address
 **/
Result CECDU_WriteMessage(u32 programID, bool outBox, u32 idSize, u32 bufferSize, const void* buffer, const void* messageID);

/**
 * CECD::WriteMessageWithHMAC service function
 *  Inputs:
 *      0 : Header Code[0x00070106]
 *      1 : NCCH Program ID
 *      2 : bool is_outbox
 *      3 : Message ID size(unused, always 8)
 *      4 : Buffer size(unused)
 *      5 : Descriptor for mapping a read-only buffer in the target process
 *      6 : Buffer address
 *      7 : Descriptor for mapping a read-only buffer in the target process
 *      8 : HMAC key address
 *      9 : Descriptor for mapping a read/write buffer in the target process
 *     10 : Message ID address
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *      2 : Descriptor for mapping a read-only buffer in the target process
 *      3 : Buffer address
 *      4 : Descriptor for mapping a read-only buffer in the target process
 *      5 : HMAC key address
 *      6 : Descriptor for mapping a read/write buffer in the target process
 *      7 : Message ID address
 **/
Result CECDU_WriteMessageWithHMAC(u32 programID, bool outBox, u32 idSize, u32 bufferSize, const void* buffer, const void* hmac, const void* messageID);

/**
 * CECD::Delete service function
 *  Inputs:
 *      0 : Header Code[0x00080102]
 *      1 : NCCH Program ID
 *      2 : Path type
 *      3 : bool is_outbox
 *      4 : Message ID size (unused)
 *      5 : Descriptor for mapping a read-only buffer in the target process
 *      6 : Message ID address
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *      2 : Descriptor for mapping a read-only buffer in the target process
 *      3 : Message ID address
 **/
Result CECDU_Delete(u32 programID, CecDataPathType path, bool outBox, u32 idSize, const void* messageID);

/**
 * CECD::SetData service function
 *  Inputs:
 *      0 : Header Code[0x000900C2]
 *      1 : NCCH Program ID
 *      2 : Buffer Size
 *      3 : Option
 *      4 : Descriptor for mapping a read-only buffer in the target process
 *      5 : Buffer address
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *      2 : Descriptor for mapping a read-only buffer in the target process
 *      3 : Buffer address
 **/
Result CECDU_SetData(u32 programID, u32 bufferSize, u32 option, const void* buffer);

/**
 * CECD::ReadData service function
 *  Inputs:
 *      0 : Header Code[0x000A00C4]
 *      1 : Destination buffer size (unused)
 *      2 : Info type
 *      3 : Param buffer size (unused)
 *      4 : Descriptor for mapping a read-only buffer in the target process
 *      5 : Param buffer address
 *      6 : Descriptor for mapping a write-only buffer in the target process
 *      7 : Destination buffer address
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *      2 : Descriptor for mapping a read-only buffer in the target process
 *      3 : Param buffer address
 *      4 : Descriptor for mapping a write-only buffer in the target process
 *      5 : Destination buffer address
 **/
Result CECDU_ReadData(u32 destBufferSize, u32 infoType, u32 paramBufferSize, const void* paramBuffer, void* destBuffer);

/**
 * CECD::Start service function
 *  Inputs:
 *      0 : Header Code[0x000B0040]
 *      1 : Command
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 **/
Result CECDU_Start(CecCommand command);

/**
 * CECD::Stop service function
 *  Inputs:
 *      0 : Header Code[0x000C0040]
 *      1 : Command
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 **/
Result CECDU_Stop(CecCommand command);

/**
 * CECD::GetCecInfoBuffer service function
 *  Inputs:
 *      0 : Header Code[0x000D0082]
 *      1 : Buffer size
 *      2 : unknown
 *      3 : Descriptor for mapping a write-only buffer in the target process
 *      4 : Destination buffer address
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *    2-3 : MappedBuffer
 **/
Result CECDU_GetCecInfoBuffer(u32 bufferSize, u32 unknown, void* buffer);


/**
 * GetCecdState service function
 *  Inputs:
 *      0: Header Code[0x000E0000]
 *  Outputs:
 *      1: ResultCode
 *      2: CecdState
 **/
Result CECDU_GetCecdState(u32* state);

/**
 * GetCecInfoEventHandle service function
 *  Inputs:
 *      0: Header Code[0x000F0000]
 *  Outputs:
 *      1: ResultCode
 *      3: Event Handle
 **/
Result CECDU_GetCecInfoEventHandle(Handle* event);

/**
 * GetChangeStateEventHandle service function
 *  Inputs:
 *      0: Header Code[0x00100000]
 *  Outputs:
 *      1: ResultCode
 *      3: Event Handle
 **/
Result CECDU_GetChangeStateEventHandle(Handle* event);

/**
 * CECD::OpenAndWrite service function
 *  Inputs:
 *      0 : Header Code[0x00110104]
 *      1 : Buffer size (unused)
 *      2 : NCCH Program ID
 *      3 : Path type
 *      4 : File open flag
 *      5 : Descriptor for process ID
 *      6 : Placeholder for process ID
 *      7 : Descriptor for mapping a read-only buffer in the target process
 *      8 : Buffer address
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *      2 : Descriptor for mapping a read-only buffer in the target process
 *      3 : Buffer address
 **/
Result CECDU_OpenAndWrite(u32 bufferSize, u32 programID, CecDataPathType path, u32 flag, const void* buffer);

/**
 * CECD::OpenAndRead service function
 *  Inputs:
 *      0 : Header Code[0x00120104]
 *      1 : Buffer size (unused)
 *      2 : NCCH Program ID
 *      3 : Path type
 *      4 : File open flag
 *      5 : Descriptor for process ID
 *      6 : Placeholder for process ID
 *      7 : Descriptor for mapping a write-only buffer in the target process
 *      8 : Buffer address
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *      2 : Toal bytes read
 *      3 : Descriptor for mapping a write-only buffer in the target process
 *      4 : Buffer address
 **/
Result CECDU_OpenAndRead(u32 bufferSize, u32 programID, CecDataPathType path, u32 flag, void* buffer, u32* readSize);

/**
 * CECD::GetEventLog service function
 *  Inputs:
 *      0 : Header Code[0x001E0082]
 *      1 : unknown
 *      2 : unknown
 *      3 : buffer descriptor
 *      4 : buffer address
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *      2 : unknown
 **/
Result CECDU_GetEventLog(u32 unknown, u32 unknown2, void* buffer, u32* unknownRet);

/**
 * CECD::GetEventLogStart service function
 *  Inputs:
 *      0 : Header Code[0x001F0000]
 *  Outputs:
 *      1 : Result of function, 0 on success, otherwise error code
 *      2 : unknown
 **/
Result CECDU_GetEventLogStart(u32* unknownRet);