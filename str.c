#include "str.h"
#include <ctype.h>
#include <string.h>

#ifndef min
#define min(X, Y) ((X) > (Y) ? (X) : (Y))
#endif // min

#ifndef max
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#endif // max

#ifdef _UNIX
char *strcpy_s(char *buf, const size_t buflen, const char *str) {
  if (strlen(str) > buflen - 1) {
      strncpy(buf, str, buflen - 1);
      buf[buflen - 1] = 0;
  } else
      strcpy(buf, str);
  return buf;
}

char *strncpy_s(char *buf, const size_t buflen, const char *str, const int n) {
  strncpy(buf, str, min(buflen - 1, (size_t)n));
  buf[min(buflen, (size_t)n)] = 0;
  return buf;
}

char* strcat_s(char* buf, const size_t buflen, const char* src) {
    if  (strlen(buf) + strlen(src) >= buflen)
        return (0);

    return strcat(buf, src);
}

int fopen_s(FILE** fp, const char* filepath, const char* mode) {
    *fp = fopen(filepath, mode);
    return (*fp == NULL ? -1 : 0);
}

void itoa(unsigned long val, char *buf, unsigned radix) {
  char *p;         /* pointer to traverse string */
  char *firstdig;  /* pointer to first digit */
  char temp;       /* temp char */
  unsigned digval; /* value of digit */

  p = buf;
  firstdig = p; /* save pointer to first digit */

  do {
    digval = (unsigned)(val % radix);
    val /= radix; /* get next digit */

    /* convert to ascii and store */
    if (digval > 9)
      *p++ = (char)(digval - 10 + 'a'); /* a letter */
    else
      *p++ = (char)(digval + '0'); /* a digit */
  } while (val > 0);

  /* We now have the digit of the number in the buffer, but in reverse
  order.  Thus we reverse them now. */

  *p-- = '\0'; /* terminate string; p points to last digit */

  do {
    temp = *p;
    *p = *firstdig;
    *firstdig = temp; /* swap *p and *firstdig */
    --p;
    ++firstdig;           /* advance to next two digits */
  } while (firstdig < p); /* repeat until halfway */
}

void localtime_s(struct tm* ttm, time_t* tt) {
  (void)localtime_r(tt, ttm);
}

#endif // UNIX

#define isnewline(c) ((c) == '\n' || (c) == '\r')

char *strtrim(char *buf) {
  char *bufptr, *backptr;
  if (!buf)
    return (0);

  bufptr = buf;
  backptr = buf + strlen(buf) - 1;

  while (*bufptr && (isspace(*bufptr) || isnewline(*bufptr)))
    ++bufptr;
  while (bufptr < backptr && (isspace(*backptr) || isnewline(*bufptr)))
    --backptr;

  if (buf < bufptr) {
    if (backptr - bufptr + 1 > 0) {
      memmove(buf, bufptr, backptr - bufptr + 1);
      buf[backptr - bufptr + 1] = 0;
    } else if (0 == backptr - bufptr + 1)
      *buf = 0;
  }

  return buf;
}

char *strltrim(char *buf) {
  char *bufptr = buf;
  if (!buf)
    return (0);

  while (*bufptr && (isspace(*bufptr) || isnewline(*bufptr)))
    ++bufptr;

  if (bufptr > buf) {
    size_t len = strlen(buf) - (bufptr - buf);
    if (len > 0) {
      memmove(buf, bufptr, len + 1);
      buf[len + 2] = 0;
    } else
      *buf = 0;
  }

  return buf;
}

char *strrtrim(char *buf) {
  char *backptr;
  if (!buf)
    return (0);

  backptr = buf + strlen(buf) - 1;
  while (buf < backptr && (isspace(*backptr) || isnewline(*backptr)))
    --backptr;

  if (backptr > buf) {
    buf[backptr - buf + 1] = 0;
  } else
    *buf = 0;

  return buf;
}

#ifndef UNUSED
#define UNUSED(x) (void)(x)
#endif //UNUSED

void itoa_s(int num, char* buf, size_t len, int base)
{
#ifdef _WINDOWS
  _itoa_s(num, buf, len, base);
#else
  UNUSED(len);
  //itoa(num, buf, base);
#endif
}
