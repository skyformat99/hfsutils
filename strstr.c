/*
 * hfsutils - tools for reading and writing Macintosh HFS volumes
 * Copyright (C) 1996-1998 Robert Leslie
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * $Id: strstr.c,v 1.5 1998/04/11 08:27:00 rob Exp $
 */

# ifdef HAVE_CONFIG_H
#  include "config.h"
# endif

/*
 * NAME:	strstr()
 * DESCRIPTION:	locate a substring
 */
char *strstr(const char *haystack, const char *needle)
{
  register const char *hptr, *nptr;

  if (*needle == 0)
    return haystack;

  while (*haystack)
    {
      if (*haystack++ != *needle)
	continue;

      hptr = haystack;
      nptr = needle + 1;

      while (1)
	{
	  if (*nptr == 0)
	    return haystack - 1;

	  if (*hptr++ != *nptr++)
	    break;
	}
    }

  return 0;
}
