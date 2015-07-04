#ifndef __MRF89XA_H
#define __MRF89XA_H

/* client exports */

#include <linux/ioctl.h>

#define MRF_IOC_MAGIC 'n'

#define MRF_IOCRESET _IO(MRF_IOC_MAGIC, 0)
#define MRF_IOC_MAXNR 0

/* board setup */
/*
    http://elinux.org/RPi_BCM2835_GPIOs
*/
#define CSCON_PIN 23
#define RESET_PIN 22
#define DATA_PIN  25

/* in microseconds */
#define RESET_DELAY 100
#define RESET_WAIT  6000


/* internals */

/* raspberry pi has just 0-bus */
#define MRFSPI_BUS_NO 0

#define CMD_READ_REGISTER(N) (0x40 | (N << 1))

#define FREQBAND_902		0x00   //902-915 00 [4:3]
#define FREQBAND_915		0x08   //915-928 01 ;default
#define FREQBAND_950_863	0x10   //950-960 or 863-870 10

#define VCO_TRIM_00			0x00	// [2:1] Vtune determined by tank inductor values
#define VCO_TRIM_01			0x02
#define VCO_TRIM_10			0x04
#define VCO_TRIM_11			0x06

#define REG_GCON        0x00
#define REG_DMOD        0x01
#define REG_FDEV        0x02
#define REG_BRS         0x03
#define REG_FLTH        0x04
#define REG_FIFO        0x05
#define REG_R1C         0x06
#define REG_P1C         0x07
#define REG_S1C         0x08
#define REG_PAC         0x0C
#define REG_FTXRXI      0x0D
#define REG_FTPRI       0x0E
#define REG_FILC        0x10
#define REG_PFC         0x11
#define REG_SYNC        0x12
#define REG_SYNC_WORD_1 0x16
#define REG_SYNC_WORD_2 0x17
#define REG_SYNC_WORD_3 0x18
#define REG_SYNC_WORD_4 0x19
#define REG_TXCON       0x1A
#define REG_CLKOUT      0x1B
#define REG_PLOAD       0x1C
#define REG_NADDS       0x1D
#define REG_PKTC        0x1E
#define REG_FCRC        0x1D

#define CHIPMODE_SLEEPMODE  0x00	//000 [7:5]
#define CHIPMODE_STBYMODE 	0x20	//001
#define CHIPMODE_FSMODE	 	0x40	//010
#define CHIPMODE_RX		 	0x60	//011
#define CHIPMODE_TX		 	0x80	//100

#define DATAMODE_CONTINUOUS 0x00	//00 [Bit2,Bit5];default
#define DATAMODE_BUFFERED	0x20	//01
#define DATAMODE_PACKET	    0x04	//1x

#define IFGAIN_0			0x00	//00 [1:0] 0dB ;default
#define IFGAIN_45			0x01	//01 -4.5dB
#define IFGAIN_9			0x02	//10 -9dB
#define IFGAIN_135			0x03	//11 -13.5dB

#define MODSEL_FSK			0x80   //10 ;default

#define FREGDEV_33		0x0B
#define FREGDEV_40		0x09
#define FREGDEV_50		0x07
#define FREGDEV_67		0x05
#define FREGDEV_80		0x04
#define FREGDEV_100		0x03
#define FREGDEV_133		0x02
#define FREGDEV_200		0x01


/* default C = 0000111, BR = 25 Kbps */
#define BITRATE_200		0x00
#define BITRATE_100		0x01
#define BITRATE_66		0x02
#define BITRATE_50		0x03
#define BITRATE_40		0x04
#define BITRATE_25		0x07
#define BITRATE_20		0x09
#define BITRATE_16		0x0B
#define BITRATE_10		0x13
#define BITRATE_5		0x27
#define BITRATE_2		0x63
#define BITRATE_1_56	0x7F
#define BITRATE_2_41	0x52
#define BITRATE_4_76	0x29
#define BITRATE_8		0x18
#define BITRATE_9_52	0x14
#define BITRATE_12_5	0x0F
#define BITRATE_16_67	0x0B

#define FIFOSIZE_16			0x00	//00 [7:6] - 16bytes - default
#define FIFOSIZE_32			0x40
#define FIFOSIZE_48			0x80
#define FIFOSIZE_64			0xC0

#define IRQ0_RX_STDBY_SYNCADRS        0xC0
#define IRQ1_RX_STDBY_CRCOK           0x00
#define IRQ1_TX_TXDONE                0x08

#define IRQ1_PLL_LOCK_PIN_ON          0x01

#define IRQ0_TX_START_FIFONOTEMPTY    0x10
/* required to setup parameter, see p. 40 of datasheet */
#define DEF_IRQPARAM1				  0x08

#define PASSIVEFILT_378           0xA0
#define RXFC_FOPLUS100            0x03

#define FO_100                    0x30

#define SYNC_ON						0x20
#define SYNC_SIZE_8					0x00
#define SYNC_SIZE_16				0x08
#define SYNC_SIZE_24				0x10
#define SYNC_SIZE_32				0x18
#define SYNC_ERRORS_0				0x00
#define SYNC_ERRORS_1				0x02
#define SYNC_ERRORS_2				0x04
#define SYNC_ERRORS_3				0x06

#define DEF_RXPARAM3				0x07

#define FC_400                     0xF0

#define TXPOWER_13					0x00
#define TXPOWER_10					0x02
#define TXPOWER_7					0x04
#define TXPOWER_4					0x06
#define TXPOWER_1					0x08
#define TXPOWER_2					0x0A
#define TXPOWER_5					0x0C
#define TXPOWER_8					0x0E

#define CLKOUT_OFF                0x00

#define MANCHESTER_ON				0x80
#define MANCHESTER_OFF				0x00

#define PAYLOAD_64                64

#define PKT_FORMAT_FIXED			0x00
#define PKT_FORMAT_VARIABLE			0x80
#define PREAMBLE_SIZE_1				0x00
#define PREAMBLE_SIZE_2				0x20
#define PREAMBLE_SIZE_3				0x40
#define PREAMBLE_SIZE_4				0x60

#define WHITENING_ON				0x10
#define WHITENING_OFF				0x00

#define CRC_ON						0x08
#define CRC_OFF						0x00

#define ADRSFILT_ME_AND_00_AND_FF	0x06	/* Node_adrs and 0x00 and 0xff accepted */

#define FIFO_AUTOCLR_ON				0x00
#define FIFO_STBY_ACCESS_WRITE		0x00

#endif /* __MRF89XA_H */
