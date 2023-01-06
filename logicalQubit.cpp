#include "LogicalQubit.h"
#include "qubit.h"


LogicalQubit::LogicalQubit(int num_qubits) : qubits_(num_qubits) {}

void LogicalQubit::X() {
    std::for_each(qubits_.begin(), qubits_.end(), [](Qubit& q) { q.X(); });
}

void LogicalQubit::Y() {
    std::for_each(qubits_.begin(), qubits_.end(), [](Qubit& q) { q.Y(); });
}

void LogicalQubit::Z() {
    std::for_each(qubits_.begin(), qubits_.end(), [](Qubit& q) { q.Z(); });
}

void LogicalQubit::H() {
    std::for_each(qubits_.begin(), qubits_.end(), [](Qubit& q) { q.H(); });
}

void LogicalQubit::R(double theta) {
    std::for_each(qubits_.begin(), qubits_.end(), [theta](Qubit& q) { q.R(theta); });
}

void LogicalQubit::CNOT(LogicalQubit& q) {
    for (int i = 0; i < qubits_.size(); i++) {
        qubits_[i].CNOT(q.qubits_[i]);
    }
}

void LogicalQubit::Toffoli(LogicalQubit& q1, LogicalQubit& q2) {
    for (int i = 0; i < qubits_.size(); i++) {
        qubits_[i].Toffoli(q1.qubits_[i], q2.qubits_[i]);
    }
}

int LogicalQubit::measure() {
    int result = 0;
    for (int i = 0; i < qubits_.size(); i++) {
        if (qubits_[i].measure()) {
            result |= (1 << i);
        }
    }
    return result;
}