package com.san.carModels.Truck;

import com.san.Car.Car;

public class Truck extends Car {

    public Truck (
        String name, 
        String brand, 
        String color, 
        int year, 
        double mileage,
        float trunkBedSize,
        short numberOfDoors,
        String licensePlate,
        String ownersName,
        double price
    ) {
        super (name, brand,color, year, mileage, trunkBedSize, licensePlate, ownersName, price);
        this.numberOfDoors = numberOfDoors;
    }

    @Override
    public double getTrunkSize() {
        return this.trunkBedSize;
    }
}
