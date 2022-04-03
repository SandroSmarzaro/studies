package com.san.carModels.SUV;

import com.san.Car.Car;

public class SUV extends Car {

    public SUV (
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
        super(name, brand, color, year, mileage, trunkSize, licensePlate, ownersName, price);
    }
}
