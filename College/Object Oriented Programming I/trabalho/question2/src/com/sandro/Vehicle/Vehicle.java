package com.sandro.Vehicle;

import com.sandro.Exception.NotEnoughFuelException;
import com.sandro.Exception.ZeroSpeedException;

public class Vehicle {
    private double mileage;
    private double fuelVolume;
    private double tankCapacity;
    private double maximumSpeed;
    private double currentSpeed;
    private double averageAcceleration;
    private double averageConsumption;

    public Vehicle (double tankCapacity, double maximumSpeed, double averageAcceleration, double averageConsumption) {
        this.mileage = 0;                   //Km
        this.fuelVolume = 0;                //L
        this.tankCapacity = tankCapacity;   //L
        this.maximumSpeed = maximumSpeed;   //M/s
        this.currentSpeed = 0;              //M/s
        this.averageAcceleration = averageAcceleration; //M/s^2
        this.averageConsumption = averageConsumption;   //L/M
    }

    public double reful(double literCoast, double amountPaid) {
        double literFilled = amountPaid / literCoast;
        double newFuelVolume = this.fuelVolume + literFilled;

        if (newFuelVolume <= this.tankCapacity) {
            this.fuelVolume = newFuelVolume;
            return 0;
        }
        else {
            double changeValue;
            double remainingFuel = this.tankCapacity - newFuelVolume;
            changeValue = remainingFuel * literCoast;
            return changeValue;
        }
    }

    public void accelerate(double seconds) throws NotEnoughFuelException {
        
        double travelledDistance;
        travelledDistance = kinematicsFormulaOfSpace(seconds, 1);
        double walkableDistance = this.fuelVolume * this.averageConsumption;
        
        if (walkableDistance >= travelledDistance) {
            double newCurrentSpeed = kinematicsFormulaOfVelocity(seconds, 1);
            if (newCurrentSpeed <= this.maximumSpeed) {
                this.currentSpeed = newCurrentSpeed;
                this.fuelVolume -= travelledDistance / this.averageConsumption;
                this.mileage += travelledDistance / 1000;
            }
            else {
                computingVariableConstantSpace(travelledDistance, seconds);
            }
        }

        else {
            travelledDistance = walkableDistance;
            this.fuelVolume = 0;
            
            double timeAccelerating = kinematicsFormulaOfTime(travelledDistance);
            double newCurrentSpeed = kinematicsFormulaOfVelocity(timeAccelerating, 1);
            if (newCurrentSpeed <= this.maximumSpeed) {
                this.currentSpeed = newCurrentSpeed;
                this.mileage += travelledDistance / 1000;
            }
            else {
                computingVariableConstantSpace(travelledDistance, seconds);
            }
            throw new NotEnoughFuelException(seconds, timeAccelerating);
        }
    }

    private void computingVariableConstantSpace(double travelledDistance, double seconds) {
        double timeInAcceleration = (this.maximumSpeed - this.currentSpeed) / this.averageAcceleration;
        double spaceInAcceleration = kinematicsFormulaOfSpace(timeInAcceleration, 1);
        this.currentSpeed = this.maximumSpeed;
        double spaceInConstantSpeed = 0;
        if (spaceInAcceleration < travelledDistance) {
            spaceInConstantSpeed = (seconds - timeInAcceleration) * this.maximumSpeed;
        }
        this.mileage += (spaceInAcceleration + spaceInConstantSpeed) / 1000;
        this.fuelVolume -= (spaceInAcceleration + spaceInConstantSpeed) / this.averageConsumption;
    }

    public void brake(double seconds) throws ZeroSpeedException {
        if (this.currentSpeed > 0) {
            double newCurrentSpeed = kinematicsFormulaOfVelocity(seconds, -1);
            if (newCurrentSpeed >= 0) 
                this.currentSpeed = newCurrentSpeed;
            else 
                this.currentSpeed = 0;

            double travelledDistance = kinematicsFormulaOfSpace(seconds, -1) * -1;
            this.mileage += travelledDistance / 1000;
        }
        else 
            throw new ZeroSpeedException();
    }
    
    private double kinematicsFormulaOfSpace(double seconds, int signal) {
        // S = Vo * t + 1/2 * a * t^2
        return ((this.currentSpeed * seconds) + 
            (((this.averageAcceleration * signal) * 
            (seconds * seconds)) / 2));
    }
    
    private double kinematicsFormulaOfVelocity(double seconds, int signal) {
        // V = Vo + a * t
        return (this.currentSpeed) + ((this.averageAcceleration * signal) * seconds);
    }
    
    private double kinematicsFormulaOfTime(double distance) {
        // t = (V - Vo) / a
        double newCurrentSpeed = kinematicsFormulaOfTorricelliVelocity(distance);
        return (newCurrentSpeed - this.currentSpeed) / this.averageAcceleration;
    }
    
    private double kinematicsFormulaOfTorricelliVelocity(double distance) {
        // V = Vo^2 + 2 * a *  S
        return Math.pow(this.currentSpeed, 2) + 2 * this.averageAcceleration * distance;
    }

    public double getCurrentSpeed() {
        return this.currentSpeed;
    }
    
    public double getFuelVolume() {
        return this.fuelVolume;
    }
}
