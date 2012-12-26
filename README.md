# telxcc

telxcc is utility extracting teletext Closed Captions from Transport Stream files (TS) into SubRip text files (SRT).

telxcc is

* tiny and lightweight (few KiBs binary, no lib dependencies)
* easy to use
* multiplatform (Mac, Windows and Linux @ x86, ARM etc.)
* modern (fully supports UTF-8, conforms to ETSI 300 706 Presentation Level 1.5)
* stable
* high performing (on Macbook with Intel SSD it processes TS files at speed over 200 MiB/s, with less than 30 % of 1 CPU core utilization, SSD is the bottleneck)
* well tested (each version is automatically tested against English, German, Czech, Norwegian, Swedish and Slovenian TS files)

## Compiled binaries and other downloads

* [telxcc v2.3.2 - Windows, x86](https://forers.com/download/telxcc/telxcc-windows-x86-v2.3.2.zip) ([GPG signature](https://forers.com/download/telxcc/telxcc-windows-x86-v2.3.2.zip.asc), [no viruses](https://www.virustotal.com/file/bc05a36a380732ad9dd6af5bb90cc7b5177d705cd2f157043209a018d551d9c9/analysis/1356474551/))
* [telxcc v2.3.2 - Mac OS X, x86_64](https://forers.com/download/telxcc/telxcc-macosx-x86-v2.3.2.zip) ([GPG signature](https://forers.com/download/telxcc/telxcc-macosx-x86-v2.3.2.zip.asc), [no viruses](https://www.virustotal.com/file/342043631e46e17fb2c5cc9d77372af9e673e88299f012170e4ab8ff51be7fb2/analysis/1356474737/))
* [telxcc v2.3.2 - Linux, x86_64](https://forers.com/download/telxcc/telxcc-linux-x86-v2.3.2.zip) ([GPG signature](https://forers.com/download/telxcc/telxcc-linux-x86-v2.3.2.zip.asc), [no viruses](https://www.virustotal.com/file/3f8c137e58678b9a4e3984ad05200e3d6525bd41508ff3338b2f7922aa3c918f/analysis/1356474834/))
* [TS sample file 1](https://forers.com/download/telxcc/sample1.ts) (1.4 GiB)

## Pricing and Support

telxcc is free GNU/GPL-licensed software. However if you use it, please consider making a [Paypal donation](http://fore.rs/donate/telxcc). Any bug reports, or TS sample files are very welcome. Unfortunately we are unable to provide you with free support.

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
    (c) Petr Kutalek <info@forers.com>, 2011-2012; Licensed under the GPL.
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
    (c) Petr Kutalek <info@forers.com>, 2011-2012; Licensed under the GPL.
    Please consider making a Paypal donation to support our free GNU/GPL software:
    http://fore.rs/donate/telxcc
    Version 2.3.0 (Built on Sep 12 2012)

    - No teletext PID specified, first received suitable stream PID is 576 (0x240), not guaranteed
    - PID 0xbd PTS available
    - Programme Identification Data = NRK TV
    - Universal Time Co-ordinated = Wed Feb 15 19:14:04 2012
    - Transmission mode = serial
    - G0 Charset translation table remapped to G0 Latin National Subset ID 2
    - There were some CC data carried via pages: 333 444 777
    - Done (562995 teletext packets processed, 629 SRT frames written)

    $ _

