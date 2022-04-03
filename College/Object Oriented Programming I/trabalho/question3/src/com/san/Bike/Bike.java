package com.san.Bike;

import com.san.Vehicle.Vehicle;

public class Bike extends Vehicle {

    private int engineCapacity;

    public Bike(
        String name, 
        String brand, 
        String color, 
        int year, 
        double mileage,
        String licensePlate,
        String ownersName,
        double price,
        int engineCapacity
    ) {
        super(name, brand, color, year, mileage, licensePlate, ownersName, price);
        this.engineCapacity = engineCapacity;
    }

    public int getEngineCapacity() {
        return engineCapacity;
    }
}
