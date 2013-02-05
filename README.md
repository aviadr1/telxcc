# telxcc

telxcc is utility extracting teletext Closed Captions from Transport Stream files (TS) into SubRip text files (SRT).

telxcc is

* tiny and lightweight (few KiBs binary, no lib dependencies)
* easy to use
* multiplatform (Mac, Windows and Linux @ x86, ARM etc.)
* modern (fully supports UTF-8, conforms to ETSI 300 706 Presentation Level 1.5)
* stable
* high performing (on Macbook with Intel SSD it processes TS files at speed over 200 MiB/s, with less than 30 % of 1 CPU core utilization, SSD is the bottleneck)
* well tested (each version is automatically tested against English, German, Czech, Italian, Norwegian, Swedish, Finnish and Slovenian TS files)

## Compiled binaries and other downloads

* [telxcc v2.4.0 - Windows, x86](https://forers.com/download/telxcc/telxcc-windows-x86-v2.4.0.zip) ([GPG signature](https://forers.com/download/telxcc/telxcc-windows-x86-v2.4.0.zip.asc))
* [telxcc v2.4.0 - Mac OS X, x86_64](https://forers.com/download/telxcc/telxcc-macosx-x86-v2.4.0.zip) ([GPG signature](https://forers.com/download/telxcc/telxcc-macosx-x86-v2.4.0.zip.asc))
* [telxcc v2.4.0 - Linux, x86_64](https://forers.com/download/telxcc/telxcc-linux-x86-v2.4.0.zip) ([GPG signature](https://forers.com/download/telxcc/telxcc-linux-x86-v2.4.0.zip.asc))
* [telxcc v2.4.0 - Linux, Raspberry Pi](https://forers.com/download/telxcc/telxcc-linux-rpi-v2.4.0.zip) ([GPG signature](https://forers.com/download/telxcc/telxcc-linux-x86-v2.4.0.zip.asc))
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

    $ make CCFLAGS="-Wall -pedantic -std=c99"

Windows binary is build in MinGW by:

    C:\devel\telxcc> mingw32-make -f Makefile.win strip

telxcc has no lib dependencies and is easy to build and run on Linux, Mac and Windows. (Generic binary files are included.)

## Command line params

    $ ./telxcc -h ↵
    telxcc - TELeteXt Closed Captions decoder
    (c) Petr Kutalek <info@forers.com>, 2011-2013; Licensed under the GPL.
    Please consider making a Paypal donation to support our free GNU/GPL software:
    http://fore.rs/donate/telxcc
    Version 2.4.0 (Built on Feb  5 2013)
    
    Usage: ./telxcc [-h] [-v] [-p PAGE] [-t TID] [-o OFFSET] [-n] [-1] [-c] [-s [REF]]
      STDIN       transport stream
      STDOUT      subtitles in SubRip SRT file format (UTF-8 encoded)
      -h          this help text
      -v          be verbose
      -p PAGE     teletext page number carrying closed captions
      -t TID      transport stream PID of teletext data sub-stream
                  if the value of 8192 is specified, the first suitable stream will be used
      -o OFFSET   subtitles offset in seconds
      -n          do not print UTF-8 BOM characters to the file
      -1          produce at least one (dummy) frame
      -c          output colour information in font HTML tags
      -s [REF]    search engine mode; produce absolute timestamps in UTC and output data in one line
                  if REF (unix timestamp) is ommited, use current system time,
                  telxcc will automatically switch to transport stream UTC timestamps when available
    
    
## Usage example

    $ ./telxcc < SWR_PID-804_PAGE-150.ts > SWR.srt ↵
    telxcc - TELeteXt Closed Captions decoder
    (c) Petr Kutalek <info@forers.com>, 2011-2013; Licensed under the GPL.
    Please consider making a Paypal donation to support our free GNU/GPL software:
    http://fore.rs/donate/telxcc
    Version 2.4.0 (Built on Feb  5 2013)
    
    - Found VBI/teletext stream ID 804 (0x324) for SID 28113 (0x6dd1)
    - No teletext page specified, first received suitable page is 150, not guaranteed
    - Programme Identification Data = SWR                 
    - Programme Timestamp (UTC) = Thu Jan 19 21:42:43 2012
    - Done (29896 teletext packets processed, 42 frames produced)
    
    $ _

