#pragma once

#include <complex>
#include <utility>
#include <random>

#include "qubit.h"


class PhysicalQubit : public Qubit {
public:
	// Constructs a new qubit in the |0> state with a specified coherence
	PhysicalQubit(double coherence);

	// Constructs a new qubit in the specified state with a specified coherence
	PhysicalQubit(std::complex<double> c0, std::complex<double> c1, double coherence);

	// Default constructor: Constructs a new qubit in the |0> state with coherence 1
	PhysicalQubit();

	// Applies a Pauli X (NOT) gate to the qubit
	void X() override;

	// Applies a Pauli Y gate to the qubit
	void Y() override;

	// Applies a Pauli Z gate to the qubit
	void Z() override;

	// Applies a Hadamard gate to the qubit
	void H() override;

	// Applies a phase shift gate to the qubit
	void R(double theta) override;

	// Applies a controlled-NOT gate to the qubit and another qubit
	void CNOT(PhysicalQubit& q);

	// Applies a Toffoli (CCNOT) gate to the qubit and two other qubits
	void Toffoli(PhysicalQubit& q1, PhysicalQubit& q2);

	// Returns the state of the qubit as a pair of complex numbers
	std::pair<std::complex<double>, std::complex<double>> state() const override;

	// Returns the coherence of the qubit
	double coherence() const;

	// Returns the state of the qubit as a discrete integer value of 1 or 0
	int measure() const;

private:
	std::complex<double> c0_;
	std::complex<double> c1_;
};