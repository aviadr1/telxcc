# telxcc

telxcc is utility extracting teletext Closed Captions from Transport Stream binary files (TS) into SubRip text files (SRT).

[![Flattr this git repository](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=forers&url=https://github.com/forers/telxcc&title=telxcc&tags=github&category=software)

telxcc is:

* tiny and lightweight (few KiBs binary, no lib dependencies)
* easy to use
* open-source
* multiplatform (Mac, Windows and Linux @ x86, ARM etc.)
* modern (fully supports UTF-8, colours in SRT files, conforms to ETSI 300 706 Presentation Level 1.5/2.5)
* stable
* secure (does not require any escalated privileges)
* high performing (even SSD is the bottleneck)
* well tested (every build is automatically tested against English, German, Czech, Italian, Norwegian, Swedish, Finnish, Slovenian and Polish TS files from different TV stations)
* 100% handcrafted in Prague, CZ. :)


telxcc is easy to use and flexible at the same time:

* telxcc could be run in "search engine mode", in which case it produces plain text output suitable for indexing (UTC airtime and caption in plain text)
* telxcc tries to automatically detect all parameters needed (transport stream ID, teletext CC page, timestamps) and environment (the way it is started on Windows for instance)
* it could be easily integrated (files could be redirected or specified on command line as parameters)


telxcc is *the only utility having correct implementation* for following languages

* Croatian
* Czech
* English
* Estonian
* Finnish
* French
* German
* Hungarian
* Italian
* Lettish
* Lithuanian
* Polish
* Portuguese
* Rumanian
* Serbian
* Slovak
* Slovenian
* Spanish
* Swedish
* Turkish


telxcc also has limited/untested implementation of cyrillic and Greek alphabet for

* Bulgarian
* Croatian
* Greek
* Russian
* Serbian
* Ukrainian

and it is also already prepared for arabic and hebrew scripts (no such TS samples are unfortunately available for testing).


## Compiled binaries and other downloads

* [telxcc v2.4.3 - Windows, x86](https://forers.com/download/telxcc/telxcc-windows-x86-v2.4.3.zip) ([GPG signature](https://forers.com/download/telxcc/telxcc-windows-x86-v2.4.3.zip.asc))
* [telxcc v2.4.3 - Mac OS X, x86_64 Lion](https://forers.com/download/telxcc/telxcc-macosx-x86_64-v2.4.3.zip) ([GPG signature](https://forers.com/download/telxcc/telxcc-macosx-x86_64-v2.4.3.zip.asc))
* [telxcc v2.4.3 - Linux, x86_64 static](https://forers.com/download/telxcc/telxcc-linux-x86_64-v2.4.3.zip) ([GPG signature](https://forers.com/download/telxcc/telxcc-linux-x86_64-v2.4.3.zip.asc))


## Pricing and Support

telxcc is free GNU/GPL-licensed software. However if you use it, please consider making a [Paypal donation](http://fore.rs/donate/telxcc). Any bug reports, or TS sample files are very welcome. *Unfortunately we are unable to provide you with free support.* 

If you like telxcc and use it, please let us know, it motivates us in further development.

Important: telxcc will *never ever* be like Emacs; it is simple and specialized utility. Do you need another output format? Just transform current one. Is online/realtime processing over TCP/IP required? I suggest Node.js as a wrapper…


## Build

To install, or uninstall telxcc on Linux and Mac:

    $ make install ↵

    $ make uninstall ↵

To build binary for Intel Core 2 processor architecture just type:

    $ make ↵

On Mac typically you can use clang preprocessor:

    $ make CC=clang ↵

You can also copy any \*.ts files into the current directory and build a profiled version (up to 3% performance gain on repeat tasks):

    $ make profiled ↵

Or you can disable all optimizations (binary target is any x86 processor):

    $ make CCFLAGS="-Wall -pedantic -std=gnu99"

Windows binary is build in MinGW by (MinGW must be included in PATH):

    C:\devel\telxcc> mingw32-make -f Makefile.win strip

telxcc has no lib dependencies and is easy to build and run on Linux, Mac and Windows. (Generic binary files are included.)


## Command line params

    $ ./telxcc -h ↵
    telxcc - TELeteXt Closed Captions decoder
    (c) Forers, s. r. o., <info@forers.com>, 2011-2013; Licensed under the GPL.
    Please consider making a donation to support our free GNU/GPL software: http://fore.rs/donate/telxcc
    Version 2.4.2 (Built on Mar 31 2013)
    
    Usage: ./telxcc [-i INPUT] [-o OUTPUT] [-h] [-v] [-p PAGE] [-t TID] [-f OFFSET] [-n] [-1] [-c] [-s [REF]]
      -i INPUT    transport stream (- = STDIN, default STDIN)
      -o OUTPUT   subtitles in SubRip SRT file format (UTF-8 encoded) (- = STDOUT, default STDOUT)
      -h          this help text
      -v          be verbose
      -p PAGE     teletext page number carrying closed captions
      -t TID      transport stream PID of teletext data sub-stream
                  if the value of 8192 is specified, the first suitable stream will be used
      -f OFFSET   subtitles offset in seconds
      -n          do not print UTF-8 BOM characters to the file
      -1          produce at least one (dummy) frame
      -c          output colour information in font HTML tags
      -s [REF]    search engine mode; produce absolute timestamps in UTC and output data in one line
                  if REF (unix timestamp) is omitted, use current system time,
                  telxcc will automatically switch to transport stream UTC timestamps when available    


    $ man ./telxcc.1 ↵

    
## Usage example

    $ ./telxcc < TVP.ts > TVP.srt ↵
    telxcc - TELeteXt Closed Captions decoder
    (c) Forers, s. r. o., <info@forers.com>, 2011-2013; Licensed under the GPL.
    Please consider making a donation to support our free GNU/GPL software: http://fore.rs/donate/telxcc
    Version 2.4.2 (Built on Mar 31 2013)
    
    - Found VBI/teletext stream ID 205 (0xcd) for SID 45 (0x2d)
    - PID 0xbd PTS available
    - Programme Identification Data = OGLOSZENIA -> 640
    - Programme Timestamp (UTC) = Thu Mar 28 14:40:00 2013
    - Transmission mode = serial
    - Using G0 Latin National Subset ID 0x1.0 (Polish)
    ! Unrecoverable data error; UNHAM8/4(70)
    - There were some CC data carried via pages = 777 778 484 488 
    - Done (181250 teletext packets processed, 321 frames produced)

    $ _


## Service Info

[analytics](https://forers.com/tmp/empty.gif)
