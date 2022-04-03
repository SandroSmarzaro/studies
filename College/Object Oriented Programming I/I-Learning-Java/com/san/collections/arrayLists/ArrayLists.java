package com.san.collections.arrayLists;

import java.util.ArrayList;
// import java.util.Collection;

public class ArrayLists {
	public static void arrayLists() {
		ArrayList<String> nomes = new ArrayList<String>();
        
        nomes.add("João");
        String nome = nomes.get(0);
        nomes.set(0, "Maria");
        nomes.remove(0);
        nomes.clear();
        nomes.size();
        nomes.contains("João");
        nomes.isEmpty();
        nomes.indexOf("João");

        // Collection.sort(nomes);
	}
}