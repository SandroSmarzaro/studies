/*---------------------------------- QUESTION 2 ------------------------------*/

SELECT clr.nome_cliente,
	SUM (cnf.valor_nf) AS soma_nf,
    COUNT (*) AS quantidade_total_nf,
	
	FROM ctrc c,
		ctrc_nf cnf,
		cliente clr,
		cliente cld,
		cidade cdr,
		cidade cdd,
		
	WHERE c.num_ctrc 			   = cnf.num_ctrc_nf 
		AND c.filial_origem_ctrc   = cnf.filial_origem_ctrc_nf
		AND c.cliente_remetente    = clr.cod_cliente
		AND clr.cidade_cliente 	   = cdr.cod_cidade
		AND cdr.sigla_uf_cidade    = 'RJ'
		AND c.cliente_destinatario = cld.cod_cliente
		AND cld.cod_cidade 		   = cdd.cod_cidade
		AND cdd.sigla_uf_cidade    = 'SP'
		AND c.peso_ctrc > 5
		
	GROUP BY clr.nome_cliente
	
	HAVING COUNT (*) > 100;
	
/*---------------------------------- QUESTION 3 ------------------------------*/

SELECT cl.nome_cliente,
	COUNT (*)
	
	FROM cliente cl,
		cidade cd,
		uf u,
		coleta co,
	
	WHERE cl.cidade_cliente     = cd.cod_cidade
		AND cd.sigla_uf_cidade  = u.sigla_uf
		AND u.nome_uf           = 'Rio de Janeiro'
		AND cl.cod_cliente      = co.cliente_coleta
		AND co.data_coleta BETWEEN '2017-01-01' AND '2017-12-31'
		
	GROUP BY cl.nome_cliente
	
	HAVING SUM (co.valor_nf_coleta) > 80;
	
/*---------------------------------- QUESTION 4 ------------------------------*/

SELECT cl.nome_cliente
	SUM (c.frete_ctrc)
	
	FROM cliente cl,
		ctrc c
		
	WHERE  cl.cod_cliente = c.cliente_remetente
	
	GROUP BY cl.cod_cliente, cl.nome_cliente
	
	HAVING SUM (c.frete_ctrc) > (SELECT c.limite_credito
									FROM cliente c
									WHERE c.cod_cliente = cl.cod_cliente);
									
/*---------------------------------- QUESTION 5 ------------------------------*/

SELECT co.nome_cidade,
	cd.nome_cidade,
	SUM (c.frete_ctrc),
	SUM (c.peso_ctrc),
	AVG (c.frete_ctrc),
	AVG (c.peso_ctrc),
	MAX (c.frete_ctrc),
	MAX (c.peso_ctrc),
	MIN (c.frete_ctrc),
	MIN (c.peso_ctrc),
	
	FROM ctrc c
	INNER JOIN cliente clo
		ON clo.cod_cliente = c.cliente_remetente
	INNER JOIN cidadde co 
		ON co.cod_ciade    = clo.cidade_cliente
	INNER JOIN cliente cld
		ON cld.cod_cliente = c.cliente_destinatario
	INNER JOIN cidade cd
		ON cld.cod_cliente = c.cliente_destinatario
		
	WHERE co.nome_cidade <> cd.nome_cidade
		
	HAVING SUM (c.frete_ctrc) > 95
		AND AVG (c.peso_ctrc) > 92
	
	GROUP BY co.nome_cidade, cd.nome_cidade
	
	ORDER BY AVG (c.frete_ctrc);

/*----------------------------------------------------------------------------*/