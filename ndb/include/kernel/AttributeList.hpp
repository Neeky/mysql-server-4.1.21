/* Copyright (C) 2003 MySQL AB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

#ifndef ATTRIBUTE_LIST_HPP
#define ATTRIBUTE_LIST_HPP

/**
 * Masks and lists used by index and trigger.  Must be plain old Uint32 data.
 * XXX depends on other headers XXX move to some common file
 */

typedef Bitmask<MAXNROFATTRIBUTESINWORDS> AttributeMask;

struct AttributeList {
  Uint32 sz;
  Uint32 id[MAX_ATTRIBUTES_IN_INDEX];
};

#endif
