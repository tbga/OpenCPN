/******************************************************************************
* 
*
* Project:  OpenCPN
* Purpose:  Connector Plugin/Seatalk
* Author:   Gilles Audemard
*
***************************************************************************
*   Copyright (C) 2012 by Gilles Audemard   *
*   $EMAIL$   *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
***************************************************************************
*/

#ifndef _Seatalk_H_
#define _Seatalk_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
#include "wx/wx.h"
#endif //precompiled headers

#include "wx/string.h"
#include "OCP_DataStreamInput_Thread.h"

//class OCP_DataStreamInput_Thread;

class OCP_StkDataStreamInput_Thread: public OCP_DataStreamInput_Thread

{
	public:
	OCP_StkDataStreamInput_Thread(DataStream *Launcher,
								wxEvtHandler *MessageTarget,
								const wxString& PortName,
								const wxString& strBaudRate,
								wxMutex *pout_mutex,
								dsPortType io_select);
							
	~OCP_StkDataStreamInput_Thread(void);
	
	bool getParity(unsigned int n);
	bool seatalk(unsigned char d, bool cde);
	unsigned char buftmp[255];
	wxString recu;
	
	};
//
//
//
//

class StkToNmea 
{
public:
	StkToNmea();
	~StkToNmea();
	
	wxString Decode(unsigned char tre[255]);
	
	unsigned long vent ;
	float HeadingMag;
	float Cog;
	float Sow;
	
};

#endif