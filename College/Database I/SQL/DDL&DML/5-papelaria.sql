/*------------------------- QUESTÃO 1 -------------------------*/

CREATE TABLE ofc ( /* Só faz refência a tabelas já criadas */
	cod_filial_o 	 	  INTEGER 		NOT NULL,
	cod_ofc 	 	 	  INTEGER 		NOT NULL,
	cod_fornecedor_o 	  INTEGER 		NOT NULL,
	data_compra		 	  DATE			NOT NULL,
	valor_total_ofc  	  NUMERIC(8,2)	NOT NULL,
	contato			 	  VARCHAR(45)	NOT NULL,
	data_previsao_entrega DATE			NOT NULL,
	observacao			  TEXT			NOT NULL,
	posicao_ofc			  CHAR(1)		NOT NULL,
	CONSTRAINT pk_ofc
		PRIMARY KEY (cod_filial_o, cod_ofc),
	CONSTRAINT fk_ofc_filial
		FOREIGN KEY (cod_filial_o)
		REFERENCES filial (cod_filial),
	CONSTRAINT fk_ofc_fornecedor
		FOREIGN KEY (cod_fornecedor_o)
		REFERENCES fornecedor (cod_fornecedor),
	CONSTRAINT ck_ofc_posicao_ofc
		CHECK (posicao_ofc IN ('A', 'F'))
);

CREATE TABLE itens_ofc ( /* Faz referência a OFC ainda não criada */
	cod_filial_io  INTEGER 		NOT NULL,
	cod_ofc_io	   INTEGER 		NOT NULL,
	cod_produto_io INTEGER 		NOT NULL,
	quantidade 	   INTEGER 		NOT NULL,
	valor_unitario NUMERIC(8,2) NOT NULL,
	valor_total    NUMERIC(8,2) NOT NULL,
	data_entrega   DATE			NOT NULL,
	CONSTRAINT pk_itens_ofc
		PRIMARY KEY (cod_filial_io, cod_ofc_io, cod_produto_io)
	CONSTRAINT fk_itens_ofc_produto /* Chave composta de produto */
		FOREIGN KEY (cod_filial_io, cod_produto_io)
		REFERENCES produto (cod_filial_p, cod_produto)
	CONSTRAINT fk_itens_ofc_ofc 	/* Chave composta de ofc */
		FOREIGN KEY (cod_filial_io, cod_ofc_io)
		REFERENCES ofc (cod_filial_o, cod_ofc)
);

/*------------------------- QUESTÃO 2 -------------------------*/

UPDATE itens_ofc io
SET valor_unitario = p.valor_produto
/* , valor_total   = io.quantidade * io.valor_unitario; */
FROM produto p,
	 ofc o
WHERE io.cod_filial_io 	  = p.cod_filial_p /* JOIN de PK composta para valor_produto */
	AND io.cod_produto_io = p.cod_produto
	AND io.cod_filial_io  = o.cod_filial_o /* JOIN de PK composta para data_compra */
	AND io.cod_ofc_io 	  = o.cod_ofc
	AND o.data_compra BETWEEN '2019-10-09' AND '2019-10-10';
	
UPDATE itens_ofc io 
SET valor_total = io.quantidade * io.valor_unitario;

/*------------------------- QUESTÃO 3 -------------------------*/

ALTER TABLE itens_ofc
	ADD COLUMN cod_filial_pio INTEGER NULL;

UPDATE itens_ofc io /* Como todos os itens só foram da mesma ofc */
	SET cod_filial_pio = io.cod_filial_io;

ALTER TABLE itens_ofc
	ALTER COLUMN cod_filial_pio SET NOT NULL;
	
ALTER TABLE itens_ofc
	DROP CONSTRAINTS pk_itens_ofc, fk_itens_ofc_produto;
	
ALTER TABLE itens_ofc
	ADD CONSTRAINT pk_itens_ofc
	PRIMARY KEY (cod_filial_io, cod_ofc_io, cod_filial_pio, cod_produto_io);

ALTER TABLE itens_ofc
	ADD CONSTRAINT fk_itens_ofc_produto
	/* Fazendo agora o apontamento para filial do produto não mas da emissão da ofc */
	FOREIGN KEY (cod_filial_pio, cod_produto_io) 
	REFERENCES produto (cod_filial_p, cod_produto);

/*------------------------- QUESTÃO 4 -------------------------*/
	
BEGIN TRANSACTION;
	DELETE FROM itens_ofc io
	USING ofc o,
		filial f
	WHERE io.cod_filial_io = o.cod_filial_o /* Join para PK composta de ofc */
	  AND io.cod_ofc_io    = o.cod_ofc
	  AND o.cod_filial_o   = f.cod_filial 	/* Join para nome de filial */
	  AND f.nome_filial LIKE 'C%';
	  
	DELETE FROM ofc o
	USING filial f
	WHERE o.cod_filial_o   = f.cod_filial 	/* Join para nome de filial */
	  AND f.nome_filial LIKE 'C%';
COMMIT;

/*------------------------- QUESTÃO 5 -------------------------*/

UPDATE produto_fornecedor pf
	SET prazo_entrega       = pf.prazo_entrega * 1.12
	FROM fornecedor f, cidade c, uf u
	WHERE pf.cod_fornecedor = f.cod_fornecedor
	AND	  f.cod_cidade_f    = c.cod_cidade
	AND   c.sigla_uf_c      = u.sigla_uf
	AND   u.nome_uf IN ('Mato Grosso', 'Santa Catarina');
	