package com.san.carModels.Sedan;

import com.san.Car.Car;

public class Sedan extends Car {

    public Sedan (
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
        this.numberOfDoors = 4;
    }
}
