package com.sandro.Exception;

public class NotEnoughFuelException extends Exception {
    public NotEnoughFuelException(double secondsRequired, double secondsLeft) {
        super("Not enough fuel to accelerate for " + secondsRequired + " seconds!" + 
            "\nYou accelerated for " + secondsLeft +  " seconds.");
    }
}
