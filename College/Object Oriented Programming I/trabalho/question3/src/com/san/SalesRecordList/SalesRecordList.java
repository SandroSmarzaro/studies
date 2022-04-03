package com.san.SalesRecordList;

import java.util.LinkedList;

import com.san.SaleRecord.SaleRecord;
import com.san.Vehicle.Vehicle;

public abstract class SalesRecordList {
    private static LinkedList<SaleRecord> salesRecordList = new LinkedList<SaleRecord>();

    public static void add(Vehicle vehicle, String buyerName, String paymentType) {
        SaleRecord saleRecord = new SaleRecord(vehicle, buyerName, paymentType);
        salesRecordList.add(saleRecord);
    }

    public static LinkedList<SaleRecord> getSalesRecordList() {
        return salesRecordList;
    }

    public static void setSalesRecordList(LinkedList<SaleRecord> salesRecordList) {
        SalesRecordList.salesRecordList = salesRecordList;
    }
}
