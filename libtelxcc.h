#ifndef LIBTELXCC_H
#define LIBTELXCC_H

#include <inttypes.h>
#include <stdio.h>

#define TS_PMT_MAP_SIZE 128
#define TS_PMT_TTXT_MAP_SIZE 128

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

typedef enum {
    NO = 0x00,
    YES = 0x01,
    UNDEF = 0xff
} bool_t;

// size of a (M2)TS packet in bytes (TS = 188, M2TS = 192)
#define TS_PACKET_SIZE 192

// size of a TS packet payload in bytes
#define TS_PACKET_PAYLOAD_SIZE 184

// size of a packet payload buffer
#define PAYLOAD_BUFFER_SIZE 4096

typedef struct {
    uint8_t sync;
    uint8_t transport_error;
    uint8_t payload_unit_start;
    uint8_t transport_priority;
    uint16_t pid;
    uint8_t scrambling_control;
    uint8_t adaptation_field_exists;
    uint8_t continuity_counter;
} ts_packet_t;

typedef struct {
    uint16_t program_num;
    uint16_t program_pid;
} pat_section_t;

typedef struct {
    uint8_t pointer_field;
    uint8_t table_id;
    uint16_t section_length;
    uint8_t current_next_indicator;
} pat_t;

typedef struct {
    uint8_t stream_type;
    uint16_t elementary_pid;
    uint16_t es_info_length;
} pmt_program_descriptor_t;

typedef struct {
    uint8_t pointer_field;
    uint8_t table_id;
    uint16_t section_length;
    uint16_t program_num;
    uint8_t current_next_indicator;
    uint16_t pcr_pid;
    uint16_t program_info_length;
} pmt_t;

typedef enum {
    TRANSMISSION_MODE_PARALLEL = 0,
    TRANSMISSION_MODE_SERIAL = 1
} transmission_mode_t;

typedef struct {
    uint64_t show_timestamp; // show at timestamp (in ms)
    uint64_t hide_timestamp; // hide at timestamp (in ms)
    uint16_t text[25][40]; // 25 lines x 40 cols (1 screen/page) of wide chars
    uint8_t tainted; // 1 = text variable contains any data
} teletext_page_t;

typedef struct {
    uint64_t show_timestamp; // show at timestamp (in ms)
    uint64_t hide_timestamp; // hide at timestamp (in ms)
    char *text;
} frame_t;

// application config global variable
typedef struct {
#ifdef __MINGW32__
    wchar_t *input_name; // input file name (used on Windows, UNICODE)
    wchar_t *output_name; // output file name (used on Windows, UNICODE)
#else
    char *input_name; // input file name
    char *output_name; // output file name
#endif
    uint8_t verbose; // should telxcc be verbose?
    uint16_t page; // teletext page containing cc we want to filter
    uint16_t tid; // 13-bit packet ID for teletext stream
    double offset; // time offset in seconds
    uint8_t colours; // output <font...></font> tags
    uint8_t bom; // print UTF-8 BOM characters at the beginning of output
    uint8_t nonempty; // produce at least one (dummy) frame
    uint64_t utc_refvalue; // UTC referential value
    // FIXME: move SE_MODE to output module
    uint8_t se_mode;
    //char *template; // output format template
    uint8_t m2ts; // consider input stream is af s M2TS, instead of TS
} telxcc_config_t;

// application states -- flags for notices that should be printed only once
typedef struct {
    uint8_t programme_info_processed;
    uint8_t pts_initialized;
} telxcc_states_t;

// current charset (charset can be -- and always is -- changed during transmission)
typedef struct {
    uint8_t current;
    uint8_t g0_m29;
    uint8_t g0_x28;
} telxcc_charset_t;

// entities, used in colour mode, to replace unsafe HTML tag chars
typedef struct {
    uint16_t character;
    char *entity;
} telxcc_entity_t;

typedef struct {
    telxcc_config_t config;

    FILE *fin;
    FILE *fout;

    telxcc_states_t states;

    // SRT frames produced
    uint32_t frames_produced;

    // subtitle type pages bitmap, 2048 bits = 2048 possible pages in teletext (excl. subpages)
    uint8_t cc_map[256];

    // global TS PCR value
    uint32_t global_timestamp;

    // last timestamp computed
    uint64_t last_timestamp;

    // working teletext page buffer
    teletext_page_t page_buffer;

    // teletext transmission mode
    transmission_mode_t transmission_mode;

    // flag indicating if incoming data should be processed or ignored
    uint8_t receiving_data;

    telxcc_charset_t primary_charset;

    // PMTs table
    uint16_t pmt_map[TS_PMT_MAP_SIZE];
    uint16_t pmt_map_count;

    // TTXT streams table
    uint16_t pmt_ttxt_map[TS_PMT_MAP_SIZE];
    uint16_t pmt_ttxt_map_count ;

} telxcc_context_t;

extern void telxcc_init_context(telxcc_context_t* ctx);
extern void telxcc_process_pes_packet(telxcc_context_t* ctx, uint8_t *buffer, uint16_t size);
extern int telxcc_main(const int argc, char *argv[]);

#endif
