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

#ifndef LCP_SIGNAL_DATA_HPP
#define LCP_SIGNAL_DATA_HPP

#include "SignalData.hpp"
#include <NodeBitmask.hpp>

class StartLcpReq {
  /**
   * Sender(s)
   */
  friend class Dbdih;
  
  /**
   * Sender(s) / Receiver(s)
   */
  
  /**
   * Receiver(s)
   */
  friend class Dblqh;

  friend bool printSTART_LCP_REQ(FILE *, const Uint32 *, Uint32, Uint16);  
public:

  STATIC_CONST( SignalLength = 2 + 2 * NdbNodeBitmask::Size );
private:
  Uint32 senderRef;
  Uint32 lcpId;
  
  NdbNodeBitmask participatingDIH;
  NdbNodeBitmask participatingLQH;
};

class StartLcpConf {
  /**
   * Sender(s)
   */
  friend class Dblqh;
  
  /**
   * Sender(s) / Receiver(s)
   */
  
  /**
   * Receiver(s)
   */
  friend class Dbdih;

  friend bool printSTART_LCP_CONF(FILE *, const Uint32 *, Uint32, Uint16);  
public:
  
  STATIC_CONST( SignalLength = 2 );
private:
  Uint32 senderRef;
  Uint32 lcpId;
};

/**
 * This signals is sent by Dbdih to Dblqh
 * to order checkpointing of a certain
 * fragment.
 */
class LcpFragOrd {
  /**
   * Sender(s)
   */
  friend class Dbdih;
  
  /**
   * Sender(s) / Receiver(s)
   */
  
  /**
   * Receiver(s)
   */
  friend class Dblqh;

  friend bool printLCP_FRAG_ORD(FILE *, const Uint32 *, Uint32, Uint16);  
public:
  STATIC_CONST( SignalLength = 6 );
private:
  
  Uint32 tableId;
  Uint32 fragmentId;
  Uint32 lcpNo;
  Uint32 lcpId;
  Uint32 lastFragmentFlag;
  Uint32 keepGci;
};


class LcpFragRep {
  /**
   * Sender(s) and receiver(s)
   */
  friend class Dbdih;

  /**
   * Sender(s)
   */
  friend class Dblqh;

  friend bool printLCP_FRAG_REP(FILE *, const Uint32 *, Uint32, Uint16);  
public:
  STATIC_CONST( SignalLength = 7 );

private:
  Uint32 nodeId;
  Uint32 lcpId;
  Uint32 lcpNo;
  Uint32 tableId;
  Uint32 fragId;
  Uint32 maxGciCompleted;
  Uint32 maxGciStarted;
};

class LcpCompleteRep {
  /**
   * Sender(s) and receiver(s)
   */
  friend class Dbdih;
  
  /**
   * Sender(s)
   */
  friend class Dblqh;

  friend bool printLCP_COMPLETE_REP(FILE *, const Uint32 *, Uint32, Uint16);  
public:
  STATIC_CONST( SignalLength = 3 );
  
private:
  Uint32 nodeId;
  Uint32 blockNo;
  Uint32 lcpId;
};

#endif
