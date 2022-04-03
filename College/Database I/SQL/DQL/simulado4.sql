/*---------------------------------- QUESTION 1 ------------------------------*/

SELECT 	f.nome_funcionario,
		COUNT (*)           AS quantidade_item_os,
		SUM (io.quantidade) AS soma_da_quantidade_utilizada,
		AVG (io.quantidade) AS media_da_quantidade_utilizada,
		MAX (ioquantidade)  AS maior_da_quantiade_utilizada,
		MIN (io.quantidade) AS menor_da_quantidade_utilizada,
		
		SUM (io.total_item) AS soma_valor_total_item,
		MIN (io.total_item) AS menor_valor_total_item,
		MAX (io.total_item) AS maior_valor_total_item,
		AVG (io.total_item) AS média_valor_total_item
		
		FROM funcionario f,
			funcao_funcionario ff,
			os o,
			itens_os io,
		WHERE f.cod_funcao_func 		   = ff.cod_funcao_funcionario  
			AND ff.desc_funcao_funcionario = 'MECÂNICO'
			AND f.matricula                =  o.mecanico
			AND o.num_os                   = io.num_os_ios
		
		GROUP BY f.nome_funcionario;
		
		HAVING SUM COUNT (*) > 100
			AND SUM (io.total_item) < 1000
			
		ORDER BY  quantidade_item_os, soma_valor_total_item;