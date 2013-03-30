/*
                  NAME - MyButami™ Source© Include File
               AUTHORS - Swaroop Bhonde & Omkar Ekbote
           DESCRIPTION - Compilation of all required include directives for MyButami™ Source©
             COPYRIGHT - Individual Copyrights to:
                         Copyright (c) 1990, 1991 by Borland International    
                         All rights reserved.
               VERSION - v1.0 (Designed for v0.9.0 BETA)
             DATE/TIME - 15/02/07 21:51
VERSION SPECIFICATIONS - Includes the content of the following files (embedded):
                         iostream.h  : Stardard I/O Compaitibility
                         conio.h     : Console I/O Compaitibility
                         process.h   : Library Functions : exit()
                         dos.h       : Library Functions : delay()
                         string.h    : String Library
                         grapihcs.h  : MyButami™ GUI Module Compaitibility
                 USAGE - To be included in all future versions of MyButami™ Source© v0.9.0+

*/

/*  iostream.h -- basic stream I/O declarations

    Copyright (c) 1990, 1991 by Borland International    
    All rights reserved.

    There are some inline functions here which generate a LOT of code
    (as much as 300 bytes), but are available inline because AT&T did
    it that way.  We have also made them true functions in the library
    and conditionally deleted the inline code from this header.
    
    If you really want these big functions to be inline, #define the
    macro name _BIG_INLINE_ before including this header.

    Programs will compile and link correctly even if some modules are
    compiled with _BIG_INLINE_ and some are not.
*/

#ifndef __cplusplus
#error Must use C++ for the type iostream.
#endif

#ifndef __IOSTREAM_H
#define __IOSTREAM_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#if !defined( __MEM_H )
#include <mem.h>    // to get memcpy and NULL
#endif

#pragma option -Vo-

// Definition of EOF must match the one in <stdio.h>
#define EOF (-1)

// extract a char from int i, ensuring that zapeof(EOF) != EOF
#define zapeof(i) ((unsigned char)(i))

typedef long streampos;
typedef long streamoff;

_CLASSDEF(ios)
_CLASSDEF(streambuf)
_CLASSDEF(istream)
_CLASSDEF(ostream)
_CLASSDEF(iostream)
_CLASSDEF(istream_withassign)
_CLASSDEF(ostream_withassign)
_CLASSDEF(iostream_withassign)

class _CLASSTYPE ios {
public:
    // stream status bits
    enum io_state   {
        goodbit  = 0x00,    // no bit set: all is ok
        eofbit   = 0x01,    // at end of file
        failbit  = 0x02,    // last I/O operation failed
        badbit   = 0x04,    // invalid operation attempted
        hardfail = 0x80     // unrecoverable error
        };

    // stream operation mode
    enum open_mode  {
        in   = 0x01,        // open for reading
        out  = 0x02,        // open for writing
        ate  = 0x04,        // seek to eof upon original open
        app  = 0x08,        // append mode: all additions at eof
        trunc    = 0x10,    // truncate file if already exists
        nocreate = 0x20,    // open fails if file doesn't exist
        noreplace= 0x40,    // open fails if file already exists
        binary   = 0x80     // binary (not text) file
        };

    // stream seek direction
    enum seek_dir { beg=0, cur=1, end=2 };

    // formatting flags
    enum    {
        skipws    = 0x0001, // skip whitespace on input
        left      = 0x0002, // left-adjust output
        right     = 0x0004, // right-adjust output
        internal  = 0x0008, // padding after sign or base indicator
        dec   = 0x0010,     // decimal conversion
        oct   = 0x0020,     // octal conversion
        hex   = 0x0040,     // hexadecimal conversion
        showbase  = 0x0080, // use base indicator on output
        showpoint = 0x0100, // force decimal point (floating output)
        uppercase = 0x0200, // upper-case hex output
        showpos   = 0x0400, // add '+' to positive integers
        scientific= 0x0800, // use 1.2345E2 floating notation
        fixed     = 0x1000, // use 123.45 floating notation
        unitbuf   = 0x2000, // flush all streams after insertion
        stdio     = 0x4000  // flush stdout, stderr after insertion
        };

    // constants for second parameter of seft()
static  const long basefield;       // dec | oct | hex
static  const long adjustfield;     // left | right | internal
static  const long floatfield;      // scientific | fixed

    // constructor, destructor
        _Cdecl ios(streambuf *);
virtual _Cdecl ~ios();

    // for reading/setting/clearing format flags
    long    _Cdecl flags();
    long    _Cdecl flags(long);
    long    _Cdecl setf(long _setbits, long _field);
    long    _Cdecl setf(long);
    long    _Cdecl unsetf(long);

    // reading/setting field width
    int     _Cdecl width();
    int     _Cdecl width(int);

    // reading/setting padding character
    char    _Cdecl fill();
    char    _Cdecl fill(char);

    // reading/setting digits of floating precision
    int     _Cdecl precision(int);
    int     _Cdecl precision();

    // reading/setting ostream tied to this stream
    ostream * _Cdecl tie(ostream *);
    ostream * _Cdecl tie();

    // find out about current stream state
    int     _Cdecl rdstate();       // return the stream state
    int     _Cdecl eof();           // non-zero on end of file
    int     _Cdecl fail();          // non-zero if an operation failed
    int     _Cdecl bad();           // non-zero if error occurred
    int     _Cdecl good();          // non-zero if no state bits set
    void    _Cdecl clear(int = 0);  // set the stream state
            _Cdecl operator void * (); // zero if state failed
    int     _Cdecl operator! ();    // non-zero if state failed

    streambuf * _Cdecl rdbuf();        // get the assigned streambuf

    // for declaring additional flag bits and user words
static long _Cdecl bitalloc();  // acquire a new flag bit, value returned
static int  _Cdecl xalloc();    // acquire a new user word, index returned
    long  & _Cdecl iword(int);  // return the nth user word as an int
    void * & _Cdecl pword(int);  // return the nth user word as a pointer

static void _Cdecl sync_with_stdio();

    // obsolete, for streams 1.2 compatibility
    int     _Cdecl skip(int);

protected:
    // additional state flags for ispecial and ospecial
    enum { skipping = 0x100, tied = 0x200 };

    streambuf * bp;    // the associated streambuf
    ostream * x_tie;   // the tied ostream, if any
    int     state;          // status bits
    int     ispecial;       // istream status bits  ***
    int     ospecial;       // ostream status bits  ***
    long    x_flags;        // formatting flag bits
    int     x_precision;    // floating-point precision on output
    int     x_width;        // field width on output
    int     x_fill;         // padding character on output
    int     isfx_special;   // unused       ***
    int     osfx_special;   // unused       ***
    int     delbuf;         // unused       ***
    int     assign_private; // unused       ***
/*
 * The data members marked with *** above are not documented in the AT&T
 * release of streams, so we cannot guarantee compatibility with any
 * other streams release in the use or values of these data members.
 * If you can document any expected behavior of these data members, we
 * will try to adjust our implementation accordingly.
 */

            _Cdecl ios();       // null constructor, does not initialize
            
    void    _Cdecl init(streambuf *);  // the actual initialization

    void    _Cdecl setstate(int);       // set all status bits

static  void _Cdecl (*stdioflush)();

private:
    // for extra flag bits and user words
static  long    nextbit;
static  int usercount;
    union ios_user_union *userwords;
    int     nwords;
    void    _Cdecl usersize(int);

    // these declarations prevent automatic copying of an ios
            _Cdecl ios(ios &);           // declared but not defined
    void    _Cdecl operator= (ios &);    // declared but not defined

};
inline streambuf * _Cdecl ios::rdbuf() { return bp; }
inline ostream * _Cdecl ios::tie() { return x_tie; }    
inline char     _Cdecl ios::fill() { return x_fill; }
inline int      _Cdecl ios::precision() { return x_precision; }
inline int      _Cdecl ios::rdstate() { return state; }
inline int      _Cdecl ios::eof() { return state & eofbit; }
inline int      _Cdecl ios::fail() 
                        { return state & (failbit | badbit | hardfail); }
inline int      _Cdecl ios::bad() { return state & (badbit | hardfail); }
inline int      _Cdecl ios::good() { return state == 0; }
inline long     _Cdecl ios::flags() { return x_flags; }
inline int      _Cdecl ios::width() { return x_width; }
inline int      _Cdecl ios::width(int _w) 
                        { int _i = x_width; x_width = _w; return _i; }
inline char     _Cdecl ios::fill(char _c) 
                        { char _x = x_fill; x_fill = _c; return _x; }
inline int      _Cdecl ios::precision(int _p) 
                        { int _x = x_precision; x_precision = _p; return _x; }
inline          _Cdecl ios::operator void *() 
                        { return fail() ? 0 : this; }
inline int      _Cdecl ios::operator! () { return fail(); }


class _CLASSTYPE streambuf {
public:
    // constructors and destructors
        _Cdecl streambuf();                 // make empty streambuf
        _Cdecl streambuf(char *, int); // make streambuf with 
                                            // given char array
virtual _Cdecl ~streambuf();

    // use the provided char array for the buffer if possible
virtual streambuf * _Cdecl setbuf(  signed char *, int);
    // WARNING:  this function is not virtual; do not override
    streambuf *  _Cdecl setbuf(unsigned char *, int);

