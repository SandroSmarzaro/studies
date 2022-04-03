package com.san.Menu;

import java.io.IOException;
import java.util.LinkedList;

import com.san.Bike.Bike;
import com.san.Car.Car;
import com.san.SalesList.SalesList;
import com.san.Vehicle.Vehicle;

public abstract class VehiclesForSaleMenu {
    protected static void show() {
        int QUANTITY_OF_CHARACTERS_LIST = 104;
        ClearScreenMenu.clearScreen();
        System.out.format("%s\n", "-".repeat(QUANTITY_OF_CHARACTERS_LIST));
        System.out.printf("| %-3s|", "ID");
        System.out.printf(" %-10s|", "Name");
        System.out.printf(" %-10s|", "Brand");
        System.out.printf(" %-10s|", "Color");
        System.out.printf(" %-5s|", "Year");
        System.out.printf(" %-10s|", "Mileage");
        System.out.printf(" %-12s|", "Trunk Size");
        System.out.printf(" %-6s|", "Doors");
        System.out.printf(" %-7s|", "Engine");
        System.out.printf(" %-10s|", "Price");
        System.out.format("\n%s\n", "-".repeat(QUANTITY_OF_CHARACTERS_LIST));

        LinkedList<Vehicle> salesList = SalesList.getSalesList();
        for (Vehicle vehicle : salesList) {
            System.out.printf(" %-5d", salesList.indexOf(vehicle) + 1);
            System.out.printf(" %-11s", vehicle.getName());
            System.out.printf(" %-11s", vehicle.getBrand());
            System.out.printf(" %-11s", vehicle.getColor());
            System.out.printf(" %-6d", vehicle.getYear());
            System.out.printf(" %-11.2f", vehicle.getMileage());
            if (vehicle instanceof Car) {
                System.out.printf(" %-14.2f", ((Car) vehicle).getTrunkSize());
                System.out.printf("%-8d", ((Car) vehicle).getNumberOfDoors());
                System.out.printf("%-9s", "N/A");
            }
            else {
                System.out.printf(" %-14s", "N/A");
                System.out.printf("%-8s", "N/A");
                System.out.printf("%-9d", ((Bike) vehicle).getEngineCapacity());
            }
            System.out.printf("%-9.2f", vehicle.getPrice());
            System.out.println();
        }
        System.out.format("%s\n\n", "-".repeat(QUANTITY_OF_CHARACTERS_LIST));
        System.out.print("Type ENTER to continue.");
        try {
            System.in.read();
        } catch (IOException e) {}
    }
}
