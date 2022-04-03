package com.san.SaleRecord;

import java.io.Serializable;
import java.time.LocalDateTime;

import com.san.Vehicle.Vehicle;

public class SaleRecord implements Serializable{
    private Vehicle vehicle;
    private String buyerName;
    private String paymentType;
    private LocalDateTime dateTime;

    public SaleRecord(Vehicle vehicle, String buyerName, String paymentType) {
        this.vehicle = vehicle;
        this.buyerName = buyerName;
        this.paymentType = paymentType;
        this.dateTime = LocalDateTime.now();
    }

    public Vehicle getVehicle() {
        return vehicle;
    }

    public String getBuyerName() {
        return buyerName;
    }

    public String getPaymentType() {
        return paymentType;
    }

    public LocalDateTime getDateTime() {
        return dateTime;
    }
}
