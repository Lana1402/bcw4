#ifndef MOHICAN_HPP
#define MOHICAN_HPP

#include <iostream>
#include <string>
#include <list>

class Mohican {
    private:
        std::string name;
        static Mohican* mohican;
        static std::list<Mohican*> list;
    public:   
        Mohican(const std::string& name);
        ~Mohican();
        
        const std::string& getName() const;
        
        static Mohican& getLastMohican();
};

std::ostream& operator<<(std::ostream& out, const Mohican& mohican);

#endif //MOHICAN_HPP