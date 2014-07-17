/**************************************************************************//*****
 * @file     stdio.c
 * @brief    Implementation of newlib syscall
 ********************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#undef errno
extern int errno;
extern int  _end;

__attribute__ ((used))
caddr_t _sbrk (int size)
{
   //extern char _Min_Heap_Size;
   //extern char __cs3_heap_end ;
   //static char *current_heap_end = &_Min_Heap_Size;
   //char *previous_heap_end;
//
   //previous_heap_end = current_heap_end;
//
   //if (current_heap_end + size > &__cs3_heap_end )
   //{
   //   errno = ENOMEM;   // don't forget to include <errno.h>
   //   return (caddr_t) -1;
   //}
//
   //current_heap_end += size;
//
   //return (caddr_t) previous_heap_end;
  return 0;
}

__attribute__ ((used))
int link(char *old, char *new) {
return -1;
}

__attribute__ ((used))
int _close(int file)
{
  return -1;
}

__attribute__ ((used))
int _fstat(int file, struct stat *st)
{
  st->st_mode = S_IFCHR;
  return 0;
}

__attribute__ ((used))
int _isatty(int file)
{
  return 1;
}

__attribute__ ((used))
int _lseek(int file, int ptr, int dir)
{
  return 0;
}
__attribute__ ((used))
int _read(int file, char *ptr, int len)
{
  return 0;
}
__attribute__ ((used))
int _write(int file, char *ptr, int len)
{
  return len;
}

__attribute__ ((used))
void _exit(int status)
{
  while(1);
}

__attribute__ ((used))
int _open(const char *path, int access)
{
  return 0;
}

//__attribute__ ((used))
//void _fini(void)
//{
//}

/* --------------------------------- End Of File ------------------------------ */
