#include "Bitmaps.h"

static const uint8_t BytewerkLogoData[] = {
	0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0x07, 0xff,
	0xff, 0xfe, 0x03, 0xff, 0xff, 0xfc, 0x01, 0xff, 0xff, 0xf8, 0x01, 0xff, 0xff,
	0xf0, 0x03, 0xff, 0xf1, 0xe0, 0x07, 0xff, 0xe0, 0xc0, 0x0f, 0xff, 0xc0, 0x60,
	0x1f, 0xff, 0x80, 0x20, 0x3f, 0xff, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x08, 0xff,
	0xff, 0x00, 0x0f, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x3f, 0xff,
	0xc0, 0x00, 0x3f, 0xff, 0x60, 0x00, 0x3f, 0xfe, 0x20, 0x00, 0x3f, 0xfc, 0x00,
	0x00, 0x3f, 0xf8, 0x0c, 0x00, 0x7f, 0xf0, 0x04, 0x01, 0xbf, 0xe0, 0x04, 0x00,
	0xbe, 0xc0, 0x04, 0x04, 0xbe, 0x80, 0x0c, 0x07, 0x36, 0x00, 0x1e, 0x08, 0x35,
	0x00, 0x3f, 0xff, 0xed, 0x80, 0x7f, 0xff, 0xd9, 0xc0, 0xff, 0xff, 0x3b, 0xe1,
	0xff, 0xff, 0xf7, 0xf3, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xfc, 0x3f, 0x00
};
const FlipdotBitmap BytewerkLogo(BytewerkLogoData, 32, 32);

static const uint8_t StatsQrCodeData[] = {
	0x01, 0x4a, 0x40, 0x3e, 0x9b, 0xaf, 0x91, 0x41, 0x34, 0x48, 0xac, 0x0a, 0x24,
	0x5a, 0x85, 0x13, 0xeb, 0xde, 0xf8, 0x05, 0x55, 0x01, 0xff, 0x49, 0xff, 0x31,
	0x97, 0x68, 0x19, 0xa5, 0x39, 0x71, 0x32, 0xae, 0x6d, 0xf4, 0xcd, 0x92, 0xdf,
	0xe1, 0x83, 0x19, 0x61, 0xb7, 0x44, 0x89, 0x87, 0x86, 0x2a, 0x71, 0x00, 0xe5,
	0x01, 0xff, 0x92, 0xba, 0xc0, 0x60, 0x54, 0xef, 0xaa, 0xee, 0x14, 0x55, 0x70,
	0x52, 0x2d, 0x68, 0xcd, 0x16, 0x27, 0x3a, 0xfa, 0x79, 0x41, 0x01, 0x5f, 0xbc,
	0x00
};
const FlipdotBitmap StatsQrCode(StatsQrCodeData, 25, 25);

static const uint8_t HeartData[] = { 0x92, 0x00, 0x04, 0x1c, 0x7d, 0xc0 };
const FlipdotBitmap Heart(HeartData, 7, 6);

static const uint8_t KrotData[] = { 0xf9, 0x15, 0x10 };
const FlipdotBitmap Krot(KrotData, 5, 4);
