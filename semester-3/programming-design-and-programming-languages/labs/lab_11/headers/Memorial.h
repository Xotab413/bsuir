#ifndef Memorial_h
#define Memorial_h

#include "author.h"
#include "Description.h"
#include "Coordinate.h"
#include "Material.h"
#include "Architectural Object.h"
#include <limits>
#include <algorithm>


namespace memorial {
class Memorial: public ArchitecturalObject {
public:
    std::string whomIsTheMemorial;
    std::string inHonorOfWhat;
    
public:
    
    ArchitecturalObject *archObj;
    Material *matObj;
    Coordinate *coorObg;
    Description *desObg;
    Author *authorObg;
    Memorial(){};
    Memorial(const Memorial &temp);
    Memorial(Material *matObg, Coordinate *coorObj, Author *authorObj);
    Memorial(Material *matObg, Coordinate *coorObj, Author *authorObj, float height, float square, std::string whomIsTheMemorial, std::string inHonorOfWhat);
    ~Memorial();
    void SetWhomIsTheMemorial(std::string whomIsTheMemorial);
    void SetInHonorOfWhat(std::string inHonorOfWhat);
    std::string GetWhomIsTheMemorial();
    std::string GetInHonorOfWhat();
    void Display();
   
    void SetInformation(Material *matObg, Coordinate *coorObj, Author *authorObj, float height, float square, std::string whomIsTheMemorial, std::string inHonorOfWhat);
    Memorial& operator =(const Memorial &temp);
    string GetAuthorName() { return authorObg->GetName(); }
    string GetSurname() { return authorObg->GetSurname(); }
    friend ostream& operator<<(std::ostream& out, const Memorial& m);
    friend bool operator == (const Memorial &m1,const Memorial &s2);
};
}

#endif
