package com.san.Menu;

import java.io.IOException;
import java.util.LinkedList;

import com.san.Car.Car;
import com.san.Bike.Bike;
import com.san.SaleRecord.SaleRecord;
import com.san.SalesRecordList.SalesRecordList;

public class RegistredSalesMenu {
    
    protected static void show() {
        ClearScreenMenu.clearScreen();
        LinkedList<SaleRecord> salesRecordList = SalesRecordList.getSalesRecordList();
        
        for (SaleRecord saleRecord : salesRecordList) {
            System.out.format("\n%s\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
            System.out.printf("\nNumber of Sale: %d", salesRecordList.indexOf(saleRecord) + 1);
            System.out.printf("\nTime of Sale: %s", saleRecord.getDateTime());
            System.out.printf("\nVehicle: %s", saleRecord.getVehicle().getName());
            System.out.printf("\nBrand: %s", saleRecord.getVehicle().getBrand());
            System.out.printf("\nLicense Plate: %s", saleRecord.getVehicle().getLicensePlate());
            System.out.printf("\nYear: %d", saleRecord.getVehicle().getYear());
            System.out.printf("\nColor: %s", saleRecord.getVehicle().getColor());
            System.out.printf("\nMileage: %.2f", saleRecord.getVehicle().getMileage());
            if (saleRecord.getVehicle() instanceof Car) {
                System.out.printf("\nNumber of Doors: %d", ((Car) saleRecord.getVehicle()).getNumberOfDoors());
                System.out.printf("\nTrunk Capacity: %.2f", ((Car) saleRecord.getVehicle()).getTrunkSize());
            }
            else if (saleRecord.getVehicle() instanceof Bike) {
                System.out.printf("\nEngine Capacity: %d", ((Bike) saleRecord.getVehicle()).getEngineCapacity());
            }
            System.out.printf("\nOwner's Name: %s", saleRecord.getVehicle().getOwnersName());
            System.out.printf("\nBuyer Name: %s", saleRecord.getBuyerName());
            System.out.printf("\nPayment Type: %s", saleRecord.getPaymentType());
            System.out.printf("\nPrice: %.2f", saleRecord.getVehicle().getPrice());
        }

        System.out.format("\n\n%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.print("Type ENTER to continue.");
        try {
            System.in.read();
        } catch (IOException e) {}

    }
}
