/**
 * @file cecdu.h
 * @brief CECD:u service.
 */
#pragma once

#include <3ds/types.h>
#include <3ds/result.h>
#include <3ds/services/fs.h>

/// Enum value that corresponds with a specific file or directory
typedef enum {
    CEC_PATH_MBOX_LIST = 1,
    CEC_PATH_MBOX_INFO = 2,
    CEC_PATH_INBOX_INFO = 3,
    CEC_PATH_OUTBOX_INFO = 4,
    CEC_PATH_OUTBOX_INDEX = 5,
    CEC_PATH_INBOX_MSG = 6,
    CEC_PATH_OUTBOX_MSG = 7,
    CEC_PATH_ROOT_DIR = 10,
    CEC_PATH_MBOX_DIR = 11,
    CEC_PATH_INBOX_DIR = 12,
    CEC_PATH_OUTBOX_DIR = 13,
    CEC_MBOX_DATA = 100,
    CEC_MBOX_ICON = 101,
    CEC_MBOX_TITLE = 110,
    CEC_MBOX_PROGRAM_ID = 150
} CecDataPathType;

/// Commands used with Start and Stop
typedef enum {
    CEC_COMMAND_NONE,
    CEC_COMMAND_START,
    CEC_COMMAND_RESET_START,
    CEC_COMMAND_READYSCAN,
    CEC_COMMAND_READYSCANWAIT,
    CEC_COMMAND_STARTSCAN,
    CEC_COMMAND_RESCAN,
    CEC_COMMAND_NDM_RESUME,
    CEC_COMMAND_NDM_SUSPEND,
    CEC_COMMAND_NDM_SUSPEND_IMMEDIATE,
    CEC_COMMAND_STOPWAIT,
    CEC_COMMAND_STOP,
    CEC_COMMAND_STOP_FORCE,
    CEC_COMMAND_STOP_FORCE_WAIT,
    CEC_COMMAND_RESET_FILTER,
    CEC_COMMAND_DAEMON_STOP,
    CEC_COMMAND_DAEMON_START,
    CEC_COMMAND_EXIT,
    CEC_COMMAND_OVER_BOSS,
    CEC_COMMAND_OVER_BOSS_FORCE,
    CEC_COMMAND_OVER_BOSS_FORCE_WAIT,
    CEC_COMMAND_END
} CecCommand;

typedef enum {
    CEC_READ = BIT(1),
    CEC_WRITE = BIT(2),
    CEC_CREATE = BIT(3),
    CEC_CHECK = BIT(4)
} CecOpenFlag;

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
//static_assert(sizeof(CecBoxInfoHeader) == 0x20, "CecBoxInfoHeader struct has incorrect size.");

typedef struct
{
    u16 magic; // 0x6868 'hh'
    u16 padding;
    u32 version;
    u32 numBoxes;
    u8 boxNames[24][16]; // 12 used, but space for 24
} CecMBoxListHeader;
//static_assert(sizeof(CecMBoxListHeader) == 0x18C, "CecMBoxListHeader struct has incorrect size.");


typedef struct {
    u16 magic; // 0x6767 'gg'
    u16 padding;
    u32 numMessages;
} CecOBIndexHeader;
//static_assert(sizeof(CecOBIndexHeader) == 0x08, "OBIndexHeader struct has incorrect size.");

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
//static_assert(sizeof(CecTimestamp) == 0x0C, "Timestamp struct has incorrect size.");

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
//static_assert(sizeof(CecMessageHeader) == 0x70, "CecMessageHeader struct has incorrect size.");

/// Initializes CECD:u
Result cecduInit(void);

/// Exits CECD:u
void cecduExit(void);

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