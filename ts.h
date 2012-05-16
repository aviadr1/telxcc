/*!
(c) 2011-2012 Petr Kutalek, Forers, s. r. o.: telxcc

Some portions/inspirations:
(c) 2007 Vincent Penne, telx.c : Minimalistic Teletext subtitles decoder
(c) 2001-2005 by dvb.matt, ProjectX java dvb decoder
(c) Dave Chapman <dave@dchapman.com> 2003-2004, dvbtextsubs
(c) Ralph Metzler, DVB driver, vbidecode
(c) Jan Pantelje, submux-dvd
(c) Ragnar Sundblad, dvbtextsubs, VDR teletext subtitles plugin
(c) Scott T. Smith, dvdauthor
(c) 2007 Vladimir Voroshilov <voroshil@gmail.com>, mplayer
(c) 2001, 2002, 2003, 2004, 2007 Michael H. Schimek, libzvbi -- Error correction functions


This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
*/

#ifndef ts_h_included
#define ts_h_included

#include <inttypes.h>

typedef struct {
	uint8_t sync : 8;
	uint8_t transport_error : 1;
	uint8_t payload_unit_start : 1;
	uint8_t transport_priority : 1;
	uint16_t pid : 13;
	uint8_t scrambling_control : 2;
	uint8_t adaptation_field_exists : 2;
	uint8_t continuity_counter : 4;
	//uint8_t payload[];
} ts_packet_t;

typedef struct {
	uint16_t program_num : 16;
	uint16_t program_pid : 13;
} pat_section_t;

typedef struct {
	uint8_t pointer_field : 8;
	uint8_t table_id : 8; // 0x00
	uint16_t section_length : 10;
	uint8_t current_next_indicator : 1;
} pat_t;

typedef struct {
	uint8_t stream_type : 8;
	uint16_t elementary_pid : 13;
	uint16_t es_info_length : 10;
} pmt_program_descriptor_t;

typedef struct {
	uint8_t descriptor_tag : 8;
	uint8_t descriptor_length : 8;
} pmt_teletext_descriptor_t;

typedef struct {
	uint32_t iso_639_language_code : 24;
	uint8_t teletext_type : 5;
	uint8_t teletext_magazine_number : 3;
	uint8_t teletext_page_number : 8;
} pmt_teletext_descriptor_payload_t;

typedef struct {
	uint8_t pointer_field : 8;
	uint8_t table_id : 8; // 0x02
	uint16_t section_length : 10;
	uint16_t program_num : 16;
	uint8_t current_next_indicator : 1;
	uint16_t pcr_pid : 16;
	uint16_t program_info_length : 10;
} pmt_t;

typedef enum {
	TELETEXT_DESCRIPTOR_TELETEXT_TYPE_RESERVED = 0,
	TELETEXT_DESCRIPTOR_TELETEXT_TYPE_INITIAL = 1,
	TELETEXT_DESCRIPTOR_TELETEXT_TYPE_SUBTITLE = 2,
	TELETEXT_DESCRIPTOR_TELETEXT_TYPE_ADDITIONAL_INFO = 3,
	TELETEXT_DESCRIPTOR_TELETEXT_TYPE_PROGRAM_SCHEDULE = 4,
	TELETEXT_DESCRIPTOR_TELETEXT_TYPE_SUBTITILE_CC = 5
} teletext_descriptor_teletext_type_t;

#endif
