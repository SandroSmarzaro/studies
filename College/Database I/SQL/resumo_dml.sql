CREATE TABLE departamento (
	cod_departamento INTEGER NOT NULL,
	trabalhando BOOLEAN NOT NULL,
	CONSTRAINT pk_cod_departamento
		PRIMARY KEY (cod_departamento)
);

DROP TABLE IF EXISTS departamento;

CREATE TABLE pessoa (
	cpf CHAR(14) NOT NULL,
	cod_departamento INTEGER NOT NULL,
	nome_pessoa 	VARCHAR(30),
	salario NUMERIC(9,2) NULL,
	CONSTRAINT pk_cpf
		PRIMARY KEY (cpf),
	CONSTRAINT fk_cod_departamento
		FOREIGN KEY (cod_departamento)
		REFERENCES departamento(cod_departamento)
);

DROP TABLE IF EXISTS pessoa;

INSERT INTO departamento(cod_departamento, trabalhando) 
	VALUES (1, TRUE),
		   (2, FALSE);

SELECT * FROM departamento;
			
INSERT INTO pessoa(cpf, cod_departamento, nome_pessoa, salario)
	VALUES ('111.111.111-11', 1, 'Fulano', 0),
		   ('123.456.789-00', 2, 'Ciclano',0);
		
SELECT * FROM pessoa;

UPDATE pessoa p
	SET nome_pessoa = 'Euclaciano'
	WHERE p.cpf = '111.111.111-11'
	AND p.cod_departamento = 1;
	
UPDATE pessoa p
	SET salario = 1100.00
	FROM departamento d
	WHERE p.cod_departamento = d.cod_departamento
	AND d.trabalhando = TRUE;
	
DELETE FROM pessoa p
	USING departamento d
	WHERE p.cod_departamento = d.cod_departamento
	AND d.trabalhando = FALSE;
	
	