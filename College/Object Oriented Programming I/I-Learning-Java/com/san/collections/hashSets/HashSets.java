package com.san.collections.hashSets;

import java.util.*;

public class HashSets {
	public static void hashSets() {
		// Parametro de tamnho não limita crescimento
		// Elementos não são duplicados
		// A ordem é de acordo com o hash code
		HashSet<String> tags = new HashSet<>();
        tags.add("java");
        tags.add("c#");
        int hashCodes = tags.hashCode();

        HashMap<Integer, String> linguagens = new HashMap<Integer, String>();
        linguagens.put(1, "Java");
        // linguagens.keySet();
        // linguagens.values();
        for (Map.Entry<Integer, String> entry : linguagens.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }
	}
}