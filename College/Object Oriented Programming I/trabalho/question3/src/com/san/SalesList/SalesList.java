package com.san.SalesList;

import java.util.LinkedList;

import com.san.Bike.Bike;
import com.san.Vehicle.Vehicle;
import com.san.carModels.Hatch.Hatch;
import com.san.carModels.SUV.SUV;
import com.san.carModels.Sedan.Sedan;
import com.san.carModels.Truck.Truck;

public abstract class SalesList {
    private static LinkedList<Vehicle> salesList = new LinkedList<Vehicle>();

    public static void add(Hatch hatch) {
        salesList.add(hatch);
    }

    public static void add(Sedan sedan) {
        salesList.add(sedan);
    }

    public static void add(SUV suv) {
        salesList.add(suv);
    }

    public static void add(Truck truck) {
        salesList.add(truck);
    }

    public static void add(Bike bike) {
        salesList.add(bike);
    }

    public static void remove(int index) {
        salesList.remove(index - 1);
    }

    public static LinkedList<Vehicle> getSalesList() {
        return salesList;
    }

    public static Vehicle getVehicle(int index) {
        return salesList.get(index - 1);
    }

    public static void setSalesList(LinkedList<Vehicle> salesList) {
        SalesList.salesList = salesList;
    }
}
