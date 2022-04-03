package com.sandro.Execeptions;

public class NegativeValueException extends Exception {
    public NegativeValueException() {
        super("The value must be greater than zero!");
    }
}
