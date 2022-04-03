package com.san.Menu;

import java.util.Scanner;

import com.san.FileList.FileList;
import com.san.SalesList.SalesList;

public abstract class SellVehicleMenu {
    protected static void show(Scanner scan) {
        byte option;
        do {
            option = VehicleTypeMenu.input(scan);
            if (option == 0) break;

            String nameVehicle = NameVehicleMenu.input(scan);
            if(nameVehicle.equals("0")) break;

            String brandVehicle = BrandVehicleMenu.input(scan);
            if (brandVehicle.equals("0")) break;

            String colorVehicle = ColorVehicleMenu.input(scan);
            if (colorVehicle.equals("0")) break;

            int yearVehicle = YearVehicleMenu.input(scan);
            if (yearVehicle == 0) break;

            double mileageVehicle = MileageVehicleMenu.input(scan);
            if (mileageVehicle == 0) break;

            String licensePlate = LicensePlateMenuVehicle.input(scan);
            if (licensePlate.equals("0")) break;

            String ownersName = OwnersNameVehicleMenu.input(scan);
            if (ownersName.equals("0")) break;

            double price = PriceVehicleMenu.input(scan);
            if (price == 0) break;
            
            if (option == 2) {
                double trunkSize = TrunkSizeVehicleMenu.input(scan);
                if (trunkSize == 0) break;

                byte optionCarModel;
                short numberOfDoors = 0;
                while (true) {
                    CarModelsMenu.show();
                    optionCarModel = scan.nextByte();
                    
                    if (optionCarModel == 0) break;
                    
                    else if (optionCarModel > 4 || optionCarModel < 0) {
                        InvalidOptionMenu.show();
                    }
                    else {
                        if (optionCarModel == 4) 
                            numberOfDoors = NumberOfDoorsVehicleMenu.input(scan);
                        
                        ProcessCarModel.process (
                            optionCarModel, 
                            nameVehicle, 
                            brandVehicle, 
                            colorVehicle, 
                            yearVehicle, 
                            mileageVehicle, 
                            trunkSize,
                            numberOfDoors,
                            licensePlate,
                            ownersName,
                            price
                        );
                        break;
                    }
                }
            }
            else {
                int engineCapacity = EngineCapacityMenu.input(scan);
                if (engineCapacity == 0) break;
                ProcessBike.process (
                    nameVehicle, 
                    brandVehicle, 
                    colorVehicle, 
                    yearVehicle, 
                    mileageVehicle,
                    licensePlate,
                    ownersName,
                    price,
                    engineCapacity
                );
            }
            FileList.saveSalesList(SalesList.getSalesList());
            break;
        } while (true);
    }
}