    // obsolete, for streams 1.2 compatibility
    streambuf *  _Cdecl setbuf(char *, int, int);

    // getting (extracting) characters
    int     _Cdecl sgetc();         // peek at next char
    int     _Cdecl snextc();        // advance to and return next char
    int     _Cdecl sbumpc();        // return current char and advance
    void    _Cdecl stossc();        // advance to next character
    int     _Cdecl sgetn(char *, int);     // get next n chars
virtual int _Cdecl do_sgetn(char *, int);  // implementation of sgetn
virtual int _Cdecl underflow();     // fill empty buffer
    int     _Cdecl sputbackc(char); // return char to input
virtual int _Cdecl pbackfail(int);  // implementation of sputbackc
    int     _Cdecl in_avail();      // number of avail chars in buffer

    // putting (inserting) characters
    int     _Cdecl sputc(int);          // put one char
    int     _Cdecl sputn(const char *, int); // put n chars from string
virtual int _Cdecl do_sputn(const char * s, int n); // implementation of sputn
virtual int _Cdecl overflow(int = EOF); // flush buffer and make more room
    int     _Cdecl out_waiting();       // number of unflushed chars

    // moving around in stream
virtual streampos _Cdecl seekoff(streamoff, ios::seek_dir, 
                                 int = (ios::in | ios::out));
virtual streampos _Cdecl seekpos(streampos, int = (ios::in | ios::out));
virtual int _Cdecl sync();

    void    _Cdecl dbp();       // for debugging streambuf implementations

protected:
    char * _Cdecl base();  // return start of buffer area
    char * _Cdecl ebuf();  // return end+1 of buffer area
    int     _Cdecl blen();      // return length of buffer area
    char * _Cdecl pbase(); // return start of put area
    char * _Cdecl pptr();  // return next location in put area
    char * _Cdecl epptr(); // return end+1 of put area
    char * _Cdecl eback(); // return base of putback section of get area
    char * _Cdecl gptr();  // return next location in get area
    char * _Cdecl egptr(); // return end+1 of get area
    void    _Cdecl setp(char *, char *); // initialize the put pointers
    void    _Cdecl setg(char *, char *, char *); // initialize the get pointers
    void    _Cdecl pbump(int);  // advance the put pointer
    void    _Cdecl gbump(int);  // advance the get pointer
    void    _Cdecl setb(char *, char *, int = 0 );    // set the buffer area
    void    _Cdecl unbuffered(int);// set the buffering state
    int     _Cdecl unbuffered();    // non-zero if not buffered
    int     _Cdecl allocate();  // set up a buffer area
virtual int _Cdecl doallocate();    // implementation of allocate

private:
    short   alloc_;     // non-zero if buffer should be deleted
    short   unbuf_;     // non-zero if unbuffered
    char * base_;  // start of buffer area
    char * ebuf_;  // end+1 of buffer area
    char * pbase_; // start of put area
    char * pptr_;  // next put location
    char * epptr_; // end+1 of put area
    char * eback_; // base of putback section of get area
    char * gptr_;  // next get location
    char * egptr_; // end+1 of get area

    int     _Cdecl do_snextc(); // implementation of snextc

    // these declarations prevent copying of a streambuf
            _Cdecl streambuf(streambuf &);   // declared but not defined
    void    _Cdecl operator= (streambuf &);  // declared but not defined
};
inline char * _Cdecl streambuf::base()  { return base_; }
inline char * _Cdecl streambuf::pbase() { return pbase_; }
inline char * _Cdecl streambuf::pptr()  { return pptr_; }
inline char * _Cdecl streambuf::epptr() { return epptr_; }
inline char * _Cdecl streambuf::gptr()  { return gptr_; }
inline char * _Cdecl streambuf::egptr() { return egptr_; }
inline char * _Cdecl streambuf::eback() { return eback_; }
inline char * _Cdecl streambuf::ebuf()  { return ebuf_; }
inline int   _Cdecl streambuf::unbuffered()  { return unbuf_; }
inline int   _Cdecl streambuf::blen() { return (int)(ebuf_ - base_);}
inline streambuf * 
            _Cdecl streambuf::setbuf(unsigned char * _p, int _len) 
                { // call the virtual function
                    return setbuf((signed char *)_p, _len); }
inline void _Cdecl streambuf::pbump(int _n) { pptr_ += _n; }
inline void _Cdecl streambuf::gbump(int _n) { gptr_ += _n; }
inline void _Cdecl streambuf::unbuffered(int _unb) { unbuf_ = (_unb != 0); }
inline int  _Cdecl streambuf::in_avail() 
                { return (egptr_ > gptr_) ? (int)(egptr_ - gptr_) : 0; }
inline int  _Cdecl streambuf::out_waiting() 
                { return pptr_ ? (int)(pptr_ - pbase_) : 0; }
inline int  _Cdecl streambuf::allocate() {
                return (base_ || unbuf_) ? 0 : doallocate();
                }
inline int  _Cdecl streambuf::sgetc() {
                return (gptr_ >= egptr_) ? underflow() :
                   (unsigned char)(*gptr_);
                }
inline int  _Cdecl streambuf::snextc() {
                return (! gptr_ || (++gptr_ >= egptr_)) ?
                    do_snextc() :
                    (unsigned char)(*gptr_);
                }
inline int  _Cdecl streambuf::sbumpc() {
                return (gptr_ >= egptr_ && underflow() == EOF) ?
                    EOF :
                    (unsigned char)(*gptr_++);
                }
inline void _Cdecl streambuf::stossc() {
                if( gptr_ >= egptr_ ) underflow();
                else ++gptr_;
                }
inline int  _Cdecl streambuf::sputbackc(char _c) {
                return (gptr_ > eback_) ?
                    (unsigned char)(*--gptr_ = _c) :
                    pbackfail(_c);
                }
inline int  _Cdecl streambuf::sputc(int _c) {
                return (pptr_ >= epptr_) ?
                    overflow((unsigned char)_c) :
                    (unsigned char)(*pptr_++ = _c);
                }
#ifdef _BIG_INLINE_
inline int  _Cdecl streambuf::sputn(const char * _s, int _n) {
                if( _n <= (epptr_ - pptr_) ) {
                    memcpy(pptr_, _s, _n);
                    pbump(_n);
                    return _n;
                }
                return do_sputn(_s, _n);
                }
inline int  _Cdecl streambuf::sgetn(char * _s, int _n) {
                if( _n <= (egptr_ - gptr_) ) {
                    memcpy(_s, gptr_, _n);
                    gbump(_n);
                    return _n;
                }
                return do_sgetn(_s, _n);
                }
#endif


class _CLASSTYPE istream : virtual public ios {
public:
    // constructor and destructor
        _Cdecl istream(streambuf *);
virtual _Cdecl ~istream();

    // Obsolete constructors, for streams 1.2 compatibility
        // obsolete: set skip via format, tie via tie() function
        _Cdecl istream(streambuf *, int _sk, ostream * _t=0);
        // obsolete: use strstream
        _Cdecl istream(int _sz, char *, int _sk=1);
        // obsolete: use fstream
        _Cdecl istream(int _fd, int _sk=1, ostream * _t=0);

    int _Cdecl ipfx(int = 0);       // input prefix function
    int _Cdecl ipfx0();     // same as ipfx(0)
    int _Cdecl ipfx1();     // same as ipfx(1)
    void _Cdecl isfx()      { } // unused input suffix function

    // set/read the get pointer's position
    istream & _Cdecl seekg(streampos);
    istream & _Cdecl seekg(streamoff, seek_dir);
    streampos _Cdecl tellg();

    int _Cdecl sync();

    /*
     * Unformatted extraction operations
     */
    // extract characters into an array
    istream & _Cdecl get(  signed char *, int, char = '\n');
    istream & _Cdecl get(unsigned char *, int, char = '\n');
    istream & _Cdecl read(  signed char *, int);
    istream & _Cdecl read(unsigned char *, int);

    // extract characters into an array up to termination char
    istream & _Cdecl getline(  signed char *, int, char = '\n');
    istream & _Cdecl getline(unsigned char *, int, char = '\n');

    // extract characters into a streambuf up to termination char
    istream & _Cdecl get(streambuf &, char = '\n');

    // extract a single character
    istream & _Cdecl get(unsigned char &);
    istream & _Cdecl get(  signed char &);
    int      _Cdecl get();
                     
    int      _Cdecl peek();     // return next char without extraction
    int      _Cdecl gcount();   // number of unformatted chars last extracted
    istream & _Cdecl putback(char);  // push back char into input

    // extract and discard chars but stop at delim
    istream & _Cdecl ignore(int = 1, int = EOF);

    /*
     * Formatted extraction operations
     */
    istream & _Cdecl operator>> (istream & (_Cdecl *_f)(istream &));
    istream & _Cdecl operator>> (ios & (_Cdecl *_f)(ios &) );
    istream & _Cdecl operator>> (  signed char *);
    istream & _Cdecl operator>> (unsigned char *);
    istream & _Cdecl operator>> (unsigned char &);
    istream & _Cdecl operator>> (  signed char &);
    istream & _Cdecl operator>> (short &);
    istream & _Cdecl operator>> (int &);
    istream & _Cdecl operator>> (long &);
    istream & _Cdecl operator>> (unsigned short &);
    istream & _Cdecl operator>> (unsigned int &);
    istream & _Cdecl operator>> (unsigned long &);
    istream & _Cdecl operator>> (float &);
    istream & _Cdecl operator>> (double &);
    istream & _Cdecl operator>> (long double &);

