#ifndef BUILDING_H
#define BUILDING_H

#include "BuildingComponent.h"
/**
 * @class Building
 * @brief Represents a building component with financial attributes like tax income and construction cost.
 *
 * The Building class provides a base structure for building objects, allowing
 * retrieval of tax income and construction cost.
 */
class Building : public BuildingComponent
{
    protected:
        double taxIncome;   /**< Tax income generated by the building. */
        double buildCost;   /**< Cost to construct the building. */
        int powerDemand;    /**< Power demand for the building. */
        int waterDemand;    /**< Water demand for the building. */
        int wasteDemand;    /**< Waste demand for the building. */
        int sewageDemand;   /**< Sewage demand for the building. */
        
        
    
    public:
        /**
         * @brief Constructs a Building object with specified tax income and build cost.
         * @param taxIncome The income generated from tax.
         * @param buildCost The cost required to build.
         */
        Building(double taxIncome, double buildCost, int pow, int water, int waste, int sewage);
        /**
         * @brief Retrieves the tax income of the building.
         * @return Tax income as a double.
         */
        virtual double getTaxIncome() const override;

        /**
         * @brief Retrieves the powerDemand of the building.
         * @return Power demand as an int.
         */
        int getPowerDemand() const ;
        /**
         * @brief Retrieves the waterDemand of the building.
         * @return Water demand as an int.
         */
        int getWaterDemand() const ;
        /**
         * @brief Retrieves the waterDemand of the building.
         * @return Waste demand as an int.
         */
        int getWasteDemand() const ;
        /**
         * @brief Retrieves the wasteDemand of the building.
         * @return Sewage demand as an int.
         */
        int getSewageDemand() const ;

        /**
         * @brief Retrieves the build cost of the building.
         * @return Build cost as a double.
         */
        virtual double getBuildCost() const override;
        /**
         * @brief Accepts a visitor object for performing operations on the building.
         * @param bv Pointer to a BuildingVisitor object.
         */
        virtual void accept(BuildingVisitor* bv) = 0; //Implemented in subclasses
        /**
         * @brief Destroys the Building object.
         */
        virtual ~Building() {};     

        /**
         * @brief Creates a copy of the current building for saving in CityMemento.
         * @return Pointer to copy of the current building as a BuildingComponent type.
         */
        virtual BuildingComponent* clone() = 0;   
};

#endif
