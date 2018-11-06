/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

 
#include "../../inc/MarlinConfig.h"

#if ENABLED(MAGNETIC_PARKING_EXTRUDER) 

#include "../gcode.h"
#include "../../module/tool_change.h"

void GcodeSuite::M951() {

  if (parser.seenval('L')) {
    const float value = parser.value_linear_units();
	parkingposx[0]=value;
  }
  if (parser.seenval('R')) {
    const float value = parser.value_linear_units();
	parkingposx[1]=value;
  }
  if (parser.seenval('G')) {
    const float value = parser.value_linear_units();
	parkinggrabdistance=value;
  }
  if (parser.seenval('N')) {
    const float value = parser.value_linear_units();
	parkingslowspeed=value;
  }
  if (parser.seenval('H')) {
    const float value = parser.value_linear_units();
	parkinghighspeed=value;
  }
  if (parser.seenval('D')) {
    const float value = parser.value_linear_units();
	parkingtraveldistance=value;
  }
  if (parser.seenval('C')) {
    const float value = parser.value_float();
	compensationmultiplier=value;
  }
  mpe_para_report();  
  return;

  SERIAL_ECHO_START();
  SERIAL_ECHOPGM("Parking Extruder not defined");

}
#endif 
