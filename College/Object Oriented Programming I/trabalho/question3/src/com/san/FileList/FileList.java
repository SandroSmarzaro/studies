package com.san.FileList;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.LinkedList;

import com.san.SaleRecord.SaleRecord;
import com.san.SalesList.SalesList;
import com.san.SalesRecordList.SalesRecordList;
import com.san.Vehicle.Vehicle;

public abstract class FileList {
    private static final String PATH_SALESLIST = "src\\com\\san\\Saves\\salesList.dat";
    private static final String PATH_SALESRECORDLIST = "src\\com\\san\\Saves\\salesRecordList.dat";

    public static void loadSalesList() {
        LinkedList<Vehicle> newSalesList = new LinkedList<Vehicle>();
        FileInputStream fileInputStream = null;
        ObjectInputStream objectInputStream = null;

        try {
            fileInputStream = new FileInputStream(PATH_SALESLIST);
            objectInputStream = new ObjectInputStream(fileInputStream);
            newSalesList = (LinkedList<Vehicle>) objectInputStream.readObject();
            SalesList.setSalesList(newSalesList);
        }
        catch (ClassNotFoundException e) {
            
        }
        catch (FileNotFoundException e) {

        }
        catch (IOException e) {
            
        }
        finally {
            if (objectInputStream != null) {
                try {
                    objectInputStream.close();
                }
                catch (Exception e) {
                    
                }
            }
        }
    }
    public static void saveSalesList(LinkedList<Vehicle> salesList) {
        FileOutputStream fileOutputStream = null;
        ObjectOutputStream objectOutputStream = null;
        
        try {
            fileOutputStream = new FileOutputStream(PATH_SALESLIST);
            objectOutputStream = new ObjectOutputStream(fileOutputStream);
            objectOutputStream.writeObject(salesList);
        }
        catch (FileNotFoundException e) {
            
        }
        catch (IOException e) {
            
        }
        finally {
            if (objectOutputStream != null) {
                try {
                    objectOutputStream.close();
                }
                catch (Exception e) {
                    
                }
            }
        }
    }

    public static void loadSalesRecordList() {
        LinkedList<SaleRecord> newSalesRecordList = new LinkedList<SaleRecord>();
        FileInputStream fileInputStream = null;
        ObjectInputStream objectInputStream = null;

        try {
            fileInputStream = new FileInputStream(PATH_SALESRECORDLIST);
            objectInputStream = new ObjectInputStream(fileInputStream);
            newSalesRecordList = (LinkedList<SaleRecord>) objectInputStream.readObject();
            SalesRecordList.setSalesRecordList(newSalesRecordList);
        }
        catch (ClassNotFoundException e) {
            
        }
        catch (FileNotFoundException e) {

        }
        catch (IOException e) {
            
        }
        finally {
            if (objectInputStream != null) {
                try {
                    objectInputStream.close();
                }
                catch (Exception e) {
                    
                }
            }
        }
    }

    public static void saveSalesRecordList(LinkedList<SaleRecord> salesRecordList) {
        FileOutputStream fileOutputStream = null;
        ObjectOutputStream objectOutputStream = null;
        
        try {
            fileOutputStream = new FileOutputStream(PATH_SALESRECORDLIST);
            objectOutputStream = new ObjectOutputStream(fileOutputStream);
            objectOutputStream.writeObject(salesRecordList);
        }
        catch (FileNotFoundException e) {
            
        }
        catch (IOException e) {
            
        }
        finally {
            if (objectOutputStream != null) {
                try {
                    objectOutputStream.close();
                }
                catch (Exception e) {
                    
                }
            }
        }
    }
}
