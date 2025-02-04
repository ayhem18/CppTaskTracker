# include<string>
# include "../utils/string_utils.h"


class Display {
    private:
        int charsByElement;
        int elementsByLine;
        std::string delimiter;

    vec_str longElementRepresentation(const std::string& str);


    vec_str elementRepresentation(const std::string& str);


    public:
        Display(int chars, int elements, const std::string& del): charsByElement{chars}, elementsByLine{elements}, delimiter{del}{
            
        };

    std::string lineRepresentation(const vec_str& elements);

};
