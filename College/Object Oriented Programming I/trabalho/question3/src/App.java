import java.util.Scanner;

import com.san.FileList.FileList;
import com.san.Menu.ProcessMenu;
import com.san.Menu.ShowMenu;

public class App {
    public static void main(String[] args) throws Exception {
        FileList.loadSalesList();
        FileList.loadSalesRecordList();
        Scanner scan = new Scanner(System.in);
        byte option;
        do {
            ShowMenu.show();
            System.out.print("\nEnter your option: ");
            option = scan.nextByte();
            ProcessMenu.process(scan, option);
        } while (option != 0);
        scan.close();
    }
}
