/* bitmask */
unsigned char flags;

// initialising the flags
// note that assignming a value will clobber any other flags, so you
// should generally only use the = operator when initialising vars.
flags = LOG_ERRORS;
// sets to 1 i.e. bit 0

//initialising to multiple values with OR (|)
flags = LOG_ERRORS | LOG_WARNINGS | LOG_INCOMING;
// sets to 1 + 2 + 8 i.e. bits 0, 1 and 3

// setting one flag on, leaving the rest untouched
// OR bitmask with the current value
flags |= LOG_INCOMING;

// testing for a flag
// AND with the bitmask before testing with ==
if ((flags & LOG_WARNINGS) == LOG_WARNINGS)
   ...

// testing for multiple flags
// as above, OR the bitmasks
if ((flags & (LOG_INCOMING | LOG_OUTGOING))
         == (LOG_INCOMING | LOG_OUTGOING))
   ...

// removing a flag, leaving the rest untouched
// AND with the inverse (NOT) of the bitmask
flags &= ~LOG_OUTGOING;

// toggling a flag, leaving the rest untouched
flags ^= LOG_LOOPBACK;


/* bit-field */

struct {
unsigned int is_keyword : 1;
unsigned int is_extern : 1;
unsigned int is_static : 1;
} flags;

// to turn the bits on;
flags.is_extern = flags.is_static = 1;

// to turn them off;
flags.is_extern = flags.is_static = 0;

// to test them
if (flags.is_extern == 0 && flags.is_static == 0)