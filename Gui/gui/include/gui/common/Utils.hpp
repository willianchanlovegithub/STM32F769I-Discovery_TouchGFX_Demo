/**
  ******************************************************************************
  * This file is part of the TouchGFX 4.10.0 distribution.
  *
  * <h2><center>&copy; Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
  


#ifndef GUI_UTILS_HPP
#define GUI_UTILS_HPP

#include <touchgfx/hal/HAL.hpp>

#ifdef SIMULATOR
#include <stdlib.h>
#endif

class Utils
{
public:
    static int randomNumberBetween(int lowest, int highest) 
    {
#ifdef SIMULATOR
        return lowest + (highest-lowest) * rand() / RAND_MAX;
#else
        uint32_t random = (touchgfx::HAL::getInstance()->getCPUCycles() * HAL::getInstance()->getCPUCycles());
        return lowest + (random % (highest-lowest));
#endif
    }

    static int nextRand(int lowest, int highest)
    {
        static uint32_t seed = 0;
        seed = ((214013 * (uint32_t)(seed) + 2531011) >> 16);
        return lowest + (seed % (highest - lowest));
    }

};


#endif /* GUI_UTILS_HPP */
