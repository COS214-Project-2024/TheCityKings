#include "TownHouse.h"

TownHouse::TownHouse(double taxIncome, double buildCost, int livingCapacity) 
        : ResidentialBuilding(taxIncome, buildCost, livingCapacity) {}

void TownHouse::accept(BuildingVisitor* v) {
    v->visit(this);
}

BuildingComponent* TownHouse::clone(){
    BuildingComponent * clone = new TownHouse(this->taxIncome, this->buildCost, this->livingCapacity);
    return clone;
}