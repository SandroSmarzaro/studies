/*---------------------------------- QUESTION 1 ------------------------------*/

SELECT u.nome_uf,
	COUNT (*)             AS quantidade_itens,
	SUM (p.valor_produto) AS soma_valor_produto,
	SUM (p.estoque)       AS soma_quantidade_estoque,
	
	FROM produto p,
		tipo_porduto tp,
		filial f,
		cidade cd,
		uf u
	WHERE p.cod_tipo_produto_p   = tp.cod_tipo_produto
		AND tp.desc_tipo_produto = 'PAPELARIA'
		AND p.cod_filial_p       = f.cod_filial
		AND f.cod_cidade_filial  = cd.cod_cidade
		AND cd.sigla_uf_c        = u.sigla_uf
	
	GROUP BY u.nome_uf;
	
	HAVING AVG (p.valor_produto) > 100
	
/*---------------------------------- QUESTION 2 ------------------------------*/

SELECT cd.sigla_uf_c,
	SUM (iofc.valor_unitario)
	
	FROM ofc o
		INNER JOIN itens_ofc iofc
			ON o.cod_filial_compra = iofc.cod_filial_compra_io
			AND o.cod_ofc		   = iofc.cod_ofc_io
		
		INNER JOIN fornecedor f
			ON f.cod_fornecedor    = o.cod_fornecedor_o
			
		INNER JOIN cidade cd
			ON cd.cod_cidade       = f.cod_cidade_f

	WHERE BETWEEN o.data_compra '2019-01-02' AND '2019-12-02'
	
	GROUP BY cd.sigla_uf_c
	
	HAVING SUM(iofc.quantidade_comprada) > 100
	
	