    // extract from this istream, insert into streambuf
    istream & _Cdecl operator>> (streambuf *);

protected:
            _Cdecl istream();
    void    _Cdecl eatwhite();      // extract consecutive whitespace

private:
    int gcount_;    // chars extracted by last unformatted operation
    signed char _Cdecl do_get();    // implementation of get
};
inline int  _Cdecl istream::gcount() { return gcount_; }
inline int  _Cdecl istream::ipfx0()  { return ipfx(0); }
inline int  _Cdecl istream::ipfx1()  { return ipfx(1); }
#ifdef _BIG_INLINE_
inline istream & _Cdecl istream::operator>> (unsigned char & _c) {
                if( ipfx0() )
                    _c = bp->in_avail() ? bp->sbumpc() : do_get();
                return *this;
                }
inline istream & _Cdecl istream::operator>> (signed char & _c) {
                if( ipfx0() )
                    _c = bp->in_avail() ? bp->sbumpc() : do_get();
                return *this;
                }
#endif
inline istream & _Cdecl istream::operator>> (unsigned char *_p) {
                return *this >> (signed char *)_p;
                }
inline istream & _Cdecl istream::get(unsigned char *_p, int _l, char _t) {
                return get((signed char *)_p, _l, _t);
                }
inline istream & _Cdecl istream::read(unsigned char *_p, int _l) {
                return read((signed char *)_p, _l);
                }
inline istream & _Cdecl istream::getline(unsigned char *_p, int _l, char _t) {
                return getline((signed char *) _p, _l, _t);
                }
inline int      _Cdecl istream::sync() { return bp->sync(); }
inline istream & _Cdecl istream::operator>> (istream & (_Cdecl *_f)(istream &)) {
                return (*_f)(*this);
                }
#ifdef _BIG_INLINE_
inline istream & _Cdecl istream::get(unsigned char & _c) {
                if( ipfx1() )
                    if( bp->in_avail() ) {
                        gcount_ = 1;
                        _c = bp->sbumpc();
                    }
                else _c = do_get();
                return *this;
                }
inline istream & _Cdecl istream::get(signed char & _c) {
                if( ipfx1() )
                    if( bp->in_avail()) {
                        gcount_ = 1;
                        _c = bp->sbumpc();
                    }
                else _c = do_get();
                return *this;
                }
inline int      _Cdecl istream::get() {
                if( ipfx1() ) {
                    int _c = bp->sbumpc();
                    if( _c == EOF ) setstate(eofbit);
                    else gcount_ = 1;
                    return _c;
                }
                else return EOF;
                }
#endif
inline int  _Cdecl istream::peek() { return ipfx1() ? bp->sgetc() : EOF; }


class _CLASSTYPE ostream : virtual public ios {
public:
    // constructors and destructor
        _Cdecl ostream(streambuf *);
virtual _Cdecl ~ostream();
    // Obsolete constructors, for streams 1.2 compatibility
        _Cdecl ostream(int _fd); // obsolete, use fstream
        _Cdecl ostream(int _sz, char *); // obsolete, use strstream

    int _Cdecl opfx();      // output prefix function
    void _Cdecl osfx();     // output suffix function
    ostream & _Cdecl flush();

    // set/read the put pointer's position
    ostream & _Cdecl seekp(streampos);
    ostream & _Cdecl seekp(streamoff, seek_dir);
    streampos _Cdecl tellp();

    /*
     * Unformatted insertion operations
     */
    ostream & _Cdecl put(char);  // insert the character
    ostream & _Cdecl write(const   signed char *, int); // insert the string
    ostream & _Cdecl write(const unsigned char *, int); // insert the string

    /*
     * Formatted insertion operations
     */
    // insert the character
    ostream & _Cdecl operator<< (  signed char);
    ostream & _Cdecl operator<< (unsigned char);

    // for the following, insert character representation of numeric value
    ostream & _Cdecl operator<< (short);
    ostream & _Cdecl operator<< (unsigned short);
    ostream & _Cdecl operator<< (int);
    ostream & _Cdecl operator<< (unsigned int);
    ostream & _Cdecl operator<< (long);
    ostream & _Cdecl operator<< (unsigned long);
    ostream & _Cdecl operator<< (float);
    ostream & _Cdecl operator<< (double);
    ostream & _Cdecl operator<< (long double);

    // insert the null-terminated string
    ostream & _Cdecl operator<< (const   signed char *);
    ostream & _Cdecl operator<< (const unsigned char *);

    // insert character representation of the value of the pointer
    ostream & _Cdecl operator<< (void *);

    // extract from streambuf, insert into this ostream
    ostream & _Cdecl operator<< (streambuf *);

    // manipulators
    ostream & _Cdecl operator<< (ostream & (_Cdecl *_f)(ostream &));
    ostream & _Cdecl operator<< (ios & (_Cdecl *_f)(ios &));

protected:
    int     _Cdecl do_opfx();   // implementation of opfx
    void    _Cdecl do_osfx();   // implementation of osfx
            _Cdecl ostream();

private:
    void    _Cdecl outstr(const signed char *, const signed char *);
};
inline int  _Cdecl ostream::opfx() { return ospecial ? do_opfx() : 1; }
inline void _Cdecl ostream::osfx() { if( x_flags & (stdio | unitbuf) ) do_osfx(); }
#ifdef _BIG_INLINE_
inline ostream & _Cdecl ostream::operator<< (signed char _c) {
                if( opfx() )
                    if( bp->sputc(_c) == EOF ) setstate(badbit);
                        osfx();
                return *this;
                }
#endif
inline ostream & _Cdecl ostream::operator<< (unsigned char _c) {
                return *this << (signed char)_c;
                }
inline ostream & _Cdecl ostream::operator<< (const signed char * _s) {
                outstr(_s, (const signed char *)0);
                return *this;
                }
inline ostream & _Cdecl ostream::operator<< (const unsigned char * _s) {
                outstr((const signed char *)_s, (const signed char *)0);
                return *this;
                }
inline ostream & _Cdecl ostream::operator<< (short _i) 
                { return *this << (long) _i; }
inline ostream & _Cdecl ostream::operator<< (unsigned short _i) 
                { return *this << (unsigned long) _i; }
inline ostream & _Cdecl ostream::operator<< (int _i) 
                { return *this << (long) _i; }
inline ostream & _Cdecl ostream::operator<< (unsigned int _i) 
                { return *this << (unsigned long) _i; }
inline ostream & _Cdecl ostream::operator<< (float _f) 
                { return *this << (long double) _f; }
inline ostream & _Cdecl ostream::operator<< (double _d) 
                { return *this << (long double) _d; }
inline ostream & _Cdecl ostream::operator<< (ostream & (_Cdecl *_f)(ostream &)) 
                { return (*_f)(*this); }
inline ostream & _Cdecl ostream::write(const unsigned char * _s, int _n) 
                { return write((const signed char *)_s, _n); }
inline ostream & _Cdecl ostream::put(char _c) {
                if( bp->sputc(_c) == EOF ) setstate(badbit);
                return *this;
                }
#ifdef _BIG_INLINE_
inline ostream & _Cdecl ostream::write(const signed char * _s, int _n) {
                if( ! fail() )
                    if( bp->sputn((const char *)_s, _n) != _n )
                        setstate(badbit);
                return *this;
                }
#endif


class _CLASSTYPE iostream : public istream, public ostream {
public:
        _Cdecl iostream(streambuf *);
virtual _Cdecl ~iostream();

protected:
        _Cdecl iostream();
};


class _CLASSTYPE istream_withassign : public istream {
public:
        // does no initialization
        _Cdecl istream_withassign();

virtual _Cdecl ~istream_withassign();

    // gets buffer from istream and does entire initialization
    istream_withassign & _Cdecl operator= (istream &);

    // associates streambuf with stream and does entire initialization
    istream_withassign & _Cdecl operator= (streambuf *);
};


class _CLASSTYPE ostream_withassign : public ostream {
public:
        // does no initialization
        _Cdecl ostream_withassign();

virtual _Cdecl ~ostream_withassign();

    // gets buffer from istream and does entire initialization
    ostream_withassign & _Cdecl operator= (ostream &);

    // associates streambuf with stream and does entire initialization
    ostream_withassign & _Cdecl operator= (streambuf *);
};


class _CLASSTYPE iostream_withassign : public iostream {
public:
        // does no initialization
        _Cdecl iostream_withassign();

virtual _Cdecl ~iostream_withassign();

    // gets buffer from stream and does entire initialization
    iostream_withassign & _Cdecl operator= (ios &);

    // associates streambuf with stream and does entire initialization
    iostream_withassign & _Cdecl operator= (streambuf *);
};


/*
 * The predefined streams
 */
extern istream_withassign _Cdecl cin;
extern ostream_withassign _Cdecl cout;
extern ostream_withassign _Cdecl cerr;
extern ostream_withassign _Cdecl clog;

/*
 * Manipulators
 */
