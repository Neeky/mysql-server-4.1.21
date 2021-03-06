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

#ifndef SETVARREQ_H
#define SETVARREQ_H

#include "SignalData.hpp"
#include "ConfigParamId.hpp"

class SetVarReq {

public:


  static UintR size();

  void mgmtSrvrBlockRef(UintR mgmtSrvrBlockRef);
  UintR mgmtSrvrBlockRef(void) const;

  void variable(ConfigParamId variable);
  ConfigParamId variable(void) const;

  void value(UintR value);
  UintR value(void) const;


private:

  UintR _mgmtSrvrBlockRef;
  UintR _variable;
  UintR _value;
};



inline UintR SetVarReq::size(void) {
  return 3;
}


inline void SetVarReq::mgmtSrvrBlockRef(UintR mgmtSrvrBlockRef) {
  _mgmtSrvrBlockRef = mgmtSrvrBlockRef;
}

inline UintR SetVarReq::mgmtSrvrBlockRef(void) const {
  return _mgmtSrvrBlockRef;
}


inline void SetVarReq::variable(ConfigParamId variable) {
  _variable = variable;
}


inline ConfigParamId SetVarReq::variable(void) const {
  return static_cast<ConfigParamId>(_variable);
}


inline void SetVarReq::value(UintR value) {
  _value = value;
}

inline UintR SetVarReq::value(void) const {
  return _value;
}



#endif // SETVARREQ_H

