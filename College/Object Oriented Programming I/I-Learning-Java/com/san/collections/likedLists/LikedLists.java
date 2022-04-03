package com.san.collections.likedLists;

import java.util.LinkedList;

public class LikedLists {
	public static void likedLists() {
		LinkedList<String> nomes = new LinkedList<>();

		nomes.addFirst("João");
        nomes.addLast("Maria");
        nomes.removeFirst();
        nomes.removeLast();
        String nome = nomes.getFirst();
        nome = nomes.getLast();
	}
}