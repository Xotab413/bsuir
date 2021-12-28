#ifndef Description_hpp
#define Description_hpp

#include <stdio.h>
#include <iostream>

namespace memorial {
class Description {
private:
    std::string openingDate;
    int expendedResources;
public:
    void SetOpeningDate(std::string openingDate);
    void SetExpendedResources(int expendedResources);
    std::string GetOpeningDate();
    int GetExpendedResources();
    void Display();
    Description();
    Description(std::string openingDate, int expendedResources);
    ~Description();
    Description(Description &descObj);
};
}


#endif /* Description_hpp */
