package com.sandro.Exception;

public class ZeroSpeedException extends Exception {
    public ZeroSpeedException() {
        super("The speed is already zero!");
    }
}
