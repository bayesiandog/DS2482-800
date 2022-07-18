// wire.h			1-wire related definitions and function prototypes
#ifndef __WIRE_H
#define __WIRE_H

#define OWDAddress						(0x30)

// Valid pointer codes for read register selection
#define	StatReg							(0xF0)
#define	DataReg							(0xE1)
#define	ChanReg							(0xD2)
#define	ConfigReg						(0xC3)

// DS2480 commands
#define OWDSConfig                      (0xD2)
#define OWDSDeviceResetCommand	   		(0xF0)
#define	OWDSSetReadPtrCommand			(0xE1)
#define	OWDSChannelSelect				(0xC3)
#define OWDSResetCommand				(0xB4)
#define OWDSReadByteCommand				(0x96)
#define OWDSTriplet						(0x78)
#define OWDSWriteByteCommand			(0xA5)

// 1-wire commands
#define OWSearchCmd                     (0xF0)
#define OWMatchROMCmd                   (0x55)
#define OWConvertTCmd                   (0x44)
#define OWReadPad                       (0xBE)

// Status register bit assesment
#define STATUS_SBR	(0x20)
#define STATUS_TSB	(0x40)
#define STATUS_DIR	(0x80)
#define STATUS_BUSY (0x01)
#define STATUS_RST  (0x10)
#define STATUS_PPD  (0x02)

// I2C value for reading only
#define OWOperation (0x69)

// DS2480 config structure
typedef struct 
{
    BYTE APU; // Active pull up
    BYTE SPU; // Strong pull up
    BYTE WS;  // Wire speed
} DS2480Config;



// Functions
BYTE OWWriteByte(BYTE wrByte);
BYTE OWReadByte(BYTE rdByte);
BYTE OWReset(void);
BYTE OWDReset(void);
BYTE OWDWriteConfig(DS2480Config *pDSconfig);
BYTE OWBusy(void);
WORD DS18B20_readTemp(BYTE deviceNumber);
int OWSearch(void);
unsigned char DS2482_search_triplet(int search_direction);

#endif
