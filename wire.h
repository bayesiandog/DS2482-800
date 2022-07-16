// wire.h			1-wire related definitions and function prototypes
#ifndef __WIRE_H
#define __WIRE_H

#define OWDAddress						(0x30)

// command opcodes
#define	OWBitCommand					(0x87)
#define	OWSetReadPtrCommand				(0xE1)
#define OWReadByteCommand				(0x96)
#define OWWriteByteCommand				(0xA5)
#define OWResetCommand					(0xB4)
#define OWDeviceResetCommand			(0xF0)
#define OWTriplet						(0x78)


// valid pointer codes for read register selection
#define	StatReg							(0xF0)
#define	DataReg							(0xE1)
#define	ChanReg							(0xD2)
#define	ConfigReg						(0xC3)

// DS2480 commands
#define OWDConfig                        (0xD2)

// status register bit assesment
#define STATUS_SBR	(0x20)
#define STATUS_TSB	(0x40)
#define STATUS_DIR	(0x80)
#define STATUS_BUSY (0x01)
#define STATUS_RST  (0x10)
#define STATUS_PPD  (0x02)

#define OWOperation (0x69)

typedef struct 
{
    BYTE APU;
    BYTE SPU;
    BYTE WS;
} DS2480Config;



// functions
BYTE OWWriteBit(BYTE value);
BYTE OWReadBit(void);
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