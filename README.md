# telxcc

telxcc is utility extracting teletext Closed Captions from Transport Stream files (TS) into SubRip text files (SRT).

telxcc is

* tiny and lightweight (few KiBs binary, no lib dependencies)
* multiplatform (Mac, Linux, Windows)
* modern (fully supports UTF-8, conforms to ETSI 300 706 Presentation Level 1.5)
* stable
* high performing (on Macbook with Intel SSD it processes TS files at speed over 200 MiBps, with less than 30 % 1 CPU core utilization, SSD is the bottleneck)
* easy to use

## Build

To build binary for Intel Core 2 processor architecture just type:

    $ make ↵

On Mac typically you can use clang preprocessor:

    $ make CC=clang ↵

You can also copy any \*.ts files into the current directory and build a profiled version (up to 3% performance gain on repeat tasks):

    $ make profiled ↵

Or you can disable all optimizations (binary target is any x86 processor):

    $ make CCFLAGS="-Wall -std=c99"

Windows binary is build in MinGW by:

    C:\devel\telxcc> mingw32-make -f Makefile.win strip

telxcc has no lib dependencies and is easy to build and run on Linux, Mac and Windows. (Generic binary files are included.)

## Command line params

    $ ./telxcc -h ↵
    telxcc - TELeteXt Closed Captions decoder
    (c) Petr Kutalek <petr.kutalek@forers.com>, 2011-2012; Licensed under the GPL.
    Please consider making a Paypal donation to support our free GNU/GPL software:
    http://fore.rs/donate/telxcc
    Version 2.3.0 (Built on Sep 12 2012)
    
    Usage: ./telxcc [-h] [-v] [-p PAGE] [-t TID] [-o OFFSET] [-n] [-1] [-c] [-s [REF]]
      STDIN       transport stream
      STDOUT      subtitles in SubRip SRT file format (UTF-8 encoded)
      -h          this help text
      -v          be verbose
      -p PAGE     teletext page number carrying closed captions
      -t TID      transport stream PID of teletext data sub-stream
      -o OFFSET   subtitles offset in seconds
      -n          do not print UTF-8 BOM characters to the file
      -1          produce at least one (dummy) frame
      -c          output colour information in font HTML tags
      -s [REF]    search engine mode; produce absolute timestamps in UTC and output data in one line
                  if REF (unix timestamp) is ommited, use current system time,
                  telxcc will automatically switch to transport stream UTC timestamps when available
    
## Usage example

    $ ./telxcc -p 777 < 2012-02-15_1900_WWW_NRK.ts > dagsrevyen.srt ↵
    telxcc - TELeteXt Closed Captions decoder
    (c) Petr Kutalek <petr.kutalek@forers.com>, 2011-2012; Licensed under the GPL.
    Please consider making a Paypal donation to support our free GNU/GPL software:
    http://fore.rs/donate/telxcc
    Version 2.1.2 (Built on May  4 2012)

    - No teletext PID specified, first received suitable stream PID is 576 (0x240), not guaranteed
    - PID 0xbd PTS available
    - Programme Identification Data = NRK TV
    - Universal Time Co-ordinated = Wed Feb 15 19:14:04 2012
    - Transmission mode = serial
    - G0 Charset translation table remapped to G0 Latin National Subset ID 2
    - There were some CC data carried via pages: 333 444 777
    - Done (562995 teletext packets processed, 629 SRT frames written)

    $ _

## Pricing

telxcc is free GNU/GPL-licensed software. However if you use it, please consider making a [Paypal donation](http://fore.rs/donate/telxcc).

## Support

Any bug reports are very welcome. Unfortunately I am unable to provide you with free support. Sorry.
