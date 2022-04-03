/*---------------------------------- QUESTION 1 ------------------------------*/

SELECT e.nome_especialidade,
	SUM (ip.valor_liquido_total_ip) AS faturamento_total
	
	FROM especialidade e
	
	INNER JOIN catalogo_venda cv
		ON e.cod_especialidade = cv.especialidade
		
	INNER JOIN itens_pedido ip
		ON cv.cod_servprod     = ip.cod_servprod_ip
	
	INNER JOIN pedido p
		ON ip.cod_filial_ip    = p.cod_filial_p
		AND ip.cod_pedido_ip   = p.cod_pedido
	
	WHERE p.data_pedido BETWEEN '2018-02-01' AND '2018-07-31'
	
	GROUP BY e.nome_especialidade;
	
	HAVING SUM(ip.valor_liquido_total_ip) 
	
	ORDER BY SUM(faturamento_total);
	
/*---------------------------------- QUESTION 2 ------------------------------*/