ostream & _Cdecl endl(ostream &); // insert newline and flush
ostream & _Cdecl ends(ostream &); // insert null to terminate string
ostream & _Cdecl flush(ostream &);// flush the ostream
ios &     _Cdecl dec(ios &);      // set conversion base to decimal
ios &     _Cdecl hex(ios &);      // set conversion base to hexadecimal
ios &     _Cdecl oct(ios &);      // set conversion base to octal
istream & _Cdecl ws(istream &);   // extract whitespace characters

#pragma option -Vo.

#endif

/*========================================================================================== <--iostream.h Ends-->*/

/*  conio.h

    Direct MSDOS console input/output.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#if !defined(__CONIO_H)
#define __CONIO_H

#if !defined(__DEFS_H)
#include <_defs.h>
#endif

#define _NOCURSOR      0
#define _SOLIDCURSOR   1
#define _NORMALCURSOR  2

struct text_info {
    unsigned char winleft;
    unsigned char wintop;
    unsigned char winright;
    unsigned char winbottom;
    unsigned char attribute;
    unsigned char normattr;
    unsigned char currmode;
    unsigned char screenheight;
    unsigned char screenwidth;
    unsigned char curx;
    unsigned char cury;
};

enum text_modes { LASTMODE=-1, BW40=0, C40, BW80, C80, MONO=7, C4350=64 };

#if !defined(__COLORS)
#define __COLORS

enum COLORS {
    BLACK,          /* dark colors */
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,       /* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};
#endif

#define BLINK       128 /* blink bit */

extern   int _Cdecl directvideo;
extern   int _Cdecl _wscroll;

#ifdef __cplusplus
extern "C" {
#endif

void        _Cdecl clreol( void );
void        _Cdecl clrscr( void );
void        _Cdecl gotoxy( int __x, int __y );
int         _Cdecl wherex( void );
int         _Cdecl wherey( void );
int         _Cdecl getch( void );
int         _Cdecl getche( void );
int         _Cdecl kbhit( void );
int         _Cdecl putch( int __c );

#ifndef _PORT_DEFS
int         _Cdecl inp( unsigned __portid );
unsigned    _Cdecl inpw( unsigned __portid );
int         _Cdecl outp( unsigned __portid, int __value );
unsigned    _Cdecl outpw( unsigned __portid, unsigned __value );
unsigned char _Cdecl inportb( int __portid );
void        _Cdecl outportb( int __portid, unsigned char __value );
#endif  /* !_PORT_DEFS */

int         _Cdecl inport( int __portid );
void        _Cdecl outport( int __portid, int __value );

void        _Cdecl delline( void );
int         _Cdecl gettext( int __left, int __top,
                            int __right, int __bottom,
                            void *__destin);
void        _Cdecl gettextinfo (struct text_info *__r );
void        _Cdecl highvideo( void );
void        _Cdecl insline( void );
void        _Cdecl lowvideo( void );
int         _Cdecl movetext( int __left, int __top,
                             int __right, int __bottom,
                             int __destleft, int __desttop );
void        _Cdecl normvideo( void );
int         _Cdecl puttext( int __left, int __top,
                            int __right, int __bottom,
                            void *__source );
void        _Cdecl textattr( int __newattr );
void        _Cdecl textbackground( int __newcolor );
void        _Cdecl textcolor( int __newcolor );
void        _Cdecl textmode( int __newmode );
void        _Cdecl window( int __left, int __top, int __right, int __bottom);

void        _Cdecl _setcursortype( int __cur_t );
char * _Cdecl cgets( char *__str );
int         _Cdecl cprintf( const char *__format, ... );
int         _Cdecl cputs( const char *__str );
int         _Cdecl cscanf( const char *__format, ... );
char * _Cdecl getpass( const char *__prompt );
int         _Cdecl ungetch( int __ch );

#ifndef _PORT_DEFS
#define _PORT_DEFS

    /* These are in-line functions.  These prototypes just clean up
       some syntax checks and code generation.
     */
unsigned char _Cdecl    __inportb__( int __portid );
unsigned int _Cdecl     __inportw__( int __portid );
void        _Cdecl      __outportb__( int __portid, unsigned char __value );
void        _Cdecl      __outportw__( int __portid, unsigned int __value );

#define inportb         __inportb__
#define inportw         __inportw__
#define outportb        __outportb__
#define outportw        __outportw__

#define inp( portid )      __inportb__( portid )
#define outp( portid,v )  (__outportb__( portid,v ), (int)_AL)
#define inpw( portid )     __inportw__( portid )
#define outpw( portid,v ) (__outportw__( portid,v ), (unsigned)_AX)

#endif  /* _PORT_DEFS */

#ifdef __cplusplus
}
#endif

#endif  /* __CONIO_H */

/*========================================================================================== <--conio.h Ends-->*/

/*  process.h

    Symbols and structures for process management.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#if !defined( __PROCESS_H )
#define __PROCESS_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

/*  Modes available as first argument to the spawnxx functions. */

#define P_WAIT    0 /* child runs separately, parent waits until exit */
#define P_NOWAIT  1 /* both concurrent -- not implemented */
#define P_OVERLAY 2 /* child replaces parent, parent no longer exists */

#define P_NOWAITO 3 /* ASYNCH,       toss RC    */
#define P_DETACH  4 /* DETACHED,     toss RC    */

#define WAIT_CHILD       0
#define WAIT_GRANDCHILD      1

/*  MSDOS does not have any abstract identifier for a process, but the
    process Program Segment Prefix location provides a similar token.
*/

extern  unsigned _Cdecl _psp;    /* provided unconditionally in dos.h */

#define  getpid()   (_psp)

#ifdef __cplusplus
extern "C" {
#endif
void _Cdecl abort(void);
void _Cdecl _cexit(void);
void _Cdecl _c_exit(void);
int  _Cdecl execl(char *__path, char *__arg0, ...);
int  _Cdecl execle(char *__path, char *__arg0, ...);
int  _Cdecl execlp(char *__path, char *__arg0, ...);
int  _Cdecl execlpe(char *__path, char *__arg0, ...);
int  _Cdecl execv(char *__path, char *__argv[]);
int  _Cdecl execve(char *__path, char *__argv[], char **__env);
int  _Cdecl execvp(char *__path, char *__argv[]);
int  _Cdecl execvpe(char *__path, char *__argv[], char **__env);
void _Cdecl exit(int __status);
void _Cdecl _exit(int __status);
int  _Cdecl spawnl(int __mode, char *__path, char *__arg0, ...);
int  _Cdecl spawnle(int __mode, char *__path, char *__arg0, ...);
int  _Cdecl spawnlp(int __mode, char *__path, char *__arg0, ...);
int  _Cdecl spawnlpe(int __mode, char *__path, char *__arg0, ...);
int  _Cdecl spawnv(int __mode, char *__path, char *__argv[]);
int  _Cdecl spawnve(int __mode, char *__path, char *__argv[], char **__env);
int  _Cdecl spawnvp(int __mode, char *__path, char *__argv[]);
int  _Cdecl spawnvpe(int __mode, char *__path, char *__argv[], char **__env);
int  _Cdecl system(const char *__command);
#ifdef __cplusplus
}
#endif

#endif  /* __PROCESS_H */

/*========================================================================================== <--process.h Ends-->*/

/*  dos.h

    Defines structs, unions, macros, and functions for dealing
    with MSDOS and the Intel iAPX86 microprocessor family.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/
#ifndef __DOS_H
#define __DOS_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

extern  int _Cdecl  errno;
extern  int _Cdecl  _doserrno;

/* Variables */
extern  int const _Cdecl _8087;
extern  int       _Cdecl _argc;
extern  char    **_Cdecl _argv;
extern  char    **_Cdecl  environ;

extern  unsigned      _Cdecl _psp;
extern  unsigned      _Cdecl _heaplen;
extern  unsigned char _Cdecl _osmajor;
extern  unsigned char _Cdecl _osminor;
extern  unsigned      _Cdecl _stklen;
extern  unsigned      _Cdecl _fpstklen;
extern  unsigned      _Cdecl _version;
extern  unsigned      _Cdecl _osversion;      /* MSC name for _version */

#define FA_NORMAL   0x00        /* Normal file, no attributes */
#define FA_RDONLY   0x01        /* Read only attribute */
#define FA_HIDDEN   0x02        /* Hidden file */
#define FA_SYSTEM   0x04        /* System file */
#define FA_LABEL    0x08        /* Volume label */
#define FA_DIREC    0x10        /* Directory */
#define FA_ARCH     0x20        /* Archive */

/* MSC names for file attributes */

#define _A_NORMAL   0x00        /* Normal file, no attributes */
#define _A_RDONLY   0x01        /* Read only attribute */
#define _A_HIDDEN   0x02        /* Hidden file */
#define _A_SYSTEM   0x04        /* System file */
#define _A_VOLID    0x08        /* Volume label */
#define _A_SUBDIR   0x10        /* Directory */
#define _A_ARCH     0x20        /* Archive */

#define NFDS    20          /* Maximum number of fds */

struct  fcb {
    char    fcb_drive;      /* 0 = default, 1 = A, 2 = B */
    char    fcb_name[8];    /* File name */
    char    fcb_ext[3];     /* File extension */
    short   fcb_curblk;     /* Current block number */
    short   fcb_recsize;    /* Logical record size in bytes */
    long    fcb_filsize;    /* File size in bytes */
    short   fcb_date;       /* Date file was last written */
    char    fcb_resv[10];   /* Reserved for DOS */
    char    fcb_currec;     /* Current record in block */
    long    fcb_random;     /* Random record number */
};

