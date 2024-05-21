#ifndef AKTIONEN_H
#define AKTIONEN_H


class Aktionen
{
    public:
        virtual void angriff() = 0;
        virtual void angriffSpezial() = 0;
        virtual ~Aktionen();

    protected:

    private:
};

#endif // AKTIONEN_H
