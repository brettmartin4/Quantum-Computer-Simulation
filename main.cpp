#include <iostream>
#include <complex>
#include <utility>
#include <memory>

#include "qubit.h"
#include "physicalQubit.h"


int main() {

	// Test cases for the physical qubits:

	// Create two qubits in the |0> state
	std::shared_ptr<PhysicalQubit> q1 = std::make_shared<PhysicalQubit>(0);
	std::shared_ptr<PhysicalQubit> q2 = std::make_shared<PhysicalQubit>(0);

	// Print the state of the two qubits prior to circuit execution
	std::cout << "(" << q1->state().first << ", " << q1->state().second << ")" << std::endl;
	std::cout << "(" << q2->state().first << ", " << q2->state().second << ")" << std::endl;

	// Perform a Hadamard gate on the first qubit
	q1->H();

	// Perform a CNOT gate with the first qubit as the control and the second qubit as the target
	q1->CNOT(q2);

	// Print the state of the two qubits
	std::cout << "(" << q1->state().first << ", " << q1->state().second << ")" << std::endl;
	std::cout << "(" << q2->state().first << ", " << q2->state().second << ")" << std::endl;

	return 0;
}