struct  xfcb    {
    char        xfcb_flag;  /* Contains 0xff to indicate xfcb */
    char        xfcb_resv[5];/* Reserved for DOS */
    char        xfcb_attr;  /* Search attribute */
    struct  fcb xfcb_fcb;   /* The standard fcb */
};

struct  COUNTRY {
    int co_date;
    char    co_curr[5];
    char    co_thsep[2];
    char    co_desep[2];
    char    co_dtsep[2];
    char    co_tmsep[2];
    char    co_currstyle;
    char    co_digits;
    char    co_time;
    long    co_case;
    char    co_dasep[2];
    char    co_fill[10];
};

#if defined(__MSC) && !defined(__cplusplus)
struct  DOSERROR {
        int     exterror;
        char    class;
        char    action;
        char    locus;
};
#else
struct  DOSERROR {
        int     de_exterror;
        char    de_class;
        char    de_action;
        char    de_locus;
};
#endif  /* __MSC and not C++ */

struct  dfree   {
    unsigned df_avail;
    unsigned df_total;
    unsigned df_bsec;
    unsigned df_sclus;
};

struct diskfree_t {
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
};

struct  fatinfo {
    char     fi_sclus;
    char     fi_fatid;
    unsigned fi_nclus;
    int      fi_bysec;
};

struct  devhdr  {
    long        dh_next;        /* Next device pointer */
    short       dh_attr;        /* Attributes */
    unsigned short  dh_strat;   /* Driver strategy routine */
    unsigned short  dh_inter;   /* Driver interrupt routine */
    char        dh_name[8];     /* Device name */
};

struct  time    {
    unsigned char   ti_min;     /* Minutes */
    unsigned char   ti_hour;    /* Hours */
    unsigned char   ti_hund;    /* Hundredths of seconds */
    unsigned char   ti_sec;     /* Seconds */
};

struct dostime_t {
    unsigned char hour;         /* Hours */
    unsigned char minute;       /* Minutes */
    unsigned char second;       /* Seconds */
    unsigned char hsecond;      /* Hundredths of seconds */
};

struct  date    {
    int     da_year;        /* Year - 1980 */
    char        da_day;     /* Day of the month */
    char        da_mon;     /* Month (1 = Jan) */
};

struct dosdate_t {
    unsigned char day;      /* 1-31 */
    unsigned char month;    /* 1-12 */
    unsigned int  year;     /* 1980 - 2099 */
    unsigned char dayofweek;/* 0 - 6 (0=Sunday) */
};

#ifndef _REG_DEFS
#define _REG_DEFS

struct WORDREGS {
    unsigned int    ax, bx, cx, dx, si, di, cflag, flags;
};

struct BYTEREGS {
    unsigned char   al, ah, bl, bh, cl, ch, dl, dh;
};

union   REGS    {
    struct  WORDREGS x;
    struct  BYTEREGS h;
};

struct  SREGS   {
    unsigned int    es;
    unsigned int    cs;
    unsigned int    ss;
    unsigned int    ds;
};

struct  REGPACK {
    unsigned    r_ax, r_bx, r_cx, r_dx;
    unsigned    r_bp, r_si, r_di, r_ds, r_es, r_flags;
};

#endif  /* _REG_DEFS */

typedef struct {
    char    ds_drive;          /* do not change    */
    char    ds_pattern [13];   /*  these fields,       */
    char    ds_reserved [7];   /*   Microsoft reserved */
    char    ds_attrib;
    short   ds_time;
    short   ds_date;
    long    ds_size;
    char    ds_nameZ [13];     /* result of the search, asciiz */
}   dosSearchInfo;  /* used with DOS functions 4E, 4F   */


#ifndef _FFBLK_DEF
#define _FFBLK_DEF
struct  ffblk   {
    char        ff_reserved[21];
    char        ff_attrib;
    unsigned    ff_ftime;
    unsigned    ff_fdate;
    long        ff_fsize;
    char        ff_name[13];
};
#endif  /* _FFBLK_DEF */

/* The MSC find_t structure corresponds exactly to the ffblk structure */
struct find_t {
    char     reserved[21];      /* Microsoft reserved - do not change */
    char     attrib;            /* attribute byte for matched file */
    unsigned wr_time;           /* time of last write to file */
    unsigned wr_date;           /* date of last write to file */
    long     size;              /* size of file */
    char     name[13];          /* asciiz name of matched file */
};

/* axret values for _hardresume() */

#define _HARDERR_IGNORE 0   /* ignore error */
#define _HARDERR_RETRY  1   /* retry the operation */
#define _HARDERR_ABORT  2   /* abort program */
#define _HARDERR_FAIL   3   /* fail the operation */

#define SEEK_CUR    1
#define SEEK_END    2
#define SEEK_SET    0

