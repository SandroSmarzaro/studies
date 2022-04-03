package com.sandro.Circle;

import com.sandro.Execeptions.NegativeValueException;

public class Circle {
    private double radius;
    private double coordinateX;
    private double coordinateY;

    public Circle(double radius, double coordinateX, double coordinateY) throws NegativeValueException {
        setRadius(radius);
        this.coordinateX = coordinateX;
        this.coordinateY = coordinateY;
    }
    public void increaseRadius(double percentage) throws NegativeValueException {
        if (percentage < 0) 
            throw new NegativeValueException();
        else {
            double decimalPercentage = percentage / 100;
            double increaseValue = this.radius * decimalPercentage;
            this.radius += increaseValue;
        }
    }

    public double getRadius() {
        return this.radius;
    }

    public void setRadius(double newRadius) throws NegativeValueException {
        if (newRadius > 0) 
            this.radius = newRadius;
        else
            throw new NegativeValueException();
    } 

    public double[] getCoordinates() {
        return new double[] {this.coordinateX, this.coordinateY};
    }
    
    public void setCoordinates(double newCoordinateX, double newCoordinateY) {
        this.coordinateX = newCoordinateX;
        this.coordinateY = newCoordinateY;
    }

    public void setCicleCenter(double newCoordinateX, double newCoordinateY) {
        setCoordinates(newCoordinateX, newCoordinateY);
    }

    public double getCircleArea() {
        return Math.PI * Math.pow(this.radius, 2);
    }

    public double getCircumference() {
        return 2 * Math.PI * this.radius;
    }

}
