/*------------------------- QUESTÃO 1 -------------------------*/

CREATE TABLE manifesto (
	num_manifesto 		     CHAR(6) NOT NULL,
	filial_origem_manifesto  CHAR(3) NOT NULL,
	filial_destino_manifesto CHAR(3) NOT NULL,
	data_emissao_manifesto 	 DATE    NOT NULL,
	data_chegada_manifesto   DATE	     NULL,
	veiculo_manifesto	     CHAR(7) NOT NULL,
	CONSTRAINT pk_manifesto
		PRIMARY KEY (num_manifesto),
	CONSTRAINT fk_manifesto_filial_origem
		FOREIGN KEY (filial_origem_manifesto)
		REFERENCES filial(sigla_filial),
	CONSTRAINT fk_manifesto_filial_destino
		FOREIGN KEY (filial_destino_manifesto)
		REFERENCES filial(sigla_filial),
	CONSTRAINT fk_manifesto_veiculo
		FOREIGN KEY (veiculo_manifesto)
		REFERENCES veiculo(placa_veiculo)
);

CREATE TABLE manifesto_motorista (
	num_manifesto CHAR(6)  NOT NULL,
	cnh_motorista CHAR(11) NOT NULL,
	CONSTRAINT pk_manifesto_motorista
		PRIMARY KEY (num_manifesto, cnh_motorista),
	CONSTRAINT fk_manifesto_motorista_manifesto
		FOREIGN KEY (num_manifesto)
		REFERENCES manifesto(num_manifesto),
	CONSTRAINT fk_manifesto_motorista_motorista
		FOREIGN KEY (cnh_motorista)
		REFERENCES motorista(cnh_motorista)
);

CREATE TABLE ctrc (
	num_ctrc 	   	  	 CHAR(6) 	  NOT NULL,
	filial_origem  	  	 CHAR(3) 	  NOT NULL,
	filial_destino 	  	 CHAR(3) 	  NOT NULL,
	cliente_remetente 	 INTEGER 	  NOT NULL,
	cliente_destinatario INTEGER 	  NOT NULL,
	data_emissao		 DATE 	 	  NOT NULL,
	peso_ctrc			 NUMERIC(9,3) NOT NULL,
	frete_ctrc			 NUMERIC(9,2) NOT NULL,
	CONSTRAINT pk_ctrc
		PRIMARY KEY (num_ctrc),
	CONSTRAINT fk_ctrc_filial_origem
		FOREIGN KEY (filial_origem)
		REFERENCES filial(sigla_filial),
	CONSTRAINT fk_ctrc_filial_destino
		FOREIGN KEY (filial_destino)
		REFERENCES filial(sigla_filial),
	CONSTRAINT fk_ctrc_cliente_remetente
		FOREIGN KEY (cliente_remetente)
		REFERENCES cliente(cod_cliente),
	CONSTRAINT fk_ctrc_cliente_destinatario
		FOREIGN KEY (cliente_destinatario)
		REFERENCES cliente(cod_cliente),
);

CREATE TABLE ctrc_nf (
	num_ctrc CHAR(6) NOT NULL,
	num_nf   CHAR(6) NOT NULL,
	CONSTRAINT pk_ctrc_nf
		PRIMARY KEY (num_ctrc, num_nf),
	CONSTRAINT fk_ctrc_nf_ctrc
		FOREIGN KEY (num_ctrc)
		REFERENCES ctrc(num_ctrc)
);

CREATE TABLE itens_manifesto (
	num_manifesto CHAR(6) NOT NULL,
	num_ctrc	  CHAR(6) NOT NULL,
	posicao_ctrc  CHAR(1) NOT NULL,
	CONSTRAINT pk_itens_manifesto
		PRIMARY KEY (num_manifesto, num_ctrc),
	CONSTRAINT fk_itens_manifesto_manifesto
		FOREIGN KEY (num_manifesto)
		REFERENCES manifesto(num_manifesto),
	CONSTRAINT fk_itens_manifesto_ctrc
		FOREIGN KEY (num_ctrc)
		REFERENCES ctrc(num_ctrc)
);

/*------------------------- QUESTÃO 2 -------------------------*/

ALTER TABLE ctrc
	ADD COLUMN valor_imposto NUMERIC(7,2) NULL;
	
UPDATE ctrc c
	SET valor_imposto = f.valor_frete * 0.025
	FROM frete
	WHERE c.filial_origem  = f.filial_origem_frete /* JOIN de PK composta do frete */
	  AND c.filial_destino = f.filial_destino_frete;

UPDATE ctrc c
	ALTER COLUMN valor_imposto SET NOT NULL;
	
/*------------------------- QUESTÃO 3 -------------------------*/

UPDATE ctrc c
	SET frete_ctrc = f.valor_frete
	FROM frete f,
		cliente cl,
		cidade cd
	WHERE c.data_emissao BETWEEN '2017-10-21' AND '2017-10-23'
	  AND c.filial_origem  = f.filial_origem_frete /* JOIN de PK composta do frete */
	  AND c.filial_destino = f.filial_destino_frete
	  AND c.cliente_remetente = cl.cod_cliente  /* JOIN para tabela cliente */
	  AND cl.cidade_cliente = cd.cod_cidade 	/* JOIN para a tabela cidade */
	  AND cd.sigla_uf = 'ES';

/*------------------------- QUESTÃO 4 -------------------------*/  

BEGIN TRANSACTION;
	DELETE FROM manifesto_motorista mm
	USING manifesto m
	WHERE m.num_manifesto = mm.num_manifesto; /* JOIN para manifesto */
	WHERE m.filial_origem_manifesto = 'RIO'

	DELETE FROM itens_manifesto im
	USING manifesto m
	WHERE m.num_manifesto = im.num_manifesto; /* JOIN para manifesto */
	WHERE m.filial_origem_manifesto = 'RIO'

	DELETE FROM manifesto m
	WHERE m.filial_origem_manifesto = 'RIO';
COMMIT TRANSACTION;

/*------------------------- QUESTÃO 5 -------------------------*/  

UPDATE ctrc c
	SET frete_ctrc = c.frete_ctrc * 1.15
	FROM itens_manifesto im,
		manifesto m,
		manifesto_motorista mm
	WHERE c.num_ctrc = im.num_ctrc				/* JOIN para itens_manifesto */
		AND im.num_manifesto = m.num_manifesto	/* JOIN para manifesto */
		AND m.num_manifesto  = mm.num_manifesto	/* JOIN para manifesto_motorista */
		AND mm.cnh_motorista = 'D'
		AND c.cliente_remetente LIKE 'H%';