#include "../headers/Plant.h"

Plant::Plant(double lenght, string name, int age) {
    m_lenght = lenght;
    m_name = name;
    m_age = age;
}
Plant::Plant(Plant const& plant) {
    m_lenght = plant.m_lenght;
    m_name = plant.m_name;
    m_age = plant.m_age;
}
bool operator==(const Plant& pl1, const Plant& pl2) {
    int cnt{0};
    return ((pl1.m_age == pl2.m_age) && (pl1.m_name == pl2.m_name) &&
            (pl1.m_lenght == pl2.m_lenght));
}

ostream& operator<<(ostream& os, const Plant& plant) {
    os << plant.m_name << endl << plant.m_age << endl << plant.m_lenght << endl;
    return os;
}
// istream& operator>>(istream& is, Plant& plant) {
//     is >> plant.m_name >> plant.m_age >> plant.m_lenght;
//     return is;
// }
