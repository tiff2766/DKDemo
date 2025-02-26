//
//  File: DKAtomicNumber32.h
//  Author: Hongtae Kim (tiff2766@gmail.com)
//
//  Copyright (c) 2004-2014 Hongtae Kim. All rights reserved.
//

#pragma once
#include "../DKInclude.h"

////////////////////////////////////////////////////////////////////////////////
// DKAtomicNumber32
// a number object which can be increased or decreased atomically.
//
// This class does not provide any numeric operators. (except assign)
////////////////////////////////////////////////////////////////////////////////

namespace DKFoundation
{
	class DKLIB_API DKAtomicNumber32
	{
	public:
		typedef int Value;
		DKAtomicNumber32(Value initialValue = 0);
		~DKAtomicNumber32(void);

		Value Increment(void);			// +1, returns previous value.
		Value Decrement(void);			// -1, returns previous value.
		Value Add(Value addend);		// +addend, returns previous value.
		Value Exchange(Value value);	// set value, returns previous value.

		// compare and set when equal. return true when operation succeeded.
		bool CompareAndSet(Value comparand, Value value);

		DKAtomicNumber32& operator = (Value value);
		DKAtomicNumber32& operator += (Value value);
		operator Value (void) const;
	private:
		volatile Value atomic;
	};
}
