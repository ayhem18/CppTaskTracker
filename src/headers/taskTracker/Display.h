# pragma once


# include <string>
# include <ctime>
# include "string_utils.h"


class Display {
    private:
        int charsByElement;
        int elementsByLine;
        std::string delimiter;

    vec_str longElementRepresentation(const std::string& str) const ;

    vec_str elementRepresentation(const std::string& str) const ;


    public:
        Display(int chars, int elements, const std::string& del): charsByElement{chars}, elementsByLine{elements}, delimiter{del}{
            
        };

    std::string displayLine(const vec_str& elements) const ;

    std::string getFormattedTime(const time_t& time) const;
            

};
