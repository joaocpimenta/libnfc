/**
 * Public platform independent Near Field Communication (NFC) library
 * 
 * Copyright (C) 2009, Roel Verdult
 * 
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 * 
 * 
 * @file pn531_usb.c
 * @brief Driver for PN531 chip using USB
 */

/*
Thanks to d18c7db and Okko for example code
*/

#include "../drivers.h"

nfc_device_t* pn531_usb_connect(const nfc_device_desc_t* pndd)
{
  int idvendor = 0x04CC;
  int idproduct = 0x0531;
  int idvendor_alt = 0x054c;
  int idproduct_alt = 0x0193;
  nfc_device_t* pnd = NULL;

  if((pnd = pn53x_usb_connect(pndd, idvendor, idproduct, "PN531USB", NC_PN531)) == NULL)
    pnd = pn53x_usb_connect(pndd, idvendor_alt, idproduct_alt, "PN531USB", NC_PN531);

  return pnd;
}