#ifdef __cplusplus
extern "C" {
#endif

int         _Cdecl absread( int __drive, int __nsects, long __lsect,
                            void *__buffer );
int         _Cdecl abswrite( int __drive, int __nsects, long __lsect,
                             void *__buffer );
int         _Cdecl allocmem( unsigned __size, unsigned *__segp );
int         _CType bdos( int __dosfun, unsigned __dosdx, unsigned __dosal );
int         _CType bdosptr( int __dosfun, void *__argument, unsigned __dosal );
struct COUNTRY *_Cdecl country( int __xcode, struct COUNTRY *__cp);
void        _Cdecl ctrlbrk( int _Cdecl( *handler )( void ));
void        _CType delay( unsigned __milliseconds );
void        _Cdecl disable( void );
int         _Cdecl dosexterr( struct DOSERROR *__eblkp );
long        _Cdecl dostounix( struct date *__d, struct time *__t );

unsigned    _Cdecl _dos_allocmem( unsigned __size, unsigned *__segp );
unsigned    _Cdecl _dos_close ( int __fd );
unsigned    _Cdecl _dos_creat( const char *__pathP, unsigned __attr, 
                    int *__fd );
unsigned    _Cdecl _dos_creatnew( const char *__pathP, unsigned __attr,
                    int *__fd );
unsigned    _Cdecl _dos_findfirst( const char *__path,
                    unsigned __attrib,
                    struct find_t *__finfo );
unsigned    _Cdecl _dos_findnext( struct find_t *__finfo );
unsigned    _Cdecl _dos_freemem( unsigned __segx );
void        _Cdecl _dos_getdate( struct dosdate_t *__datep );
unsigned    _Cdecl _dos_getdiskfree( unsigned __drive,
                      struct diskfree_t *__dtable);
void        _Cdecl _dos_getdrive( unsigned *__drive );
unsigned    _Cdecl _dos_getfileattr( const char *__filename,
                      unsigned *__attrib );
unsigned    _Cdecl _dos_getftime( int __fd, unsigned *__date,
                   unsigned *__time );
void        _Cdecl _dos_gettime( struct dostime_t *__timep );
void        _Cdecl _dos_keep(unsigned char __status, unsigned __size);
unsigned    _Cdecl _dos_open( const char *__pathP, unsigned __oflag,
                   int *__fd );
unsigned    _Cdecl _dos_read( int __fd, void far *__buf, unsigned __len,
                   unsigned *__nread );
unsigned    _Cdecl _dos_setblock( unsigned __size, unsigned __segx,
                   unsigned *__maxp );
unsigned    _Cdecl _dos_setdate( struct dosdate_t *__datep );
void        _Cdecl _dos_setdrive( unsigned __drive, unsigned *__ndrives );
unsigned    _Cdecl _dos_setfileattr( const char *__filename,
                      unsigned __attrib);
unsigned    _Cdecl _dos_setftime( int __fd, unsigned __date, unsigned __time );
unsigned    _Cdecl _dos_settime( struct dostime_t *__timep );
unsigned    _Cdecl _dos_write( int __fd, void far *__buf, unsigned __len,
                unsigned *__nread );

void        __emit__( unsigned char __byte, ...);
void        _Cdecl enable( void );

int         _Cdecl freemem( unsigned __segx );
int         _Cdecl getcbrk( void );
void        _CType getdate( struct date *__datep );
void        _Cdecl getdfree( unsigned char __drive,
                    struct dfree *__dtable );
int         _Cdecl _getdrive( void );
void        _Cdecl getfat( unsigned char __drive,
                    struct fatinfo *__dtable );
void        _Cdecl getfatd( struct fatinfo *__dtable );
unsigned    _Cdecl getpsp( void );
int         _Cdecl getswitchar( void );
void        _CType gettime( struct time *__timep );
int         _Cdecl getverify( void );

#ifdef __cplusplus
void        _Cdecl _harderr( void _Cdecl (far *__fptr)( unsigned __deverr,
                             unsigned __doserr, unsigned far *__hdr) );
#else
void        _Cdecl _harderr( void _Cdecl (far *__fptr)( ) );
#endif
void        _Cdecl _hardresume( int __axret );
void        _Cdecl _hardretn( int __retn );

#ifdef __cplusplus
void        _CType harderr( int _Cdecl( *__handler )( int __errval, int __ax, 
                            int __bp, int __si) );
#else
void        _CType harderr( int _Cdecl( *__handler )( ) );
#endif
void        _CType hardresume( int __axret );
void        _CType hardretn( int __retn );

#ifndef _PORT_DEFS
int         _Cdecl inp( unsigned __portid );
unsigned    _Cdecl inpw( unsigned __portid );
#endif

int         _Cdecl inport( int __portid );
#ifndef _PORT_DEFS
unsigned char _Cdecl inportb( int __portid );
#endif
int         _Cdecl int86( int __intno,
                          union REGS *__inregs,
                          union REGS *__outregs );
int         _Cdecl int86x( int __intno,
                           union REGS *__inregs,
                           union REGS *__outregs,
                           struct SREGS *__segregs );
int         _Cdecl intdos( union REGS *__inregs,
                           union REGS *__outregs );
int         _Cdecl intdosx( union REGS *__inregs,
                                     union REGS *__outregs,
                                     struct SREGS *__segregs );
void        _Cdecl intr( int __intno, struct REGPACK *__preg );

void        _Cdecl keep( unsigned char __status, unsigned __size );
void        _Cdecl nosound( void );

#ifndef _PORT_DEFS
int         _Cdecl outp( unsigned __portid, int __value );
unsigned    _Cdecl outpw( unsigned __portid, unsigned __value );
#endif

void        _Cdecl outport( int __portid, int __value );
#ifndef _PORT_DEFS
void        _Cdecl outportb( int __portid, unsigned char __value );
#endif
char * _Cdecl parsfnm( const char *__cmdline,
                       struct fcb *__fcb, int __opt );
int         _Cdecl peek( unsigned __segment, unsigned __offset );
char        _Cdecl peekb( unsigned __segment, unsigned __offset );
void        _Cdecl poke( unsigned __segment, unsigned __offset, int __value);
void        _Cdecl pokeb( unsigned __segment,
                          unsigned __offset, char __value );
int         _Cdecl randbrd( struct fcb *__fcb, int __rcnt );
int         _Cdecl randbwr( struct fcb *__fcb, int __rcnt );
void        _Cdecl segread( struct SREGS *__segp );
int         _Cdecl setblock( unsigned __segx, unsigned __newsize );
int         _Cdecl setcbrk( int __cbrkvalue );
void        _Cdecl setdate( struct date *__datep );
void        _Cdecl setswitchar( char __ch );
void        _Cdecl settime( struct time *__timep );
void        _Cdecl setverify( int __value );
void        _Cdecl sleep( unsigned __seconds );
void        _Cdecl sound( unsigned __frequency );
void        _Cdecl unixtodos( long __time, struct date *__d,
                              struct time *__t );
int         _CType unlink( const char *__path );

    /* These are in-line functions.  These prototypes just clean up
       some syntax checks and code generation.
     */

void        _Cdecl          __cli__( void );
void        _Cdecl          __sti__( void );
void        _Cdecl          __int__( int __interruptnum );

#define disable( ) __emit__( (char )( 0xfa ) )
#define _disable( ) __emit__( (char )( 0xfa ) ) /* MSC name */
#define enable( )  __emit__( (char )( 0xfb ) )
#define _enable( )  __emit__( (char )( 0xfb ) ) /* MSC name */

#define geninterrupt( i ) __int__( i )      /* Interrupt instruction */

#ifndef _PORT_DEFS
#define _PORT_DEFS

unsigned char _Cdecl    __inportb__( int __portid );
unsigned int _Cdecl     __inportw__( int __portid );
void        _Cdecl      __outportb__( int __portid, unsigned char __value );
void        _Cdecl      __outportw__( int __portid, unsigned int __value );

#define inportb         __inportb__
#define outportb        __outportb__

/* MSC-compatible macros for port I/O */
#define inp( portid )      __inportb__( portid )
#define outp( portid,v )  (__outportb__( portid,v ), (int)_AL)
#define inpw( portid )     __inportw__( portid )
#define outpw( portid,v ) (__outportw__( portid,v ), (unsigned)_AX)

#endif  /* _PORT_DEFS */

#if !__STDC__

extern  unsigned    _Cdecl  _ovrbuffer;
int cdecl far _OvrInitEms( unsigned __emsHandle, unsigned __emsFirst,
                           unsigned __emsPages );
int cdecl far _OvrInitExt( unsigned long __extStart,
                           unsigned long __extLength );

char far *cdecl getdta( void );
void      cdecl setdta( char far *__dta );

#define MK_FP( seg,ofs )( (void _seg * )( seg ) +( void near * )( ofs ))
#define FP_SEG( fp )( (unsigned )( void _seg * )( void far * )( fp ))
#define FP_OFF( fp )( (unsigned )( fp ))

#ifdef __cplusplus
void        _Cdecl _chain_intr ( void interrupt (far *__target)( ... ));
void interrupt( far * _Cdecl _dos_getvect( unsigned __interruptno ))( ... );
void interrupt( far * _CType getvect( int __interruptno ))( ... );
void        _Cdecl _dos_setvect( unsigned __interruptno,
                                 void interrupt( far *__isr )( ... ));
void        _CType setvect( int __interruptno,
                            void interrupt( far *__isr )( ... ));
int  inline _Cdecl peek( unsigned __segment, unsigned __offset )  
                  { return( *( (int  far* )MK_FP( __segment, __offset )) ); }
char inline _Cdecl peekb( unsigned __segment, unsigned __offset ) 
                  { return( *( (char far* )MK_FP( __segment, __offset )) ); }
void inline _Cdecl poke( unsigned __segment, unsigned __offset, int __value )  
               {( *( (int  far* )MK_FP( __segment, __offset )) = __value ); }
void inline _Cdecl pokeb( unsigned __segment, unsigned __offset, char __value )   
               {( *( (char far* )MK_FP( __segment, __offset )) = __value ); }
#else
void        _Cdecl _chain_intr ( void interrupt (far *__target)( ));
void interrupt( far * _Cdecl _dos_getvect( unsigned __interruptno ))( );
void interrupt( far * _CType getvect( int __interruptno ))( );
void        _Cdecl _dos_setvect( unsigned __interruptno,
                void interrupt( far *__isr )( ));
void        _CType setvect( int __interruptno,
                void interrupt( far *__isr )( ) );
#define peek( a,b )( *( (int  far* )MK_FP( (a ),( b )) ))
#define peekb( a,b )( *( (char far* )MK_FP( (a ),( b )) ))
#define poke( a,b,c )( *( (int  far* )MK_FP( (a ),( b )) ) =( int )( c ))
#define pokeb( a,b,c )( *( (char far* )MK_FP( (a ),( b )) ) =( char )( c ))
#endif  /* __cplusplus */

#endif  /* !__STDC__ */


#ifdef __cplusplus
}
#endif

#endif  /* __DOS_H */


/*========================================================================================== <--dos.h Ends-->*/

/*  string.h

    Definitions for memory and string functions.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#ifndef __STRING_H
#define __STRING_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif
void * _Cdecl memchr  (const void *__s, int __c, size_t __n);
int         _Cdecl memcmp(const void *__s1,
                          const void *__s2, size_t __n);
void * _Cdecl memcpy(void *__dest, const void *__src,
                          size_t __n);
void * _CType memmove(void *__dest, const void *__src,
                           size_t __n);
void * _CType memset(void *__s, int __c, size_t __n);
char * _CType strcat(char *__dest, const char *__src);
char * _CType strchr(const char *__s, int __c);
int         _CType strcmp(const char *__s1, const char *__s2);
int         _Cdecl strcoll(const char *__s1, const char *__s2);
char * _CType strcpy(char *__dest, const char *__src);
size_t      _Cdecl strcspn(const char *__s1, const char *__s2);
char * _Cdecl strerror(int __errnum);
size_t      _CType strlen(const char *__s);
char * _CType strncat(char *__dest, const char *__src,
               size_t __maxlen);
int         _CType strncmp(const char *__s1, const char *__s2,
               size_t __maxlen);
char * _CType strncpy(char *__dest, const char *__src,
                           size_t __maxlen);
char * _CType strpbrk(const char *__s1, const char *__s2);
char * _CType strrchr(const char *__s, int __c);
size_t      _Cdecl strspn(const char *__s1, const char *__s2);
char * _Cdecl strstr(const char *__s1, const char *__s2);
char * _CType strtok(char *__s1, const char *__s2);
size_t      _Cdecl strxfrm(char *__s1, const char *__s2,
               size_t __n );
char * _Cdecl _strerror(const char *__s);


#if !__STDC__
/* compatibility with other compilers */
#define strcmpi(s1,s2)      stricmp(s1,s2)
#define strncmpi(s1,s2,n)   strnicmp(s1,s2,n)

void * _Cdecl memccpy(void *__dest, const void *__src,
               int __c, size_t __n);
int         _Cdecl memicmp(const void *__s1, const void *__s2,
                           size_t __n);
void        _Cdecl movedata(unsigned __srcseg,unsigned __srcoff,
                            unsigned __dstseg,unsigned __dstoff, size_t __n);
char * _CType stpcpy(char *__dest, const char *__src);
char * _Cdecl _stpcpy(char *__dest, const char *__src);
char * _Cdecl strdup(const char *__s);
int         _CType stricmp(const char *__s1, const char *__s2);
char * _CType strlwr(char *__s);
int         _CType strnicmp(const char *__s1, const char *__s2,
                size_t __maxlen);
