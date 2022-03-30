/*----------------------------------------------------------------------------------------------*/
/*      Autor: Georgios Terzoglou                                                               */
/*      Copyright (©) 2017 by Georgios Terzoglou                                                */
/*      Bug-reports and suggestions to georgios.terzoglou@googlemail.com                        */
/*                                                                                              */
/*                                                                                              */
/*      GENERAL NOTE: I assume no liability for any damages with this header.                   */
/*      Using this header at your own risk.                                                     */
/*                                                                                              */
/*                                                                                              */
/*      File: registerAccessHelper.h                                                            */
/*                                                                                              */
/*                                                                                              */
/*      State:		Release candidate [RC]                                                  */
/*      Date:		13.09.2017 [Last changes]                                               */
/*                                                                                              */
/*----------------------------------------------------------------------------------------------*/
#ifndef REGISTERACCESSHELPER_HPP
#define REGISTERACCESSHELPER_HPP


// Global includes ------------------------------------------
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <utility>
#include <type_traits>


// gtest includes -------------------------------------------
// #include "gmock/gmock.h"


// Local includes -------------------------------------------
// #include "privateAccessHelper.h"


// DEFINES --------------------------------------------------


// GLOBAL VARIABLES -----------------------------------------


// UTILITY FUNCTIONS ----------------------------------------
namespace utility
{
  template<typename Datatype, typename Mask> inline void SetBit(Datatype &dataRegister, Mask bitMask)
  {
    dataRegister |= static_cast<Datatype>(bitMask);
  };

  template<typename Datatype, typename Mask> inline void SetBits(Datatype &dataRegister, Mask bitMask)
  {
    dataRegister = bitMask;
  };

  template<uint8_t num, typename Datatype, typename Mask> inline void SetBitsArray(Datatype &dataRegister, Mask bitMask)
  {
    std::fill(std::begin(dataRegister), std::begin(dataRegister)+num, 0x00);
  };

  template<typename Datatype, typename Mask> inline bool ReadBit(const Datatype &dataRegister, Mask bitMask)
  {
    return static_cast<bool>(dataRegister & static_cast<Datatype>(bitMask));
  };

  template<typename Datatype, typename Mask> inline void ClearBit(Datatype &dataRegister, Mask bitMask)
  {
    dataRegister &= ~static_cast<Datatype>(bitMask);
  };

  template<typename Datatype> inline void ClearRegister(Datatype &dataRegister)
  {
    dataRegister = static_cast<Datatype>(0x00U);
  };

  template<typename Datatype, typename Mask> inline uint32_t ReadBits(const Datatype &dataRegister, Mask bitMask)
  {
    return static_cast<Datatype>(dataRegister & static_cast<Datatype>(bitMask));
  };
}


#endif REGISTERACCESSHELPER_HPP
