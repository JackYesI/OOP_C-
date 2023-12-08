#include <iostream>
#include "foreign.h"


int main()
{
    pasport::Passport passport("den", "M", "27.03.2002", "28.03.2022", "UA");
    passport.Print();
    Foreing::ForeignPassport Fpassport(passport, "03489154", "Hello");

    cout << "\n=================================\n";
    Fpassport.Print();

    Fpassport.setVizy("Viza number 2");
    cout << "\n=================================\n";
    Fpassport.Print();
}


