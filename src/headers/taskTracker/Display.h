# pragma once


# include <string>
# include <ctime>
# include "string_utils.h"

class Display {
    protected:
        int charsByElement;
        int elementsByLine;
        std::string delimiter;

    vec_str longElementRepresentation(const std::string& str) const ;

    vec_str singleElementRepresentation(const std::string& str) const ;


    public:
        Display(int charsByElement, int elementsByLine, const std::string& delimiter): charsByElement{charsByElement}, elementsByLine{elementsByLine}, delimiter{delimiter}{
            
        };

    std::string displayLine(const vec_str& elements) const ;

    std::string getFormattedTime(const time_t& time) const;
            

};
