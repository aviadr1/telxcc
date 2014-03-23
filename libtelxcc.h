#ifndef LIBTELXCC_H
#define LIBTELXCC_H

#include <inttypes.h>

typedef enum {
    DATA_UNIT_EBU_TELETEXT_NONSUBTITLE = 0x02,
    DATA_UNIT_EBU_TELETEXT_SUBTITLE = 0x03,
    DATA_UNIT_EBU_TELETEXT_INVERTED = 0x0c,
    DATA_UNIT_VPS = 0xc3,
    DATA_UNIT_CLOSED_CAPTIONS = 0xc5
} data_unit_t;

// 1-byte alignment; just to be sure, this struct is being used for explicit type conversion
// FIXME: remove explicit type conversion from buffer to structs
#pragma pack(push)
#pragma pack(1)
typedef struct {
    uint8_t _clock_in; // clock run in
    uint8_t _framing_code; // framing code, not needed, ETSI 300 706: const 0xe4
    uint8_t address[2];
    uint8_t data[40];
} teletext_packet_payload_t;
#pragma pack(pop)

extern void process_telx_packet(data_unit_t data_unit_id, teletext_packet_payload_t *packet, uint64_t timestamp);

#endif
