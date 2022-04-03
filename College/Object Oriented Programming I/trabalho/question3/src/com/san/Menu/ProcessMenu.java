package com.san.Menu;

import java.util.Scanner;

public abstract class ProcessMenu {
    public static void process(Scanner scan, byte option) {
        switch (option) {
            case 1:
                VehiclesForSaleMenu.show();
                break;
            case 2:
                RegisterSalesMenu.show(scan);
                break;
            case 3:
                SellVehicleMenu.show(scan);
                break;
            case 4:
                RegistredSalesMenu.show();
                break;
            case 0:
                ExitProgramMenu.show();
                break;
            default:
                InvalidOptionMenu.show();
                break;
        }
    }
}
