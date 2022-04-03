package com.san.strings;

import java.util.Formatter;

public class Strings {
	public static void strings() {
		String string = "string";				// SCP
		String string2 = new String("string"); 	// Heap
		boolean boo_st = (string == string2); 	// Comparação de referência
		string.equals(string2); 				// Comparação de contéudo
		string.equalsIgnoreCase(string2); 		// Comparação de contéudo ignorando case
		string.compareTo(string2); 				// Diferença de contéudo com base em ASCII
		string.compareToIgnoreCase(string2); 	// Diferença de contéudo com base em ASCII ignorando case
		string.concat(string2);					// Concatenação
		string.replace(string, string2);		// Troca a primeira ocorrencia do 1o pelo 2o
		string.replaceAll(string, string2);		// Troca o 1o pelo 2o em todos os casos
		string.toUpperCase();					// Deixa tudo maiusculo
		string.toLowerCase();					// Deixa tudo minusculo
		string.trim(); 							// Remove espaços nas laterais
		string.split(string2);					// Cria um array com elementos sepados pelo parametro
		string.charAt(1);						// Qual caracter está no index do parametro passado
		string.substring(0, 1);					// Obter uma nova stirng contida naquele intervalo de index passado
		string.valueOf(boo_st);					// Tranformar o valor do objeto qualquer em string
		string.contains(string2);				// Verifica se a string tem inserida string2
		string.startsWith(string2);				// Verifica se a string começa com tal string2
		string.endsWith(string2);				// Verifica se a string termina com string2
		string.indexOf(string2);				// Retorna o indice da primeira ocorrecia de string2
		string.lastIndexOf(string2);			// Retorna o indice da última ocorrência de string2
		string.isEmpty();						// Verifica se a string está vazia
		string.length();						// Retorna o tamanho da string
		StringBuilder string3 = new StringBuilder();
		string3.append(string);					// Adiciona no final da string3 a string passada
		string3.insert(0,string);				// Adiciona na posição especificada a sting passadaem string3

		Formatter formatter = new Formatter(string3);
		formatter.format("Test %s", string3);
		formatter.close();
		System.out.println(formatter.toString());
	}
}