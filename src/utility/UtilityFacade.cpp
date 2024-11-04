#include "UtilityFacade.h"

UtilityFacade::UtilityFacade()
{
    powerPlant = new PowerPlantDecorator();
    sewageManagement = new SewageManagementDecorator();
    wasteManagement = new WasteManagementDecorator();
    waterSupply = new WaterSupplyDecorator(); 
}

void UtilityFacade::checkAndUpgradeUtilities(int demand)
{
    if(powerPlant->isEfficient(demand))
    {
        powerPlant->upgradeLevel();
        std::cout<<"Power Plant has been upgraded since demand was to high\n";
    }

    if(powerPlant->isEfficient(demand))
    {
        sewageManagement->upgradeLevel();
        std::cout<<"Sewage Management has been upgraded since demand was to high\n";
    }

    if(powerPlant->isEfficient(demand))
    {
        wasteManagement->upgradeLevel();
        std::cout<<"Waste Management has been upgraded since demand was to high\n";
    }

    if(powerPlant->isEfficient(demand))
    {
        waterSupply->upgradeLevel();
        std::cout<<"Water Supply has been upgraded since demand was to high\n";
    }
}

void UtilityFacade::printResourceDistribution()
{
    std::cout<<"Current Utilities Output Capacities"<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Power Capacity: "<<getPowerCapacity()<<std::endl;
    std::cout<<"Sewage Capacity: "<<getSewageCapacity()<<std::endl;
    std::cout<<"Waste Capacity: "<<getWasteCapacity()<<std::endl;
    std::cout<<"Water Capacity: "<<getWaterCapacity()<<std::endl;
}  

UtilityFacade::~UtilityFacade()
{
    delete powerPlant;
    delete sewageManagement;
    delete waterSupply;
    delete wasteManagement;
}

int UtilityFacade::getPowerCapacity()
{
    return powerPlant->getCapacity();
}

int UtilityFacade::getWaterCapacity()
{
    return waterSupply->getCapacity();
}

int UtilityFacade::getWasteCapacity()
{
    return wasteManagement->getCapacity();
}

int UtilityFacade::getSewageCapacity()
{
    return sewageManagement->getCapacity();
}

UtilityFacade* UtilityFacade::clone(){
    UtilityFacade* clone = new UtilityFacade();
    clone->powerPlant->setCapacity(this->powerPlant->getCapacity());
    clone->powerPlant->setLevel(this->powerPlant->getLevel());

    clone->sewageManagement->setCapacity(this->sewageManagement->getCapacity());
    clone->sewageManagement->setLevel(this->sewageManagement->getLevel());

    clone->wasteManagement->setCapacity(this->wasteManagement->getCapacity());
    clone->wasteManagement->setLevel(this->wasteManagement->getLevel());

    clone->waterSupply->setCapacity(this->waterSupply->getCapacity());
    clone->waterSupply->setLevel(this->waterSupply->getLevel());

    return clone;
}