char * _Cdecl strnset(char *__s, int __ch, size_t __n);
char * _Cdecl strrev(char *__s);
char * _Cdecl strset(char *__s, int __ch);
char * _CType strupr(char *__s);

void    far * far cdecl _fmemccpy(void far *__dest, const void far *__src,
                int c, size_t __n);
void    far * far cdecl _fmemchr(const void far *__s, int c, size_t __n);
int           far cdecl _fmemcmp(const void far *__s1, const void far *__s2,
                size_t __n);
void    far * far cdecl _fmemcpy(void far *__dest, const void far *__src,
                size_t __n);
int           far cdecl _fmemicmp(const void far *__s1, const void far *__s2,
                size_t __n);
void    far * far cdecl _fmemmove(void far *__dest, const void far *__src,
                size_t __n);
void    far * far cdecl _fmemset(void far *__s, int c, size_t __n);
void          far cdecl _fmovmem(const void far *__src, void far *__dest,
                unsigned __length);
void          far cdecl _fsetmem(void far *__dest,unsigned __length,
                char __value);

char    far * far cdecl _fstrcat(char far *__dest, const char far *__src);
char    far * far cdecl _fstrchr(const char far *__s, int c);
int           far cdecl _fstrcmp(const char far *__s1, const char far *__s2);
char    far * far cdecl _fstrcpy(char far *__dest, const char far *__src);
size_t        far cdecl _fstrcspn(const char far *__s1, const char far *__s2);
char    far * far cdecl _fstrdup(const char far *__s);
int           far cdecl _fstricmp(const char far *__s1, const char far *__s2);
size_t        far cdecl _fstrlen(const char far *__s);
char    far * far cdecl _fstrlwr(char far *__s);
char    far * far cdecl _fstrncat(char far *__dest, const char far *__src,
             size_t maxlen);
int           far cdecl _fstrncmp(const char far *__s1, const char far *__s2,
             size_t maxlen);
char    far * far cdecl _fstrncpy(char far *__dest, const char far *__src,
             size_t maxlen);
int           far cdecl _fstrnicmp(const char far *__s1, const char far *__s2,
              size_t maxlen);
char    far * far cdecl _fstrnset(char far *__s, int ch, size_t __n);
char    far * far cdecl _fstrpbrk(const char far *__s1, const char far *__s2);
char    far * far cdecl _fstrrchr(const char far *__s, int c);
char    far * far cdecl _fstrrev(char far *__s);
char    far * far cdecl _fstrset(char far *__s, int ch);
size_t        far cdecl _fstrspn(const char far *__s1, const char far *__s2);
char    far * far cdecl _fstrstr(const char far *__s1, const char far *__s2);
char    far * far cdecl _fstrtok(char far *__s1, const char far *__s2);
char    far * far cdecl _fstrupr(char far *__s);

#endif  /* ! __STDC__ */

#ifdef __cplusplus
}
#endif

#endif

/*========================================================================================== <--string.h Ends-->*/

/*  graphics.h

    Definitions for Graphics Package.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#if !defined(__GRAPHICS_H)
#define __GRAPHICS_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

enum graphics_errors {      /* graphresult error return codes */
    grOk                =   0,
    grNoInitGraph       =  -1,
    grNotDetected       =  -2,
    grFileNotFound      =  -3,
    grInvalidDriver     =  -4,
    grNoLoadMem         =  -5,
    grNoScanMem         =  -6,
    grNoFloodMem        =  -7,
    grFontNotFound      =  -8,
    grNoFontMem         =  -9,
    grInvalidMode       = -10,
    grError             = -11,   /* generic error */
    grIOerror           = -12,
    grInvalidFont       = -13,
    grInvalidFontNum    = -14,
    grInvalidVersion    = -18
};

enum graphics_drivers {     /* define graphics drivers */
    DETECT,         /* requests autodetection */
    CGA, MCGA, EGA, EGA64, EGAMONO, IBM8514,    /* 1 - 6 */
    HERCMONO, ATT400, VGA, PC3270,          /* 7 - 10 */
    CURRENT_DRIVER = -1
};

enum graphics_modes {       /* graphics modes for each driver */
    CGAC0      = 0,  /* 320x200 palette 0; 1 page   */
    CGAC1      = 1,  /* 320x200 palette 1; 1 page   */
    CGAC2      = 2,  /* 320x200 palette 2: 1 page   */
    CGAC3      = 3,  /* 320x200 palette 3; 1 page   */
    CGAHI      = 4,  /* 640x200 1 page          */
    MCGAC0     = 0,  /* 320x200 palette 0; 1 page   */
    MCGAC1     = 1,  /* 320x200 palette 1; 1 page   */
    MCGAC2     = 2,  /* 320x200 palette 2; 1 page   */
    MCGAC3     = 3,  /* 320x200 palette 3; 1 page   */
    MCGAMED    = 4,  /* 640x200 1 page          */
    MCGAHI     = 5,  /* 640x480 1 page          */
    EGALO      = 0,  /* 640x200 16 color 4 pages    */
    EGAHI      = 1,  /* 640x350 16 color 2 pages    */
    EGA64LO    = 0,  /* 640x200 16 color 1 page     */
    EGA64HI    = 1,  /* 640x350 4 color  1 page     */
    EGAMONOHI  = 0,  /* 640x350 64K on card, 1 page - 256K on card, 4 pages */
    HERCMONOHI = 0,  /* 720x348 2 pages         */
    ATT400C0   = 0,  /* 320x200 palette 0; 1 page   */
    ATT400C1   = 1,  /* 320x200 palette 1; 1 page   */
    ATT400C2   = 2,  /* 320x200 palette 2; 1 page   */
    ATT400C3   = 3,  /* 320x200 palette 3; 1 page   */
    ATT400MED  = 4,  /* 640x200 1 page          */
    ATT400HI   = 5,  /* 640x400 1 page          */
    VGALO      = 0,  /* 640x200 16 color 4 pages    */
    VGAMED     = 1,  /* 640x350 16 color 2 pages    */
    VGAHI      = 2,  /* 640x480 16 color 1 page     */
    PC3270HI   = 0,  /* 720x350 1 page          */
    IBM8514LO  = 0,  /* 640x480 256 colors      */
    IBM8514HI  = 1   /*1024x768 256 colors      */
};

/* Colors for setpalette and setallpalette */

#if !defined(__COLORS)
#define __COLORS

enum COLORS {
    BLACK,          /* dark colors */
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,       /* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};
#endif

enum CGA_COLORS {
    CGA_LIGHTGREEN     = 1,     /* Palette C0 Color Names   */
    CGA_LIGHTRED       = 2,
    CGA_YELLOW         = 3,

    CGA_LIGHTCYAN      = 1,     /* Palette C1 Color Names   */
    CGA_LIGHTMAGENTA   = 2,
    CGA_WHITE          = 3,

    CGA_GREEN          = 1,     /* Palette C2 Color Names   */
    CGA_RED            = 2,
    CGA_BROWN          = 3,

    CGA_CYAN           = 1,     /* Palette C3 Color Names   */
    CGA_MAGENTA        = 2,
    CGA_LIGHTGRAY      = 3
};


enum EGA_COLORS {
    EGA_BLACK        =  0,      /* dark colors */
    EGA_BLUE         =  1,
    EGA_GREEN        =  2,
    EGA_CYAN         =  3,
    EGA_RED          =  4,
    EGA_MAGENTA      =  5,
    EGA_BROWN        =  20,
    EGA_LIGHTGRAY    =  7,
    EGA_DARKGRAY     =  56,     /* light colors */
    EGA_LIGHTBLUE    =  57,
    EGA_LIGHTGREEN   =  58,
    EGA_LIGHTCYAN    =  59,
    EGA_LIGHTRED     =  60,
    EGA_LIGHTMAGENTA =  61,
    EGA_YELLOW       =  62,
    EGA_WHITE        =  63
};

enum line_styles {      /* Line styles for get/setlinestyle */
    SOLID_LINE   = 0,
    DOTTED_LINE  = 1,
    CENTER_LINE  = 2,
    DASHED_LINE  = 3,
    USERBIT_LINE = 4,   /* User defined line style */
};

enum line_widths {      /* Line widths for get/setlinestyle */
    NORM_WIDTH  = 1,
    THICK_WIDTH = 3,
};

enum font_names {
    DEFAULT_FONT        = 0,    /* 8x8 bit mapped font */
    TRIPLEX_FONT        = 1,    /* "Stroked" fonts */
    SMALL_FONT          = 2,
    SANS_SERIF_FONT     = 3,
    GOTHIC_FONT         = 4,
    SCRIPT_FONT         = 5,        
    SIMPLEX_FONT        = 6,       
    TRIPLEX_SCR_FONT    = 7,
    COMPLEX_FONT        = 8,       
    EUROPEAN_FONT       = 9,  
    BOLD_FONT           = 10      
};

#define HORIZ_DIR   0   /* left to right */
#define VERT_DIR    1   /* bottom to top */

#define USER_CHAR_SIZE  0   /* user-defined char size */

