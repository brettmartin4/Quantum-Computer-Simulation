#pragma once

#include <complex>
#include <utility>
#include <vector>

#include "qubit.h"
#include "physicalQubit.h"


class LogicalQubit : public Qubit {
public:
	// Constructs a new logical qubit from a specified number of physical qubits
	LogicalQubit(int num_qubits);

	// Applies a Pauli X (NOT) gate to the logical qubit
	void X() override;

	// Applies a Pauli Y gate to the logical qubit
	void Y() override;

	// Applies a Pauli Z gate to the logical qubit
	void Z() override;

	// Applies a Hadamard gate to the logical qubit
	void H() override;

	// Applies a phase shift gate to the logical qubit
	void R(double theta) override;

	// Applies a controlled-NOT gate to the logical qubit and another logical qubit
	void CNOT(LogicalQubit& q);

	// Applies a Toffoli (CCNOT) gate to the qubit and two other qubits
	void Toffoli(LogicalQubit& q1, LogicalQubit& q2);

	// Measures the state of the logical qubit
	int measure();

private:
	std::vector<PhysicalQubit> qubits_;
};