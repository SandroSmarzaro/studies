CREATE OR REPLACE FUNCTION lista_cidade() 
	RETURNS SETOF cidade 
	AS
		'SELECT * FROM cidade;' 
	LANGUAGE 'sql';

/*------------------------------------------*/

SELECT * FROM lista_cidade();

SELECT * 
	FROM lista_cidade() lc
	WHERE lc.sigla_uf = 'ES';
	
/*------------------------------------------*/

SELECT  lc.nome_cidade,
		u.nome_uf
	FROM lista_cidade() lc,
		 uf u
	WHERE lc.sigla_uf = u.sigla_uf;


SELECT lc.nome_cidade
	   u.nome_uf
	  FROM lista_cidade() lc  
	  INNER JOIN uf u
	  	ON lc.sigla_uf = u.sigla_uf;

/*------------------------------------------*/

SELECT u.nome_uf AS nome_da_uf
	COUNT (*) AS quantidade_cidade
	FROM uf u,
	INNER JOIN lista_cidade() lc
		ON u.nome_uf = lc.nome_uf
	WHERE lc.nome_cidade LIKE 'C%'
	GROUP BY u.nome_uf
	HAVING count(*) > 1
	ORDER BY nome_da_uf DESC;
	
/*------------------------------------------*/
	