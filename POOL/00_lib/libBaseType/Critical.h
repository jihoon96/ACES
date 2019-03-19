#pragma once
#ifndef _CRITICAL_SECTION_H_
#define _CRITICAL_SECTION_H_

#include <unistd.h>

namespace ACES
{
	class CriticalSectionObject
	{
		public:
			CriticalSectionObject();
			virtual ~CriticalSectionObject();

		private:

	};
}

#endif // end of _CRITICAL_SECTION_H_
