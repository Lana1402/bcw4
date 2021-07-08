#ifndef IDENTIFIABLE_HPP
#define IDENTIFIABLE_HPP

class Identifiable {
    private:
        static int globalId;
        int id;
    public:   
        Identifiable();
        ~Identifiable();
        
        int getID() const;
};

#endif //IDENTIFIABLE_HPP
