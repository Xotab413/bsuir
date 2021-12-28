#include "../headers/Pupil.h"

Pupil::Pupil(const string name, const int age)
    : m_name{name}, m_age{age} {}

Pupil::~Pupil() { m_name.clear(); }

ostream& operator<<(std::ostream& out, const Pupil* p) { return p->print(out); }