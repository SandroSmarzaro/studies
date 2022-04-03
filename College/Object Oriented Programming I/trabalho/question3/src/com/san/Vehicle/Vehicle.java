package com.san.Vehicle;

import java.io.Serializable;

import com.san.VehicleInterface.VehicleInterface;

public abstract class Vehicle implements VehicleInterface, Serializable{
    protected String name;
    protected String brand;
    protected String color;
    protected int year;
    protected double mileage;
    private String licensePlate;
    private String ownersName;
    private double price;

    public Vehicle (
        String name, 
        String brand, 
        String color, 
        int year, 
        double mileage, 
        String licensePlate,
        String ownersName,
        double price
    ) {
        this.name = name;
        this.brand = brand;
        this.color = color;
        this.year = year;
        this.mileage = mileage;
        this.licensePlate = licensePlate;
        this.ownersName = ownersName;
        this.price = price;
    }

    public String getName() {
        return this.name;
    }

    public String getBrand() {
        return this.brand;
    }

    public String getColor() {
        return this.color;
    }

    public int getYear() {
        return this.year;
    }

    public double getMileage() {
        return this.mileage;
    }

    public String getLicensePlate() {
        return this.licensePlate;
    }

    public String getOwnersName() {
        return this.ownersName;
    }

    public double getPrice() {
        return this.price;
    }

}
