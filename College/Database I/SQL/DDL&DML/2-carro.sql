/*------------------------- QUESTÃO 1 -------------------------*/

CREATE TABLE produto (
	cod_fornecedor_p INTEGER 	  NOT NULL,
	cod_produto 	 INTEGER 	  NOT NULL,
	desc_produto 	 VARCHAR(30)  NOT NULL,
	valor_compra 	 NUMERIC(6,2) NOT NULL,
	estoque 		 INTEGER 	  NOT NULL,
	valor_venda 	 NUMERIC(6,2) NOT NULL,
	CONSTRAINT pk_produto
		PRIMARY KEY (cod_fornecedor_p, cod_produto),
	CONSTRAINT fk_produto_fornecedor
		FOREIGN KEY (cod_fornecedor_p)
		REFERENCES fornecedor(cod_fornecedor)
);

CREATE TABLE tabela (
	cod_tabela   INTEGER 	  NOT NULL,
	desc_tabela  VARCHAR(20)  NOT NULL,
	valor_tabela NUMERIC(6,2) NOT NULL,
	CONSTRAINT pk_tabela
		PRIMARY KEY (cod_tabela)
);

CREATE TABLE item_os (
	num_os_ios 	   INTEGER 		NOT NULL,
	cod_tabela_ios INTEGER 		NOT NULL,
	valor_item     NUMERIC(6,2) NOT NULL,
	quantidade 	   INTEGER 		NOT NULL,
	CONSTRAINT pk_item_os
		PRIMARY KEY (num_os_ios, cod_tabela_ios),
	CONSTRAINT fk_item_os_os
		FOREIGN KEY (num_os_ios)
		REFERENCES os(num_os),
	CONSTRAINTS fk_item_os_tabela
		FOREIGN KEY (cod_tabela_ios)
		REFERENCES tabela(cod_tabela)
);

CREATE TABLE utiliza (
	num_os_u 			 INTEGER NOT NULL,
	cod_tabela_u 		 INTEGER NOT NULL,
	cod_fornecedor_u 	 INTEGER NOT NULL,
	cod_produto_u 		 INTEGER NOT NULL,
	quantidade_utilizada INTEGER NOT NULL,
	CONSTRAINT pk_utiliza
		PRIMARY KEY (num_os_u, cod_tabela_u, cod_fornecedor_u, cod_produto_u),
	CONSTRAINT fk_utiliza_item_os
		FOREIGN KEY (num_os_u, cod_tabela_u)
		REFERENCES item_os(num_os_ios, cod_tabela_ios),
	CONSTRAINT fk_utiliza_produto
		FOREIGN KEY (cod_fornecedor_u, cod_produto_u)
		REFERENCES produto(cod_fornecedor_p, cod_produto)
);

/*------------------------- QUESTÃO 2 -------------------------*/

ALTER TABLE item_os
	ADD COLUMN valor_total_item NUMERIC(8,2) NULL;
	
UPDATE item_os ios
	SET valor_total_item = ios.valor_item * ios.quantidade;

ALTER TABLE item_os
	ALTER COLUMN valor_total_item SET NOT NULL;

/*------------------------- QUESTÃO 3 -------------------------*/

UPDATE item_os ios
	SET valor_item = t.valor_tabela
	FROM tabela t,
		os o,
		cliente c
	WHERE ios.cod_tabela_ios = t.cod_tabela 	/* JOIN do SET da linha 70 */
		AND ios.num_os_ios 	 = o.num_os			/* JOIN para as datas */
		AND o.data_incio BETWEEN '2016-09-13' AND '2016-10-14'
		AND o.cod_cliente_os = c.cod_cliente	/* JOIN para a UF */
		AND c.uf = 'ES';

/*------------------------- QUESTÃO 4 -------------------------*/

BEGIN TRANSACTION;
	
	UPDATE produto p
		SET estoque = p.estoque + u.quantidade_utilizada
		FROM utiliza u
		WHERE p.cod_fornecedor_p = u.cod_fornecedor_u /* JOIN de PK composta para estoque */
			AND p.cod_produto 	 = u.cod_produto_u
			AND u.num_os_u 		 = 123456;		/* Para não alterar o estoque de todos produtos */
	
	DELETE FROM utiliza u 
		WHERE u.num_os_u = 123456;
	
	DELETE FROM item_os ios
		WHERE ios.num_os_ios = 123456;
	
	DELETE FROM os o 
		WHERE o.num_os = 123456;
	
COMMIT;

/*------------------------- QUESTÃO 5 -------------------------*/

UPDATE os o
	SET total_os = o.total_os * 1.25
	FROM cliente cl,
		 carro cr,
		 modelo mod,
		 marca mac,
	WHERE o.cod_cliente_os = cl.cod_cliente /* JOIN para UF de cliente */
		AND cl.uf IN ('ES', 'RJ', 'SP')
		AND cl.cod_cliente  = cr.cod_cliente_c /* JOIN para carro */
		AND cr.cod_modelo_c = mod.cod_modelo   /* JOIN para modelo */
		AND mod.cod_marca_m = mac.cod_marca    /* JOIN para nome da marca */
		AND mac.nome_marca LIKE 'ABC%';