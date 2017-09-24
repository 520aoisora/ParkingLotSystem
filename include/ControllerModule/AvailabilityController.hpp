/*
 * AvailabilityController.hpp
 *
 *  Created on: 24 Sep 2017
 *      Author: Yi
 */

#ifndef INCLUDE_CONTROLLERMODULE_AVAILABILITYCONTROLLER_HPP_
#define INCLUDE_CONTROLLERMODULE_AVAILABILITYCONTROLLER_HPP_

namespace controller_module
{
	class AvailabilityController
	{
	public:
		AvailabilityController()
		: _availableSpaceCount(CAPACITY)
		{}

		explicit AvailabilityController(const unsigned int& initialASC)
		: _availableSpaceCount(initialASC)
		{}

	private:
		static const unsigned int CAPACITY = 100;
		unsigned int _availableSpaceCount;

	public:
		bool hasAvailability() const;
		bool increaseCountBy1();
		bool decreaseCountBy1();
		unsigned int getAvailableSpaceCount() const;
	};
}

#endif /* INCLUDE_CONTROLLERMODULE_AVAILABILITYCONTROLLER_HPP_ */
