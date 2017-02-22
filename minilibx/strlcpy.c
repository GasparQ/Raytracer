#include <string.h>

size_t		strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
  size_t	i;

  i = 0;
  while (i < dstsize && src[i] != '\0')
    {
      dst[i] = src[i];
      ++i;
    }
  return (i);
}
