/**************************************************************************/
/*!
    @file     BLEHomekit.h
    @author   hathach

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2017, Adafruit Industries (adafruit.com)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/
#ifndef BLEHOMEKIT_H_
#define BLEHOMEKIT_H_

#include "HAPUuid.h"
#include "HAPCharacteristic.h"
#include "HAPService.h"

#include "HapAccessoryInfo.h"

enum
{
  HAP_CAT_OTHER = 1           ,
  HAP_CAT_BRIDGE              ,
  HAP_CAT_FAN                 ,
  HAP_CAT_GARAGE              ,
  HAP_CAT_LIGHTBULB           ,
  HAP_CAT_DOOR_LOCK           ,
  HAP_CAT_OUTLET              ,
  HAP_CAT_SWITCH              ,
  HAP_CAT_THERMOSTAT          ,
  HAP_CAT_SENSOR              ,
  HAP_CAT_SECURITY_SYSTEM     ,
  HAP_CAT_DOOR                ,
  HAP_CAT_WINDOWS             ,
  HAP_CAT_WINDOWS_COVERING    ,
  HAP_CAT_PROGRAMMABLE_SWITCH ,
  HAP_CAT_RANGE_EXTENDER      ,
  HAP_CAT_IP_CAMERA           ,
  HAP_CAT_VIDEO_DOOR_BELL     ,
  HAP_CAT_AIR_PURFIER         ,
};

class BLEHomekit : public Advertisable
{
  public:
    static uint16_t _gInstanceID;

    virtual bool setAdv(BLEAdvertisingData& adv);
    BLEHomekit();
    err_t begin();


    HAPAccessoryInfo AccessoryInfo;

  private:
    // Mandatory services
    HAPService _protocol_info;

    HAPService _pairing;
    HAPCharacteristic _pair_setup, _pair_verify, _pair_features, _pair_pairing;

    HAPService _lightbulb;
    HAPCharacteristic _on;
};

#endif /* BLEHOMEKIT_H_ */
