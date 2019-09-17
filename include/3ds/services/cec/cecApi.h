/**
 * @file cecApi.h
 * @brief Top level cec namespace functions.
 */
#pragma once

#include <3ds/types.h>

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
