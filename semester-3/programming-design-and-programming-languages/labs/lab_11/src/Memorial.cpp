#include "Memorial.h"
#include "func.hpp"
namespace memorial {
ostream &operator<<(std::ostream &out, const Memorial &m) {
    out << "Name and surname author: " << m.authorObg->GetName() << " "
        << m.authorObg->GetSurname() << endl
        << "Opening Date memorial: " << m.desObg->GetOpeningDate() << endl
        << "expended Resources memorial: " << m.desObg->GetExpendedResources()
        << endl
        << "Coordinate(latitude/longitude) memorial: "
        << m.coorObg->GetLatitude() << "/" << m.coorObg->GetLongitude() << endl
        << "Name of material memorial: " << m.matObj->GetNameOfMaterial()
        << endl
        << "Price material: " << m.matObj->GetPrice() << endl
        << "Memorial height/square: " << m.archObj->GetHeight() << "/"
        << m.archObj->GetSquare() << endl
        << "Whom Is The Memorial: " << m.whomIsTheMemorial << endl
        << "In Honor Of What: " << m.inHonorOfWhat << endl;
    return out;
}

void Memorial::SetInHonorOfWhat(std::string inHonorOfWhat) {
    this->inHonorOfWhat = inHonorOfWhat;
}

void Memorial::SetWhomIsTheMemorial(std::string whomIsTheMemorial) {
    this->whomIsTheMemorial = whomIsTheMemorial;
}

std::string Memorial::GetInHonorOfWhat() { return inHonorOfWhat; }

std::string Memorial::GetWhomIsTheMemorial() { return whomIsTheMemorial; }

Memorial::Memorial(Material *matObg, Coordinate *coorObj, Author *authorObj)
    : ArchitecturalObject() {
    this->matObj = matObg;
    this->coorObg = coorObj;
    this->authorObg = authorObj;

    this->desObg = new Description("23.10.2002", 650);
    this->archObj = new ArchitecturalObject(20, 500);

    SetInHonorOfWhat(" ");
    SetWhomIsTheMemorial(" ");
}

Memorial::Memorial(Material *matObg, Coordinate *coorObj, Author *authorObj,
                   float height, float square, std::string whomIsTheMemorial,
                   std::string inHonorOfWhat)
    : ArchitecturalObject(height, square) {
    this->matObj = matObg;
    this->coorObg = coorObj;
    this->authorObg = authorObj;

    this->archObj = new ArchitecturalObject(height, square);
    this->desObg = new Description("23.10.2002", 650);
    SetInHonorOfWhat(inHonorOfWhat);
    SetWhomIsTheMemorial(whomIsTheMemorial);
}

Memorial::~Memorial() {
    delete archObj;
    delete desObg;
}

Memorial::Memorial(const Memorial &temp) {
    // выделение памяти
    matObj = new Material();
    this->matObj->SetPrice(temp.matObj->GetPrice());
    this->matObj->SetNameOfMaterial(temp.matObj->GetNameOfMaterial());
    coorObg = new Coordinate();
    this->coorObg->SetLatitude(temp.coorObg->GetLatitude());
    this->coorObg->SetLongitude(temp.coorObg->GetLongitude());
    authorObg = new Author();
    this->authorObg->SetName(temp.authorObg->GetName());
    this->authorObg->SetSurName(temp.authorObg->GetSurname());
    archObj = new ArchitecturalObject();
    this->archObj->SetHeight(temp.archObj->GetHeight());
    this->archObj->SetSquare(temp.archObj->GetSquare());
    desObg = new Description();
    this->desObg->SetOpeningDate(temp.desObg->GetOpeningDate());
    this->desObg->SetExpendedResources(temp.desObg->GetExpendedResources());
    SetInHonorOfWhat(temp.inHonorOfWhat);
    SetWhomIsTheMemorial(temp.whomIsTheMemorial);
}

void Memorial::SetInformation(Material *matObg, Coordinate *coorObj,
                              Author *authorObj, float height, float square,
                              std::string whomIsTheMemorial,
                              std::string inHonorOfWhat) {
    this->SetSquare(square);
    this->SetHeight(height);

    this->matObj = matObg;
    this->coorObg = coorObj;
    this->authorObg = authorObj;

    this->archObj = new ArchitecturalObject(height, square);
    std::string temp;
    std::cout << "Enter a opening data" << std::endl;
    std::cin >> temp;

    std::cout << "Enter a expended Resources" << std::endl;
    this->desObg = new Description(temp, checkNum());
    SetInHonorOfWhat(inHonorOfWhat);
    SetWhomIsTheMemorial(whomIsTheMemorial);
}

Memorial &Memorial::operator=(const Memorial &temp) {
    this->matObj->SetPrice(temp.matObj->GetPrice());
    this->matObj->SetNameOfMaterial(temp.matObj->GetNameOfMaterial());
    this->coorObg->SetLatitude(temp.coorObg->GetLatitude());
    this->coorObg->SetLongitude(temp.coorObg->GetLongitude());
    this->authorObg->SetName(temp.authorObg->GetName());
    this->authorObg->SetSurName(temp.authorObg->GetSurname());
    this->archObj->SetHeight(temp.archObj->GetHeight());
    this->archObj->SetSquare(temp.archObj->GetSquare());
    this->desObg->SetOpeningDate(temp.desObg->GetOpeningDate());
    this->desObg->SetExpendedResources(temp.desObg->GetExpendedResources());
    SetInHonorOfWhat(temp.inHonorOfWhat);
    SetWhomIsTheMemorial(temp.whomIsTheMemorial);
    return *this;
}

bool operator==(const Memorial &m1, const Memorial &m2) {
    return (
        (m1.archObj->GetHeight() == m2.archObj->GetHeight()) &&
        (m1.archObj->GetSquare() == m2.archObj->GetSquare()) &&
        (m1.authorObg->GetName() == m2.authorObg->GetName()) &&
        (m1.authorObg->GetSurname() == m2.authorObg->GetSurname()) &&
        (m1.coorObg->GetLatitude() == m2.coorObg->GetLatitude()) &&
        (m1.coorObg->GetLongitude() == m2.coorObg->GetLongitude()) &&
        (m1.desObg->GetExpendedResources() ==
         m2.desObg->GetExpendedResources()) &&
        (m1.desObg->GetOpeningDate() == m2.desObg->GetOpeningDate()) &&
        (m1.matObj->GetNameOfMaterial() == m2.matObj->GetNameOfMaterial()) &&
        (m1.matObj->GetPrice() == m2.matObj->GetPrice()));
}

}  // namespace memorial
