/*********************** Antigo JOIN ************************/

SELECT x.campo1 AS campo1,
	   y.campo2 AS campo2
	FROM tabelax x,
		 tabelay y
	WHERE x.campo3 = y.campo3;

/*********************** CROSS JOIN *************************/

/* Para cada linha da Tabela X
Agrupa-se com todas as linhas da Tabela Y */

SELECT *
	FROM tabelaX
	CROSS JOIN tabelaY;

/********************** INNER JOIN **************************/

SELECT * 
	FROM tabela1 t1
	INNER JOIN tabela2 t2 
		ON  t1.colunaX = t2.colunaY;
	
SELECT tx.colunaA,
	   ty.colunaB,
	   tz.colunaC AS alias1,
	   tZ.colunaC AS alias2,
	FROM tabelaX tx
	INNER JOIN tabelaY ty
		ON tx.colunaA = ty.colunaB
	INNER JOIN tabelaZ tz
		ON ty.colunaB = tz.colunaC
	INNER JOIN tabelaZ tZ			/* Dois relacionamentos */
		ON ty.colunaB = tZ.colunaC;
		
SELECT tk.coluna1,
	   tw.coluna2
	FROM tabelak tk
	INNER JOIN 
			ON tk.chave1 = tw.chave1 /* Chave composta */
		   AND tk.chave2 = tw.chave2;

/*********************** LEFT/RIGHT OUTER JOIN *************************************/

/* Realiza um JOIN interno primeiramente para na seguida
também retornar as outras linhas da tabela a esquerda do comando
que ficaram de fora do JOIN interno, o conjunto final então é esse JOIN */

SELECT t1.colunaA,
       t2.colunaB
	FROM tabela1 t1
	LEFT OUTER JOIN tabela2 t2
		ON t1.id = t2.id;
		
/************************** FULL OUTER JOIN ****************************************/

/* Junção do LEFT e RIGHT JOIN no memso conjunto de resultado */

SELECT t1.colunaA,
       t2.colunaB
	FROM tabela1 t1
	FULL OUTER JOIN tabela2 t2
		ON t1.id = t2.id;

/************************** NATURAL INNER JOIN *************************************/

/* JOIN interno com a ausência do ON devido as PK e FK nas respectivas tabelas 
terem o nome idênticos, no caso a coluna id em ambas */

SELECT t1.colunaA,
       t2.colunaB
	FROM tabela1 t1
	NATURAL INNER JOIN tabela2 t2;
	
/******************************** AGREGAÇÃO *****************************************/

SELECT COUNT (t.coluna)
	FROM tabela t;

SUM	
AVG
MIN
MAX

SELECT t.coluna,
	COUNT (*)
	FROM tabela t
	GROUP BY t.tipoColuna;
	
/******************************* Informação *****************************************

* ANALÍTICA - Dado puro isolado
* SINTETICA - Dado resultante de um processo 

* Não há como unir informações analíticas e sintéticas em um mesmo SELECT
exceto quando houver informações analíticas concebidas por GROUP BY


******************************* STORAGE PROCEDURE ***********************************/
/* Processos de processamento demorado e retorno pequeno */

/*1*/
CREATE FUNCTION soma(INTEGER, INTEGER)
	RETURNS INTEGER
	AS
		'SELECT $1 + $2;'
	LANGUAGE 'sql';
	
SELECT * FROM soma(2, 3);

DROP FUNCTION soma(INTEGER, INTEGER);

/*2*/
CREATE OR REPLACE FUNCTION soma(CHAR, CHAR)
	RETURNS CHAR
	AS
		'SELECT $1 || $2;'
	LANGUAGE 'sql';