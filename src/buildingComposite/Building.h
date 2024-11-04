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
    
    public:
        /**
         * @brief Constructs a Building object with specified tax income and build cost.
         * @param taxIncome The income generated from tax.
         * @param buildCost The cost required to build.
         */
        Building(double taxIncome, double buildCost);
        /**
         * @brief Retrieves the tax income of the building.
         * @return Tax income as a double.
         */
        virtual double getTaxIncome() const override;
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
};

#endif
