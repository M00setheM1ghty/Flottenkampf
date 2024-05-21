#ifndef SCHIFF_H
#define SCHIFF_H

class Schiff
{
    public:
        int groesse_;
        int huelle_;
        int schaden_;
        int erfahrungspunkte_ = 0;
    public:
        Schiff(int groesse, int huelle, int schaden) : groesse_(groesse), huelle_(huelle), schaden_(schaden){};
        //virtual void SpezialAngriff() = 0;
        virtual ~Schiff();
    protected:

    private:
};

#endif // SCHIFF_H
