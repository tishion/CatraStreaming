/*
 Copyright (C) Giuliano Catrambone (giuliano.catrambone@catrasoftware.it)

 This program is free software; you can redistribute it and/or 
 modify it under the terms of the GNU General Public License 
 as published by the Free Software Foundation; either 
 version 2 of the License, or (at your option) any later 
 version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

 Commercial use other than under the terms of the GNU General Public
 License is allowed only after express negotiation of conditions
 with the authors.
*/


#ifndef MP4StringLastProperty_h
	#define MP4StringLastProperty_h

	#include "MP4Property.h"
	#include "FileReader.h"

	#define MP4_MAXLONGLENGTH					512 + 1


	typedef class MP4StringLastProperty: public MP4Property {

		private:
			char						**_pValues;
			unsigned long				_ulBytesNumber;

		public:
			MP4StringLastProperty (void);

			~MP4StringLastProperty (void);

			Error init (const char *pName, Boolean_p pbIsImplicitProperty,
				unsigned long *pulBytesNumber, char *pValue,
				Tracer_p ptTracer);

			Error init (const char *pName, unsigned long ulBytesNumber,
				FileReader_p pfFile, Tracer_p ptTracer);

			Error getValue (Buffer_p pbValue, long lIndex);

			Error setValue (Buffer_p pbValue, long lIndex,
				long *plSizeChangedInBytes);

			virtual Error write (int iFileDescriptor);

			virtual Error getSize (unsigned long *pulSize);

			virtual Error getType (char *pType);

			virtual Error appendDump (Buffer_p pbBuffer);

			virtual Error printOnStdOutput (void);

	} MP4StringLastProperty_t, *MP4StringLastProperty_p;

#endif

