/*
 * GateManager.hpp
 *
 *  Created on: 20 Sep 2017
 *      Author: Yi
 */

#ifndef GATEMANAGER_HPP_
#define GATEMANAGER_HPP_

namespace gate_module
{
	class GateManager
	{
	private:
		bool _isGateOpen = false;
	public:
		void openGate();
		void closeGate();
		bool isGateOpen() const;
};
}

#endif /* GATEMANAGER_HPP_ */