enum fill_patterns {    /* Fill patterns for get/setfillstyle */
    EMPTY_FILL,         /* fills area in background color */
    SOLID_FILL,         /* fills area in solid fill color */
    LINE_FILL,          /* --- fill */
    LTSLASH_FILL,       /* /// fill */
    SLASH_FILL,         /* /// fill with thick lines */
    BKSLASH_FILL,       /* \\\ fill with thick lines */
    LTBKSLASH_FILL,     /* \\\ fill */
    HATCH_FILL,         /* light hatch fill */
    XHATCH_FILL,        /* heavy cross hatch fill */
    INTERLEAVE_FILL,    /* interleaving line fill */
    WIDE_DOT_FILL,      /* Widely spaced dot fill */
    CLOSE_DOT_FILL,     /* Closely spaced dot fill */
    USER_FILL           /* user defined fill */
};

enum putimage_ops {     /* BitBlt operators for putimage */
    COPY_PUT,           /* MOV */
    XOR_PUT,            /* XOR */
    OR_PUT,             /* OR  */
    AND_PUT,            /* AND */
    NOT_PUT             /* NOT */
};

enum text_just {        /* Horizontal and vertical justification
                           for settextjustify */
    LEFT_TEXT   = 0,
    CENTER_TEXT = 1,
    RIGHT_TEXT  = 2,

    BOTTOM_TEXT = 0,
     /* CENTER_TEXT = 1,  already defined above */
    TOP_TEXT    = 2
};


#define MAXCOLORS 15

struct palettetype {
    unsigned char size;
    signed char colors[MAXCOLORS+1];
};

struct linesettingstype {
    int linestyle;
    unsigned upattern;
    int thickness;
};

struct textsettingstype {
    int font;
    int direction;
    int charsize;
    int horiz;
    int vert;
};

struct fillsettingstype {
    int pattern;
    int color;
};

struct pointtype {
    int x, y;
};

struct viewporttype {
    int left, top, right, bottom;
    int clip;
};

struct arccoordstype {
    int x, y;
    int xstart, ystart, xend, yend;
};

#ifdef __cplusplus
extern "C" {
#endif
void       far _Cdecl arc(int __x, int __y, int __stangle, int __endangle,
              int __radius);
void       far _Cdecl bar(int __left, int __top, int __right, int __bottom);
void       far _Cdecl bar3d(int __left, int __top, int __right, int __bottom,
                int __depth, int __topflag);
void       far _Cdecl circle(int __x, int __y, int __radius);
void       far _Cdecl cleardevice(void);
void       far _Cdecl clearviewport(void);
void       far _Cdecl closegraph(void);
void       far _Cdecl detectgraph(int far *__graphdriver,int far *__graphmode);
void       far _Cdecl drawpoly(int __numpoints, const int far *__polypoints);
void       far _Cdecl ellipse(int __x, int __y, int __stangle, int __endangle,
                  int __xradius, int __yradius);
void       far _Cdecl fillellipse( int __x, int __y, int __xradius, int __yradius );
void       far _Cdecl fillpoly(int __numpoints, const int far *__polypoints);
void       far _Cdecl floodfill(int __x, int __y, int __border);
void       far _Cdecl getarccoords(struct arccoordstype far *__arccoords);
void       far _Cdecl getaspectratio(int far *__xasp, int far *__yasp);
int    far _Cdecl getbkcolor(void);
int    far _Cdecl getcolor(void);
struct palettetype far * far _Cdecl getdefaultpalette( void );
char *     far _Cdecl getdrivername( void );
void       far _Cdecl getfillpattern(char far *__pattern);
void       far _Cdecl getfillsettings(struct fillsettingstype far *__fillinfo);
int    far _Cdecl getgraphmode(void);
void       far _Cdecl getimage(int __left, int __top, int __right, int __bottom,
                   void far *__bitmap);
void       far _Cdecl getlinesettings(struct linesettingstype far *__lineinfo);
int    far _Cdecl getmaxcolor(void);
int    far _Cdecl getmaxmode(void);
int    far _Cdecl getmaxx(void);
int    far _Cdecl getmaxy(void);
char *     far _Cdecl getmodename( int __mode_number );
void       far _Cdecl getmoderange(int __graphdriver, int far *__lomode,
                   int far *__himode);
unsigned   far _Cdecl getpixel(int __x, int __y);
void       far _Cdecl getpalette(struct palettetype far *__palette);
int    far _Cdecl getpalettesize( void );
void       far _Cdecl gettextsettings(struct textsettingstype far *__texttypeinfo);
void       far _Cdecl getviewsettings(struct viewporttype far *__viewport);
int    far _Cdecl getx(void);
int    far _Cdecl gety(void);
void       far _Cdecl graphdefaults(void);
char *     far _Cdecl grapherrormsg(int __errorcode);
void       far _Cdecl _graphfreemem(void far *__ptr, unsigned __size);
void far * far _Cdecl _graphgetmem(unsigned __size);
int    far _Cdecl graphresult(void);
unsigned   far _Cdecl imagesize(int __left, int __top, int __right, int __bottom);
void       far _Cdecl initgraph(int  far *__graphdriver,
                int  far *__graphmode,
                const char far *__pathtodriver);
int    far _Cdecl installuserdriver( const char far *__name,
                int huge (*detect)(void) );
int    far _Cdecl installuserfont( const char far *__name );
void       far _Cdecl line(int __x1, int __y1, int __x2, int __y2);
void       far _Cdecl linerel(int __dx, int __dy);
void       far _Cdecl lineto(int __x, int __y);
void       far _Cdecl moverel(int __dx, int __dy);
void       far _Cdecl moveto(int __x, int __y);
void       far _Cdecl outtext(const char far *__textstring);
void       far _Cdecl outtextxy(int __x, int __y, const char far *__textstring);
void       far _Cdecl pieslice(int __x, int __y, int __stangle, int __endangle,
                   int __radius);
void       far _Cdecl putimage(int __left, int __top, const void far *__bitmap,
                int __op);
void       far _Cdecl putpixel(int __x, int __y, int __color);
void       far _Cdecl rectangle(int __left, int __top, int __right, int __bottom);
void       far _Cdecl restorecrtmode(void);
void       far _Cdecl sector( int __X, int __Y, int __StAngle, int __EndAngle,
                  int __XRadius, int __YRadius );
void       far _Cdecl setactivepage(int __page);
void       far _Cdecl setallpalette(const struct palettetype far *__palette);
void       far _Cdecl setaspectratio( int __xasp, int __yasp );
void       far _Cdecl setbkcolor(int __color);
void       far _Cdecl setcolor(int __color);
void       far _Cdecl setfillpattern(const char far *__upattern, int __color);
void       far _Cdecl setfillstyle(int __pattern, int __color);
unsigned   far _Cdecl setgraphbufsize(unsigned __bufsize);
void       far _Cdecl setgraphmode(int __mode);
void       far _Cdecl setlinestyle(int __linestyle, unsigned __upattern,
                   int __thickness);
void       far _Cdecl setpalette(int __colornum, int __color);
void       far _Cdecl setrgbpalette(int __colornum,
                    int __red, int __green, int __blue);
void       far _Cdecl settextjustify(int __horiz, int __vert);
void       far _Cdecl settextstyle(int __font, int __direction, int __charsize);
void       far _Cdecl setusercharsize(int __multx, int __divx,
                      int __multy, int __divy);
void       far _Cdecl setviewport(int __left, int __top, int __right, int __bottom,
                  int __clip);
void       far _Cdecl setvisualpage(int __page);
void       far _Cdecl setwritemode( int __mode );
int    far _Cdecl textheight(const char far *__textstring);
int    far _Cdecl textwidth(const char far *__textstring);

/***** graphics drivers *****/

int        _Cdecl registerbgidriver(void (*driver)(void));
int    far _Cdecl registerfarbgidriver(void far *__driver);

/* !!        These "functions" are NOT user-callable          !! */
/* !! They are there just so you can link in graphics drivers !! */

void           _Cdecl CGA_driver(void);
void           _Cdecl EGAVGA_driver(void);
void           _Cdecl IBM8514_driver(void);
void           _Cdecl Herc_driver(void);
void           _Cdecl ATT_driver(void);
void           _Cdecl PC3270_driver(void);

extern int far _Cdecl CGA_driver_far[];
extern int far _Cdecl EGAVGA_driver_far[];
extern int far _Cdecl IBM8514_driver_far[];
extern int far _Cdecl Herc_driver_far[];
extern int far _Cdecl ATT_driver_far[];
extern int far _Cdecl PC3270_driver_far[];


/***** graphics fonts *****/

int        _Cdecl registerbgifont(void (*font)(void));
int    far _Cdecl registerfarbgifont(void far *__font);

/* !!   These "functions" are NOT user-callable,   !! */
/* !! they are there just so you can link in fonts !! */

void           _Cdecl   triplex_font(void);
void           _Cdecl     small_font(void);
void           _Cdecl sansserif_font(void);
void           _Cdecl    gothic_font(void);

extern int far _Cdecl   triplex_font_far[];
extern int far _Cdecl     small_font_far[];
extern int far _Cdecl sansserif_font_far[];
extern int far _Cdecl    gothic_font_far[];

#ifdef __cplusplus
}
#endif

#endif

/*========================================================================================== <--graphics.h Ends-->*/

/*

         Note : This custom include file is compaitible with all standard C++ Compilers. It is to be used
                ONLY with MyButami™ Source© v0.9.0+, and has been customized for the same.
                Previous versions of this include file are not preserved, as the file is a global include
                directive, and is incremental in nature.

                This header file is NOT meant for individual use.

*/
