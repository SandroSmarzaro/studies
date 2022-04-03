package com.san.carModels.Hatch;

import com.san.Car.Car;

public class Hatch extends Car {
    
    public Hatch (
        String name, 
        String brand, 
        String color, 
        int year, 
        double mileage,
        double trunkSize,
        String licensePlate,
        String ownersName,
        double price
    ) {
        super (name, brand,color, year, mileage, trunkSize, licensePlate, ownersName, price);
        this.numberOfDoors = 2;
    }
}
